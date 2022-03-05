const setup_trainer_eps = (declarations, trainer_type, trained_function_type, sample_type, props = []) => {
    declarations.push(...[
        [`class dlib.${ trainer_type }`, "", ["/Simple"], ([
            ["double", "epsilon", "", ["/RW", "/R=get_epsilon", "/W=set_epsilon"]],
        ].concat(props)), "", ""],

        [`dlib.${ trainer_type }.${ trainer_type }`, "", [], [], "", ""],

        [`dlib.${ trainer_type }.train`, trained_function_type, [], [
            [`vector_${ sample_type }`, "samples", "", []],
            ["vector_double", "labels", "", []],
        ], "", ""],

        ["dlib.cross_validate_trainer", "binary_test", ["/WrapAs=binary_test"], [
            [trainer_type, "samples", "", []],
            [`vector_${ sample_type }`, "x", "", []],
            ["vector_double", "y", "", []],
            ["ULONG", "folds", "", []],
        ], "", ""],

        ["dlib.cross_validate_trainer_threaded", "binary_test", ["/WrapAs=binary_test"], [
            [trainer_type, "samples", "", []],
            [`vector_${ sample_type }`, "x", "", []],
            ["vector_double", "y", "", []],
            ["ULONG", "folds", "", []],
            ["ULONG", "num_threads", "", []],
        ], "", ""],
    ]);
};

const setup_trainer_eps_c = (declarations, trainer_type, trained_function_type, sample_type, props = [], methods = []) => {
    const idecl = [];
    setup_trainer_eps(idecl, trainer_type, trained_function_type, sample_type);

    const [, , , properties] = idecl[0];
    properties.push(...[
        ["double", "c_class1", "", ["/RW", "/R=get_c_class1", "/W=set_c_class1"]],
        ["double", "c_class2", "", ["/RW", "/R=get_c_class2", "/W=set_c_class2"]],
    ]);

    properties.push(...props);

    idecl.push(...[
        [`dlib.${ trainer_type }.set_c`, "void", [], [
            ["double", "c", "", []],
        ], "", ""],
    ]);

    idecl.push(...methods);

    declarations.push(...idecl);
};

const setup_trainer_eps_c_cache = (declarations, trainer_type, trained_function_type, sample_type, props = [], methods = []) => {
    const idecl = [];
    setup_trainer_eps_c(idecl, trainer_type, trained_function_type, sample_type);

    const [, , , properties] = idecl[0];
    properties.push(...[
        ["long", "cache_size", "", ["/RW", "/R=get_cache_size", "/W=set_cache_size"]]
    ]);

    properties.push(...props);

    idecl.push(...methods);

    declarations.push(...idecl);
};

const declarations = [];

const sparse_vect = "vector_pair_ULONG_and_double";

// ----------------------------------------------------------------------------------------
// svm_c
// ----------------------------------------------------------------------------------------
setup_trainer_eps_c_cache(declarations, "svm_c_trainer_radial_basis", "_decision_function_radial_basis", "sample_type", [
    ["double", "gamma", "", ["/RW", "/External"]]
]);
setup_trainer_eps_c_cache(declarations, "svm_c_trainer_sparse_radial_basis", "_decision_function_sparse_radial_basis", sparse_vect, [
    ["double", "gamma", "", ["/RW", "/External"]]
]);

setup_trainer_eps_c_cache(declarations, "svm_c_trainer_histogram_intersection", "_decision_function_histogram_intersection", "sample_type");

setup_trainer_eps_c_cache(declarations, "svm_c_trainer_sparse_histogram_intersection", "_decision_function_sparse_histogram_intersection", sparse_vect);

// ----------------------------------------------------------------------------------------
// svm_c_linear
// ----------------------------------------------------------------------------------------
setup_trainer_eps_c(declarations, "svm_c_trainer_linear", "_decision_function_linear", "sample_type", [
    ["ULONG", "max_iterations", "", ["/RW", "/R=get_max_iterations", "/W=set_max_iterations"]],
    ["bool", "force_last_weight_to_1", "", ["/RW", "/R=forces_last_weight_to_1", "/W=force_last_weight_to_1"]],
    ["bool", "learns_nonnegative_weights", "", ["/RW", "/R=learns_nonnegative_weights", "/W=set_learns_nonnegative_weights"]],
    ["bool", "has_prior", "", ["=has_prior()"]],
], [
    ["dlib.svm_c_trainer_linear.set_prior", "void", [], [
        ["_decision_function_linear", "prior_", "", []],
    ], "", ""],
    ["dlib.svm_c_trainer_linear.be_verbose", "void", [], [], "", ""],
    ["dlib.svm_c_trainer_linear.be_quiet", "void", [], [], "", ""],
]);

setup_trainer_eps_c(declarations, "svm_c_trainer_sparse_linear", "_decision_function_sparse_linear", sparse_vect, [
    ["ULONG", "max_iterations", "", ["/RW", "/R=get_max_iterations", "/W=set_max_iterations"]],
    ["bool", "force_last_weight_to_1", "", ["/RW", "/R=forces_last_weight_to_1", "/W=force_last_weight_to_1"]],
    ["bool", "learns_nonnegative_weights", "", ["/RW", "/R=learns_nonnegative_weights", "/W=set_learns_nonnegative_weights"]],
    ["bool", "has_prior", "", ["=has_prior()"]],
], [
    ["dlib.svm_c_trainer_sparse_linear.set_prior", "void", [], [
        ["_decision_function_sparse_linear", "prior_", "", []],
    ], "", ""],
    ["dlib.svm_c_trainer_sparse_linear.be_verbose", "void", [], [], "", ""],
    ["dlib.svm_c_trainer_sparse_linear.be_quiet", "void", [], [], "", ""],
]);

// ----------------------------------------------------------------------------------------
// rvm
// ----------------------------------------------------------------------------------------
setup_trainer_eps(declarations, "rvm_trainer_radial_basis", "_decision_function_radial_basis", "sample_type", [
    ["double", "gamma", "", ["/RW", "/External"]]
]);
setup_trainer_eps(declarations, "rvm_trainer_sparse_radial_basis", "_decision_function_sparse_radial_basis", sparse_vect, [
    ["double", "gamma", "", ["/RW", "/External"]]
]);

setup_trainer_eps(declarations, "rvm_trainer_histogram_intersection", "_decision_function_histogram_intersection", "sample_type");

setup_trainer_eps(declarations, "rvm_trainer_sparse_histogram_intersection", "_decision_function_sparse_histogram_intersection", sparse_vect);

// ----------------------------------------------------------------------------------------
// rvm linear
// ----------------------------------------------------------------------------------------
setup_trainer_eps(declarations, "rvm_trainer_linear", "_decision_function_linear", "sample_type");

setup_trainer_eps(declarations, "rvm_trainer_sparse_linear", "_decision_function_sparse_linear", sparse_vect);

module.exports = declarations;
