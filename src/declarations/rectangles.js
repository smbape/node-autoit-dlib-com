module.exports = ({ self, self_get }) => {
    const declarations = [
        ["class dlib.rect_filter", "", ["/Simple"], [], "", ""],

        ["dlib.rect_filter.rect_filter", "", [], [], "", ""],

        ["dlib.rect_filter.rect_filter", "", [], [
            ["double", "measurement_noise", "", []],
            ["double", "typical_acceleration", "", []],
            ["double", "max_measurement_deviation", "", []],
        ], "", ""],

        ["dlib.rect_filter.measurement_noise", "double", [`/Call=${ self_get("get_left") }().get_measurement_noise`], [], "", ""],
        ["dlib.rect_filter.typical_acceleration", "double", [`/Call=${ self_get("get_left") }().get_typical_acceleration`], [], "", ""],
        ["dlib.rect_filter.max_measurement_deviation", "double", [`/Call=${ self_get("get_left") }().get_max_measurement_deviation`], [], "", ""],

        ["dlib.rect_filter.call", "drectangle", [`/Call=(${ self })`, "/attr=propget", "=get_call", "/idlname=call", "/id=DISPID_VALUE"], [
            ["rectangle", "rect", "", []],
        ], "", ""],

        ["dlib.rect_filter.call", "drectangle", [`/Call=(${ self })`, "/attr=propget", "=get_call", "/idlname=call", "/id=DISPID_VALUE"], [
            ["drectangle", "rect", "", []],
        ], "", ""],

        ["dlib.find_optimal_rect_filter", "rect_filter", [], [
            ["std::vector<rectangle>", "rects", "", []],
            ["double", "smoothness", "1", []],
        ], "", ""],
    ];

    for (const [class_type, scalar_type, unsigned_type, point_type] of [["rectangle", "long", "ULONG", "point"], ["drectangle", "double", "double", "dpoint"]]) {
        const abbr = class_type.slice(0, -"angle".length);

        declarations.push(...[
            [`class dlib.${ class_type }`, "", ["/Simple"], [], "", ""],

            [`dlib.${ class_type }.${ class_type }`, "", [], [], "", ""],

            [`dlib.${ class_type }.${ class_type }`, "", [], [
                [scalar_type, "left", "", ["/Ref"]],
                [scalar_type, "top", "", ["/Ref"]],
                [scalar_type, "right", "", ["/Ref"]],
                [scalar_type, "bottom", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.${ class_type }`, "", [], [
                ["drectangle", "rect", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.${ class_type }`, "", [], [
                ["rectangle", "rect", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.area`, unsigned_type, [], [], "", ""],
            [`dlib.${ class_type }.left`, scalar_type, [], [], "", ""],
            [`dlib.${ class_type }.top`, scalar_type, [], [], "", ""],
            [`dlib.${ class_type }.right`, scalar_type, [], [], "", ""],
            [`dlib.${ class_type }.bottom`, scalar_type, [], [], "", ""],
            [`dlib.${ class_type }.width`, unsigned_type, [], [], "", ""],
            [`dlib.${ class_type }.height`, unsigned_type, [], [], "", ""],

            [`dlib.${ class_type }.tl_corner`, point_type, [], [], "", ""],
            [`dlib.${ class_type }.tr_corner`, point_type, [], [], "", ""],
            [`dlib.${ class_type }.bl_corner`, point_type, [], [], "", ""],
            [`dlib.${ class_type }.br_corner`, point_type, [], [], "", ""],

            [`dlib.${ class_type }.is_empty`, "bool", [], [], "", ""],

            [`dlib.${ class_type }.center`, point_type, ["/Call=dlib::center", `/Expr=${ self }`], [], "", ""],
            [`dlib.${ class_type }.dcenter`, "dpoint", ["/Call=dlib::dcenter", `/Expr=${ self }`], [], "", ""],

            [`dlib.${ class_type }.contains`, "bool", [], [
                ["dpoint", "point", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.contains`, "bool", [], [
                ["point", "point", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.contains`, "bool", ["/Expr=point($0)"], [
                ["long", "x", "", ["/Ref"]],
                ["long", "y", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.contains`, "bool", [], [
                [class_type, "rect", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.intersect`, class_type, [], [
                [class_type, "rect", "", ["/Ref"]],
            ], "", ""],

            [`dlib.${ class_type }.ToString`, "string", ["/External"], [], "", ""],

            ["dlib.translate_rect", class_type, [], [
                [class_type, "rect", "", []],
                ["point", "p", "", []],
            ], "", ""],

            ["dlib.translate_rect", class_type, [], [
                [class_type, "rect", "", []],
                ["dpoint", "p", "", [point_type === "point" ? "/Cast=point" : ""]],
            ], "", ""],

            ["dlib.shrink_rect", class_type, [], [
                [class_type, "rect", "", []],
                [scalar_type, "num", "", []],
            ], "", ""],

            ["dlib.scale_rect", class_type, [], [
                [class_type, "rect", "", []],
                ["double", "scale", "", []],
            ], "", ""],

            [`dlib.centered_${ abbr }`, class_type, [], [
                [point_type, "p", "", []],
                [unsigned_type, "width", "", []],
                [unsigned_type, "height", "", []],
            ], "", ""],

            [`dlib.centered_${ abbr }`, class_type, [], [
                [class_type, "rect", "", []],
                [unsigned_type, "width", "", []],
                [unsigned_type, "height", "", []],
            ], "", ""],

            ["dlib.center", point_type, [], [
                [class_type, "rect", "", []],
            ], "", ""],
        ]);

        if (class_type === "rectangle") {
            declarations.push(...[
                [`dlib.centered_${ abbr }`, class_type, [], [
                    [scalar_type, "x", "", []],
                    [scalar_type, "y", "", []],
                    [unsigned_type, "width", "", []],
                    [unsigned_type, "height", "", []],
                ], "", ""],

                [`dlib.centered_${ abbr }s`, `std::vector<${ class_type }>`, [], [
                    [`std::vector<${ point_type }>`, "pts", "", []],
                    [unsigned_type, "width", "", []],
                    [unsigned_type, "height", "", []],
                ], "", ""],
            ]);
        }
    }

    return declarations;
};
