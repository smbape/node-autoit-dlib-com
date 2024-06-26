module.exports = ({ self_get, shared_ptr }) => {
        const declarations = [
        // vector
        ["class dlib.SpaceVector", "", ["/Simple"], [
            ["std::tuple<long, long>", "shape", "", ["/R", "/External"]],
        ], "", ""],

        ["dlib.SpaceVector.SpaceVector", "", [], [], "", ""],

        ["dlib.SpaceVector.create", `${ shared_ptr }<SpaceVector>`, ["/External", "/S"], [
            ["std::vector<double>", "list", "", []]
        ], "", ""],

        ["dlib.SpaceVector.create", `${ shared_ptr }<SpaceVector>`, ["/External", "/S"], [
            ["long", "rows", "", []],
        ], "", ""],

        ["dlib.SpaceVector.set_size", "void", ["/External"], [
            ["long", "rows", "", []],
        ], "", ""],

        ["dlib.SpaceVector.resize", "void", ["/External"], [
            ["long", "rows", "", []],
        ], "", ""],

        ["dlib.SpaceVector.size", "long", [], [], "", ""],

        ["dlib.SpaceVector.get", "double", ["/External"], [
            ["long", "row", "", []],
        ], "", ""],

        ["dlib.SpaceVector.set", "void", ["/External"], [
            ["long", "row", "", []],
            ["double", "val", "", []],
        ], "", ""],

        ["dlib.SpaceVector.get", "double", ["/ExternalNoDecl", "/attr=propget", "=get_Item", "/idlname=Item", "/id=DISPID_VALUE"], [
            ["long", "row", "", []],
        ], "", ""],

        ["dlib.SpaceVector.set", "void", ["/ExternalNoDecl", "/attr=propput", "=put_Item", "/idlname=Item", "/id=DISPID_VALUE"], [
            ["long", "row", "", []],
            ["double", "val", "", []],
        ], "", ""],

        ["dlib.SpaceVector.slice", "SpaceVector", ["/External"], [
            ["long", "start", "", []],
            ["long", "stop", `${ self_get("size") }()`, []],
            ["long", "step", "1", []],
        ], "", ""],

        ["dlib.SpaceVector.ToString", "string", ["/External"], [], "", ""],

        ["dlib.dot", "double", [], [
            ["SpaceVector", "a", "", ["/Ref"]],
            ["SpaceVector", "b", "", ["/Ref"]],
        ], "", ""],

        // point_transform_projective

        ["class dlib.point_transform_projective", "", ["/Simple"], [
            ["Matrix", "m", "", ["/R", "=get_m()"]]
        ], "", ""],

        ["dlib.point_transform_projective.point_transform_projective", "", [], [], "", ""],

        ["dlib.point_transform_projective.create", `${ shared_ptr }<point_transform_projective>`, ["/External"], [
            ["Matrix", "m", "", []]
        ], "", ""],

        ["dlib.point_transform_projective.create", `${ shared_ptr }<point_transform_projective>`, ["/External"], [
            ["cv::Mat", "m", "", []]
        ], "", ""],

        ["dlib.inv", "point_transform_projective", [], [
            ["point_transform_projective", "trans", "", ["/Ref"]],
        ], "", ""],

        ["dlib.find_projective_transform", "point_transform_projective", ["/External"], [
            ["std::vector<dpoint>", "from_points", "", ["/Ref"]],
            ["std::vector<dpoint>", "to_points", "", ["/Ref"]],
        ], "", ""],

        ["dlib.find_projective_transform", "point_transform_projective", ["/External"], [
            ["Matrix", "from_points", "", ["/Ref"]],
            ["Matrix", "to_points", "", ["/Ref"]],
        ], "", ""],

        ["dlib.find_projective_transform", "point_transform_projective", ["/External"], [
            ["cv::Mat", "from_points", "", ["/Ref"]],
            ["cv::Mat", "to_points", "", ["/Ref"]],
        ], "", ""],

        // dlib methods

        ["dlib.polygon_area", "double", [], [
            ["std::vector<dpoint>", "pts", "", ["/Ref"]],
        ], "", ""],
    ];

    for (const [class_type, scalar_type, other_type] of [["dpoint", "double", "point"], ["point", "long", "dpoint"]]) {
        declarations.push(...[
            [`class dlib.${ class_type }`, "", ["/Simple"], [
                [scalar_type, "x", "", ["/RW", "=x()"]],
                [scalar_type, "y", "", ["/RW", "=y()"]],
            ], "", ""],

            [`dlib.${ class_type }.${ class_type }`, "", [], [
                [scalar_type, "x", "0", ["/Ref"]],
                [scalar_type, "y", "0", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.${ class_type }`, "", [], [
                [other_type, "p", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.normalize`, class_type, [], [], "", ""],

            [`dlib.${ class_type }.operator+`, class_type, ["=add"], [
                [class_type, "other", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.operator-`, class_type, ["=sub"], [
                [class_type, "other", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.operator/`, class_type, ["=divide"], [
                ["double", "scalar", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.operator*`, class_type, ["=multiply"], [
                ["double", "scalar", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.ToString`, "string", ["/External"], [], "", ""],

            ["dlib.dot", "double", [], [
                [class_type, "a", "", ["/Ref"]],
                [class_type, "b", "", ["/Ref"]],
            ], "", ""],

            ["dlib.length", "double", [], [
                [class_type, "p", "", ["/Ref"]],
            ], "", ""],
        ]);
    }

    return declarations;
};
