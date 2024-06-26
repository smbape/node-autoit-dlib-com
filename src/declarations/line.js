module.exports = [
    ["class dlib.line", "", ["/Simple"], [
        ["dpoint", "normal", "", ["/R", "=normal()"]],
        ["dpoint", "p1", "", ["/R", "=p1()"]],
        ["dpoint", "p2", "", ["/R", "=p2()"]],
    ], "", ""],

    ["dlib.line.line", "", [], [], "", ""],

    ["dlib.line.line", "", [], [
        ["dpoint", "a", "", []],
        ["dpoint", "b", "", []],
    ], "", ""],

    ["dlib.line.line", "", [], [
        ["point", "a", "", []],
        ["point", "b", "", []],
    ], "", ""],

    ["dlib.signed_distance_to_line", "double", [], [
        ["line", "l", "", []],
        ["dpoint", "p", "", []],
    ], "", ""],

    ["dlib.signed_distance_to_line", "double", [], [
        ["line", "l", "", []],
        ["point", "p", "", []],
    ], "", ""],

    ["dlib.distance_to_line", "double", [], [
        ["line", "l", "", []],
        ["dpoint", "p", "", []],
    ], "", ""],

    ["dlib.distance_to_line", "double", [], [
        ["line", "l", "", []],
        ["point", "p", "", []],
    ], "", ""],

    ["dlib.intersect", "dpoint", [], [
        ["line", "a", "", []],
        ["line", "b", "", []],
    ], "", ""],

    ["dlib.angle_between_lines", "double", [], [
        ["line", "a", "", []],
        ["line", "b", "", []],
    ], "", ""],

    ["dlib.count_points_on_side_of_line", "double", [], [
        ["line", "l", "", []],
        ["dpoint", "reference_point", "", []],
        ["std::vector<dpoint>", "pts", "", []],
        ["double", "dist_thresh_min", "0", []],
        ["double", "dist_thresh_max", "std::numeric_limits<double>::infinity()", []],
    ], "", ""],

    ["dlib.count_points_on_side_of_line", "double", [], [
        ["line", "l", "", []],
        ["dpoint", "reference_point", "", []],
        ["std::vector<point>", "pts", "", []],
        ["double", "dist_thresh_min", "0", []],
        ["double", "dist_thresh_max", "std::numeric_limits<double>::infinity()", []],
    ], "", ""],

    ["dlib.count_points_between_lines", "double", [], [
        ["line", "l1", "", []],
        ["line", "l2", "", []],
        ["dpoint", "reference_point", "", []],
        ["std::vector<dpoint>", "pts", "", []],
    ], "", ""],

    ["dlib.count_points_between_lines", "double", [], [
        ["line", "l1", "", []],
        ["line", "l2", "", []],
        ["dpoint", "reference_point", "", []],
        ["std::vector<point>", "pts", "", []],
    ], "", ""],
];
