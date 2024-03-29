/* eslint-disable no-magic-numbers */

const fs = require("node:fs");
const fsPromises = require("node:fs/promises");
const sysPath = require("node:path");
const {spawn} = require("node:child_process");

const mkdirp = require("mkdirp");
const waterfall = require("async/waterfall");
const {explore} = require("fs-explorer");

const OpenCV_VERSION = "opencv-4.7.0";
const OpenCV_DLLVERSION = OpenCV_VERSION.slice("opencv-".length).replaceAll(".", "");
const DLIB_VERSION = "19.24";

const progids = new Map([
    ["dlib.simple_object_detector", "dlib.fhog_object_detector"],
    ["dlib.simple_object_detector_com", "dlib.simple_object_detector"],
    ["dlib.simple_structural_svm_problem", "dlib.structural_svm_problem"],
    ["dlib.SpaceVector", "dlib.vector"],
    ["dlib.Matrix", "dlib.matrix"],
    ["dlib.vec_ranking_pair", "dlib.ranking_pair"],
    ["dlib.vec_svm_rank_trainer", "dlib.svm_rank_trainer"],
    ["dlib.mmod_rect", "dlib.mmod_rectangle"],
    ["dlib.gender_t", "dlib.gender_type"],
]);

const parseArguments = PROJECT_DIR => {
    const options = {
        APP_NAME: "Dlib",
        LIB_UID: "a7599799-48f5-4569-b79e-7eff77460ede",
        LIBRARY: "dlibCOM",
        OUTPUT_NAME: `autoit_dlib_com-${ DLIB_VERSION }-${ OpenCV_DLLVERSION }`,
        OUTPUT_DIRECTORY_DEBUG: `${ PROJECT_DIR }/build_x64/bin/Debug`,
        OUTPUT_DIRECTORY_RELEASE: `${ PROJECT_DIR }/build_x64/bin/Release`,
        namespace: "dlib",
        shared_ptr: "std::shared_ptr",
        make_shared: "std::make_shared",
        assert: "AUTOIT_ASSERT",
        progid: progid => {
            if (progids.has(progid)) {
                return progids.get(progid);
            }

            return progid;
        },
        namespaces: new Set([
            "cv",
            "dlib",
            "std",
        ]),
        other_namespaces: new Set([
            "dlib::image_dataset_metadata"
        ]),
        remove_namespaces: new Set([
            "cv(?!::Point)",
            "dlib",
            "std",
        ]),
        build: new Set(),
        notest: new Set(),
        skip: new Set(),
        includes: [sysPath.join(PROJECT_DIR, "src")],
        output: sysPath.join(PROJECT_DIR, "generated"),
        toc: true,
        globals: [
            "$CV_ACCESS_READ",
            "$CV_ACCESS_WRITE",
            "$CV_ACCESS_RW",
            "$CV_ACCESS_MASK",
            "$CV_ACCESS_FAST",
            "$CV_USAGE_DEFAULT",
            "$CV_USAGE_ALLOCATE_HOST_MEMORY",
            "$CV_USAGE_ALLOCATE_DEVICE_MEMORY",
            "$CV_USAGE_ALLOCATE_SHARED_MEMORY",
            "$CV___UMAT_USAGE_FLAGS_32BIT",
        ],
        onCoClass: (generator, coclass, opts) => {
            const {fqn} = coclass;

            const parts = fqn.split("::");

            for (let i = 1; i < parts.length; i++) {
                generator.add_func([`${ parts.slice(0, i).join(".") }.`, "", ["/Properties"], [
                    [parts.slice(0, i + 1).join("::"), parts[i], "", ["/R", "/S", "=this"]],
                ], "", ""]);
            }
        },
    };

    for (const opt of ["iface", "hdr", "impl", "idl", "manifest", "rgs", "res", "save"]) {
        options[opt] = !process.argv.includes(`--no-${ opt }`);
    }

    for (const opt of ["test"]) {
        options[opt] = process.argv.includes(`--${ opt }`);
    }

    for (const opt of process.argv) {
        if (opt.startsWith("--no-test=")) {
            for (const fqn of opt.slice("--no-test=".length).split(/[ ,]/)) {
                options.notest.add(fqn);
            }
        }

        if (opt.startsWith("--build=")) {
            for (const fqn of opt.slice("--build=".length).split(/[ ,]/)) {
                options.build.add(fqn);
            }
        }

        if (opt.startsWith("--skip=")) {
            for (const fqn of opt.slice("--skip=".length).split(/[ ,]/)) {
                options.skip.add(fqn);
            }
        }
    }

    return options;
};

