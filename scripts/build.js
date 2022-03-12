const { spawn } = require("child_process");
const sysPath = require("path");
const eachOfLimit = require("async/eachOfLimit");

const version = process.env.npm_package_version || require("../package.json").version;
const sources = sysPath.resolve(__dirname, "..");
const archive = sysPath.join(sources, `autoit-dlib-19.23.0-opencv-4.5.5-com-v${ version }.7z`);
const project = sysPath.join(sources, "autoit-dlib-com");

const files = [
    [project, "install.bat"],
    [project, "udf/*.au3"],
    [sysPath.join(project, "generated"), "dlibCOM.tlb"],
    [sysPath.join(project, "build_x64", "Debug"), "autoit*"],
    [sysPath.join(project, "build_x64", "Release"), "autoit*"],
];

eachOfLimit(files, 1, ([cwd, file], i, next) => {
    const child = spawn("7z", ["a", archive, file], {
        cwd,
        stdio: "inherit"
    });

    child.on("close", next);
    child.on("error", next);
});
