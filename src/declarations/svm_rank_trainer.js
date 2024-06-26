const sparse_vect = "std::vector<std::pair<ULONG, double>>";

module.exports = [
    ["struct dlib.vec_ranking_pair", "", ["/Simple"], [
        ["std::vector<SpaceVector>", "relevant", "", ["/RW"]],
        ["std::vector<SpaceVector>", "nonrelevant", "", ["/RW"]],
    ], "", ""],

    ["dlib.vec_ranking_pair.vec_ranking_pair", "", [], [], "", ""],

    ["dlib.vec_ranking_pair.vec_ranking_pair", "", [], [
        ["std::vector<SpaceVector>", "relevant", "", []],
        ["std::vector<SpaceVector>", "nonrelevant", "", []],
    ], "", ""],

    ["struct dlib.sparse_ranking_pair", "", ["/Simple"], [
        [`std::vector<${ sparse_vect }>`, "relevant", "", ["/RW"]],
        [`std::vector<${ sparse_vect }>`, "nonrelevant", "", ["/RW"]],
    ], "", ""],

    ["dlib.sparse_ranking_pair.sparse_ranking_pair", "", [], [], "", ""],

    ["dlib.sparse_ranking_pair.sparse_ranking_pair", "", [], [
        [`std::vector<${ sparse_vect }>`, "relevant", "", []],
        [`std::vector<${ sparse_vect }>`, "nonrelevant", "", []],
    ], "", ""],

    ["class dlib.vec_svm_rank_trainer", "", ["/Simple"], [
        ["double", "epsilon", "", ["/RW", "/R=get_epsilon", "/W=set_epsilon"]],
        ["double", "c", "", ["/RW", "/R=get_c", "/W=set_c"]],
        ["ULONG", "max_iterations", "", ["/RW", "/R=get_max_iterations", "/W=set_max_iterations"]],
        ["bool", "force_last_weight_to_1", "", ["/RW", "/R=forces_last_weight_to_1", "/W=force_last_weight_to_1"]],
        ["bool", "learns_nonnegative_weights", "", ["/RW", "/R=learns_nonnegative_weights", "/W=set_learns_nonnegative_weights"]],
        ["bool", "has_prior", "", ["=has_prior()"]],
    ], "", ""],

    ["dlib.vec_svm_rank_trainer.vec_svm_rank_trainer", "", [], [], "", ""],

    ["dlib.vec_svm_rank_trainer.train", "_decision_function_linear", ["/External"], [
        ["vec_ranking_pair", "sample", "", []],
    ], "", ""],

    ["dlib.vec_svm_rank_trainer.train", "_decision_function_linear", ["/External"], [
        ["std::vector<vec_ranking_pair>", "samples", "", []],
    ], "", ""],

    ["dlib.vec_svm_rank_trainer.set_prior", "void", [], [
        ["_decision_function_linear", "prior_", "", []],
    ], "", ""],

    ["dlib.vec_svm_rank_trainer.be_verbose", "void", [], [], "", ""],
    ["dlib.vec_svm_rank_trainer.be_quiet", "void", [], [], "", ""],

    ["class dlib.svm_rank_trainer_sparse", "", ["/Simple"], [
        ["double", "epsilon", "", ["/RW", "/R=get_epsilon", "/W=set_epsilon"]],
        ["double", "c", "", ["/RW", "/R=get_c", "/W=set_c"]],
        ["ULONG", "max_iterations", "", ["/RW", "/R=get_max_iterations", "/W=set_max_iterations"]],
        ["bool", "force_last_weight_to_1", "", ["/RW", "/R=forces_last_weight_to_1", "/W=force_last_weight_to_1"]],
        ["bool", "learns_nonnegative_weights", "", ["/RW", "/R=learns_nonnegative_weights", "/W=set_learns_nonnegative_weights"]],
        ["bool", "has_prior", "", ["=has_prior()"]],
    ], "", ""],

    ["dlib.svm_rank_trainer_sparse.svm_rank_trainer_sparse", "", [], [], "", ""],

    ["dlib.svm_rank_trainer_sparse.train", "_decision_function_sparse_linear", ["/External"], [
        ["sparse_ranking_pair", "sample", "", []],
    ], "", ""],

    ["dlib.svm_rank_trainer_sparse.train", "_decision_function_sparse_linear", ["/External"], [
        ["std::vector<sparse_ranking_pair>", "samples", "", []],
    ], "", ""],

    ["dlib.svm_rank_trainer_sparse.set_prior", "void", [], [
        ["_decision_function_sparse_linear", "prior_", "", []],
    ], "", ""],

    ["dlib.svm_rank_trainer_sparse.be_verbose", "void", [], [], "", ""],
    ["dlib.svm_rank_trainer_sparse.be_quiet", "void", [], [], "", ""],

    ["dlib.cross_validate_ranking_trainer", "ranking_test", ["/External"], [
        ["vec_svm_rank_trainer", "trainer", "", []],
        ["std::vector<vec_ranking_pair>", "samples", "", []],
        ["ULONG", "folds", "", []],
    ], "", ""],

    ["dlib.cross_validate_ranking_trainer", "ranking_test", ["/External"], [
        ["svm_rank_trainer_sparse", "trainer", "", []],
        ["std::vector<sparse_ranking_pair>", "samples", "", []],
        ["ULONG", "folds", "", []],
    ], "", ""],
];
