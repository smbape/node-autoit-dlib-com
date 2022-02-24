const { spawn } = require("child_process");
const sysPath = require("path");
const fs = require("fs");
const eachOfLimit = require("async/eachOfLimit");
const waterfall = require("async/waterfall");

const regexEscape = str => {
    return str.replace(/[-/\\^$*+?.()|[\]{}]/g, "\\$&");
};

const version = process.env.npm_package_version || require("../package.json").version;
const readme = sysPath.join(__dirname, "..", "README.md");

const updateContent = (file, replacer, cb) => {
    waterfall([
        next => {
            fs.readFile(file, next);
        },

        (buffer, next) => {
            const oldContent = buffer.toString();
            const newContent = replacer(oldContent);

            if (newContent === oldContent) {
                next(null, false);
                return;
            }

            fs.writeFile(file, newContent, err => {
                next(err, true);
            });
        },

        (hasChanged, next) => {
            if (!hasChanged) {
                next(0, null);
                return;
            }

            const child = spawn("git", ["add", file], {
                stdio: "inherit"
            });

            child.on("error", next);
            child.on("close", next);
        }
    ], (err, chunk) => {
        cb(err);
    });
};

waterfall([
    next => {
        const oldContent = fs.readFileSync(readme).toString();
        const pos = oldContent.indexOf("autoit-dlib-com-v");
        if (pos === -1) {
            next(null, false);
            return;
        }

        const start = pos + "autoit-dlib-com-v".length;
        const end = oldContent.indexOf(".7z", start);
        if (end === -1) {
            next(null, false);
            return;
        }

        const oldVersion = oldContent.slice(start, end);
        next(null, oldVersion);
    },

    (oldVersion, next) => {
        if (!oldVersion) {
            next();
            return;
        }

        waterfall([
            next => {
                updateContent(readme, oldContent => {
                    const replacer = new RegExp(regexEscape(oldVersion), "g");
                    return oldContent.replace(replacer, version);
                }, next);
            },

            next => {
                updateContent(sysPath.join(__dirname, "..", "autoit-dlib-com", "install.bat"), oldContent => {
                    return oldContent.replace(/VERSION: \S+/, `VERSION: ${ version }`);
                }, next);
            },

            next => {
                updateContent(sysPath.join(__dirname, "..", "autoit-dlib-com", "src", "dlibCOM.rc"), oldContent => {
                    const vsversion = version.split(".").join(",").replace(/[^\d,]/g, "");
                    return oldContent
                        .replace(/FILEVERSION \S+/, `FILEVERSION ${ vsversion }`)
                        .replace(/PRODUCTVERSION \S+/, `PRODUCTVERSION ${ vsversion }`)
                        .replace(/"FileVersion", "\S+"/, `"FileVersion", "${ version }"`)
                        .replace(/"ProductVersion", "\S+"/, `"ProductVersion", "${ version }"`);
                }, next);
            }
        ], next);
    }
], err => {
    if (err) {
        throw err;
    }
});
