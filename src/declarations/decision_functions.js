const add_linear_df = (declarations, function_type, sample_type, scalar_type = "double") => {
    declarations.push(...[
        [`struct dlib.${ function_type }`, "", ["/Simple"], [
            [sample_type, "weights", "", ["/R", "/External"]],
            [scalar_type, "bias", "", ["/RW", "/External"]],
        ], "", ""],

        [`dlib.${ function_type }.call`, "double", ["/External"], [
            [sample_type, "sample", "", []],
        ], "", ""],
    ]);
};

const add_df = (declarations, function_type, sample_type, scalar_type = "double") => {
    declarations.push(...[
        [`struct dlib.${ function_type }`, "", ["/Simple"], [
            ["sample_type", "alpha", "", ["/R"]],
            [scalar_type, "b", "", ["/R"]],
            ["vector_sample_type", "basis_vectors", "", ["/R", "/External"]],
        ], "", ""],

        [`dlib.${ function_type }.call`, "double", ["/External"], [
            [sample_type, "sample", "", []],
        ], "", ""],
    ]);
};

const add_normalized_df = (declarations, function_type, sample_type, scalar_type = "double") => {
    declarations.push(...[
        [`struct dlib.${ function_type }`, "", ["/Simple"], [
            ["sample_type", "alpha", "", ["/R", "=function.alpha"]],
            [scalar_type, "b", "", ["/R", "=function.b"]],
            ["vector_sample_type", "basis_vectors", "", ["/R", "/External"]],
            [sample_type, "means", "", ["/R", "=normalizer.means()"]],
            [sample_type, "invstd_devs", "", ["/R", "=normalizer.std_devs()"]],
        ], "", ""],

        [`dlib.${ function_type }.call`, "double", ["/External"], [
            [sample_type, "sample", "", ["/Ref"]],
        ], "", ""],

        [`dlib.${ function_type }.batch_predict`, "vector_double", ["/External"], [
            [`vector_${ sample_type }`, "samples", "", ["/Ref"]],
        ], "", ""],

        [`dlib.${ function_type }.batch_predict`, "vector_double", ["/External"], [
            ["cv::Mat", "samples", "", ["/Ref"]],
        ], "", ""],
    ]);
};

const setup_auto_train_rbf_classifier = declarations => {
    declarations.push(...[
        ["dlib.auto_train_rbf_classifier", "_normalized_decision_function_radial_basis", [], [
            ["vector_sample_type", "x", "", ["/Ref"]],
            ["vector_double", "y", "", ["/Ref"]],
            ["double", "max_runtime_seconds", "", ["/Expr=std::chrono::microseconds((uint64_t)(max_runtime_seconds * 1e6))"]],
            ["bool", "be_verbose", "true", []],
        ], "", ""],

        ["dlib.auto_train_rbf_classifier", "_normalized_decision_function_radial_basis", [], [
            ["cv::Mat", "x", "", ["/Ref", "/Cast=Mat_to_vector_sample_type"]],
            ["vector_double", "y", "", ["/Ref"]],
            ["double", "max_runtime_seconds", "", ["/Expr=std::chrono::microseconds((uint64_t)(max_runtime_seconds * 1e6))"]],
            ["bool", "be_verbose", "true", []],
        ], "", ""],

        ["dlib.reduce", "_normalized_decision_function_radial_basis", ["/External"], [
            ["_normalized_decision_function_radial_basis", "df", "", ["/Ref"]],
            ["vector_sample_type", "x", "", ["/Ref"]],
            ["long", "num_basis_vectors", "", []],
            ["double", "eps", "1e-3", []],
        ], "", ""],

        ["dlib.reduce", "_normalized_decision_function_radial_basis", ["/External"], [
            ["_normalized_decision_function_radial_basis", "df", "", ["/Ref"]],
            ["cv::Mat", "x", "", ["/Ref"]],
            ["long", "num_basis_vectors", "", []],
            ["double", "eps", "1e-3", []],
        ], "", ""],
    ]);
};

