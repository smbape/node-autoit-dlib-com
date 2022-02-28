/* eslint-disable no-magic-numbers */

const fs = require("fs");
const fsPromises = require("fs/promises");
const sysPath = require("path");
const {spawn} = require("child_process");

const mkdirp = require("mkdirp");
const waterfall = require("async/waterfall");
const {explore} = require("fs-explorer");

const progids = new Map([
    ["dlib.simple_structural_svm_problem", "structural_svm_problem"],
    ["dlib.SpaceVector", "vector"],
    ["vec_ranking_pair", "ranking_pair"],
    ["vec_svm_rank_trainer", "svm_rank_trainer"],
]);

const parseArguments = PROJECT_DIR => {
    const options = {
        APP_NAME: "Dlib",
        LIB_UID: "a7599799-48f5-4569-b79e-7eff77460ede",
        LIBRARY: "dlibCOM",
        namespace: "dlib",
        shared_ptr: "std::shared_ptr",
        assert: "AUTOIT_ASSERT",
        // variantTypeReg: /^d?point$/,
        progid: progid => {
            if (progids.has(progid)) {
                return progids.get(progid);
            }

            return progid;
        },
        build: new Set(),
        notest: new Set(),
        skip: new Set(),
        make: sysPath.join(PROJECT_DIR, "build.bat"),
        includes: [sysPath.join(PROJECT_DIR, "src")],
        output: sysPath.join(PROJECT_DIR, "generated"),
    };

    for (const opt of ["iface", "hdr", "impl", "idl", "rgs", "res", "save"]) {
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
    ALIASES,
    CUSTOM_CLASSES,
    CUSTOM_NAMESPACES,
} = require("./constants");

const custom_declarations = require("./custom_declarations");
const AutoItGenerator = require("./AutoItGenerator");

const PROJECT_DIR = sysPath.resolve(__dirname, "../autoit-dlib-com");
const SRC_DIR = sysPath.join(PROJECT_DIR, "src");

const hdr_parser = fs.readFileSync(sysPath.join(PROJECT_DIR, "hdr_parser.py")).toString();
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
        let srcfiles = [sysPath.join(SRC_DIR, "dlib/basic.h")];

        explore(SRC_DIR, async (path, stats, next) => {
            if (path.endsWith(".h") || path.endsWith(".hpp")) {
                const content = await fsPromises.readFile(path);
                if (content.includes("CV_EXPORTS")) {
                    srcfiles.push(path);
                }
            }
            next();
        }, {followSymlink: true}, err => {
            srcfiles = [...(new Set(srcfiles))];
            const generated_include = srcfiles.map(path => `#include "${ path.slice(SRC_DIR.length + 1).replace("\\", "/") }"`);
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
            const aliases = new RegExp(Array.from(ALIASES.keys()).join("|"), "g");
            const replacer = (match, offset, string) => {
                return offset === 0
                    || /\W/.test(string[offset - 1])
                    || string.endsWith("vector_", offset)
                    || string.endsWith("Ptr_", offset) ? ALIASES.get(match) : match;
            };

            let result = buffer.toString();
            if (ALIASES.size !== 0) {
                result = result.replace(aliases, replacer);
            }

            const configuration = JSON.parse(result);
            configuration.generated_include = generated_include;

            configuration.decls.push(...custom_declarations);

            for (const [name, modifiers] of CUSTOM_CLASSES) {
                configuration.decls.push([`class ${ name }`, "", modifiers, [], "", ""]);
            }

            configuration.namespaces.push(...CUSTOM_NAMESPACES);

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

        child.stdin.write(`
            import io, json, os, re, string, sys

            ${ hdr_parser
                .slice(hdr_parser_start, hdr_parser_end)
                .replace(`${ " ".repeat(20) }if self.wrap_mode:`, `${ " ".repeat(20) }if False:`)
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

            print(json.dumps({"decls": all_decls, "namespaces": sorted(parser.namespaces)}, indent=4))
        `.trim().replace(/^ {12}/mg, ""));
        child.stdin.end();
    }
], err => {
    if (err) {
        throw err;
    }
    console.log(`Build files have been written to: ${ options.output }`);
});
