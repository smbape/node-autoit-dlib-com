module.exports = ({ make_shared }) => [
    ["struct dlib.function_evaluation", "", ["/Simple"], [
        ["dense_vect", "x", "", ["/R"]],
        ["double", "y", "", ["/R"]],
    ], "", ""],

    ["dlib.function_evaluation.function_evaluation", "", [], [], "", ""],

    ["dlib.function_evaluation.function_evaluation", "", [], [
        ["dense_vect", "x", "", []],
        ["double", "y", "", []],
    ], "", ""],

    ["dlib.function_evaluation.function_evaluation", "", [], [
        ["std::vector<double>", "x", "", ["/Cast=list_to_mat"]],
        ["double", "y", "", []],
    ], "", ""],

    ["struct dlib.function_spec", "", [], [
        ["dense_vect", "lower", "", ["/R"]],
        ["dense_vect", "upper", "", ["/R"]],
        ["std::vector<bool>", "is_integer_variable", "", ["/R"]],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["dense_vect", "bound2", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["dense_vect", "bound2", "", []],
        ["std::vector<bool>", "is_integer", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["std::vector<double>", "bound1", "", ["/Cast=list_to_mat"]],
        ["dense_vect", "bound2", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["std::vector<double>", "bound1", "", ["/Cast=list_to_mat"]],
        ["dense_vect", "bound2", "", []],
        ["std::vector<bool>", "is_integer", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["std::vector<double>", "bound2", "", ["/Cast=list_to_mat"]],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["std::vector<double>", "bound2", "", ["/Cast=list_to_mat"]],
        ["std::vector<bool>", "is_integer", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["std::vector<double>", "bound1", "", ["/Cast=list_to_mat"]],
        ["std::vector<double>", "bound2", "", ["/Cast=list_to_mat"]],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["std::vector<double>", "bound1", "", ["/Cast=list_to_mat"]],
        ["std::vector<double>", "bound2", "", ["/Cast=list_to_mat"]],
        ["std::vector<bool>", "is_integer", "", []],
    ], "", ""],

    ["class dlib.function_evaluation_request", "", [], [
        ["size_t", "function_idx", "", ["/R=function_idx"]],
        ["dense_vect", "x", "", ["/R=x", "/C"]],
        ["bool", "has_been_evaluated", "", ["/R=has_been_evaluated"]],
    ], "", ""],

    ["dlib.function_evaluation_request.set", "void", [], [
        ["double", "y", "", []],
    ], "", ""],

    ["class dlib.global_function_search", "", [], [], "", ""],

    ["dlib.global_function_search.global_function_search", "", [], [
        ["function_spec", "function", "", ["/Ref"]],
    ], "", ""],

    ["dlib.global_function_search.global_function_search", "", [], [
        ["std::vector<function_spec>", "functions", "", ["/Ref"]],
    ], "", ""],

    ["dlib.global_function_search.global_function_search", "", [], [
        ["std::vector<function_spec>", "functions", "", []],
        ["std::vector<std::vector<function_evaluation>>", "initial_function_evals", "", []],
        ["double", "relative_noise_magnitude", "0.001", []],
    ], "", ""],

    ["dlib.global_function_search.set_seed", "void", [], [
        ["LONGLONG", "seed", "", []],
    ], "", ""],

    ["dlib.global_function_search.num_functions", "size_t", [], [], "", ""],

    ["dlib.global_function_search.get_function_evaluations", "void", [], [
        ["std::vector<function_spec>", "specs", "", ["/O"]],
        ["std::vector<std::vector<function_evaluation>>", "function_evals", "", ["/O"]],
    ], "", ""],

    ["dlib.global_function_search.get_best_function_eval", "void", [], [
        ["dense_vect", "x", "", ["/O", "/Ref"]],
        ["double", "y", "", ["/O", "/Ref"]],
        ["size_t", "idx", "", ["/O", "/Ref"]],
    ], "", ""],

    ["dlib.global_function_search.get_next_x", "std::shared_ptr<function_evaluation_request>", ["/WrapAs=std::move", `/WrapAs=${ make_shared }<function_evaluation_request>`], [], "", ""],

    ["dlib.global_function_search.get_pure_random_search_probability", "double", [], [], "", ""],
    ["dlib.global_function_search.set_pure_random_search_probability", "void", [], [
        ["double", "prob", "", []],
    ], "", ""],

    ["dlib.global_function_search.get_solver_epsilon", "double", [], [], "", ""],
    ["dlib.global_function_search.set_solver_epsilon", "void", [], [
        ["double", "eps", "", []],
    ], "", ""],

    ["dlib.global_function_search.get_relative_noise_magnitude", "double", [], [], "", ""],
    ["dlib.global_function_search.set_relative_noise_magnitude", "void", [], [
        ["double", "value", "", []],
    ], "", ""],

    ["dlib.global_function_search.get_monte_carlo_upper_bound_sample_num", "size_t", [], [], "", ""],
    ["dlib.global_function_search.set_monte_carlo_upper_bound_sample_num", "void", [], [
        ["size_t", "num", "", []],
    ], "", ""],

];
