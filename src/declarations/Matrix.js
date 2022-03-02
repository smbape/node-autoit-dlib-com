module.exports = [
    ["class dlib.Matrix", "", ["/Simple"], [
        ["tuple_long_and_long", "shape", "", ["/R", "/External"]],
    ], "", ""],

    ["dlib.Matrix.Matrix", "", [], [], "", ""],

    ["dlib.Matrix.create", "shared_ptr<Matrix>", ["/External"], [
        ["vector_double", "list", "", []]
    ], "", ""],

    ["dlib.Matrix.create", "shared_ptr<Matrix>", ["/External"], [
        ["vector_vector_double", "list", "", []]
    ], "", ""],

    ["dlib.Matrix.create", "shared_ptr<Matrix>", ["/External"], [
        ["long", "rows", "", []],
        ["long", "cols", "", []],
    ], "", ""],

    ["dlib.Matrix.set_size", "void", ["/External"], [
        ["long", "rows", "", []],
        ["long", "cols", "", []],
    ], "", ""],

    ["dlib.Matrix.nr", "long", [], [], "", ""],
    ["dlib.Matrix.nc", "long", [], [], "", ""],

    ["dlib.Matrix.serialize", "void", ["/External"], [
        ["string", "file", "", []]
    ], "", ""],
    ["dlib.Matrix.deserialize", "void", ["/External"], [
        ["string", "file", "", []]
    ], "", ""],

    ["dlib.Matrix.get", "_row", ["/External"], [
        ["long", "row", "", []],
    ], "", ""],

    ["dlib.Matrix.ToString", "string", ["/External"], [], "", ""],

    ["dlib.dot", "double", [], [
        ["Matrix", "a", "", ["/Ref"]],
        ["Matrix", "b", "", ["/Ref"]],
    ], "", ""],
];
