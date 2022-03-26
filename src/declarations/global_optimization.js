module.exports = [
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
        ["vector_double", "x", "", ["/Cast=list_to_mat"]],
        ["double", "y", "", []],
    ], "", ""],

    ["struct dlib.function_spec", "", [], [
        ["dense_vect", "lower", "", ["/R"]],
        ["dense_vect", "upper", "", ["/R"]],
        ["vector_bool", "is_integer_variable", "", ["/R"]],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["dense_vect", "bound2", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["dense_vect", "bound2", "", []],
        ["vector_bool", "is_integer", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["vector_double", "bound1", "", ["/Cast=list_to_mat"]],
        ["dense_vect", "bound2", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["vector_double", "bound1", "", ["/Cast=list_to_mat"]],
        ["dense_vect", "bound2", "", []],
        ["vector_bool", "is_integer", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["vector_double", "bound2", "", ["/Cast=list_to_mat"]],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["dense_vect", "bound1", "", []],
        ["vector_double", "bound2", "", ["/Cast=list_to_mat"]],
        ["vector_bool", "is_integer", "", []],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["vector_double", "bound1", "", ["/Cast=list_to_mat"]],
        ["vector_double", "bound2", "", ["/Cast=list_to_mat"]],
    ], "", ""],

    ["dlib.function_spec.function_spec", "", [], [
        ["vector_double", "bound1", "", ["/Cast=list_to_mat"]],
        ["vector_double", "bound2", "", ["/Cast=list_to_mat"]],
        ["vector_bool", "is_integer", "", []],
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
        ["vector_function_spec", "functions", "", ["/Ref"]],
    ], "", ""],

    ["dlib.global_function_search.global_function_search", "", [], [
        ["vector_function_spec", "functions", "", []],
        ["vector_vector_function_evaluation", "initial_function_evals", "", []],
        ["double", "relative_noise_magnitude", "0.001", []],
    ], "", ""],

    ["dlib.global_function_search.set_seed", "void", [], [
        ["LONGLONG", "seed", "", []],
    ], "", ""],

    ["dlib.global_function_search.num_functions", "size_t", [], [], "", ""],

    ["dlib.global_function_search.get_function_evaluations", "void", [], [
        ["vector_function_spec", "specs", "", ["/O"]],
        ["vector_vector_function_evaluation", "function_evals", "", ["/O"]],
    ], "", ""],

    ["dlib.global_function_search.get_best_function_eval", "void", [], [
        ["dense_vect", "x", "", ["/O", "/Ref"]],
        ["double", "y", "", ["/O", "/Ref"]],
        ["size_t", "idx", "", ["/O", "/Ref"]],
    ], "", ""],

    ["dlib.global_function_search.get_next_x", "function_evaluation_request", ["/WrapAs=std::move", "/WrapAs=std::make_shared<function_evaluation_request>"], [], "", ""],

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
