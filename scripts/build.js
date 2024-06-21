const { spawn } = require("child_process");
const sysPath = require("path");
const eachOfLimit = require("async/eachOfLimit");

const version = process.env.npm_package_version || require("../package.json").version;
const sources = sysPath.resolve(__dirname, "..");
const archive = sysPath.join(sources, `autoit-dlib-19.24.4-opencv-4.10.0-com-v${ version }.7z`);
const project = sysPath.join(sources, "autoit-dlib-com");

const files = [
    [project, "install.bat"],
    [project, "udf/*.au3", "udf/*.md"],
    [sysPath.join(project, "generated"), "*.tlb"],
    [sysPath.join(project, "build_x64", "bin", "Debug"), "autoit_dlib_com-19.24.4-4100*"],
    [sysPath.join(project, "build_x64", "bin", "Release"), "autoit_dlib_com-19.24.4-4100*"],
];

eachOfLimit(files, 1, ([cwd, ...args], i, next) => {
    const child = spawn("7z", ["a", archive, ...args], {
        cwd,
        stdio: "inherit"
    });

    child.on("close", () => {
        if (next !== null) {
            next();
        }
    });
    child.on("error", err => {
        if (next !== null) {
            next(err);
            next = null;
        } else {
            console.error(err);
        }
    });
});
