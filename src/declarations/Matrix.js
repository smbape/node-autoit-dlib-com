const declarations = [
    ["class dlib.Matrix", "", ["/Simple"], [], "", ""],

    ["dlib.Matrix.Matrix", "", [], [], "", ""],

    ["dlib.Matrix.create", "Ptr<Matrix>", ["/External"], [
        ["vector_double", "list", "", []]
    ], "", ""],

    ["dlib.Matrix.create", "Ptr<Matrix>", ["/External"], [
        ["vector_vector_double", "list", "", []]
    ], "", ""],

    ["dlib.Matrix.create", "Ptr<Matrix>", ["/External"], [
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

    ["dlib.Matrix.shape", "tuple_long_and_long", ["/External"], [], "", ""],

    ["dlib.Matrix.ToString", "string", ["/External"], [], "", ""],
];

module.exports = declarations;
