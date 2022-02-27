module.exports = [
    ["class dlib.SpaceVector", "", ["/Simple"], [
        ["tuple_long_and_long", "shape", "", ["/R", "/External"]],
    ], "", ""],

    ["dlib.SpaceVector.SpaceVector", "", [], [], "", ""],

    ["dlib.SpaceVector.create", "Ptr_SpaceVector", ["/External"], [
        ["vector_double", "list", "", []]
    ], "", ""],

    ["dlib.SpaceVector.create", "Ptr_SpaceVector", ["/External"], [
        ["long", "rows", "", []],
    ], "", ""],

    ["dlib.SpaceVector.set_size", "void", ["/External"], [
        ["long", "rows", "", []],
    ], "", ""],

    ["dlib.SpaceVector.resize", "void", ["/External"], [
        ["long", "rows", "", []],
    ], "", ""],

    ["dlib.SpaceVector.size", "long", [], [], "", ""],

    ["dlib.SpaceVector.set", "void", ["/External"], [
        ["long", "row", "", []],
        ["double", "val", "", []],
    ], "", ""],

    ["dlib.SpaceVector.get", "double", ["/External"], [
        ["long", "row", "", []],
    ], "", ""],

    ["dlib.SpaceVector.slice", "SpaceVector", ["/External"], [
        ["size_t", "start", "", []],
        ["size_t", "stop", "this->__self->get()->size()", []],
        ["size_t", "step", "1", []],
    ], "", ""],

    ["dlib.SpaceVector.ToString", "string", ["/External"], [], "", ""],

    ["dlib.dot", "double", [], [
        ["SpaceVector", "a", "", ["/Ref"]],
        ["SpaceVector", "b", "", ["/Ref"]],
    ], "", ""],
];
