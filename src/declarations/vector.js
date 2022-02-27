module.exports = [
    ["class dlib.point_transform_projective", "", ["/Simple"], [
        ["Matrix", "m", "", ["/R", "=get_m()"]]
    ], "", ""],

    ["dlib.point_transform_projective.point_transform_projective", "", [], [], "", ""],

    ["dlib.point_transform_projective.create", "Ptr_point_transform_projective", ["/External"], [
        ["Matrix", "m", "", []]
    ], "", ""],

    ["dlib.inv", "point_transform_projective", [], [
        ["point_transform_projective", "trans", "", ["/Ref"]],
    ], "", ""],

    ["dlib.find_projective_transform", "point_transform_projective", ["/External"], [
        ["vector_dpoint", "from_points", "", ["/Ref"]],
        ["vector_dpoint", "to_points", "", ["/Ref"]],
    ], "", ""],

    ["dlib.find_projective_transform", "point_transform_projective", ["/External"], [
        ["Matrix", "from_points", "", ["/Ref"]],
        ["Matrix", "to_points", "", ["/Ref"]],
    ], "", ""],
];
