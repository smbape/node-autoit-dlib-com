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

    ["dlib.dnn_prefer_fastest_algorithms", "bool", [], [], "", ""],
    ["dlib.set_dnn_prefer_fastest_algorithms", "void", [], [], "", ""],
    ["dlib.set_dnn_prefer_smallest_algorithms", "void", [], [], "", ""],

    ["dlib.cuda.set_device", "void", [], [
        ["int", "device", "", []],
    ], "", ""],

    ["dlib.cuda.get_device", "int", [], [], "", ""],

    ["dlib.cuda.get_device_name", "string", [], [
        ["int", "device", "", []],
    ], "", ""],

    ["dlib.cuda.set_current_device_blocking_sync", "void", [], [], "", ""],

    ["dlib.cuda.can_access_peer", "bool", [], [
        ["int", "device_id", "", []],
        ["int", "peer_device_id", "", []],
    ], "", ""],

    ["dlib.cuda.device_synchronize", "void", [], [
        ["int", "device_id", "", []],
    ], "", ""],
];