const {
    CUSTOM_CLASSES,
} = require("./constants");

const {findFile} = require("./FileUtils");
const custom_declarations = require("./custom_declarations");
const AutoItGenerator = require("./AutoItGenerator");

const PROJECT_DIR = sysPath.resolve(__dirname, "../autoit-dlib-com");
const SRC_DIR = sysPath.join(PROJECT_DIR, "src");
const opencv_SOURCE_DIR = findFile(`${ OpenCV_VERSION }-*/opencv/sources`, sysPath.resolve(__dirname, ".."));

const src2 = sysPath.resolve(opencv_SOURCE_DIR, "modules/python/src2");

const hdr_parser = fs.readFileSync(sysPath.join(src2, "hdr_parser.py")).toString();
const hdr_parser_start = hdr_parser.indexOf("class CppHeaderParser");
const hdr_parser_end = hdr_parser.indexOf("if __name__ == '__main__':");

const options = parseArguments(PROJECT_DIR);

waterfall([
    next => {
        mkdirp(options.output).then(performed => {
            next();
        }, next);
    },

    next => {
        const srcfiles = [];

        explore(SRC_DIR, async (path, stats, next) => {
            if (path.endsWith(".h") || path.endsWith(".hpp")) {
                const content = await fsPromises.readFile(path);
                if (content.includes("CV_EXPORTS")) {
                    srcfiles.push(path);
                }
            }
            next();
        }, {followSymlink: true}, err => {
            const generated_include = srcfiles.map(path => `#include "${ path.slice(SRC_DIR.length + 1).replace("\\", "/") }"`);
            generated_include.push("#include <opencv2/imgcodecs.hpp>");
            next(err, srcfiles, generated_include);
        });
    },

    (srcfiles, generated_include, next) => {
        const buffers = [];
        let nlen = 0;
        const child = spawn("python", []);

        child.stderr.on("data", chunk => {
            process.stderr.write(chunk);
        });

        child.on("close", code => {
            if (code !== 0) {
                console.log(`python process exited with code ${ code }`);
                process.exit(code);
            }

            const buffer = Buffer.concat(buffers, nlen);

            const configuration = JSON.parse(buffer.toString());
            configuration.decls.push(...custom_declarations.load(options));
            configuration.generated_include = generated_include;

            for (const [name, modifiers] of CUSTOM_CLASSES) {
                configuration.decls.push([`class ${ name }`, "", modifiers, [], "", ""]);
            }

            configuration.namespaces.push(...options.namespaces);
            configuration.namespaces.push(...options.other_namespaces);

            const generator = new AutoItGenerator();
            generator.generate(configuration, options, next);
        });

        child.stderr.on("data", chunk => {
            process.stderr.write(chunk);
        });

        child.stdout.on("data", chunk => {
            buffers.push(chunk);
            nlen += chunk.length;
        });

        const code = `
            import io, json, os, re, string, sys

            ${ hdr_parser
                .slice(hdr_parser_start, hdr_parser_end)
                .replace(`${ " ".repeat(20) }if self.wrap_mode:`, `${ " ".repeat(20) }if False:`)
                .replace(/\("std::", ""\), \("cv::", ""\)/g, Array.from(options.namespaces).map(namespace => `("${ namespace }::", "")`).join(", "))
                .split("\n")
                .join(`\n${ " ".repeat(12) }`) }

            srcfiles = []

            ${ srcfiles.map(file => `srcfiles.append(${ JSON.stringify(file) })`).join(`\n${ " ".repeat(12) }`) }

            parser = CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
            all_decls = []
            for hdr in srcfiles:
                decls = parser.parse(hdr)
                if len(decls) == 0 or hdr.find('/python/') != -1:
                    continue

                all_decls += decls

            # parser.print_decls(all_decls)
            print(json.dumps({"decls": all_decls, "namespaces": sorted(parser.namespaces)}, indent=4))
        `.trim().replace(/^ {12}/mg, "");

        // fs.writeFileSync(sysPath.join(__dirname, "../gen.py"), code);

        child.stdin.write(code);
        child.stdin.end();
    }
], err => {
    if (err) {
        throw err;
    }
    console.log(`Build files have been written to: ${ options.output }`);
});