const add_test_binary = (declarations, decision_function, sample_type) => {
    declarations.push(...[
        ["dlib.test_binary_decision_function", "binary_test", ["/WrapAs=binary_test"], [
            [decision_function, "dec_funct", "", ["/Ref"]],
            [`vector_${ sample_type }`, "samples", "", ["/Ref"]],
            ["vector_double", "labels", "", ["/Ref"]],
        ], "", ""],
    ]);

    if (sample_type === "sample_type") {
        declarations.push(...[
            ["dlib.test_binary_decision_function", "binary_test", ["/WrapAs=binary_test"], [
                [decision_function, "dec_funct", "", ["/Ref"]],
                ["cv::Mat", "samples", "", ["/Ref", "/Cast=Mat_to_vector_sample_type"]],
                ["vector_double", "labels", "", ["/Ref"]],
            ], "", ""],
        ]);
    }
};

const add_test_regression = (declarations, decision_function, sample_type) => {
    declarations.push(...[
        ["dlib.test_regression_function", "regression_test", ["/WrapAs=regression_test"], [
            [decision_function, "dec_funct", "", ["/Ref"]],
            [`vector_${ sample_type }`, "samples", "", ["/Ref"]],
            ["vector_double", "labels", "", ["/Ref"]],
        ], "", ""],
    ]);

    if (sample_type === "sample_type") {
        declarations.push(...[
            ["dlib.test_regression_function", "regression_test", ["/WrapAs=regression_test"], [
                [decision_function, "dec_funct", "", ["/Ref"]],
                ["cv::Mat", "samples", "", ["/Ref", "/Cast=Mat_to_vector_sample_type"]],
                ["vector_double", "labels", "", ["/Ref"]],
            ], "", ""],
        ]);
    }
};

const add_test_ranking = (declarations, decision_function, ranking_pair) => {
    declarations.push(...[
        ["dlib.test_ranking_function", "ranking_test", ["/WrapAs=ranking_test"], [
            [decision_function, "dec_funct", "", ["/Ref"]],
            [`vector_${ ranking_pair }`, "samples", "", ["/Ref"]],
        ], "", ""],

        ["dlib.test_ranking_function", "ranking_test", ["/WrapAs=ranking_test"], [
            [decision_function, "dec_funct", "", ["/Ref"]],
            [ranking_pair, "sample", "", ["/Ref"]],
        ], "", ""],
    ]);
};

const declarations = [
    ["struct dlib._radial_basis_kernel", "", ["/Simple"], [
        ["double", "gamma", "", ["/R"]],
    ], "", ""],

    ["struct dlib._linear_kernel", "", ["/Simple"], [], "", ""],
];

const sparse_vect = "vector_pair_ULONG_and_double";

add_linear_df(declarations, "_decision_function_linear", "sample_type");
add_linear_df(declarations, "_decision_function_sparse_linear", sparse_vect);

add_df(declarations, "_decision_function_histogram_intersection", "sample_type");
add_df(declarations, "_decision_function_sparse_histogram_intersection", sparse_vect);

add_df(declarations, "_decision_function_polynomial", "sample_type");
add_df(declarations, "_decision_function_sparse_polynomial", sparse_vect);

add_df(declarations, "_decision_function_radial_basis", "sample_type");
add_df(declarations, "_decision_function_sparse_radial_basis", sparse_vect);

add_df(declarations, "_decision_function_sigmoid", "sample_type");
add_df(declarations, "_decision_function_sparse_sigmoid", sparse_vect);

add_normalized_df(declarations, "_normalized_decision_function_radial_basis", "sample_type");

setup_auto_train_rbf_classifier(declarations);

add_test_binary(declarations, "_normalized_decision_function_radial_basis", "sample_type");

for (const function_type of ["linear", "radial_basis", "polynomial", "histogram_intersection", "sigmoid"]) {
    for (const [prefix, sample_type] of [["", "sample_type"], ["sparse_", sparse_vect]]) {
        add_test_binary(declarations, `_decision_function_${ prefix }${ function_type }`, sample_type);
        add_test_regression(declarations, `_decision_function_${ prefix }${ function_type }`, sample_type);
    }
}

add_test_ranking(declarations, "_decision_function_linear", "vec_ranking_pair");
add_test_ranking(declarations, "_decision_function_sparse_linear", "sparse_ranking_pair");

module.exports = declarations;
