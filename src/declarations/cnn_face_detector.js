module.exports = [
    ["struct dlib.mmod_rect", "", ["/Simple"], [
        ["rectangle", "rect", "", ["/RW"]],
        ["double", "confidence", "", ["/RW", "=detection_confidence"]],
        ["string", "label", "", ["/RW"]],
        ["bool", "ignore", "", ["/RW"]],
    ], "", ""],

    ["dlib.mmod_rect.mmod_rect", "", [], [
        ["rectangle", "rect", "rectangle()", []],
        ["double", "detection_confidence", "0", []],
        ["string", "label", "string()", ""],
    ], "", ""],
];
