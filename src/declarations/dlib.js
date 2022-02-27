module.exports = [
    // ["dlib.", "", ["/Properties"], [
    //     ["_variant_t", "extended", "", ["/R", "/External"]],
    // ], "", ""],

    ["dlib.variant", "_variant_t", ["/External"], [
        ["void*", "ptr", "", []],
    ], "", ""],

    ["dlib.dot", "double", [], [
        ["dpoint", "a", "", ["/Ref"]],
        ["dpoint", "b", "", ["/Ref"]],
    ], "", ""],

    ["dlib.length", "double", [], [
        ["dpoint", "p", "", ["/Ref"]],
    ], "", ""],

    ["dlib.polygon_area", "double", [], [
        ["vector_dpoint", "pts", "", ["/Ref"]],
    ], "", ""],
];
