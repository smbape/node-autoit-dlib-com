const sparse_vect = "std::vector<std::pair<ULONG, double>>";

module.exports = [
    ["dlib.load_libsvm_formatted_data", "void", [], [
        ["string", "file_name", "", ["/Ref"]],
        [`std::vector<${ sparse_vect }>`, "samples", "", ["/Ref", "/O"]],
        ["std::vector<double>", "labels", "", ["/Ref", "/O"]],
    ], "", ""],

    ["dlib.count_steps_without_decrease", "size_t", [], [
        ["std::vector<double>", "time_series", "", ["/Ref"]],
        ["double", "probability_of_decrease", "0.51", []],
    ], "", ""],

    ["dlib.count_steps_without_decrease_robust", "size_t", [], [
        ["std::vector<double>", "time_series", "", ["/Ref"]],
        ["double", "probability_of_decrease", "0.51", []],
        ["double", "quantile_discard", "0.1", []],
    ], "", ""],

    ["dlib.probability_gradient_greater_than", "double", ["=probability_that_sequence_is_increasing"], [
        ["std::vector<double>", "time_series", "", ["/Ref"]],
        ["double", "thresh", "0", []],
    ], "", ""],
];
