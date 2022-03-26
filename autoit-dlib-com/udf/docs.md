# AutoIt Dlib UDF

## Table Of Contents

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [dlib](#dlib)
  - [dlib::cca](#dlibcca)
  - [dlib::apply_cca_transform](#dlibapply_cca_transform)
  - [dlib::load_rgb_image](#dlibload_rgb_image)
  - [dlib::load_grayscale_image](#dlibload_grayscale_image)
  - [dlib::save_image](#dlibsave_image)
  - [dlib::jitter_image](#dlibjitter_image)
  - [dlib::get_face_chip](#dlibget_face_chip)
  - [dlib::get_face_chips](#dlibget_face_chips)
  - [dlib::save_face_chip](#dlibsave_face_chip)
  - [dlib::save_face_chips](#dlibsave_face_chips)
  - [dlib::chinese_whispers_clustering](#dlibchinese_whispers_clustering)
  - [dlib::chinese_whispers](#dlibchinese_whispers)
  - [dlib::find_max_global](#dlibfind_max_global)
  - [dlib::find_min_global](#dlibfind_min_global)
  - [dlib::find_candidate_object_locations](#dlibfind_candidate_object_locations)
  - [dlib::max_cost_assignment](#dlibmax_cost_assignment)
  - [dlib::assignment_cost](#dlibassignment_cost)
  - [dlib::make_sparse_vector](#dlibmake_sparse_vector)
  - [dlib::save_libsvm_formatted_data](#dlibsave_libsvm_formatted_data)
  - [dlib::hit_enter_to_continue](#dlibhit_enter_to_continue)
  - [dlib::train_sequence_segmenter](#dlibtrain_sequence_segmenter)
  - [dlib::test_sequence_segmenter](#dlibtest_sequence_segmenter)
  - [dlib::cross_validate_sequence_segmenter](#dlibcross_validate_sequence_segmenter)
  - [dlib::train_shape_predictor](#dlibtrain_shape_predictor)
  - [dlib::train_simple_object_detector](#dlibtrain_simple_object_detector)
  - [dlib::test_simple_object_detector](#dlibtest_simple_object_detector)
  - [dlib::solve_structural_svm_problem](#dlibsolve_structural_svm_problem)
  - [dlib::max_index_plus_one](#dlibmax_index_plus_one)
  - [dlib::dnn_prefer_fastest_algorithms](#dlibdnn_prefer_fastest_algorithms)
  - [dlib::set_dnn_prefer_fastest_algorithms](#dlibset_dnn_prefer_fastest_algorithms)
  - [dlib::set_dnn_prefer_smallest_algorithms](#dlibset_dnn_prefer_smallest_algorithms)
  - [dlib::auto_train_rbf_classifier](#dlibauto_train_rbf_classifier)
  - [dlib::reduce](#dlibreduce)
  - [dlib::test_binary_decision_function](#dlibtest_binary_decision_function)
  - [dlib::test_regression_function](#dlibtest_regression_function)
  - [dlib::test_ranking_function](#dlibtest_ranking_function)
  - [dlib::variant](#dlibvariant)
  - [dlib::signed_distance_to_line](#dlibsigned_distance_to_line)
  - [dlib::distance_to_line](#dlibdistance_to_line)
  - [dlib::intersect](#dlibintersect)
  - [dlib::angle_between_lines](#dlibangle_between_lines)
  - [dlib::count_points_on_side_of_line](#dlibcount_points_on_side_of_line)
  - [dlib::count_points_between_lines](#dlibcount_points_between_lines)
  - [dlib::dot](#dlibdot)
  - [dlib::get_frontal_face_detector](#dlibget_frontal_face_detector)
  - [dlib::num_separable_filters](#dlibnum_separable_filters)
  - [dlib::threshold_filter_singular_values](#dlibthreshold_filter_singular_values)
  - [dlib::load_libsvm_formatted_data](#dlibload_libsvm_formatted_data)
  - [dlib::count_steps_without_decrease](#dlibcount_steps_without_decrease)
  - [dlib::count_steps_without_decrease_robust](#dlibcount_steps_without_decrease_robust)
  - [dlib::probability_that_sequence_is_increasing](#dlibprobability_that_sequence_is_increasing)
  - [dlib::find_optimal_rect_filter](#dlibfind_optimal_rect_filter)
  - [dlib::translate_rect](#dlibtranslate_rect)
  - [dlib::shrink_rect](#dlibshrink_rect)
  - [dlib::scale_rect](#dlibscale_rect)
  - [dlib::centered_rect](#dlibcentered_rect)
  - [dlib::center](#dlibcenter)
  - [dlib::centered_rects](#dlibcentered_rects)
  - [dlib::centered_drect](#dlibcentered_drect)
  - [dlib::test_shape_predictor](#dlibtest_shape_predictor)
  - [dlib::cross_validate_trainer](#dlibcross_validate_trainer)
  - [dlib::cross_validate_trainer_threaded](#dlibcross_validate_trainer_threaded)
  - [dlib::cross_validate_ranking_trainer](#dlibcross_validate_ranking_trainer)
  - [dlib::inv](#dlibinv)
  - [dlib::find_projective_transform](#dlibfind_projective_transform)
  - [dlib::polygon_area](#dlibpolygon_area)
  - [dlib::length](#dliblength)
- [dlib::binary_test](#dlibbinary_test)
  - [dlib::binary_test::create](#dlibbinary_testcreate)
  - [dlib::binary_test::ToString](#dlibbinary_testtostring)
- [dlib::regression_test](#dlibregression_test)
  - [dlib::regression_test::create](#dlibregression_testcreate)
  - [dlib::regression_test::ToString](#dlibregression_testtostring)
- [dlib::ranking_test](#dlibranking_test)
  - [dlib::ranking_test::create](#dlibranking_testcreate)
  - [dlib::ranking_test::ToString](#dlibranking_testtostring)
- [dlib::cca_outputs](#dlibcca_outputs)
  - [dlib::cca_outputs::create](#dlibcca_outputscreate)
- [dlib::cnn_face_detection_model_v1](#dlibcnn_face_detection_model_v1)
  - [dlib::cnn_face_detection_model_v1::create](#dlibcnn_face_detection_model_v1create)
  - [dlib::cnn_face_detection_model_v1::detect](#dlibcnn_face_detection_model_v1detect)
  - [dlib::cnn_face_detection_model_v1::get_call](#dlibcnn_face_detection_model_v1get_call)
  - [dlib::cnn_face_detection_model_v1::detect_multi](#dlibcnn_face_detection_model_v1detect_multi)
- [dlib::face_recognition_model_v1](#dlibface_recognition_model_v1)
  - [dlib::face_recognition_model_v1::create](#dlibface_recognition_model_v1create)
  - [dlib::face_recognition_model_v1::compute_face_descriptor](#dlibface_recognition_model_v1compute_face_descriptor)
- [dlib::_row](#dlib_row)
  - [dlib::_row::create](#dlib_rowcreate)
  - [dlib::_row::ToString](#dlib_rowtostring)
  - [dlib::_row::get](#dlib_rowget)
  - [dlib::_row::set](#dlib_rowset)
- [dlib::segmenter_type](#dlibsegmenter_type)
  - [dlib::segmenter_type::create](#dlibsegmenter_typecreate)
  - [dlib::segmenter_type::get_call](#dlibsegmenter_typeget_call)
- [dlib::segmenter_params](#dlibsegmenter_params)
  - [dlib::segmenter_params::create](#dlibsegmenter_paramscreate)
  - [dlib::segmenter_params::ToString](#dlibsegmenter_paramstostring)
- [dlib::segmenter_test](#dlibsegmenter_test)
  - [dlib::segmenter_test::create](#dlibsegmenter_testcreate)
  - [dlib::segmenter_test::ToString](#dlibsegmenter_testtostring)
- [dlib::shape_predictor_training_options](#dlibshape_predictor_training_options)
  - [dlib::shape_predictor_training_options::create](#dlibshape_predictor_training_optionscreate)
  - [dlib::shape_predictor_training_options::ToString](#dlibshape_predictor_training_optionstostring)
- [dlib::simple_object_detector_training_options](#dlibsimple_object_detector_training_options)
  - [dlib::simple_object_detector_training_options::create](#dlibsimple_object_detector_training_optionscreate)
  - [dlib::simple_object_detector_training_options::ToString](#dlibsimple_object_detector_training_optionstostring)
- [dlib::simple_test_results](#dlibsimple_test_results)
  - [dlib::simple_test_results::create](#dlibsimple_test_resultscreate)
  - [dlib::simple_test_results::ToString](#dlibsimple_test_resultstostring)
- [dlib::simple_object_detector_com](#dlibsimple_object_detector_com)
  - [dlib::simple_object_detector_com::create](#dlibsimple_object_detector_comcreate)
  - [dlib::simple_object_detector_com::get_call](#dlibsimple_object_detector_comget_call)
  - [dlib::simple_object_detector_com::run_multiple](#dlibsimple_object_detector_comrun_multiple)
- [dlib::simple_structural_svm_problem](#dlibsimple_structural_svm_problem)
  - [dlib::simple_structural_svm_problem::create](#dlibsimple_structural_svm_problemcreate)
- [dlib::mmod_rect](#dlibmmod_rect)
  - [dlib::mmod_rect::create](#dlibmmod_rectcreate)
- [dlib::cuda](#dlibcuda)
  - [dlib::cuda::set_device](#dlibcudaset_device)
  - [dlib::cuda::get_device](#dlibcudaget_device)
  - [dlib::cuda::get_device_name](#dlibcudaget_device_name)
  - [dlib::cuda::set_current_device_blocking_sync](#dlibcudaset_current_device_blocking_sync)
  - [dlib::cuda::can_access_peer](#dlibcudacan_access_peer)
  - [dlib::cuda::device_synchronize](#dlibcudadevice_synchronize)
- [dlib::correlation_tracker](#dlibcorrelation_tracker)
  - [dlib::correlation_tracker::create](#dlibcorrelation_trackercreate)
  - [dlib::correlation_tracker::start_track](#dlibcorrelation_trackerstart_track)
  - [dlib::correlation_tracker::update](#dlibcorrelation_trackerupdate)
  - [dlib::correlation_tracker::get_position](#dlibcorrelation_trackerget_position)
- [dlib::_radial_basis_kernel](#dlib_radial_basis_kernel)
  - [dlib::_radial_basis_kernel::create](#dlib_radial_basis_kernelcreate)
- [dlib::_linear_kernel](#dlib_linear_kernel)
  - [dlib::_linear_kernel::create](#dlib_linear_kernelcreate)
- [dlib::_decision_function_linear](#dlib_decision_function_linear)
  - [dlib::_decision_function_linear::create](#dlib_decision_function_linearcreate)
  - [dlib::_decision_function_linear::get_call](#dlib_decision_function_linearget_call)
- [dlib::_decision_function_sparse_linear](#dlib_decision_function_sparse_linear)
  - [dlib::_decision_function_sparse_linear::create](#dlib_decision_function_sparse_linearcreate)
  - [dlib::_decision_function_sparse_linear::get_call](#dlib_decision_function_sparse_linearget_call)
- [dlib::_decision_function_histogram_intersection](#dlib_decision_function_histogram_intersection)
  - [dlib::_decision_function_histogram_intersection::create](#dlib_decision_function_histogram_intersectioncreate)
  - [dlib::_decision_function_histogram_intersection::get_call](#dlib_decision_function_histogram_intersectionget_call)
- [dlib::_decision_function_sparse_histogram_intersection](#dlib_decision_function_sparse_histogram_intersection)
  - [dlib::_decision_function_sparse_histogram_intersection::create](#dlib_decision_function_sparse_histogram_intersectioncreate)
  - [dlib::_decision_function_sparse_histogram_intersection::get_call](#dlib_decision_function_sparse_histogram_intersectionget_call)
- [dlib::_decision_function_polynomial](#dlib_decision_function_polynomial)
  - [dlib::_decision_function_polynomial::create](#dlib_decision_function_polynomialcreate)
  - [dlib::_decision_function_polynomial::get_call](#dlib_decision_function_polynomialget_call)
- [dlib::_decision_function_sparse_polynomial](#dlib_decision_function_sparse_polynomial)
  - [dlib::_decision_function_sparse_polynomial::create](#dlib_decision_function_sparse_polynomialcreate)
  - [dlib::_decision_function_sparse_polynomial::get_call](#dlib_decision_function_sparse_polynomialget_call)
- [dlib::_decision_function_radial_basis](#dlib_decision_function_radial_basis)
  - [dlib::_decision_function_radial_basis::create](#dlib_decision_function_radial_basiscreate)
  - [dlib::_decision_function_radial_basis::get_call](#dlib_decision_function_radial_basisget_call)
- [dlib::_decision_function_sparse_radial_basis](#dlib_decision_function_sparse_radial_basis)
  - [dlib::_decision_function_sparse_radial_basis::create](#dlib_decision_function_sparse_radial_basiscreate)
  - [dlib::_decision_function_sparse_radial_basis::get_call](#dlib_decision_function_sparse_radial_basisget_call)
- [dlib::_decision_function_sigmoid](#dlib_decision_function_sigmoid)
  - [dlib::_decision_function_sigmoid::create](#dlib_decision_function_sigmoidcreate)
  - [dlib::_decision_function_sigmoid::get_call](#dlib_decision_function_sigmoidget_call)
- [dlib::_decision_function_sparse_sigmoid](#dlib_decision_function_sparse_sigmoid)
  - [dlib::_decision_function_sparse_sigmoid::create](#dlib_decision_function_sparse_sigmoidcreate)
  - [dlib::_decision_function_sparse_sigmoid::get_call](#dlib_decision_function_sparse_sigmoidget_call)
- [dlib::_normalized_decision_function_radial_basis](#dlib_normalized_decision_function_radial_basis)
  - [dlib::_normalized_decision_function_radial_basis::create](#dlib_normalized_decision_function_radial_basiscreate)
  - [dlib::_normalized_decision_function_radial_basis::get_call](#dlib_normalized_decision_function_radial_basisget_call)
  - [dlib::_normalized_decision_function_radial_basis::batch_predict](#dlib_normalized_decision_function_radial_basisbatch_predict)
- [dlib::function_evaluation](#dlibfunction_evaluation)
  - [dlib::function_evaluation::create](#dlibfunction_evaluationcreate)
- [dlib::function_spec](#dlibfunction_spec)
  - [dlib::function_spec::create](#dlibfunction_speccreate)
- [dlib::function_evaluation_request](#dlibfunction_evaluation_request)
  - [dlib::function_evaluation_request::set](#dlibfunction_evaluation_requestset)
- [dlib::global_function_search](#dlibglobal_function_search)
  - [dlib::global_function_search::create](#dlibglobal_function_searchcreate)
  - [dlib::global_function_search::set_seed](#dlibglobal_function_searchset_seed)
  - [dlib::global_function_search::num_functions](#dlibglobal_function_searchnum_functions)
  - [dlib::global_function_search::get_function_evaluations](#dlibglobal_function_searchget_function_evaluations)
  - [dlib::global_function_search::get_best_function_eval](#dlibglobal_function_searchget_best_function_eval)
  - [dlib::global_function_search::get_next_x](#dlibglobal_function_searchget_next_x)
  - [dlib::global_function_search::get_pure_random_search_probability](#dlibglobal_function_searchget_pure_random_search_probability)
  - [dlib::global_function_search::set_pure_random_search_probability](#dlibglobal_function_searchset_pure_random_search_probability)
  - [dlib::global_function_search::get_solver_epsilon](#dlibglobal_function_searchget_solver_epsilon)
  - [dlib::global_function_search::set_solver_epsilon](#dlibglobal_function_searchset_solver_epsilon)
  - [dlib::global_function_search::get_relative_noise_magnitude](#dlibglobal_function_searchget_relative_noise_magnitude)
  - [dlib::global_function_search::set_relative_noise_magnitude](#dlibglobal_function_searchset_relative_noise_magnitude)
  - [dlib::global_function_search::get_monte_carlo_upper_bound_sample_num](#dlibglobal_function_searchget_monte_carlo_upper_bound_sample_num)
  - [dlib::global_function_search::set_monte_carlo_upper_bound_sample_num](#dlibglobal_function_searchset_monte_carlo_upper_bound_sample_num)
- [dlib::image_window](#dlibimage_window)
  - [dlib::image_window::create](#dlibimage_windowcreate)
  - [dlib::image_window::set_image](#dlibimage_windowset_image)
  - [dlib::image_window::set_title](#dlibimage_windowset_title)
  - [dlib::image_window::clear_overlay](#dlibimage_windowclear_overlay)
  - [dlib::image_window::add_overlay](#dlibimage_windowadd_overlay)
  - [dlib::image_window::add_overlay_circle](#dlibimage_windowadd_overlay_circle)
  - [dlib::image_window::wait_until_closed](#dlibimage_windowwait_until_closed)
  - [dlib::image_window::is_closed](#dlibimage_windowis_closed)
  - [dlib::image_window::get_next_double_click](#dlibimage_windowget_next_double_click)
  - [dlib::image_window::wait_for_keypress](#dlibimage_windowwait_for_keypress)
  - [dlib::image_window::get_next_keypress](#dlibimage_windowget_next_keypress)
- [dlib::rgb_pixel](#dlibrgb_pixel)
  - [dlib::rgb_pixel::create](#dlibrgb_pixelcreate)
- [cv](#cv)
  - [cv::haveImageReader](#cvhaveimagereader)
  - [cv::haveImageWriter](#cvhaveimagewriter)
  - [cv::imcount](#cvimcount)
  - [cv::imdecode](#cvimdecode)
  - [cv::imencode](#cvimencode)
  - [cv::imread](#cvimread)
  - [cv::imreadmulti](#cvimreadmulti)
  - [cv::imwrite](#cvimwrite)
  - [cv::imwritemulti](#cvimwritemulti)
- [cv::Mat](#cvmat)
  - [cv::Mat::create](#cvmatcreate)
  - [cv::Mat::isContinuous](#cvmatiscontinuous)
  - [cv::Mat::isSubmatrix](#cvmatissubmatrix)
  - [cv::Mat::elemSize](#cvmatelemsize)
  - [cv::Mat::elemSize1](#cvmatelemsize1)
  - [cv::Mat::type](#cvmattype)
  - [cv::Mat::depth](#cvmatdepth)
  - [cv::Mat::channels](#cvmatchannels)
  - [cv::Mat::step1](#cvmatstep1)
  - [cv::Mat::empty](#cvmatempty)
  - [cv::Mat::total](#cvmattotal)
  - [cv::Mat::checkVector](#cvmatcheckvector)
  - [cv::Mat::ptr](#cvmatptr)
  - [cv::Mat::pop_back](#cvmatpop_back)
  - [cv::Mat::push_back](#cvmatpush_back)
  - [cv::Mat::reshape](#cvmatreshape)
  - [cv::Mat::eye](#cvmateye)
  - [cv::Mat::zeros](#cvmatzeros)
  - [cv::Mat::ones](#cvmatones)
- [dlib::image_dataset_metadata](#dlibimage_dataset_metadata)
  - [dlib::image_dataset_metadata::save_image_dataset_metadata](#dlibimage_dataset_metadatasave_image_dataset_metadata)
  - [dlib::image_dataset_metadata::load_image_dataset_metadata](#dlibimage_dataset_metadataload_image_dataset_metadata)
  - [dlib::image_dataset_metadata::make_bounding_box_regression_training_data](#dlibimage_dataset_metadatamake_bounding_box_regression_training_data)
- [dlib::image_dataset_metadata::box](#dlibimage_dataset_metadatabox)
  - [dlib::image_dataset_metadata::box::create](#dlibimage_dataset_metadataboxcreate)
  - [dlib::image_dataset_metadata::box::has_label](#dlibimage_dataset_metadataboxhas_label)
- [dlib::image_dataset_metadata::image](#dlibimage_dataset_metadataimage)
  - [dlib::image_dataset_metadata::image::create](#dlibimage_dataset_metadataimagecreate)
- [dlib::image_dataset_metadata::dataset](#dlibimage_dataset_metadatadataset)
  - [dlib::image_dataset_metadata::dataset::create](#dlibimage_dataset_metadatadatasetcreate)
- [dlib::line](#dlibline)
  - [dlib::line::create](#dliblinecreate)
- [dlib::Matrix](#dlibmatrix)
  - [dlib::Matrix::create](#dlibmatrixcreate)
  - [dlib::Matrix::set_size](#dlibmatrixset_size)
  - [dlib::Matrix::nr](#dlibmatrixnr)
  - [dlib::Matrix::nc](#dlibmatrixnc)
  - [dlib::Matrix::serialize](#dlibmatrixserialize)
  - [dlib::Matrix::deserialize](#dlibmatrixdeserialize)
  - [dlib::Matrix::get](#dlibmatrixget)
  - [dlib::Matrix::ToString](#dlibmatrixtostring)
- [dlib::fhog_object_detector](#dlibfhog_object_detector)
  - [dlib::fhog_object_detector::create](#dlibfhog_object_detectorcreate)
  - [dlib::fhog_object_detector::run](#dlibfhog_object_detectorrun)
  - [dlib::fhog_object_detector::get_call](#dlibfhog_object_detectorget_call)
  - [dlib::fhog_object_detector::save](#dlibfhog_object_detectorsave)
  - [dlib::fhog_object_detector::run_multiple](#dlibfhog_object_detectorrun_multiple)
- [dlib::rect_filter](#dlibrect_filter)
  - [dlib::rect_filter::create](#dlibrect_filtercreate)
  - [dlib::rect_filter::measurement_noise](#dlibrect_filtermeasurement_noise)
  - [dlib::rect_filter::typical_acceleration](#dlibrect_filtertypical_acceleration)
  - [dlib::rect_filter::max_measurement_deviation](#dlibrect_filtermax_measurement_deviation)
  - [dlib::rect_filter::get_call](#dlibrect_filterget_call)
- [dlib::rectangle](#dlibrectangle)
  - [dlib::rectangle::create](#dlibrectanglecreate)
  - [dlib::rectangle::area](#dlibrectanglearea)
  - [dlib::rectangle::left](#dlibrectangleleft)
  - [dlib::rectangle::top](#dlibrectangletop)
  - [dlib::rectangle::right](#dlibrectangleright)
  - [dlib::rectangle::bottom](#dlibrectanglebottom)
  - [dlib::rectangle::width](#dlibrectanglewidth)
  - [dlib::rectangle::height](#dlibrectangleheight)
  - [dlib::rectangle::tl_corner](#dlibrectangletl_corner)
  - [dlib::rectangle::tr_corner](#dlibrectangletr_corner)
  - [dlib::rectangle::bl_corner](#dlibrectanglebl_corner)
  - [dlib::rectangle::br_corner](#dlibrectanglebr_corner)
  - [dlib::rectangle::is_empty](#dlibrectangleis_empty)
  - [dlib::rectangle::center](#dlibrectanglecenter)
  - [dlib::rectangle::dcenter](#dlibrectangledcenter)
  - [dlib::rectangle::contains](#dlibrectanglecontains)
  - [dlib::rectangle::intersect](#dlibrectangleintersect)
  - [dlib::rectangle::ToString](#dlibrectangletostring)
- [dlib::drectangle](#dlibdrectangle)
  - [dlib::drectangle::create](#dlibdrectanglecreate)
  - [dlib::drectangle::area](#dlibdrectanglearea)
  - [dlib::drectangle::left](#dlibdrectangleleft)
  - [dlib::drectangle::top](#dlibdrectangletop)
  - [dlib::drectangle::right](#dlibdrectangleright)
  - [dlib::drectangle::bottom](#dlibdrectanglebottom)
  - [dlib::drectangle::width](#dlibdrectanglewidth)
  - [dlib::drectangle::height](#dlibdrectangleheight)
  - [dlib::drectangle::tl_corner](#dlibdrectangletl_corner)
  - [dlib::drectangle::tr_corner](#dlibdrectangletr_corner)
  - [dlib::drectangle::bl_corner](#dlibdrectanglebl_corner)
  - [dlib::drectangle::br_corner](#dlibdrectanglebr_corner)
  - [dlib::drectangle::is_empty](#dlibdrectangleis_empty)
  - [dlib::drectangle::center](#dlibdrectanglecenter)
  - [dlib::drectangle::dcenter](#dlibdrectangledcenter)
  - [dlib::drectangle::contains](#dlibdrectanglecontains)
  - [dlib::drectangle::intersect](#dlibdrectangleintersect)
  - [dlib::drectangle::ToString](#dlibdrectangletostring)
- [dlib::full_object_detection](#dlibfull_object_detection)
  - [dlib::full_object_detection::create](#dlibfull_object_detectioncreate)
  - [dlib::full_object_detection::part](#dlibfull_object_detectionpart)
  - [dlib::full_object_detection::parts](#dlibfull_object_detectionparts)
- [dlib::shape_predictor](#dlibshape_predictor)
  - [dlib::shape_predictor::create](#dlibshape_predictorcreate)
  - [dlib::shape_predictor::get_call](#dlibshape_predictorget_call)
  - [dlib::shape_predictor::save](#dlibshape_predictorsave)
- [dlib::svm_c_trainer_radial_basis](#dlibsvm_c_trainer_radial_basis)
  - [dlib::svm_c_trainer_radial_basis::create](#dlibsvm_c_trainer_radial_basiscreate)
  - [dlib::svm_c_trainer_radial_basis::train](#dlibsvm_c_trainer_radial_basistrain)
  - [dlib::svm_c_trainer_radial_basis::set_c](#dlibsvm_c_trainer_radial_basisset_c)
- [dlib::svm_c_trainer_sparse_radial_basis](#dlibsvm_c_trainer_sparse_radial_basis)
  - [dlib::svm_c_trainer_sparse_radial_basis::create](#dlibsvm_c_trainer_sparse_radial_basiscreate)
  - [dlib::svm_c_trainer_sparse_radial_basis::train](#dlibsvm_c_trainer_sparse_radial_basistrain)
  - [dlib::svm_c_trainer_sparse_radial_basis::set_c](#dlibsvm_c_trainer_sparse_radial_basisset_c)
- [dlib::svm_c_trainer_histogram_intersection](#dlibsvm_c_trainer_histogram_intersection)
  - [dlib::svm_c_trainer_histogram_intersection::create](#dlibsvm_c_trainer_histogram_intersectioncreate)
  - [dlib::svm_c_trainer_histogram_intersection::train](#dlibsvm_c_trainer_histogram_intersectiontrain)
  - [dlib::svm_c_trainer_histogram_intersection::set_c](#dlibsvm_c_trainer_histogram_intersectionset_c)
- [dlib::svm_c_trainer_sparse_histogram_intersection](#dlibsvm_c_trainer_sparse_histogram_intersection)
  - [dlib::svm_c_trainer_sparse_histogram_intersection::create](#dlibsvm_c_trainer_sparse_histogram_intersectioncreate)
  - [dlib::svm_c_trainer_sparse_histogram_intersection::train](#dlibsvm_c_trainer_sparse_histogram_intersectiontrain)
  - [dlib::svm_c_trainer_sparse_histogram_intersection::set_c](#dlibsvm_c_trainer_sparse_histogram_intersectionset_c)
- [dlib::svm_c_trainer_linear](#dlibsvm_c_trainer_linear)
  - [dlib::svm_c_trainer_linear::create](#dlibsvm_c_trainer_linearcreate)
  - [dlib::svm_c_trainer_linear::train](#dlibsvm_c_trainer_lineartrain)
  - [dlib::svm_c_trainer_linear::set_c](#dlibsvm_c_trainer_linearset_c)
  - [dlib::svm_c_trainer_linear::set_prior](#dlibsvm_c_trainer_linearset_prior)
  - [dlib::svm_c_trainer_linear::be_verbose](#dlibsvm_c_trainer_linearbe_verbose)
  - [dlib::svm_c_trainer_linear::be_quiet](#dlibsvm_c_trainer_linearbe_quiet)
- [dlib::svm_c_trainer_sparse_linear](#dlibsvm_c_trainer_sparse_linear)
  - [dlib::svm_c_trainer_sparse_linear::create](#dlibsvm_c_trainer_sparse_linearcreate)
  - [dlib::svm_c_trainer_sparse_linear::train](#dlibsvm_c_trainer_sparse_lineartrain)
  - [dlib::svm_c_trainer_sparse_linear::set_c](#dlibsvm_c_trainer_sparse_linearset_c)
  - [dlib::svm_c_trainer_sparse_linear::set_prior](#dlibsvm_c_trainer_sparse_linearset_prior)
  - [dlib::svm_c_trainer_sparse_linear::be_verbose](#dlibsvm_c_trainer_sparse_linearbe_verbose)
  - [dlib::svm_c_trainer_sparse_linear::be_quiet](#dlibsvm_c_trainer_sparse_linearbe_quiet)
- [dlib::rvm_trainer_radial_basis](#dlibrvm_trainer_radial_basis)
  - [dlib::rvm_trainer_radial_basis::create](#dlibrvm_trainer_radial_basiscreate)
  - [dlib::rvm_trainer_radial_basis::train](#dlibrvm_trainer_radial_basistrain)
- [dlib::rvm_trainer_sparse_radial_basis](#dlibrvm_trainer_sparse_radial_basis)
  - [dlib::rvm_trainer_sparse_radial_basis::create](#dlibrvm_trainer_sparse_radial_basiscreate)
  - [dlib::rvm_trainer_sparse_radial_basis::train](#dlibrvm_trainer_sparse_radial_basistrain)
- [dlib::rvm_trainer_histogram_intersection](#dlibrvm_trainer_histogram_intersection)
  - [dlib::rvm_trainer_histogram_intersection::create](#dlibrvm_trainer_histogram_intersectioncreate)
  - [dlib::rvm_trainer_histogram_intersection::train](#dlibrvm_trainer_histogram_intersectiontrain)
- [dlib::rvm_trainer_sparse_histogram_intersection](#dlibrvm_trainer_sparse_histogram_intersection)
  - [dlib::rvm_trainer_sparse_histogram_intersection::create](#dlibrvm_trainer_sparse_histogram_intersectioncreate)
  - [dlib::rvm_trainer_sparse_histogram_intersection::train](#dlibrvm_trainer_sparse_histogram_intersectiontrain)
- [dlib::rvm_trainer_linear](#dlibrvm_trainer_linear)
  - [dlib::rvm_trainer_linear::create](#dlibrvm_trainer_linearcreate)
  - [dlib::rvm_trainer_linear::train](#dlibrvm_trainer_lineartrain)
- [dlib::rvm_trainer_sparse_linear](#dlibrvm_trainer_sparse_linear)
  - [dlib::rvm_trainer_sparse_linear::create](#dlibrvm_trainer_sparse_linearcreate)
  - [dlib::rvm_trainer_sparse_linear::train](#dlibrvm_trainer_sparse_lineartrain)
- [dlib::vec_ranking_pair](#dlibvec_ranking_pair)
  - [dlib::vec_ranking_pair::create](#dlibvec_ranking_paircreate)
- [dlib::sparse_ranking_pair](#dlibsparse_ranking_pair)
  - [dlib::sparse_ranking_pair::create](#dlibsparse_ranking_paircreate)
- [dlib::vec_svm_rank_trainer](#dlibvec_svm_rank_trainer)
  - [dlib::vec_svm_rank_trainer::create](#dlibvec_svm_rank_trainercreate)
  - [dlib::vec_svm_rank_trainer::train](#dlibvec_svm_rank_trainertrain)
  - [dlib::vec_svm_rank_trainer::set_prior](#dlibvec_svm_rank_trainerset_prior)
  - [dlib::vec_svm_rank_trainer::be_verbose](#dlibvec_svm_rank_trainerbe_verbose)
  - [dlib::vec_svm_rank_trainer::be_quiet](#dlibvec_svm_rank_trainerbe_quiet)
- [dlib::svm_rank_trainer_sparse](#dlibsvm_rank_trainer_sparse)
  - [dlib::svm_rank_trainer_sparse::create](#dlibsvm_rank_trainer_sparsecreate)
  - [dlib::svm_rank_trainer_sparse::train](#dlibsvm_rank_trainer_sparsetrain)
  - [dlib::svm_rank_trainer_sparse::set_prior](#dlibsvm_rank_trainer_sparseset_prior)
  - [dlib::svm_rank_trainer_sparse::be_verbose](#dlibsvm_rank_trainer_sparsebe_verbose)
  - [dlib::svm_rank_trainer_sparse::be_quiet](#dlibsvm_rank_trainer_sparsebe_quiet)
- [dlib::SpaceVector](#dlibspacevector)
  - [dlib::SpaceVector::create](#dlibspacevectorcreate)
  - [dlib::SpaceVector::set_size](#dlibspacevectorset_size)
  - [dlib::SpaceVector::resize](#dlibspacevectorresize)
  - [dlib::SpaceVector::size](#dlibspacevectorsize)
  - [dlib::SpaceVector::get](#dlibspacevectorget)
  - [dlib::SpaceVector::set](#dlibspacevectorset)
  - [dlib::SpaceVector::get_Item](#dlibspacevectorget_item)
  - [dlib::SpaceVector::put_Item](#dlibspacevectorput_item)
  - [dlib::SpaceVector::slice](#dlibspacevectorslice)
  - [dlib::SpaceVector::ToString](#dlibspacevectortostring)
- [dlib::point_transform_projective](#dlibpoint_transform_projective)
  - [dlib::point_transform_projective::create](#dlibpoint_transform_projectivecreate)
- [dlib::dpoint](#dlibdpoint)
  - [dlib::dpoint::create](#dlibdpointcreate)
  - [dlib::dpoint::normalize](#dlibdpointnormalize)
  - [dlib::dpoint::add](#dlibdpointadd)
  - [dlib::dpoint::sub](#dlibdpointsub)
  - [dlib::dpoint::divide](#dlibdpointdivide)
  - [dlib::dpoint::multiply](#dlibdpointmultiply)
  - [dlib::dpoint::ToString](#dlibdpointtostring)
- [dlib::point](#dlibpoint)
  - [dlib::point::create](#dlibpointcreate)
  - [dlib::point::normalize](#dlibpointnormalize)
  - [dlib::point::add](#dlibpointadd)
  - [dlib::point::sub](#dlibpointsub)
  - [dlib::point::divide](#dlibpointdivide)
  - [dlib::point::multiply](#dlibpointmultiply)
  - [dlib::point::ToString](#dlibpointtostring)
- [VectorOfVariant](#vectorofvariant)
  - [VectorOfVariant::create](#vectorofvariantcreate)
  - [VectorOfVariant::Keys](#vectorofvariantkeys)
  - [VectorOfVariant::Items](#vectorofvariantitems)
  - [VectorOfVariant::push_back](#vectorofvariantpush_back)
  - [VectorOfVariant::Add](#vectorofvariantadd)
  - [VectorOfVariant::Remove](#vectorofvariantremove)
  - [VectorOfVariant::at](#vectorofvariantat)
  - [VectorOfVariant::size](#vectorofvariantsize)
  - [VectorOfVariant::empty](#vectorofvariantempty)
  - [VectorOfVariant::clear](#vectorofvariantclear)
  - [VectorOfVariant::push_vector](#vectorofvariantpush_vector)
  - [VectorOfVariant::slice](#vectorofvariantslice)
  - [VectorOfVariant::sort](#vectorofvariantsort)
  - [VectorOfVariant::sort_variant](#vectorofvariantsort_variant)
  - [VectorOfVariant::start](#vectorofvariantstart)
  - [VectorOfVariant::end](#vectorofvariantend)
  - [VectorOfVariant::get_Item](#vectorofvariantget_item)
  - [VectorOfVariant::put_Item](#vectorofvariantput_item)
- [VectorOfPairOfULONGAndDouble](#vectorofpairofulonganddouble)
  - [VectorOfPairOfULONGAndDouble::create](#vectorofpairofulonganddoublecreate)
  - [VectorOfPairOfULONGAndDouble::Keys](#vectorofpairofulonganddoublekeys)
  - [VectorOfPairOfULONGAndDouble::Items](#vectorofpairofulonganddoubleitems)
  - [VectorOfPairOfULONGAndDouble::push_back](#vectorofpairofulonganddoublepush_back)
  - [VectorOfPairOfULONGAndDouble::Add](#vectorofpairofulonganddoubleadd)
  - [VectorOfPairOfULONGAndDouble::Remove](#vectorofpairofulonganddoubleremove)
  - [VectorOfPairOfULONGAndDouble::at](#vectorofpairofulonganddoubleat)
  - [VectorOfPairOfULONGAndDouble::size](#vectorofpairofulonganddoublesize)
  - [VectorOfPairOfULONGAndDouble::empty](#vectorofpairofulonganddoubleempty)
  - [VectorOfPairOfULONGAndDouble::clear](#vectorofpairofulonganddoubleclear)
  - [VectorOfPairOfULONGAndDouble::push_vector](#vectorofpairofulonganddoublepush_vector)
  - [VectorOfPairOfULONGAndDouble::slice](#vectorofpairofulonganddoubleslice)
  - [VectorOfPairOfULONGAndDouble::sort](#vectorofpairofulonganddoublesort)
  - [VectorOfPairOfULONGAndDouble::sort_variant](#vectorofpairofulonganddoublesort_variant)
  - [VectorOfPairOfULONGAndDouble::start](#vectorofpairofulonganddoublestart)
  - [VectorOfPairOfULONGAndDouble::end](#vectorofpairofulonganddoubleend)
  - [VectorOfPairOfULONGAndDouble::get_Item](#vectorofpairofulonganddoubleget_item)
  - [VectorOfPairOfULONGAndDouble::put_Item](#vectorofpairofulonganddoubleput_item)
- [VectorOfVectorOfPairOfULONGAndDouble](#vectorofvectorofpairofulonganddouble)
  - [VectorOfVectorOfPairOfULONGAndDouble::create](#vectorofvectorofpairofulonganddoublecreate)
  - [VectorOfVectorOfPairOfULONGAndDouble::Keys](#vectorofvectorofpairofulonganddoublekeys)
  - [VectorOfVectorOfPairOfULONGAndDouble::Items](#vectorofvectorofpairofulonganddoubleitems)
  - [VectorOfVectorOfPairOfULONGAndDouble::push_back](#vectorofvectorofpairofulonganddoublepush_back)
  - [VectorOfVectorOfPairOfULONGAndDouble::Add](#vectorofvectorofpairofulonganddoubleadd)
  - [VectorOfVectorOfPairOfULONGAndDouble::Remove](#vectorofvectorofpairofulonganddoubleremove)
  - [VectorOfVectorOfPairOfULONGAndDouble::at](#vectorofvectorofpairofulonganddoubleat)
  - [VectorOfVectorOfPairOfULONGAndDouble::size](#vectorofvectorofpairofulonganddoublesize)
  - [VectorOfVectorOfPairOfULONGAndDouble::empty](#vectorofvectorofpairofulonganddoubleempty)
  - [VectorOfVectorOfPairOfULONGAndDouble::clear](#vectorofvectorofpairofulonganddoubleclear)
  - [VectorOfVectorOfPairOfULONGAndDouble::push_vector](#vectorofvectorofpairofulonganddoublepush_vector)
  - [VectorOfVectorOfPairOfULONGAndDouble::slice](#vectorofvectorofpairofulonganddoubleslice)
  - [VectorOfVectorOfPairOfULONGAndDouble::sort](#vectorofvectorofpairofulonganddoublesort)
  - [VectorOfVectorOfPairOfULONGAndDouble::sort_variant](#vectorofvectorofpairofulonganddoublesort_variant)
  - [VectorOfVectorOfPairOfULONGAndDouble::start](#vectorofvectorofpairofulonganddoublestart)
  - [VectorOfVectorOfPairOfULONGAndDouble::end](#vectorofvectorofpairofulonganddoubleend)
  - [VectorOfVectorOfPairOfULONGAndDouble::get_Item](#vectorofvectorofpairofulonganddoubleget_item)
  - [VectorOfVectorOfPairOfULONGAndDouble::put_Item](#vectorofvectorofpairofulonganddoubleput_item)
- [VectorOfMat](#vectorofmat)
  - [VectorOfMat::create](#vectorofmatcreate)
  - [VectorOfMat::Keys](#vectorofmatkeys)
  - [VectorOfMat::Items](#vectorofmatitems)
  - [VectorOfMat::push_back](#vectorofmatpush_back)
  - [VectorOfMat::Add](#vectorofmatadd)
  - [VectorOfMat::Remove](#vectorofmatremove)
  - [VectorOfMat::at](#vectorofmatat)
  - [VectorOfMat::size](#vectorofmatsize)
  - [VectorOfMat::empty](#vectorofmatempty)
  - [VectorOfMat::clear](#vectorofmatclear)
  - [VectorOfMat::push_vector](#vectorofmatpush_vector)
  - [VectorOfMat::slice](#vectorofmatslice)
  - [VectorOfMat::sort](#vectorofmatsort)
  - [VectorOfMat::sort_variant](#vectorofmatsort_variant)
  - [VectorOfMat::start](#vectorofmatstart)
  - [VectorOfMat::end](#vectorofmatend)
  - [VectorOfMat::get_Item](#vectorofmatget_item)
  - [VectorOfMat::put_Item](#vectorofmatput_item)
- [VectorOfFull_object_detection](#vectoroffull_object_detection)
  - [VectorOfFull_object_detection::create](#vectoroffull_object_detectioncreate)
  - [VectorOfFull_object_detection::Keys](#vectoroffull_object_detectionkeys)
  - [VectorOfFull_object_detection::Items](#vectoroffull_object_detectionitems)
  - [VectorOfFull_object_detection::push_back](#vectoroffull_object_detectionpush_back)
  - [VectorOfFull_object_detection::Add](#vectoroffull_object_detectionadd)
  - [VectorOfFull_object_detection::Remove](#vectoroffull_object_detectionremove)
  - [VectorOfFull_object_detection::at](#vectoroffull_object_detectionat)
  - [VectorOfFull_object_detection::size](#vectoroffull_object_detectionsize)
  - [VectorOfFull_object_detection::empty](#vectoroffull_object_detectionempty)
  - [VectorOfFull_object_detection::clear](#vectoroffull_object_detectionclear)
  - [VectorOfFull_object_detection::push_vector](#vectoroffull_object_detectionpush_vector)
  - [VectorOfFull_object_detection::slice](#vectoroffull_object_detectionslice)
  - [VectorOfFull_object_detection::sort](#vectoroffull_object_detectionsort)
  - [VectorOfFull_object_detection::sort_variant](#vectoroffull_object_detectionsort_variant)
  - [VectorOfFull_object_detection::start](#vectoroffull_object_detectionstart)
  - [VectorOfFull_object_detection::end](#vectoroffull_object_detectionend)
  - [VectorOfFull_object_detection::get_Item](#vectoroffull_object_detectionget_item)
  - [VectorOfFull_object_detection::put_Item](#vectoroffull_object_detectionput_item)
- [VectorOfSpaceVector](#vectorofspacevector)
  - [VectorOfSpaceVector::create](#vectorofspacevectorcreate)
  - [VectorOfSpaceVector::Keys](#vectorofspacevectorkeys)
  - [VectorOfSpaceVector::Items](#vectorofspacevectoritems)
  - [VectorOfSpaceVector::push_back](#vectorofspacevectorpush_back)
  - [VectorOfSpaceVector::Add](#vectorofspacevectoradd)
  - [VectorOfSpaceVector::Remove](#vectorofspacevectorremove)
  - [VectorOfSpaceVector::at](#vectorofspacevectorat)
  - [VectorOfSpaceVector::size](#vectorofspacevectorsize)
  - [VectorOfSpaceVector::empty](#vectorofspacevectorempty)
  - [VectorOfSpaceVector::clear](#vectorofspacevectorclear)
  - [VectorOfSpaceVector::push_vector](#vectorofspacevectorpush_vector)
  - [VectorOfSpaceVector::slice](#vectorofspacevectorslice)
  - [VectorOfSpaceVector::sort](#vectorofspacevectorsort)
  - [VectorOfSpaceVector::sort_variant](#vectorofspacevectorsort_variant)
  - [VectorOfSpaceVector::start](#vectorofspacevectorstart)
  - [VectorOfSpaceVector::end](#vectorofspacevectorend)
  - [VectorOfSpaceVector::get_Item](#vectorofspacevectorget_item)
  - [VectorOfSpaceVector::put_Item](#vectorofspacevectorput_item)
- [VectorOfULONG](#vectorofulong)
  - [VectorOfULONG::create](#vectorofulongcreate)
  - [VectorOfULONG::Keys](#vectorofulongkeys)
  - [VectorOfULONG::Items](#vectorofulongitems)
  - [VectorOfULONG::push_back](#vectorofulongpush_back)
  - [VectorOfULONG::Add](#vectorofulongadd)
  - [VectorOfULONG::Remove](#vectorofulongremove)
  - [VectorOfULONG::at](#vectorofulongat)
  - [VectorOfULONG::size](#vectorofulongsize)
  - [VectorOfULONG::empty](#vectorofulongempty)
  - [VectorOfULONG::clear](#vectorofulongclear)
  - [VectorOfULONG::push_vector](#vectorofulongpush_vector)
  - [VectorOfULONG::slice](#vectorofulongslice)
  - [VectorOfULONG::sort](#vectorofulongsort)
  - [VectorOfULONG::sort_variant](#vectorofulongsort_variant)
  - [VectorOfULONG::start](#vectorofulongstart)
  - [VectorOfULONG::end](#vectorofulongend)
  - [VectorOfULONG::get_Item](#vectorofulongget_item)
  - [VectorOfULONG::put_Item](#vectorofulongput_item)
- [VectorOfDouble](#vectorofdouble)
  - [VectorOfDouble::create](#vectorofdoublecreate)
  - [VectorOfDouble::Keys](#vectorofdoublekeys)
  - [VectorOfDouble::Items](#vectorofdoubleitems)
  - [VectorOfDouble::push_back](#vectorofdoublepush_back)
  - [VectorOfDouble::Add](#vectorofdoubleadd)
  - [VectorOfDouble::Remove](#vectorofdoubleremove)
  - [VectorOfDouble::at](#vectorofdoubleat)
  - [VectorOfDouble::size](#vectorofdoublesize)
  - [VectorOfDouble::empty](#vectorofdoubleempty)
  - [VectorOfDouble::clear](#vectorofdoubleclear)
  - [VectorOfDouble::push_vector](#vectorofdoublepush_vector)
  - [VectorOfDouble::slice](#vectorofdoubleslice)
  - [VectorOfDouble::sort](#vectorofdoublesort)
  - [VectorOfDouble::sort_variant](#vectorofdoublesort_variant)
  - [VectorOfDouble::start](#vectorofdoublestart)
  - [VectorOfDouble::end](#vectorofdoubleend)
  - [VectorOfDouble::get_Item](#vectorofdoubleget_item)
  - [VectorOfDouble::put_Item](#vectorofdoubleput_item)
- [VectorOfBool](#vectorofbool)
  - [VectorOfBool::create](#vectorofboolcreate)
  - [VectorOfBool::Keys](#vectorofboolkeys)
  - [VectorOfBool::Items](#vectorofboolitems)
  - [VectorOfBool::push_back](#vectorofboolpush_back)
  - [VectorOfBool::Add](#vectorofbooladd)
  - [VectorOfBool::Remove](#vectorofboolremove)
  - [VectorOfBool::at](#vectorofboolat)
  - [VectorOfBool::size](#vectorofboolsize)
  - [VectorOfBool::empty](#vectorofboolempty)
  - [VectorOfBool::clear](#vectorofboolclear)
  - [VectorOfBool::push_vector](#vectorofboolpush_vector)
  - [VectorOfBool::slice](#vectorofboolslice)
  - [VectorOfBool::sort](#vectorofboolsort)
  - [VectorOfBool::sort_variant](#vectorofboolsort_variant)
  - [VectorOfBool::start](#vectorofboolstart)
  - [VectorOfBool::end](#vectorofboolend)
  - [VectorOfBool::get_Item](#vectorofboolget_item)
  - [VectorOfBool::put_Item](#vectorofboolput_item)
- [VectorOfRectangle](#vectorofrectangle)
  - [VectorOfRectangle::create](#vectorofrectanglecreate)
  - [VectorOfRectangle::Keys](#vectorofrectanglekeys)
  - [VectorOfRectangle::Items](#vectorofrectangleitems)
  - [VectorOfRectangle::push_back](#vectorofrectanglepush_back)
  - [VectorOfRectangle::Add](#vectorofrectangleadd)
  - [VectorOfRectangle::Remove](#vectorofrectangleremove)
  - [VectorOfRectangle::at](#vectorofrectangleat)
  - [VectorOfRectangle::size](#vectorofrectanglesize)
  - [VectorOfRectangle::empty](#vectorofrectangleempty)
  - [VectorOfRectangle::clear](#vectorofrectangleclear)
  - [VectorOfRectangle::push_vector](#vectorofrectanglepush_vector)
  - [VectorOfRectangle::slice](#vectorofrectangleslice)
  - [VectorOfRectangle::sort](#vectorofrectanglesort)
  - [VectorOfRectangle::sort_variant](#vectorofrectanglesort_variant)
  - [VectorOfRectangle::start](#vectorofrectanglestart)
  - [VectorOfRectangle::end](#vectorofrectangleend)
  - [VectorOfRectangle::get_Item](#vectorofrectangleget_item)
  - [VectorOfRectangle::put_Item](#vectorofrectangleput_item)
- [VectorOfLong](#vectoroflong)
  - [VectorOfLong::create](#vectoroflongcreate)
  - [VectorOfLong::Keys](#vectoroflongkeys)
  - [VectorOfLong::Items](#vectoroflongitems)
  - [VectorOfLong::push_back](#vectoroflongpush_back)
  - [VectorOfLong::Add](#vectoroflongadd)
  - [VectorOfLong::Remove](#vectoroflongremove)
  - [VectorOfLong::at](#vectoroflongat)
  - [VectorOfLong::size](#vectoroflongsize)
  - [VectorOfLong::empty](#vectoroflongempty)
  - [VectorOfLong::clear](#vectoroflongclear)
  - [VectorOfLong::push_vector](#vectoroflongpush_vector)
  - [VectorOfLong::slice](#vectoroflongslice)
  - [VectorOfLong::sort](#vectoroflongsort)
  - [VectorOfLong::sort_variant](#vectoroflongsort_variant)
  - [VectorOfLong::start](#vectoroflongstart)
  - [VectorOfLong::end](#vectoroflongend)
  - [VectorOfLong::get_Item](#vectoroflongget_item)
  - [VectorOfLong::put_Item](#vectoroflongput_item)
- [VectorOfVectorOfSpaceVector](#vectorofvectorofspacevector)
  - [VectorOfVectorOfSpaceVector::create](#vectorofvectorofspacevectorcreate)
  - [VectorOfVectorOfSpaceVector::Keys](#vectorofvectorofspacevectorkeys)
  - [VectorOfVectorOfSpaceVector::Items](#vectorofvectorofspacevectoritems)
  - [VectorOfVectorOfSpaceVector::push_back](#vectorofvectorofspacevectorpush_back)
  - [VectorOfVectorOfSpaceVector::Add](#vectorofvectorofspacevectoradd)
  - [VectorOfVectorOfSpaceVector::Remove](#vectorofvectorofspacevectorremove)
  - [VectorOfVectorOfSpaceVector::at](#vectorofvectorofspacevectorat)
  - [VectorOfVectorOfSpaceVector::size](#vectorofvectorofspacevectorsize)
  - [VectorOfVectorOfSpaceVector::empty](#vectorofvectorofspacevectorempty)
  - [VectorOfVectorOfSpaceVector::clear](#vectorofvectorofspacevectorclear)
  - [VectorOfVectorOfSpaceVector::push_vector](#vectorofvectorofspacevectorpush_vector)
  - [VectorOfVectorOfSpaceVector::slice](#vectorofvectorofspacevectorslice)
  - [VectorOfVectorOfSpaceVector::sort](#vectorofvectorofspacevectorsort)
  - [VectorOfVectorOfSpaceVector::sort_variant](#vectorofvectorofspacevectorsort_variant)
  - [VectorOfVectorOfSpaceVector::start](#vectorofvectorofspacevectorstart)
  - [VectorOfVectorOfSpaceVector::end](#vectorofvectorofspacevectorend)
  - [VectorOfVectorOfSpaceVector::get_Item](#vectorofvectorofspacevectorget_item)
  - [VectorOfVectorOfSpaceVector::put_Item](#vectorofvectorofspacevectorput_item)
- [VectorOfPairOfULONGAndULONG](#vectorofpairofulongandulong)
  - [VectorOfPairOfULONGAndULONG::create](#vectorofpairofulongandulongcreate)
  - [VectorOfPairOfULONGAndULONG::Keys](#vectorofpairofulongandulongkeys)
  - [VectorOfPairOfULONGAndULONG::Items](#vectorofpairofulongandulongitems)
  - [VectorOfPairOfULONGAndULONG::push_back](#vectorofpairofulongandulongpush_back)
  - [VectorOfPairOfULONGAndULONG::Add](#vectorofpairofulongandulongadd)
  - [VectorOfPairOfULONGAndULONG::Remove](#vectorofpairofulongandulongremove)
  - [VectorOfPairOfULONGAndULONG::at](#vectorofpairofulongandulongat)
  - [VectorOfPairOfULONGAndULONG::size](#vectorofpairofulongandulongsize)
  - [VectorOfPairOfULONGAndULONG::empty](#vectorofpairofulongandulongempty)
  - [VectorOfPairOfULONGAndULONG::clear](#vectorofpairofulongandulongclear)
  - [VectorOfPairOfULONGAndULONG::push_vector](#vectorofpairofulongandulongpush_vector)
  - [VectorOfPairOfULONGAndULONG::slice](#vectorofpairofulongandulongslice)
  - [VectorOfPairOfULONGAndULONG::sort](#vectorofpairofulongandulongsort)
  - [VectorOfPairOfULONGAndULONG::sort_variant](#vectorofpairofulongandulongsort_variant)
  - [VectorOfPairOfULONGAndULONG::start](#vectorofpairofulongandulongstart)
  - [VectorOfPairOfULONGAndULONG::end](#vectorofpairofulongandulongend)
  - [VectorOfPairOfULONGAndULONG::get_Item](#vectorofpairofulongandulongget_item)
  - [VectorOfPairOfULONGAndULONG::put_Item](#vectorofpairofulongandulongput_item)
- [VectorOfVectorOfPairOfULONGAndULONG](#vectorofvectorofpairofulongandulong)
  - [VectorOfVectorOfPairOfULONGAndULONG::create](#vectorofvectorofpairofulongandulongcreate)
  - [VectorOfVectorOfPairOfULONGAndULONG::Keys](#vectorofvectorofpairofulongandulongkeys)
  - [VectorOfVectorOfPairOfULONGAndULONG::Items](#vectorofvectorofpairofulongandulongitems)
  - [VectorOfVectorOfPairOfULONGAndULONG::push_back](#vectorofvectorofpairofulongandulongpush_back)
  - [VectorOfVectorOfPairOfULONGAndULONG::Add](#vectorofvectorofpairofulongandulongadd)
  - [VectorOfVectorOfPairOfULONGAndULONG::Remove](#vectorofvectorofpairofulongandulongremove)
  - [VectorOfVectorOfPairOfULONGAndULONG::at](#vectorofvectorofpairofulongandulongat)
  - [VectorOfVectorOfPairOfULONGAndULONG::size](#vectorofvectorofpairofulongandulongsize)
  - [VectorOfVectorOfPairOfULONGAndULONG::empty](#vectorofvectorofpairofulongandulongempty)
  - [VectorOfVectorOfPairOfULONGAndULONG::clear](#vectorofvectorofpairofulongandulongclear)
  - [VectorOfVectorOfPairOfULONGAndULONG::push_vector](#vectorofvectorofpairofulongandulongpush_vector)
  - [VectorOfVectorOfPairOfULONGAndULONG::slice](#vectorofvectorofpairofulongandulongslice)
  - [VectorOfVectorOfPairOfULONGAndULONG::sort](#vectorofvectorofpairofulongandulongsort)
  - [VectorOfVectorOfPairOfULONGAndULONG::sort_variant](#vectorofvectorofpairofulongandulongsort_variant)
  - [VectorOfVectorOfPairOfULONGAndULONG::start](#vectorofvectorofpairofulongandulongstart)
  - [VectorOfVectorOfPairOfULONGAndULONG::end](#vectorofvectorofpairofulongandulongend)
  - [VectorOfVectorOfPairOfULONGAndULONG::get_Item](#vectorofvectorofpairofulongandulongget_item)
  - [VectorOfVectorOfPairOfULONGAndULONG::put_Item](#vectorofvectorofpairofulongandulongput_item)
- [VectorOfVectorOfVectorOfPairOfULONGAndDouble](#vectorofvectorofvectorofpairofulonganddouble)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::create](#vectorofvectorofvectorofpairofulonganddoublecreate)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Keys](#vectorofvectorofvectorofpairofulonganddoublekeys)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Items](#vectorofvectorofvectorofpairofulonganddoubleitems)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_back](#vectorofvectorofvectorofpairofulonganddoublepush_back)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Add](#vectorofvectorofvectorofpairofulonganddoubleadd)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Remove](#vectorofvectorofvectorofpairofulonganddoubleremove)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::at](#vectorofvectorofvectorofpairofulonganddoubleat)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::size](#vectorofvectorofvectorofpairofulonganddoublesize)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::empty](#vectorofvectorofvectorofpairofulonganddoubleempty)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::clear](#vectorofvectorofvectorofpairofulonganddoubleclear)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_vector](#vectorofvectorofvectorofpairofulonganddoublepush_vector)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::slice](#vectorofvectorofvectorofpairofulonganddoubleslice)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort](#vectorofvectorofvectorofpairofulonganddoublesort)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort_variant](#vectorofvectorofvectorofpairofulonganddoublesort_variant)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::start](#vectorofvectorofvectorofpairofulonganddoublestart)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::end](#vectorofvectorofvectorofpairofulonganddoubleend)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::get_Item](#vectorofvectorofvectorofpairofulonganddoubleget_item)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::put_Item](#vectorofvectorofvectorofpairofulonganddoubleput_item)
- [VectorOfVectorOfFull_object_detection](#vectorofvectoroffull_object_detection)
  - [VectorOfVectorOfFull_object_detection::create](#vectorofvectoroffull_object_detectioncreate)
  - [VectorOfVectorOfFull_object_detection::Keys](#vectorofvectoroffull_object_detectionkeys)
  - [VectorOfVectorOfFull_object_detection::Items](#vectorofvectoroffull_object_detectionitems)
  - [VectorOfVectorOfFull_object_detection::push_back](#vectorofvectoroffull_object_detectionpush_back)
  - [VectorOfVectorOfFull_object_detection::Add](#vectorofvectoroffull_object_detectionadd)
  - [VectorOfVectorOfFull_object_detection::Remove](#vectorofvectoroffull_object_detectionremove)
  - [VectorOfVectorOfFull_object_detection::at](#vectorofvectoroffull_object_detectionat)
  - [VectorOfVectorOfFull_object_detection::size](#vectorofvectoroffull_object_detectionsize)
  - [VectorOfVectorOfFull_object_detection::empty](#vectorofvectoroffull_object_detectionempty)
  - [VectorOfVectorOfFull_object_detection::clear](#vectorofvectoroffull_object_detectionclear)
  - [VectorOfVectorOfFull_object_detection::push_vector](#vectorofvectoroffull_object_detectionpush_vector)
  - [VectorOfVectorOfFull_object_detection::slice](#vectorofvectoroffull_object_detectionslice)
  - [VectorOfVectorOfFull_object_detection::sort](#vectorofvectoroffull_object_detectionsort)
  - [VectorOfVectorOfFull_object_detection::sort_variant](#vectorofvectoroffull_object_detectionsort_variant)
  - [VectorOfVectorOfFull_object_detection::start](#vectorofvectoroffull_object_detectionstart)
  - [VectorOfVectorOfFull_object_detection::end](#vectorofvectoroffull_object_detectionend)
  - [VectorOfVectorOfFull_object_detection::get_Item](#vectorofvectoroffull_object_detectionget_item)
  - [VectorOfVectorOfFull_object_detection::put_Item](#vectorofvectoroffull_object_detectionput_item)
- [VectorOfVectorOfRectangle](#vectorofvectorofrectangle)
  - [VectorOfVectorOfRectangle::create](#vectorofvectorofrectanglecreate)
  - [VectorOfVectorOfRectangle::Keys](#vectorofvectorofrectanglekeys)
  - [VectorOfVectorOfRectangle::Items](#vectorofvectorofrectangleitems)
  - [VectorOfVectorOfRectangle::push_back](#vectorofvectorofrectanglepush_back)
  - [VectorOfVectorOfRectangle::Add](#vectorofvectorofrectangleadd)
  - [VectorOfVectorOfRectangle::Remove](#vectorofvectorofrectangleremove)
  - [VectorOfVectorOfRectangle::at](#vectorofvectorofrectangleat)
  - [VectorOfVectorOfRectangle::size](#vectorofvectorofrectanglesize)
  - [VectorOfVectorOfRectangle::empty](#vectorofvectorofrectangleempty)
  - [VectorOfVectorOfRectangle::clear](#vectorofvectorofrectangleclear)
  - [VectorOfVectorOfRectangle::push_vector](#vectorofvectorofrectanglepush_vector)
  - [VectorOfVectorOfRectangle::slice](#vectorofvectorofrectangleslice)
  - [VectorOfVectorOfRectangle::sort](#vectorofvectorofrectanglesort)
  - [VectorOfVectorOfRectangle::sort_variant](#vectorofvectorofrectanglesort_variant)
  - [VectorOfVectorOfRectangle::start](#vectorofvectorofrectanglestart)
  - [VectorOfVectorOfRectangle::end](#vectorofvectorofrectangleend)
  - [VectorOfVectorOfRectangle::get_Item](#vectorofvectorofrectangleget_item)
  - [VectorOfVectorOfRectangle::put_Item](#vectorofvectorofrectangleput_item)
- [VectorOfVec_ranking_pair](#vectorofvec_ranking_pair)
  - [VectorOfVec_ranking_pair::create](#vectorofvec_ranking_paircreate)
  - [VectorOfVec_ranking_pair::Keys](#vectorofvec_ranking_pairkeys)
  - [VectorOfVec_ranking_pair::Items](#vectorofvec_ranking_pairitems)
  - [VectorOfVec_ranking_pair::push_back](#vectorofvec_ranking_pairpush_back)
  - [VectorOfVec_ranking_pair::Add](#vectorofvec_ranking_pairadd)
  - [VectorOfVec_ranking_pair::Remove](#vectorofvec_ranking_pairremove)
  - [VectorOfVec_ranking_pair::at](#vectorofvec_ranking_pairat)
  - [VectorOfVec_ranking_pair::size](#vectorofvec_ranking_pairsize)
  - [VectorOfVec_ranking_pair::empty](#vectorofvec_ranking_pairempty)
  - [VectorOfVec_ranking_pair::clear](#vectorofvec_ranking_pairclear)
  - [VectorOfVec_ranking_pair::push_vector](#vectorofvec_ranking_pairpush_vector)
  - [VectorOfVec_ranking_pair::slice](#vectorofvec_ranking_pairslice)
  - [VectorOfVec_ranking_pair::sort](#vectorofvec_ranking_pairsort)
  - [VectorOfVec_ranking_pair::sort_variant](#vectorofvec_ranking_pairsort_variant)
  - [VectorOfVec_ranking_pair::start](#vectorofvec_ranking_pairstart)
  - [VectorOfVec_ranking_pair::end](#vectorofvec_ranking_pairend)
  - [VectorOfVec_ranking_pair::get_Item](#vectorofvec_ranking_pairget_item)
  - [VectorOfVec_ranking_pair::put_Item](#vectorofvec_ranking_pairput_item)
- [VectorOfSparse_ranking_pair](#vectorofsparse_ranking_pair)
  - [VectorOfSparse_ranking_pair::create](#vectorofsparse_ranking_paircreate)
  - [VectorOfSparse_ranking_pair::Keys](#vectorofsparse_ranking_pairkeys)
  - [VectorOfSparse_ranking_pair::Items](#vectorofsparse_ranking_pairitems)
  - [VectorOfSparse_ranking_pair::push_back](#vectorofsparse_ranking_pairpush_back)
  - [VectorOfSparse_ranking_pair::Add](#vectorofsparse_ranking_pairadd)
  - [VectorOfSparse_ranking_pair::Remove](#vectorofsparse_ranking_pairremove)
  - [VectorOfSparse_ranking_pair::at](#vectorofsparse_ranking_pairat)
  - [VectorOfSparse_ranking_pair::size](#vectorofsparse_ranking_pairsize)
  - [VectorOfSparse_ranking_pair::empty](#vectorofsparse_ranking_pairempty)
  - [VectorOfSparse_ranking_pair::clear](#vectorofsparse_ranking_pairclear)
  - [VectorOfSparse_ranking_pair::push_vector](#vectorofsparse_ranking_pairpush_vector)
  - [VectorOfSparse_ranking_pair::slice](#vectorofsparse_ranking_pairslice)
  - [VectorOfSparse_ranking_pair::sort](#vectorofsparse_ranking_pairsort)
  - [VectorOfSparse_ranking_pair::sort_variant](#vectorofsparse_ranking_pairsort_variant)
  - [VectorOfSparse_ranking_pair::start](#vectorofsparse_ranking_pairstart)
  - [VectorOfSparse_ranking_pair::end](#vectorofsparse_ranking_pairend)
  - [VectorOfSparse_ranking_pair::get_Item](#vectorofsparse_ranking_pairget_item)
  - [VectorOfSparse_ranking_pair::put_Item](#vectorofsparse_ranking_pairput_item)
- [VectorOfDpoint](#vectorofdpoint)
  - [VectorOfDpoint::create](#vectorofdpointcreate)
  - [VectorOfDpoint::Keys](#vectorofdpointkeys)
  - [VectorOfDpoint::Items](#vectorofdpointitems)
  - [VectorOfDpoint::push_back](#vectorofdpointpush_back)
  - [VectorOfDpoint::Add](#vectorofdpointadd)
  - [VectorOfDpoint::Remove](#vectorofdpointremove)
  - [VectorOfDpoint::at](#vectorofdpointat)
  - [VectorOfDpoint::size](#vectorofdpointsize)
  - [VectorOfDpoint::empty](#vectorofdpointempty)
  - [VectorOfDpoint::clear](#vectorofdpointclear)
  - [VectorOfDpoint::push_vector](#vectorofdpointpush_vector)
  - [VectorOfDpoint::slice](#vectorofdpointslice)
  - [VectorOfDpoint::sort](#vectorofdpointsort)
  - [VectorOfDpoint::sort_variant](#vectorofdpointsort_variant)
  - [VectorOfDpoint::start](#vectorofdpointstart)
  - [VectorOfDpoint::end](#vectorofdpointend)
  - [VectorOfDpoint::get_Item](#vectorofdpointget_item)
  - [VectorOfDpoint::put_Item](#vectorofdpointput_item)
- [VectorOfPoint](#vectorofpoint)
  - [VectorOfPoint::create](#vectorofpointcreate)
  - [VectorOfPoint::Keys](#vectorofpointkeys)
  - [VectorOfPoint::Items](#vectorofpointitems)
  - [VectorOfPoint::push_back](#vectorofpointpush_back)
  - [VectorOfPoint::Add](#vectorofpointadd)
  - [VectorOfPoint::Remove](#vectorofpointremove)
  - [VectorOfPoint::at](#vectorofpointat)
  - [VectorOfPoint::size](#vectorofpointsize)
  - [VectorOfPoint::empty](#vectorofpointempty)
  - [VectorOfPoint::clear](#vectorofpointclear)
  - [VectorOfPoint::push_vector](#vectorofpointpush_vector)
  - [VectorOfPoint::slice](#vectorofpointslice)
  - [VectorOfPoint::sort](#vectorofpointsort)
  - [VectorOfPoint::sort_variant](#vectorofpointsort_variant)
  - [VectorOfPoint::start](#vectorofpointstart)
  - [VectorOfPoint::end](#vectorofpointend)
  - [VectorOfPoint::get_Item](#vectorofpointget_item)
  - [VectorOfPoint::put_Item](#vectorofpointput_item)
- [VectorOfVectorOfDouble](#vectorofvectorofdouble)
  - [VectorOfVectorOfDouble::create](#vectorofvectorofdoublecreate)
  - [VectorOfVectorOfDouble::Keys](#vectorofvectorofdoublekeys)
  - [VectorOfVectorOfDouble::Items](#vectorofvectorofdoubleitems)
  - [VectorOfVectorOfDouble::push_back](#vectorofvectorofdoublepush_back)
  - [VectorOfVectorOfDouble::Add](#vectorofvectorofdoubleadd)
  - [VectorOfVectorOfDouble::Remove](#vectorofvectorofdoubleremove)
  - [VectorOfVectorOfDouble::at](#vectorofvectorofdoubleat)
  - [VectorOfVectorOfDouble::size](#vectorofvectorofdoublesize)
  - [VectorOfVectorOfDouble::empty](#vectorofvectorofdoubleempty)
  - [VectorOfVectorOfDouble::clear](#vectorofvectorofdoubleclear)
  - [VectorOfVectorOfDouble::push_vector](#vectorofvectorofdoublepush_vector)
  - [VectorOfVectorOfDouble::slice](#vectorofvectorofdoubleslice)
  - [VectorOfVectorOfDouble::sort](#vectorofvectorofdoublesort)
  - [VectorOfVectorOfDouble::sort_variant](#vectorofvectorofdoublesort_variant)
  - [VectorOfVectorOfDouble::start](#vectorofvectorofdoublestart)
  - [VectorOfVectorOfDouble::end](#vectorofvectorofdoubleend)
  - [VectorOfVectorOfDouble::get_Item](#vectorofvectorofdoubleget_item)
  - [VectorOfVectorOfDouble::put_Item](#vectorofvectorofdoubleput_item)
- [VectorOfMmod_rect](#vectorofmmod_rect)
  - [VectorOfMmod_rect::create](#vectorofmmod_rectcreate)
  - [VectorOfMmod_rect::Keys](#vectorofmmod_rectkeys)
  - [VectorOfMmod_rect::Items](#vectorofmmod_rectitems)
  - [VectorOfMmod_rect::push_back](#vectorofmmod_rectpush_back)
  - [VectorOfMmod_rect::Add](#vectorofmmod_rectadd)
  - [VectorOfMmod_rect::Remove](#vectorofmmod_rectremove)
  - [VectorOfMmod_rect::at](#vectorofmmod_rectat)
  - [VectorOfMmod_rect::size](#vectorofmmod_rectsize)
  - [VectorOfMmod_rect::empty](#vectorofmmod_rectempty)
  - [VectorOfMmod_rect::clear](#vectorofmmod_rectclear)
  - [VectorOfMmod_rect::push_vector](#vectorofmmod_rectpush_vector)
  - [VectorOfMmod_rect::slice](#vectorofmmod_rectslice)
  - [VectorOfMmod_rect::sort](#vectorofmmod_rectsort)
  - [VectorOfMmod_rect::sort_variant](#vectorofmmod_rectsort_variant)
  - [VectorOfMmod_rect::start](#vectorofmmod_rectstart)
  - [VectorOfMmod_rect::end](#vectorofmmod_rectend)
  - [VectorOfMmod_rect::get_Item](#vectorofmmod_rectget_item)
  - [VectorOfMmod_rect::put_Item](#vectorofmmod_rectput_item)
- [VectorOfVectorOfMmod_rect](#vectorofvectorofmmod_rect)
  - [VectorOfVectorOfMmod_rect::create](#vectorofvectorofmmod_rectcreate)
  - [VectorOfVectorOfMmod_rect::Keys](#vectorofvectorofmmod_rectkeys)
  - [VectorOfVectorOfMmod_rect::Items](#vectorofvectorofmmod_rectitems)
  - [VectorOfVectorOfMmod_rect::push_back](#vectorofvectorofmmod_rectpush_back)
  - [VectorOfVectorOfMmod_rect::Add](#vectorofvectorofmmod_rectadd)
  - [VectorOfVectorOfMmod_rect::Remove](#vectorofvectorofmmod_rectremove)
  - [VectorOfVectorOfMmod_rect::at](#vectorofvectorofmmod_rectat)
  - [VectorOfVectorOfMmod_rect::size](#vectorofvectorofmmod_rectsize)
  - [VectorOfVectorOfMmod_rect::empty](#vectorofvectorofmmod_rectempty)
  - [VectorOfVectorOfMmod_rect::clear](#vectorofvectorofmmod_rectclear)
  - [VectorOfVectorOfMmod_rect::push_vector](#vectorofvectorofmmod_rectpush_vector)
  - [VectorOfVectorOfMmod_rect::slice](#vectorofvectorofmmod_rectslice)
  - [VectorOfVectorOfMmod_rect::sort](#vectorofvectorofmmod_rectsort)
  - [VectorOfVectorOfMmod_rect::sort_variant](#vectorofvectorofmmod_rectsort_variant)
  - [VectorOfVectorOfMmod_rect::start](#vectorofvectorofmmod_rectstart)
  - [VectorOfVectorOfMmod_rect::end](#vectorofvectorofmmod_rectend)
  - [VectorOfVectorOfMmod_rect::get_Item](#vectorofvectorofmmod_rectget_item)
  - [VectorOfVectorOfMmod_rect::put_Item](#vectorofvectorofmmod_rectput_item)
- [VectorOfSimple_object_detector_com](#vectorofsimple_object_detector_com)
  - [VectorOfSimple_object_detector_com::create](#vectorofsimple_object_detector_comcreate)
  - [VectorOfSimple_object_detector_com::Keys](#vectorofsimple_object_detector_comkeys)
  - [VectorOfSimple_object_detector_com::Items](#vectorofsimple_object_detector_comitems)
  - [VectorOfSimple_object_detector_com::push_back](#vectorofsimple_object_detector_compush_back)
  - [VectorOfSimple_object_detector_com::Add](#vectorofsimple_object_detector_comadd)
  - [VectorOfSimple_object_detector_com::Remove](#vectorofsimple_object_detector_comremove)
  - [VectorOfSimple_object_detector_com::at](#vectorofsimple_object_detector_comat)
  - [VectorOfSimple_object_detector_com::size](#vectorofsimple_object_detector_comsize)
  - [VectorOfSimple_object_detector_com::empty](#vectorofsimple_object_detector_comempty)
  - [VectorOfSimple_object_detector_com::clear](#vectorofsimple_object_detector_comclear)
  - [VectorOfSimple_object_detector_com::push_vector](#vectorofsimple_object_detector_compush_vector)
  - [VectorOfSimple_object_detector_com::slice](#vectorofsimple_object_detector_comslice)
  - [VectorOfSimple_object_detector_com::sort](#vectorofsimple_object_detector_comsort)
  - [VectorOfSimple_object_detector_com::sort_variant](#vectorofsimple_object_detector_comsort_variant)
  - [VectorOfSimple_object_detector_com::start](#vectorofsimple_object_detector_comstart)
  - [VectorOfSimple_object_detector_com::end](#vectorofsimple_object_detector_comend)
  - [VectorOfSimple_object_detector_com::get_Item](#vectorofsimple_object_detector_comget_item)
  - [VectorOfSimple_object_detector_com::put_Item](#vectorofsimple_object_detector_comput_item)
- [VectorOfFhog_object_detector](#vectoroffhog_object_detector)
  - [VectorOfFhog_object_detector::create](#vectoroffhog_object_detectorcreate)
  - [VectorOfFhog_object_detector::Keys](#vectoroffhog_object_detectorkeys)
  - [VectorOfFhog_object_detector::Items](#vectoroffhog_object_detectoritems)
  - [VectorOfFhog_object_detector::push_back](#vectoroffhog_object_detectorpush_back)
  - [VectorOfFhog_object_detector::Add](#vectoroffhog_object_detectoradd)
  - [VectorOfFhog_object_detector::Remove](#vectoroffhog_object_detectorremove)
  - [VectorOfFhog_object_detector::at](#vectoroffhog_object_detectorat)
  - [VectorOfFhog_object_detector::size](#vectoroffhog_object_detectorsize)
  - [VectorOfFhog_object_detector::empty](#vectoroffhog_object_detectorempty)
  - [VectorOfFhog_object_detector::clear](#vectoroffhog_object_detectorclear)
  - [VectorOfFhog_object_detector::push_vector](#vectoroffhog_object_detectorpush_vector)
  - [VectorOfFhog_object_detector::slice](#vectoroffhog_object_detectorslice)
  - [VectorOfFhog_object_detector::sort](#vectoroffhog_object_detectorsort)
  - [VectorOfFhog_object_detector::sort_variant](#vectoroffhog_object_detectorsort_variant)
  - [VectorOfFhog_object_detector::start](#vectoroffhog_object_detectorstart)
  - [VectorOfFhog_object_detector::end](#vectoroffhog_object_detectorend)
  - [VectorOfFhog_object_detector::get_Item](#vectoroffhog_object_detectorget_item)
  - [VectorOfFhog_object_detector::put_Item](#vectoroffhog_object_detectorput_item)
- [VectorOfFunction_spec](#vectoroffunction_spec)
  - [VectorOfFunction_spec::create](#vectoroffunction_speccreate)
  - [VectorOfFunction_spec::Keys](#vectoroffunction_speckeys)
  - [VectorOfFunction_spec::Items](#vectoroffunction_specitems)
  - [VectorOfFunction_spec::push_back](#vectoroffunction_specpush_back)
  - [VectorOfFunction_spec::Add](#vectoroffunction_specadd)
  - [VectorOfFunction_spec::Remove](#vectoroffunction_specremove)
  - [VectorOfFunction_spec::at](#vectoroffunction_specat)
  - [VectorOfFunction_spec::size](#vectoroffunction_specsize)
  - [VectorOfFunction_spec::empty](#vectoroffunction_specempty)
  - [VectorOfFunction_spec::clear](#vectoroffunction_specclear)
  - [VectorOfFunction_spec::push_vector](#vectoroffunction_specpush_vector)
  - [VectorOfFunction_spec::slice](#vectoroffunction_specslice)
  - [VectorOfFunction_spec::sort](#vectoroffunction_specsort)
  - [VectorOfFunction_spec::sort_variant](#vectoroffunction_specsort_variant)
  - [VectorOfFunction_spec::start](#vectoroffunction_specstart)
  - [VectorOfFunction_spec::end](#vectoroffunction_specend)
  - [VectorOfFunction_spec::get_Item](#vectoroffunction_specget_item)
  - [VectorOfFunction_spec::put_Item](#vectoroffunction_specput_item)
- [VectorOfFunction_evaluation](#vectoroffunction_evaluation)
  - [VectorOfFunction_evaluation::create](#vectoroffunction_evaluationcreate)
  - [VectorOfFunction_evaluation::Keys](#vectoroffunction_evaluationkeys)
  - [VectorOfFunction_evaluation::Items](#vectoroffunction_evaluationitems)
  - [VectorOfFunction_evaluation::push_back](#vectoroffunction_evaluationpush_back)
  - [VectorOfFunction_evaluation::Add](#vectoroffunction_evaluationadd)
  - [VectorOfFunction_evaluation::Remove](#vectoroffunction_evaluationremove)
  - [VectorOfFunction_evaluation::at](#vectoroffunction_evaluationat)
  - [VectorOfFunction_evaluation::size](#vectoroffunction_evaluationsize)
  - [VectorOfFunction_evaluation::empty](#vectoroffunction_evaluationempty)
  - [VectorOfFunction_evaluation::clear](#vectoroffunction_evaluationclear)
  - [VectorOfFunction_evaluation::push_vector](#vectoroffunction_evaluationpush_vector)
  - [VectorOfFunction_evaluation::slice](#vectoroffunction_evaluationslice)
  - [VectorOfFunction_evaluation::sort](#vectoroffunction_evaluationsort)
  - [VectorOfFunction_evaluation::sort_variant](#vectoroffunction_evaluationsort_variant)
  - [VectorOfFunction_evaluation::start](#vectoroffunction_evaluationstart)
  - [VectorOfFunction_evaluation::end](#vectoroffunction_evaluationend)
  - [VectorOfFunction_evaluation::get_Item](#vectoroffunction_evaluationget_item)
  - [VectorOfFunction_evaluation::put_Item](#vectoroffunction_evaluationput_item)
- [VectorOfVectorOfFunction_evaluation](#vectorofvectoroffunction_evaluation)
  - [VectorOfVectorOfFunction_evaluation::create](#vectorofvectoroffunction_evaluationcreate)
  - [VectorOfVectorOfFunction_evaluation::Keys](#vectorofvectoroffunction_evaluationkeys)
  - [VectorOfVectorOfFunction_evaluation::Items](#vectorofvectoroffunction_evaluationitems)
  - [VectorOfVectorOfFunction_evaluation::push_back](#vectorofvectoroffunction_evaluationpush_back)
  - [VectorOfVectorOfFunction_evaluation::Add](#vectorofvectoroffunction_evaluationadd)
  - [VectorOfVectorOfFunction_evaluation::Remove](#vectorofvectoroffunction_evaluationremove)
  - [VectorOfVectorOfFunction_evaluation::at](#vectorofvectoroffunction_evaluationat)
  - [VectorOfVectorOfFunction_evaluation::size](#vectorofvectoroffunction_evaluationsize)
  - [VectorOfVectorOfFunction_evaluation::empty](#vectorofvectoroffunction_evaluationempty)
  - [VectorOfVectorOfFunction_evaluation::clear](#vectorofvectoroffunction_evaluationclear)
  - [VectorOfVectorOfFunction_evaluation::push_vector](#vectorofvectoroffunction_evaluationpush_vector)
  - [VectorOfVectorOfFunction_evaluation::slice](#vectorofvectoroffunction_evaluationslice)
  - [VectorOfVectorOfFunction_evaluation::sort](#vectorofvectoroffunction_evaluationsort)
  - [VectorOfVectorOfFunction_evaluation::sort_variant](#vectorofvectoroffunction_evaluationsort_variant)
  - [VectorOfVectorOfFunction_evaluation::start](#vectorofvectoroffunction_evaluationstart)
  - [VectorOfVectorOfFunction_evaluation::end](#vectorofvectoroffunction_evaluationend)
  - [VectorOfVectorOfFunction_evaluation::get_Item](#vectorofvectoroffunction_evaluationget_item)
  - [VectorOfVectorOfFunction_evaluation::put_Item](#vectorofvectoroffunction_evaluationput_item)
- [VectorOfDrectangle](#vectorofdrectangle)
  - [VectorOfDrectangle::create](#vectorofdrectanglecreate)
  - [VectorOfDrectangle::Keys](#vectorofdrectanglekeys)
  - [VectorOfDrectangle::Items](#vectorofdrectangleitems)
  - [VectorOfDrectangle::push_back](#vectorofdrectanglepush_back)
  - [VectorOfDrectangle::Add](#vectorofdrectangleadd)
  - [VectorOfDrectangle::Remove](#vectorofdrectangleremove)
  - [VectorOfDrectangle::at](#vectorofdrectangleat)
  - [VectorOfDrectangle::size](#vectorofdrectanglesize)
  - [VectorOfDrectangle::empty](#vectorofdrectangleempty)
  - [VectorOfDrectangle::clear](#vectorofdrectangleclear)
  - [VectorOfDrectangle::push_vector](#vectorofdrectanglepush_vector)
  - [VectorOfDrectangle::slice](#vectorofdrectangleslice)
  - [VectorOfDrectangle::sort](#vectorofdrectanglesort)
  - [VectorOfDrectangle::sort_variant](#vectorofdrectanglesort_variant)
  - [VectorOfDrectangle::start](#vectorofdrectanglestart)
  - [VectorOfDrectangle::end](#vectorofdrectangleend)
  - [VectorOfDrectangle::get_Item](#vectorofdrectangleget_item)
  - [VectorOfDrectangle::put_Item](#vectorofdrectangleput_item)
- [VectorOfInt](#vectorofint)
  - [VectorOfInt::create](#vectorofintcreate)
  - [VectorOfInt::Keys](#vectorofintkeys)
  - [VectorOfInt::Items](#vectorofintitems)
  - [VectorOfInt::push_back](#vectorofintpush_back)
  - [VectorOfInt::Add](#vectorofintadd)
  - [VectorOfInt::Remove](#vectorofintremove)
  - [VectorOfInt::at](#vectorofintat)
  - [VectorOfInt::size](#vectorofintsize)
  - [VectorOfInt::empty](#vectorofintempty)
  - [VectorOfInt::clear](#vectorofintclear)
  - [VectorOfInt::push_vector](#vectorofintpush_vector)
  - [VectorOfInt::slice](#vectorofintslice)
  - [VectorOfInt::sort](#vectorofintsort)
  - [VectorOfInt::sort_variant](#vectorofintsort_variant)
  - [VectorOfInt::start](#vectorofintstart)
  - [VectorOfInt::end](#vectorofintend)
  - [VectorOfInt::get_Item](#vectorofintget_item)
  - [VectorOfInt::put_Item](#vectorofintput_item)
- [VectorOfUchar](#vectorofuchar)
  - [VectorOfUchar::create](#vectorofucharcreate)
  - [VectorOfUchar::Keys](#vectorofucharkeys)
  - [VectorOfUchar::Items](#vectorofucharitems)
  - [VectorOfUchar::push_back](#vectorofucharpush_back)
  - [VectorOfUchar::Add](#vectorofucharadd)
  - [VectorOfUchar::Remove](#vectorofucharremove)
  - [VectorOfUchar::at](#vectorofucharat)
  - [VectorOfUchar::size](#vectorofucharsize)
  - [VectorOfUchar::empty](#vectorofucharempty)
  - [VectorOfUchar::clear](#vectorofucharclear)
  - [VectorOfUchar::push_vector](#vectorofucharpush_vector)
  - [VectorOfUchar::slice](#vectorofucharslice)
  - [VectorOfUchar::sort](#vectorofucharsort)
  - [VectorOfUchar::sort_variant](#vectorofucharsort_variant)
  - [VectorOfUchar::start](#vectorofucharstart)
  - [VectorOfUchar::end](#vectorofucharend)
  - [VectorOfUchar::get_Item](#vectorofucharget_item)
  - [VectorOfUchar::put_Item](#vectorofucharput_item)
- [MapOfStringAndPoint](#mapofstringandpoint)
  - [MapOfStringAndPoint::create](#mapofstringandpointcreate)
  - [MapOfStringAndPoint::Get](#mapofstringandpointget)
  - [MapOfStringAndPoint::Keys](#mapofstringandpointkeys)
  - [MapOfStringAndPoint::Items](#mapofstringandpointitems)
  - [MapOfStringAndPoint::empty](#mapofstringandpointempty)
  - [MapOfStringAndPoint::size](#mapofstringandpointsize)
  - [MapOfStringAndPoint::max_size](#mapofstringandpointmax_size)
  - [MapOfStringAndPoint::clear](#mapofstringandpointclear)
  - [MapOfStringAndPoint::Add](#mapofstringandpointadd)
  - [MapOfStringAndPoint::erase](#mapofstringandpointerase)
  - [MapOfStringAndPoint::Remove](#mapofstringandpointremove)
  - [MapOfStringAndPoint::merge](#mapofstringandpointmerge)
  - [MapOfStringAndPoint::count](#mapofstringandpointcount)
  - [MapOfStringAndPoint::contains](#mapofstringandpointcontains)
  - [MapOfStringAndPoint::has](#mapofstringandpointhas)
  - [MapOfStringAndPoint::get_Item](#mapofstringandpointget_item)
  - [MapOfStringAndPoint::put_Item](#mapofstringandpointput_item)
- [VectorOfBox](#vectorofbox)
  - [VectorOfBox::create](#vectorofboxcreate)
  - [VectorOfBox::Keys](#vectorofboxkeys)
  - [VectorOfBox::Items](#vectorofboxitems)
  - [VectorOfBox::push_back](#vectorofboxpush_back)
  - [VectorOfBox::Add](#vectorofboxadd)
  - [VectorOfBox::Remove](#vectorofboxremove)
  - [VectorOfBox::at](#vectorofboxat)
  - [VectorOfBox::size](#vectorofboxsize)
  - [VectorOfBox::empty](#vectorofboxempty)
  - [VectorOfBox::clear](#vectorofboxclear)
  - [VectorOfBox::push_vector](#vectorofboxpush_vector)
  - [VectorOfBox::slice](#vectorofboxslice)
  - [VectorOfBox::sort](#vectorofboxsort)
  - [VectorOfBox::sort_variant](#vectorofboxsort_variant)
  - [VectorOfBox::start](#vectorofboxstart)
  - [VectorOfBox::end](#vectorofboxend)
  - [VectorOfBox::get_Item](#vectorofboxget_item)
  - [VectorOfBox::put_Item](#vectorofboxput_item)
- [VectorOfImage](#vectorofimage)
  - [VectorOfImage::create](#vectorofimagecreate)
  - [VectorOfImage::Keys](#vectorofimagekeys)
  - [VectorOfImage::Items](#vectorofimageitems)
  - [VectorOfImage::push_back](#vectorofimagepush_back)
  - [VectorOfImage::Add](#vectorofimageadd)
  - [VectorOfImage::Remove](#vectorofimageremove)
  - [VectorOfImage::at](#vectorofimageat)
  - [VectorOfImage::size](#vectorofimagesize)
  - [VectorOfImage::empty](#vectorofimageempty)
  - [VectorOfImage::clear](#vectorofimageclear)
  - [VectorOfImage::push_vector](#vectorofimagepush_vector)
  - [VectorOfImage::slice](#vectorofimageslice)
  - [VectorOfImage::sort](#vectorofimagesort)
  - [VectorOfImage::sort_variant](#vectorofimagesort_variant)
  - [VectorOfImage::start](#vectorofimagestart)
  - [VectorOfImage::end](#vectorofimageend)
  - [VectorOfImage::get_Item](#vectorofimageget_item)
  - [VectorOfImage::put_Item](#vectorofimageput_item)
- [VectorOfPairOfStringAndPoint](#vectorofpairofstringandpoint)
  - [VectorOfPairOfStringAndPoint::create](#vectorofpairofstringandpointcreate)
  - [VectorOfPairOfStringAndPoint::Keys](#vectorofpairofstringandpointkeys)
  - [VectorOfPairOfStringAndPoint::Items](#vectorofpairofstringandpointitems)
  - [VectorOfPairOfStringAndPoint::push_back](#vectorofpairofstringandpointpush_back)
  - [VectorOfPairOfStringAndPoint::Add](#vectorofpairofstringandpointadd)
  - [VectorOfPairOfStringAndPoint::Remove](#vectorofpairofstringandpointremove)
  - [VectorOfPairOfStringAndPoint::at](#vectorofpairofstringandpointat)
  - [VectorOfPairOfStringAndPoint::size](#vectorofpairofstringandpointsize)
  - [VectorOfPairOfStringAndPoint::empty](#vectorofpairofstringandpointempty)
  - [VectorOfPairOfStringAndPoint::clear](#vectorofpairofstringandpointclear)
  - [VectorOfPairOfStringAndPoint::push_vector](#vectorofpairofstringandpointpush_vector)
  - [VectorOfPairOfStringAndPoint::slice](#vectorofpairofstringandpointslice)
  - [VectorOfPairOfStringAndPoint::sort](#vectorofpairofstringandpointsort)
  - [VectorOfPairOfStringAndPoint::sort_variant](#vectorofpairofstringandpointsort_variant)
  - [VectorOfPairOfStringAndPoint::start](#vectorofpairofstringandpointstart)
  - [VectorOfPairOfStringAndPoint::end](#vectorofpairofstringandpointend)
  - [VectorOfPairOfStringAndPoint::get_Item](#vectorofpairofstringandpointget_item)
  - [VectorOfPairOfStringAndPoint::put_Item](#vectorofpairofstringandpointput_item)
- [VectorOfString](#vectorofstring)
  - [VectorOfString::create](#vectorofstringcreate)
  - [VectorOfString::Keys](#vectorofstringkeys)
  - [VectorOfString::Items](#vectorofstringitems)
  - [VectorOfString::push_back](#vectorofstringpush_back)
  - [VectorOfString::Add](#vectorofstringadd)
  - [VectorOfString::Remove](#vectorofstringremove)
  - [VectorOfString::at](#vectorofstringat)
  - [VectorOfString::size](#vectorofstringsize)
  - [VectorOfString::empty](#vectorofstringempty)
  - [VectorOfString::clear](#vectorofstringclear)
  - [VectorOfString::push_vector](#vectorofstringpush_vector)
  - [VectorOfString::slice](#vectorofstringslice)
  - [VectorOfString::sort](#vectorofstringsort)
  - [VectorOfString::sort_variant](#vectorofstringsort_variant)
  - [VectorOfString::start](#vectorofstringstart)
  - [VectorOfString::end](#vectorofstringend)
  - [VectorOfString::get_Item](#vectorofstringget_item)
  - [VectorOfString::put_Item](#vectorofstringput_item)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## dlib

### dlib::cca

```cpp
dlib::cca_outputs dlib::cca( const std::vector<std::vector<std::pair<ULONG, double>>>& L,
                             const std::vector<std::vector<std::pair<ULONG, double>>>& R,
                             ULONG                                                     num_correlations,
                             ULONG                                                     extra_rank = 5,
                             ULONG                                                     q = 2,
                             double                                                    regularization = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib").cca( $L, $R, $num_correlations[, $extra_rank[, $q[, $regularization]]] ) -> retval
```

### dlib::apply_cca_transform

```cpp
dlib::SpaceVector dlib::apply_cca_transform( const dlib::Matrix&                          m,
                                             const std::vector<std::pair<ULONG, double>>& v );

AutoIt:
    _Dlib_ObjCreate("dlib").apply_cca_transform( $m, $v ) -> retval
```

### dlib::load_rgb_image

```cpp
cv::Mat dlib::load_rgb_image( const string& path );

AutoIt:
    _Dlib_ObjCreate("dlib").load_rgb_image( $path ) -> retval
```

### dlib::load_grayscale_image

```cpp
cv::Mat dlib::load_grayscale_image( const string& path );

AutoIt:
    _Dlib_ObjCreate("dlib").load_grayscale_image( $path ) -> retval
```

### dlib::save_image

```cpp
void dlib::save_image( const cv::Mat& img,
                       const string&  path );

AutoIt:
    _Dlib_ObjCreate("dlib").save_image( $img, $path ) -> None
```

### dlib::jitter_image

```cpp
std::vector<cv::Mat> dlib::jitter_image( const cv::Mat& img,
                                         size_t         num_jitters = 1,
                                         bool           disturb_colors = false );

AutoIt:
    _Dlib_ObjCreate("dlib").jitter_image( $img[, $num_jitters[, $disturb_colors]] ) -> retval
```

### dlib::get_face_chip

```cpp
cv::Mat dlib::get_face_chip( const cv::Mat&                     img,
                             const dlib::full_object_detection& face,
                             size_t                             size = 150,
                             float                              padding = 0.25 );

AutoIt:
    _Dlib_ObjCreate("dlib").get_face_chip( $img, $face[, $size[, $padding]] ) -> retval
```

### dlib::get_face_chips

```cpp
std::vector<cv::Mat> dlib::get_face_chips( const cv::Mat&                                  img,
                                           const std::vector<dlib::full_object_detection>& faces,
                                           size_t                                          size = 150,
                                           float                                           padding = 0.25 );

AutoIt:
    _Dlib_ObjCreate("dlib").get_face_chips( $img, $faces[, $size[, $padding]] ) -> retval
```

### dlib::save_face_chip

```cpp
void dlib::save_face_chip( const cv::Mat&                     img,
                           const dlib::full_object_detection& face,
                           const string&                      chip_filename,
                           size_t                             size = 150,
                           float                              padding = 0.25 );

AutoIt:
    _Dlib_ObjCreate("dlib").save_face_chip( $img, $face, $chip_filename[, $size[, $padding]] ) -> None
```

### dlib::save_face_chips

```cpp
void dlib::save_face_chips( const cv::Mat&                                  img,
                            const std::vector<dlib::full_object_detection>& faces,
                            const string&                                   chip_filename,
                            size_t                                          size = 150,
                            float                                           padding = 0.25 );

AutoIt:
    _Dlib_ObjCreate("dlib").save_face_chips( $img, $faces, $chip_filename[, $size[, $padding]] ) -> None
```

### dlib::chinese_whispers_clustering

```cpp
std::vector<ULONG> dlib::chinese_whispers_clustering( std::vector<dlib::SpaceVector> descriptors,
                                                      float                          threshold );

AutoIt:
    _Dlib_ObjCreate("dlib").chinese_whispers_clustering( $descriptors, $threshold ) -> retval
```

### dlib::chinese_whispers

```cpp
std::vector<ULONG> dlib::chinese_whispers( std::vector<dlib::SpaceVector> edges );

AutoIt:
    _Dlib_ObjCreate("dlib").chinese_whispers( $edges ) -> retval
```

### dlib::find_max_global

```cpp
void dlib::find_max_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            std::vector<bool>&   is_integer_variable,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );

AutoIt:
    _Dlib_ObjCreate("dlib").find_max_global( $f, $bound1, $bound2, $is_integer_variable, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

```cpp
void dlib::find_max_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );

AutoIt:
    _Dlib_ObjCreate("dlib").find_max_global( $f, $bound1, $bound2, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

### dlib::find_min_global

```cpp
void dlib::find_min_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            std::vector<bool>&   is_integer_variable,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );

AutoIt:
    _Dlib_ObjCreate("dlib").find_min_global( $f, $bound1, $bound2, $is_integer_variable, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

```cpp
void dlib::find_min_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );

AutoIt:
    _Dlib_ObjCreate("dlib").find_min_global( $f, $bound1, $bound2, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

### dlib::find_candidate_object_locations

```cpp
void dlib::find_candidate_object_locations( cv::Mat&                         image,
                                            std::vector<dlib::rectangle>&    rects,
                                            std::tuple<double, double, long> kvals = std::tuple<double, double, long>(50, 200, 3),
                                            ULONG                            min_size = 20,
                                            ULONG                            max_merging_iterations = 50 );

AutoIt:
    _Dlib_ObjCreate("dlib").find_candidate_object_locations( $image[, $kvals[, $min_size[, $max_merging_iterations[, $rects]]]] ) -> $rects
```

### dlib::max_cost_assignment

```cpp
std::vector<long> dlib::max_cost_assignment( const dlib::Matrix& cost );

AutoIt:
    _Dlib_ObjCreate("dlib").max_cost_assignment( $cost ) -> retval
```

### dlib::assignment_cost

```cpp
double dlib::assignment_cost( const dlib::Matrix& cost,
                              std::vector<long>&  assignment );

AutoIt:
    _Dlib_ObjCreate("dlib").assignment_cost( $cost, $assignment ) -> retval
```

### dlib::make_sparse_vector

```cpp
void dlib::make_sparse_vector( std::vector<std::pair<ULONG, double>>& v );

AutoIt:
    _Dlib_ObjCreate("dlib").make_sparse_vector( [$v] ) -> $v
```

```cpp
void dlib::make_sparse_vector( std::vector<std::vector<std::pair<ULONG, double>>>& v );

AutoIt:
    _Dlib_ObjCreate("dlib").make_sparse_vector( [$v] ) -> $v
```

### dlib::save_libsvm_formatted_data

```cpp
void dlib::save_libsvm_formatted_data( const string&                                             file_name,
                                       const std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                       const std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").save_libsvm_formatted_data( $file_name, $samples, $labels ) -> None
```

### dlib::hit_enter_to_continue

```cpp
void dlib::hit_enter_to_continue();

AutoIt:
    _Dlib_ObjCreate("dlib").hit_enter_to_continue() -> None
```

### dlib::train_sequence_segmenter

```cpp
dlib::segmenter_type dlib::train_sequence_segmenter( const std::vector<std::vector<dlib::SpaceVector>>&       samples,
                                                     const std::vector<std::vector<std::pair<ULONG, ULONG>>>& segments,
                                                     dlib::segmenter_params                                   params = segmenter_params() );

AutoIt:
    _Dlib_ObjCreate("dlib").train_sequence_segmenter( $samples, $segments[, $params] ) -> retval
```

```cpp
dlib::segmenter_type dlib::train_sequence_segmenter( const std::vector<std::vector<std::vector<std::pair<ULONG, double>>>>& samples,
                                                     const std::vector<std::vector<std::pair<ULONG, ULONG>>>&               segments,
                                                     dlib::segmenter_params                                                 params = segmenter_params() );

AutoIt:
    _Dlib_ObjCreate("dlib").train_sequence_segmenter( $samples, $segments[, $params] ) -> retval
```

### dlib::test_sequence_segmenter

```cpp
dlib::segmenter_test dlib::test_sequence_segmenter( const dlib::segmenter_type&                              segmenter,
                                                    const std::vector<std::vector<dlib::SpaceVector>>&       samples,
                                                    const std::vector<std::vector<std::pair<ULONG, ULONG>>>& segments );

AutoIt:
    _Dlib_ObjCreate("dlib").test_sequence_segmenter( $segmenter, $samples, $segments ) -> retval
```

```cpp
dlib::segmenter_test dlib::test_sequence_segmenter( const dlib::segmenter_type&                                            segmenter,
                                                    const std::vector<std::vector<std::vector<std::pair<ULONG, double>>>>& samples,
                                                    const std::vector<std::vector<std::pair<ULONG, ULONG>>>&               segments );

AutoIt:
    _Dlib_ObjCreate("dlib").test_sequence_segmenter( $segmenter, $samples, $segments ) -> retval
```

### dlib::cross_validate_sequence_segmenter

```cpp
dlib::segmenter_test dlib::cross_validate_sequence_segmenter( const std::vector<std::vector<dlib::SpaceVector>>&       samples,
                                                              const std::vector<std::vector<std::pair<ULONG, ULONG>>>& segments,
                                                              long                                                     folds,
                                                              dlib::segmenter_params                                   params = segmenter_params() );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_sequence_segmenter( $samples, $segments, $folds[, $params] ) -> retval
```

```cpp
dlib::segmenter_test dlib::cross_validate_sequence_segmenter( const std::vector<std::vector<std::vector<std::pair<ULONG, double>>>>& samples,
                                                              const std::vector<std::vector<std::pair<ULONG, ULONG>>>&               segments,
                                                              long                                                                   folds,
                                                              dlib::segmenter_params                                                 params = segmenter_params() );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_sequence_segmenter( $samples, $segments, $folds[, $params] ) -> retval
```

### dlib::train_shape_predictor

```cpp
void dlib::train_shape_predictor( const string&                                 dataset_filename,
                                  const string&                                 predictor_output_filename,
                                  const dlib::shape_predictor_training_options& options );

AutoIt:
    _Dlib_ObjCreate("dlib").train_shape_predictor( $dataset_filename, $predictor_output_filename, $options ) -> None
```

```cpp
dlib::shape_predictor dlib::train_shape_predictor( std::vector<cv::Mat>&                                  images,
                                                   std::vector<std::vector<dlib::full_object_detection>>& detections,
                                                   dlib::shape_predictor_training_options&                options );

AutoIt:
    _Dlib_ObjCreate("dlib").train_shape_predictor( $images, $detections, $options ) -> retval
```

### dlib::train_simple_object_detector

```cpp
void dlib::train_simple_object_detector( const string&                                        dataset_filename,
                                         const string&                                        detector_output_filename,
                                         const dlib::simple_object_detector_training_options& options );

AutoIt:
    _Dlib_ObjCreate("dlib").train_simple_object_detector( $dataset_filename, $detector_output_filename, $options ) -> None
```

```cpp
dlib::simple_object_detector_com dlib::train_simple_object_detector( const std::vector<cv::Mat>&                          images,
                                                                     std::vector<std::vector<dlib::rectangle>>&           boxes,
                                                                     const dlib::simple_object_detector_training_options& options );

AutoIt:
    _Dlib_ObjCreate("dlib").train_simple_object_detector( $images, $boxes, $options ) -> retval
```

### dlib::test_simple_object_detector

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const string& dataset_filename,
                                                             const string& detector_filename,
                                                             const int     upsampling_amount = -1 );

AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $dataset_filename, $detector_filename[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const string&               dataset_filename,
                                                             dlib::fhog_object_detector& detector,
                                                             const int                   upsampling_amount = -1 );

AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $dataset_filename, $detector[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const string&                     dataset_filename,
                                                             dlib::simple_object_detector_com& detector,
                                                             const int                         upsampling_amount = -1 );

AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $dataset_filename, $detector[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::vector<cv::Mat>&                images,
                                                             std::vector<std::vector<dlib::rectangle>>& boxes,
                                                             dlib::fhog_object_detector&                detector,
                                                             const int                                  upsampling_amount = -1 );

AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $images, $boxes, $detector[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::vector<cv::Mat>&                images,
                                                             std::vector<std::vector<dlib::rectangle>>& boxes,
                                                             dlib::simple_object_detector_com&          detector,
                                                             const int                                  upsampling_amount = -1 );

AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $images, $boxes, $detector[, $upsampling_amount] ) -> retval
```

### dlib::solve_structural_svm_problem

```cpp
dlib::SpaceVector dlib::solve_structural_svm_problem( dlib::simple_structural_svm_problem& problem );

AutoIt:
    _Dlib_ObjCreate("dlib").solve_structural_svm_problem( $problem ) -> retval
```

### dlib::max_index_plus_one

```cpp
ULONG dlib::max_index_plus_one( std::vector<std::pair<ULONG, double>>& v );

AutoIt:
    _Dlib_ObjCreate("dlib").max_index_plus_one( $v ) -> retval
```

### dlib::dnn_prefer_fastest_algorithms

```cpp
bool dlib::dnn_prefer_fastest_algorithms();

AutoIt:
    _Dlib_ObjCreate("dlib").dnn_prefer_fastest_algorithms() -> retval
```

### dlib::set_dnn_prefer_fastest_algorithms

```cpp
void dlib::set_dnn_prefer_fastest_algorithms();

AutoIt:
    _Dlib_ObjCreate("dlib").set_dnn_prefer_fastest_algorithms() -> None
```

### dlib::set_dnn_prefer_smallest_algorithms

```cpp
void dlib::set_dnn_prefer_smallest_algorithms();

AutoIt:
    _Dlib_ObjCreate("dlib").set_dnn_prefer_smallest_algorithms() -> None
```

### dlib::auto_train_rbf_classifier

```cpp
dlib::_normalized_decision_function_radial_basis dlib::auto_train_rbf_classifier( std::vector<dlib::SpaceVector>& x,
                                                                                  std::vector<double>&            y,
                                                                                  double                          max_runtime_seconds,
                                                                                  bool                            be_verbose = true );

AutoIt:
    _Dlib_ObjCreate("dlib").auto_train_rbf_classifier( $x, $y, $max_runtime_seconds[, $be_verbose] ) -> retval
```

```cpp
dlib::_normalized_decision_function_radial_basis dlib::auto_train_rbf_classifier( cv::Mat&             x,
                                                                                  std::vector<double>& y,
                                                                                  double               max_runtime_seconds,
                                                                                  bool                 be_verbose = true );

AutoIt:
    _Dlib_ObjCreate("dlib").auto_train_rbf_classifier( $x, $y, $max_runtime_seconds[, $be_verbose] ) -> retval
```

### dlib::reduce

```cpp
dlib::_normalized_decision_function_radial_basis dlib::reduce( dlib::_normalized_decision_function_radial_basis& df,
                                                               std::vector<dlib::SpaceVector>&                   x,
                                                               long                                              num_basis_vectors,
                                                               double                                            eps = 1e-3 );

AutoIt:
    _Dlib_ObjCreate("dlib").reduce( $df, $x, $num_basis_vectors[, $eps] ) -> retval
```

```cpp
dlib::_normalized_decision_function_radial_basis dlib::reduce( dlib::_normalized_decision_function_radial_basis& df,
                                                               cv::Mat&                                          x,
                                                               long                                              num_basis_vectors,
                                                               double                                            eps = 1e-3 );

AutoIt:
    _Dlib_ObjCreate("dlib").reduce( $df, $x, $num_basis_vectors[, $eps] ) -> retval
```

### dlib::test_binary_decision_function

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_normalized_decision_function_radial_basis& dec_funct,
                                                       std::vector<dlib::SpaceVector>&                   samples,
                                                       std::vector<double>&                              labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_normalized_decision_function_radial_basis& dec_funct,
                                                       cv::Mat&                                          samples,
                                                       std::vector<double>&                              labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_linear& dec_funct,
                                                       std::vector<dlib::SpaceVector>&  samples,
                                                       std::vector<double>&             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_linear& dec_funct,
                                                       cv::Mat&                         samples,
                                                       std::vector<double>&             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_linear&             dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_radial_basis& dec_funct,
                                                       std::vector<dlib::SpaceVector>&        samples,
                                                       std::vector<double>&                   labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_radial_basis& dec_funct,
                                                       cv::Mat&                               samples,
                                                       std::vector<double>&                   labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_radial_basis&       dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_polynomial& dec_funct,
                                                       std::vector<dlib::SpaceVector>&      samples,
                                                       std::vector<double>&                 labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_polynomial& dec_funct,
                                                       cv::Mat&                             samples,
                                                       std::vector<double>&                 labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_polynomial&         dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                       std::vector<dlib::SpaceVector>&                  samples,
                                                       std::vector<double>&                             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                       cv::Mat&                                         samples,
                                                       std::vector<double>&                             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_histogram_intersection& dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>&     samples,
                                                       std::vector<double>&                                    labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sigmoid& dec_funct,
                                                       std::vector<dlib::SpaceVector>&   samples,
                                                       std::vector<double>&              labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sigmoid& dec_funct,
                                                       cv::Mat&                          samples,
                                                       std::vector<double>&              labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_sigmoid&            dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

### dlib::test_regression_function

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_linear& dec_funct,
                                                      std::vector<dlib::SpaceVector>&  samples,
                                                      std::vector<double>&             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_linear& dec_funct,
                                                      cv::Mat&                         samples,
                                                      std::vector<double>&             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_linear&             dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_radial_basis& dec_funct,
                                                      std::vector<dlib::SpaceVector>&        samples,
                                                      std::vector<double>&                   labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_radial_basis& dec_funct,
                                                      cv::Mat&                               samples,
                                                      std::vector<double>&                   labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_radial_basis&       dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_polynomial& dec_funct,
                                                      std::vector<dlib::SpaceVector>&      samples,
                                                      std::vector<double>&                 labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_polynomial& dec_funct,
                                                      cv::Mat&                             samples,
                                                      std::vector<double>&                 labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_polynomial&         dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                      std::vector<dlib::SpaceVector>&                  samples,
                                                      std::vector<double>&                             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                      cv::Mat&                                         samples,
                                                      std::vector<double>&                             labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_histogram_intersection& dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>&     samples,
                                                      std::vector<double>&                                    labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sigmoid& dec_funct,
                                                      std::vector<dlib::SpaceVector>&   samples,
                                                      std::vector<double>&              labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sigmoid& dec_funct,
                                                      cv::Mat&                          samples,
                                                      std::vector<double>&              labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_sigmoid&            dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

### dlib::test_ranking_function

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_linear&     dec_funct,
                                                std::vector<dlib::vec_ranking_pair>& samples );

AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $samples ) -> retval
```

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_linear& dec_funct,
                                                dlib::vec_ranking_pair&          sample );

AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $sample ) -> retval
```

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_sparse_linear& dec_funct,
                                                std::vector<dlib::sparse_ranking_pair>& samples );

AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $samples ) -> retval
```

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_sparse_linear& dec_funct,
                                                dlib::sparse_ranking_pair&              sample );

AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $sample ) -> retval
```

### dlib::variant

```cpp
_variant_t dlib::variant( void* ptr );

AutoIt:
    _Dlib_ObjCreate("dlib").variant( $ptr ) -> retval
```

### dlib::signed_distance_to_line

```cpp
double dlib::signed_distance_to_line( dlib::line   l,
                                      dlib::dpoint p );

AutoIt:
    _Dlib_ObjCreate("dlib").signed_distance_to_line( $l, $p ) -> retval
```

```cpp
double dlib::signed_distance_to_line( dlib::line  l,
                                      dlib::point p );

AutoIt:
    _Dlib_ObjCreate("dlib").signed_distance_to_line( $l, $p ) -> retval
```

### dlib::distance_to_line

```cpp
double dlib::distance_to_line( dlib::line   l,
                               dlib::dpoint p );

AutoIt:
    _Dlib_ObjCreate("dlib").distance_to_line( $l, $p ) -> retval
```

```cpp
double dlib::distance_to_line( dlib::line  l,
                               dlib::point p );

AutoIt:
    _Dlib_ObjCreate("dlib").distance_to_line( $l, $p ) -> retval
```

### dlib::intersect

```cpp
dlib::dpoint dlib::intersect( dlib::line a,
                              dlib::line b );

AutoIt:
    _Dlib_ObjCreate("dlib").intersect( $a, $b ) -> retval
```

### dlib::angle_between_lines

```cpp
double dlib::angle_between_lines( dlib::line a,
                                  dlib::line b );

AutoIt:
    _Dlib_ObjCreate("dlib").angle_between_lines( $a, $b ) -> retval
```

### dlib::count_points_on_side_of_line

```cpp
double dlib::count_points_on_side_of_line( dlib::line                l,
                                           dlib::dpoint              reference_point,
                                           std::vector<dlib::dpoint> pts,
                                           double                    dist_thresh_min = 0,
                                           double                    dist_thresh_max = std::numeric_limits<double>::infinity() );

AutoIt:
    _Dlib_ObjCreate("dlib").count_points_on_side_of_line( $l, $reference_point, $pts[, $dist_thresh_min[, $dist_thresh_max]] ) -> retval
```

```cpp
double dlib::count_points_on_side_of_line( dlib::line               l,
                                           dlib::dpoint             reference_point,
                                           std::vector<dlib::point> pts,
                                           double                   dist_thresh_min = 0,
                                           double                   dist_thresh_max = std::numeric_limits<double>::infinity() );

AutoIt:
    _Dlib_ObjCreate("dlib").count_points_on_side_of_line( $l, $reference_point, $pts[, $dist_thresh_min[, $dist_thresh_max]] ) -> retval
```

### dlib::count_points_between_lines

```cpp
double dlib::count_points_between_lines( dlib::line                l1,
                                         dlib::line                l2,
                                         dlib::dpoint              reference_point,
                                         std::vector<dlib::dpoint> pts );

AutoIt:
    _Dlib_ObjCreate("dlib").count_points_between_lines( $l1, $l2, $reference_point, $pts ) -> retval
```

```cpp
double dlib::count_points_between_lines( dlib::line               l1,
                                         dlib::line               l2,
                                         dlib::dpoint             reference_point,
                                         std::vector<dlib::point> pts );

AutoIt:
    _Dlib_ObjCreate("dlib").count_points_between_lines( $l1, $l2, $reference_point, $pts ) -> retval
```

### dlib::dot

```cpp
double dlib::dot( dlib::Matrix& a,
                  dlib::Matrix& b );

AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

```cpp
double dlib::dot( dlib::SpaceVector& a,
                  dlib::SpaceVector& b );

AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

```cpp
double dlib::dot( dlib::dpoint& a,
                  dlib::dpoint& b );

AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

```cpp
double dlib::dot( dlib::point& a,
                  dlib::point& b );

AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

### dlib::get_frontal_face_detector

```cpp
dlib::fhog_object_detector dlib::get_frontal_face_detector();

AutoIt:
    _Dlib_ObjCreate("dlib").get_frontal_face_detector() -> retval
```

### dlib::num_separable_filters

```cpp
ULONG dlib::num_separable_filters( dlib::fhog_object_detector& detector );

AutoIt:
    _Dlib_ObjCreate("dlib").num_separable_filters( $detector ) -> retval
```

```cpp
ULONG dlib::num_separable_filters( dlib::simple_object_detector_com& detector );

AutoIt:
    _Dlib_ObjCreate("dlib").num_separable_filters( $detector ) -> retval
```

### dlib::threshold_filter_singular_values

```cpp
dlib::fhog_object_detector dlib::threshold_filter_singular_values( dlib::fhog_object_detector& detector,
                                                                   double                      thresh,
                                                                   ULONG                       weight_index = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib").threshold_filter_singular_values( $detector, $thresh[, $weight_index] ) -> retval
```

```cpp
dlib::simple_object_detector_com dlib::threshold_filter_singular_values( dlib::simple_object_detector_com& detector,
                                                                         double                            thresh,
                                                                         ULONG                             weight_index = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib").threshold_filter_singular_values( $detector, $thresh[, $weight_index] ) -> retval
```

### dlib::load_libsvm_formatted_data

```cpp
void dlib::load_libsvm_formatted_data( string&                                             file_name,
                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                       std::vector<double>&                                labels );

AutoIt:
    _Dlib_ObjCreate("dlib").load_libsvm_formatted_data( $file_name[, $samples[, $labels]] ) -> $samples, $labels
```

### dlib::count_steps_without_decrease

```cpp
size_t dlib::count_steps_without_decrease( std::vector<double>& time_series,
                                           double               probability_of_decrease = 0.51 );

AutoIt:
    _Dlib_ObjCreate("dlib").count_steps_without_decrease( $time_series[, $probability_of_decrease] ) -> retval
```

### dlib::count_steps_without_decrease_robust

```cpp
size_t dlib::count_steps_without_decrease_robust( std::vector<double>& time_series,
                                                  double               probability_of_decrease = 0.51,
                                                  double               quantile_discard = 0.1 );

AutoIt:
    _Dlib_ObjCreate("dlib").count_steps_without_decrease_robust( $time_series[, $probability_of_decrease[, $quantile_discard]] ) -> retval
```

### dlib::probability_that_sequence_is_increasing

```cpp
double dlib::probability_that_sequence_is_increasing( std::vector<double>& time_series,
                                                      double               thresh = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib").probability_that_sequence_is_increasing( $time_series[, $thresh] ) -> retval
```

### dlib::find_optimal_rect_filter

```cpp
dlib::rect_filter dlib::find_optimal_rect_filter( std::vector<dlib::rectangle> rects,
                                                  double                       smoothness = 1 );

AutoIt:
    _Dlib_ObjCreate("dlib").find_optimal_rect_filter( $rects[, $smoothness] ) -> retval
```

### dlib::translate_rect

```cpp
dlib::rectangle dlib::translate_rect( dlib::rectangle rect,
                                      dlib::point     p );

AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

```cpp
dlib::rectangle dlib::translate_rect( dlib::rectangle rect,
                                      dlib::dpoint    p );

AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

```cpp
dlib::drectangle dlib::translate_rect( dlib::drectangle rect,
                                       dlib::point      p );

AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

```cpp
dlib::drectangle dlib::translate_rect( dlib::drectangle rect,
                                       dlib::dpoint     p );

AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

### dlib::shrink_rect

```cpp
dlib::rectangle dlib::shrink_rect( dlib::rectangle rect,
                                   long            num );

AutoIt:
    _Dlib_ObjCreate("dlib").shrink_rect( $rect, $num ) -> retval
```

```cpp
dlib::drectangle dlib::shrink_rect( dlib::drectangle rect,
                                    double           num );

AutoIt:
    _Dlib_ObjCreate("dlib").shrink_rect( $rect, $num ) -> retval
```

### dlib::scale_rect

```cpp
dlib::rectangle dlib::scale_rect( dlib::rectangle rect,
                                  double          scale );

AutoIt:
    _Dlib_ObjCreate("dlib").scale_rect( $rect, $scale ) -> retval
```

```cpp
dlib::drectangle dlib::scale_rect( dlib::drectangle rect,
                                   double           scale );

AutoIt:
    _Dlib_ObjCreate("dlib").scale_rect( $rect, $scale ) -> retval
```

### dlib::centered_rect

```cpp
dlib::rectangle dlib::centered_rect( dlib::point p,
                                     ULONG       width,
                                     ULONG       height );

AutoIt:
    _Dlib_ObjCreate("dlib").centered_rect( $p, $width, $height ) -> retval
```

```cpp
dlib::rectangle dlib::centered_rect( dlib::rectangle rect,
                                     ULONG           width,
                                     ULONG           height );

AutoIt:
    _Dlib_ObjCreate("dlib").centered_rect( $rect, $width, $height ) -> retval
```

```cpp
dlib::rectangle dlib::centered_rect( long  x,
                                     long  y,
                                     ULONG width,
                                     ULONG height );

AutoIt:
    _Dlib_ObjCreate("dlib").centered_rect( $x, $y, $width, $height ) -> retval
```

### dlib::center

```cpp
dlib::point dlib::center( dlib::rectangle rect );

AutoIt:
    _Dlib_ObjCreate("dlib").center( $rect ) -> retval
```

```cpp
dlib::dpoint dlib::center( dlib::drectangle rect );

AutoIt:
    _Dlib_ObjCreate("dlib").center( $rect ) -> retval
```

### dlib::centered_rects

```cpp
std::vector<dlib::rectangle> dlib::centered_rects( std::vector<dlib::point> pts,
                                                   ULONG                    width,
                                                   ULONG                    height );

AutoIt:
    _Dlib_ObjCreate("dlib").centered_rects( $pts, $width, $height ) -> retval
```

### dlib::centered_drect

```cpp
dlib::drectangle dlib::centered_drect( dlib::dpoint p,
                                       double       width,
                                       double       height );

AutoIt:
    _Dlib_ObjCreate("dlib").centered_drect( $p, $width, $height ) -> retval
```

```cpp
dlib::drectangle dlib::centered_drect( dlib::drectangle rect,
                                       double           width,
                                       double           height );

AutoIt:
    _Dlib_ObjCreate("dlib").centered_drect( $rect, $width, $height ) -> retval
```

### dlib::test_shape_predictor

```cpp
double dlib::test_shape_predictor( string dataset_filename,
                                   string predictor_filename );

AutoIt:
    _Dlib_ObjCreate("dlib").test_shape_predictor( $dataset_filename, $predictor_filename ) -> retval
```

```cpp
double dlib::test_shape_predictor( std::vector<cv::Mat>&                                  images,
                                   std::vector<std::vector<dlib::full_object_detection>>& detections,
                                   std::vector<std::vector<double>>&                      scales,
                                   dlib::shape_predictor&                                 predictor );

AutoIt:
    _Dlib_ObjCreate("dlib").test_shape_predictor( $images, $detections, $scales, $predictor ) -> retval
```

```cpp
double dlib::test_shape_predictor( std::vector<cv::Mat>&                                  images,
                                   std::vector<std::vector<dlib::full_object_detection>>& detections,
                                   dlib::shape_predictor&                                 predictor,
                                   std::vector<std::vector<double>>&                      scales = vector_vector_double() );

AutoIt:
    _Dlib_ObjCreate("dlib").test_shape_predictor( $images, $detections, $predictor[, $scales] ) -> retval
```

### dlib::cross_validate_trainer

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_radial_basis samples,
                                                std::vector<dlib::SpaceVector>   x,
                                                std::vector<double>              y,
                                                ULONG                            folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_sparse_radial_basis            samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_histogram_intersection samples,
                                                std::vector<dlib::SpaceVector>             x,
                                                std::vector<double>                        y,
                                                ULONG                                      folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_sparse_histogram_intersection  samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_linear     samples,
                                                std::vector<dlib::SpaceVector> x,
                                                std::vector<double>            y,
                                                ULONG                          folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_sparse_linear                  samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_radial_basis samples,
                                                std::vector<dlib::SpaceVector> x,
                                                std::vector<double>            y,
                                                ULONG                          folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_sparse_radial_basis              samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_histogram_intersection samples,
                                                std::vector<dlib::SpaceVector>           x,
                                                std::vector<double>                      y,
                                                ULONG                                    folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_sparse_histogram_intersection    samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_linear       samples,
                                                std::vector<dlib::SpaceVector> x,
                                                std::vector<double>            y,
                                                ULONG                          folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_sparse_linear                    samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

### dlib::cross_validate_trainer_threaded

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_radial_basis samples,
                                                         std::vector<dlib::SpaceVector>   x,
                                                         std::vector<double>              y,
                                                         ULONG                            folds,
                                                         ULONG                            num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_sparse_radial_basis            samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_histogram_intersection samples,
                                                         std::vector<dlib::SpaceVector>             x,
                                                         std::vector<double>                        y,
                                                         ULONG                                      folds,
                                                         ULONG                                      num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_sparse_histogram_intersection  samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_linear     samples,
                                                         std::vector<dlib::SpaceVector> x,
                                                         std::vector<double>            y,
                                                         ULONG                          folds,
                                                         ULONG                          num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_sparse_linear                  samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_radial_basis samples,
                                                         std::vector<dlib::SpaceVector> x,
                                                         std::vector<double>            y,
                                                         ULONG                          folds,
                                                         ULONG                          num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_sparse_radial_basis              samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_histogram_intersection samples,
                                                         std::vector<dlib::SpaceVector>           x,
                                                         std::vector<double>                      y,
                                                         ULONG                                    folds,
                                                         ULONG                                    num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_sparse_histogram_intersection    samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_linear       samples,
                                                         std::vector<dlib::SpaceVector> x,
                                                         std::vector<double>            y,
                                                         ULONG                          folds,
                                                         ULONG                          num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_sparse_linear                    samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

### dlib::cross_validate_ranking_trainer

```cpp
dlib::ranking_test dlib::cross_validate_ranking_trainer( dlib::vec_svm_rank_trainer          trainer,
                                                         std::vector<dlib::vec_ranking_pair> samples,
                                                         ULONG                               folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_ranking_trainer( $trainer, $samples, $folds ) -> retval
```

```cpp
dlib::ranking_test dlib::cross_validate_ranking_trainer( dlib::svm_rank_trainer_sparse          trainer,
                                                         std::vector<dlib::sparse_ranking_pair> samples,
                                                         ULONG                                  folds );

AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_ranking_trainer( $trainer, $samples, $folds ) -> retval
```

### dlib::inv

```cpp
dlib::point_transform_projective dlib::inv( dlib::point_transform_projective& trans );

AutoIt:
    _Dlib_ObjCreate("dlib").inv( $trans ) -> retval
```

### dlib::find_projective_transform

```cpp
dlib::point_transform_projective dlib::find_projective_transform( std::vector<dlib::dpoint>& from_points,
                                                                  std::vector<dlib::dpoint>& to_points );

AutoIt:
    _Dlib_ObjCreate("dlib").find_projective_transform( $from_points, $to_points ) -> retval
```

```cpp
dlib::point_transform_projective dlib::find_projective_transform( dlib::Matrix& from_points,
                                                                  dlib::Matrix& to_points );

AutoIt:
    _Dlib_ObjCreate("dlib").find_projective_transform( $from_points, $to_points ) -> retval
```

```cpp
dlib::point_transform_projective dlib::find_projective_transform( cv::Mat& from_points,
                                                                  cv::Mat& to_points );

AutoIt:
    _Dlib_ObjCreate("dlib").find_projective_transform( $from_points, $to_points ) -> retval
```

### dlib::polygon_area

```cpp
double dlib::polygon_area( std::vector<dlib::dpoint>& pts );

AutoIt:
    _Dlib_ObjCreate("dlib").polygon_area( $pts ) -> retval
```

### dlib::length

```cpp
double dlib::length( dlib::dpoint& p );

AutoIt:
    _Dlib_ObjCreate("dlib").length( $p ) -> retval
```

```cpp
double dlib::length( dlib::point& p );

AutoIt:
    _Dlib_ObjCreate("dlib").length( $p ) -> retval
```

## dlib::binary_test

### dlib::binary_test::create

```cpp
static dlib::binary_test dlib::binary_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.binary_test").create() -> <dlib.binary_test object>
```

```cpp
static dlib::binary_test dlib::binary_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.binary_test").create() -> <dlib.binary_test object>
```

### dlib::binary_test::ToString

```cpp
string dlib::binary_test::ToString() const;

AutoIt:
    $obinary_test.ToString() -> retval
```

## dlib::regression_test

### dlib::regression_test::create

```cpp
static dlib::regression_test dlib::regression_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.regression_test").create() -> <dlib.regression_test object>
```

```cpp
static dlib::regression_test dlib::regression_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.regression_test").create() -> <dlib.regression_test object>
```

### dlib::regression_test::ToString

```cpp
string dlib::regression_test::ToString() const;

AutoIt:
    $oregression_test.ToString() -> retval
```

## dlib::ranking_test

### dlib::ranking_test::create

```cpp
static dlib::ranking_test dlib::ranking_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.ranking_test").create() -> <dlib.ranking_test object>
```

```cpp
static dlib::ranking_test dlib::ranking_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.ranking_test").create() -> <dlib.ranking_test object>
```

### dlib::ranking_test::ToString

```cpp
string dlib::ranking_test::ToString() const;

AutoIt:
    $oranking_test.ToString() -> retval
```

## dlib::cca_outputs

### dlib::cca_outputs::create

```cpp
static dlib::cca_outputs dlib::cca_outputs::create();

AutoIt:
    _Dlib_ObjCreate("dlib.cca_outputs").create() -> <dlib.cca_outputs object>
```

## dlib::cnn_face_detection_model_v1

### dlib::cnn_face_detection_model_v1::create

```cpp
static dlib::cnn_face_detection_model_v1 dlib::cnn_face_detection_model_v1::create( const string& model_filename );

AutoIt:
    _Dlib_ObjCreate("dlib.cnn_face_detection_model_v1").create( $model_filename ) -> <dlib.cnn_face_detection_model_v1 object>
```

### dlib::cnn_face_detection_model_v1::detect

```cpp
std::vector<dlib::mmod_rect> dlib::cnn_face_detection_model_v1::detect( const cv::Mat& img,
                                                                        const int      upsample_num_times = 0 );

AutoIt:
    $ocnn_face_detection_model_v1.detect( $img[, $upsample_num_times] ) -> retval
```

### dlib::cnn_face_detection_model_v1::get_call

```cpp
std::vector<dlib::mmod_rect> dlib::cnn_face_detection_model_v1::get_call( const cv::Mat& img,
                                                                          const int      upsample_num_times = 0 );

AutoIt:
    $ocnn_face_detection_model_v1.call( $img[, $upsample_num_times] ) -> retval
    dlib.cnn_face_detection_model_v1( $img[, $upsample_num_times] ) -> retval
```

```cpp
std::vector<std::vector<dlib::mmod_rect>> dlib::cnn_face_detection_model_v1::get_call( const std::vector<cv::Mat>& imgs,
                                                                                       const int                   upsample_num_times = 0,
                                                                                       const int                   batch_size = 128 );

AutoIt:
    $ocnn_face_detection_model_v1.call( $imgs[, $upsample_num_times[, $batch_size]] ) -> retval
    dlib.cnn_face_detection_model_v1( $imgs[, $upsample_num_times[, $batch_size]] ) -> retval
```

### dlib::cnn_face_detection_model_v1::detect_multi

```cpp
std::vector<std::vector<dlib::mmod_rect>> dlib::cnn_face_detection_model_v1::detect_multi( const std::vector<cv::Mat>& imgs,
                                                                                           const int                   upsample_num_times = 0,
                                                                                           const int                   batch_size = 128 );

AutoIt:
    $ocnn_face_detection_model_v1.detect_multi( $imgs[, $upsample_num_times[, $batch_size]] ) -> retval
```

## dlib::face_recognition_model_v1

### dlib::face_recognition_model_v1::create

```cpp
static dlib::face_recognition_model_v1 dlib::face_recognition_model_v1::create( const string& model_filename );

AutoIt:
    _Dlib_ObjCreate("dlib.face_recognition_model_v1").create( $model_filename ) -> <dlib.face_recognition_model_v1 object>
```

### dlib::face_recognition_model_v1::compute_face_descriptor

```cpp
dlib::SpaceVector dlib::face_recognition_model_v1::compute_face_descriptor( const cv::Mat&                     image,
                                                                            const dlib::full_object_detection& face,
                                                                            const int                          num_jitters = 0,
                                                                            float                              padding = 0.25 );

AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $image, $face[, $num_jitters[, $padding]] ) -> retval
```

```cpp
dlib::SpaceVector dlib::face_recognition_model_v1::compute_face_descriptor( const cv::Mat& image,
                                                                            const int      num_jitters = 0 );

AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $image[, $num_jitters] ) -> retval
```

```cpp
std::vector<dlib::SpaceVector> dlib::face_recognition_model_v1::compute_face_descriptor( const cv::Mat&                                  image,
                                                                                         const std::vector<dlib::full_object_detection>& faces,
                                                                                         const int                                       num_jitters = 0,
                                                                                         float                                           padding = 0.25 );

AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $image, $faces[, $num_jitters[, $padding]] ) -> retval
```

```cpp
std::vector<std::vector<dlib::SpaceVector>> dlib::face_recognition_model_v1::compute_face_descriptor( const std::vector<cv::Mat>&                                  images,
                                                                                                      const std::vector<std::vector<dlib::full_object_detection>>& batch_faces,
                                                                                                      const int                                                    num_jitters = 0,
                                                                                                      float                                                        padding = 0.25 );

AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $images, $batch_faces[, $num_jitters[, $padding]] ) -> retval
```

```cpp
std::vector<dlib::SpaceVector> dlib::face_recognition_model_v1::compute_face_descriptor( const std::vector<cv::Mat>& images,
                                                                                         const int                   num_jitters = 0 );

AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $images[, $num_jitters] ) -> retval
```

## dlib::_row

### dlib::_row::create

```cpp
static dlib::_row dlib::_row::create();

AutoIt:
    _Dlib_ObjCreate("dlib._row").create() -> <dlib._row object>
```

```cpp
static dlib::_row dlib::_row::create();

AutoIt:
    _Dlib_ObjCreate("dlib._row").create() -> <dlib._row object>
```

```cpp
static dlib::_row dlib::_row::create( double* data_,
                                      long    size_ );

AutoIt:
    _Dlib_ObjCreate("dlib._row").create( $size_[, $data_] ) -> <dlib._row object>
```

### dlib::_row::ToString

```cpp
string dlib::_row::ToString();

AutoIt:
    $o_row.ToString() -> retval
```

### dlib::_row::get

```cpp
double dlib::_row::get( long r );

AutoIt:
    $o_row.get( $r ) -> retval
```

### dlib::_row::set

```cpp
void dlib::_row::set( long   r,
                      double val );

AutoIt:
    $o_row.set( $r, $val ) -> None
```

## dlib::segmenter_type

### dlib::segmenter_type::create

```cpp
static dlib::segmenter_type dlib::segmenter_type::create();

AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_type").create() -> <dlib.segmenter_type object>
```

```cpp
static dlib::segmenter_type dlib::segmenter_type::create();

AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_type").create() -> <dlib.segmenter_type object>
```

### dlib::segmenter_type::get_call

```cpp
std::vector<std::pair<ULONG, ULONG>> dlib::segmenter_type::get_call( const std::vector<dlib::SpaceVector>& x ) const;

AutoIt:
    $osegmenter_type.call( $x ) -> retval
    dlib.segmenter_type( $x ) -> retval
```

```cpp
std::vector<std::pair<ULONG, ULONG>> dlib::segmenter_type::get_call( const std::vector<std::vector<std::pair<ULONG, double>>>& x ) const;

AutoIt:
    $osegmenter_type.call( $x ) -> retval
    dlib.segmenter_type( $x ) -> retval
```

## dlib::segmenter_params

### dlib::segmenter_params::create

```cpp
static dlib::segmenter_params dlib::segmenter_params::create();

AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_params").create() -> <dlib.segmenter_params object>
```

```cpp
static dlib::segmenter_params dlib::segmenter_params::create();

AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_params").create() -> <dlib.segmenter_params object>
```

### dlib::segmenter_params::ToString

```cpp
string dlib::segmenter_params::ToString() const;

AutoIt:
    $osegmenter_params.ToString() -> retval
```

## dlib::segmenter_test

### dlib::segmenter_test::create

```cpp
static dlib::segmenter_test dlib::segmenter_test::create();

AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_test").create() -> <dlib.segmenter_test object>
```

### dlib::segmenter_test::ToString

```cpp
string dlib::segmenter_test::ToString() const;

AutoIt:
    $osegmenter_test.ToString() -> retval
```

## dlib::shape_predictor_training_options

### dlib::shape_predictor_training_options::create

```cpp
static dlib::shape_predictor_training_options dlib::shape_predictor_training_options::create();

AutoIt:
    _Dlib_ObjCreate("dlib.shape_predictor_training_options").create() -> <dlib.shape_predictor_training_options object>
```

```cpp
static dlib::shape_predictor_training_options dlib::shape_predictor_training_options::create();

AutoIt:
    _Dlib_ObjCreate("dlib.shape_predictor_training_options").create() -> <dlib.shape_predictor_training_options object>
```

### dlib::shape_predictor_training_options::ToString

```cpp
string dlib::shape_predictor_training_options::ToString() const;

AutoIt:
    $oshape_predictor_training_options.ToString() -> retval
```

## dlib::simple_object_detector_training_options

### dlib::simple_object_detector_training_options::create

```cpp
static dlib::simple_object_detector_training_options dlib::simple_object_detector_training_options::create();

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector_training_options").create() -> <dlib.simple_object_detector_training_options object>
```

```cpp
static dlib::simple_object_detector_training_options dlib::simple_object_detector_training_options::create();

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector_training_options").create() -> <dlib.simple_object_detector_training_options object>
```

### dlib::simple_object_detector_training_options::ToString

```cpp
string dlib::simple_object_detector_training_options::ToString() const;

AutoIt:
    $osimple_object_detector_training_options.ToString() -> retval
```

## dlib::simple_test_results

### dlib::simple_test_results::create

```cpp
static dlib::simple_test_results dlib::simple_test_results::create();

AutoIt:
    _Dlib_ObjCreate("dlib.simple_test_results").create() -> <dlib.simple_test_results object>
```

### dlib::simple_test_results::ToString

```cpp
string dlib::simple_test_results::ToString() const;

AutoIt:
    $osimple_test_results.ToString() -> retval
```

## dlib::simple_object_detector_com

### dlib::simple_object_detector_com::create

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create();

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create() -> <dlib.simple_object_detector_com object>
```

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create();

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create() -> <dlib.simple_object_detector_com object>
```

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create( dlib::fhog_object_detector& _detector,
                                                                                  uint                        _upsampling_amount = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create( $_detector[, $_upsampling_amount] ) -> <dlib.simple_object_detector_com object>
```

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create( std::vector<dlib::simple_object_detector_com>& detectors );

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create( $detectors ) -> <dlib.simple_object_detector_com object>
```

```cpp
static std::shared_ptr<dlib::simple_object_detector_com> dlib::simple_object_detector_com::create( const string& filename );

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create( $filename ) -> retval
```

### dlib::simple_object_detector_com::get_call

```cpp
std::vector<dlib::rectangle> dlib::simple_object_detector_com::get_call( cv::Mat&   img,
                                                                         const uint upsampling_amount_ );

AutoIt:
    $osimple_object_detector_com.call( $img, $upsampling_amount_ ) -> retval
    dlib.simple_object_detector( $img, $upsampling_amount_ ) -> retval
```

```cpp
std::vector<dlib::rectangle> dlib::simple_object_detector_com::get_call( cv::Mat& img );

AutoIt:
    $osimple_object_detector_com.call( $img ) -> retval
    dlib.simple_object_detector( $img ) -> retval
```

### dlib::simple_object_detector_com::run_multiple

```cpp
static void dlib::simple_object_detector_com::run_multiple( std::vector<dlib::fhog_object_detector> vectors,
                                                            cv::Mat                                 image,
                                                            std::vector<dlib::rectangle>            rectangles,
                                                            std::vector<double>                     detection_confidences,
                                                            std::vector<ULONG>                      weight_indices,
                                                            uint                                    upsample_num_times = 0,
                                                            double                                  adjust_threshold = 0.0 );

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

```cpp
static void dlib::simple_object_detector_com::run_multiple( std::vector<dlib::simple_object_detector_com> vectors,
                                                            cv::Mat                                       image,
                                                            std::vector<dlib::rectangle>                  rectangles,
                                                            std::vector<double>                           detection_confidences,
                                                            std::vector<ULONG>                            weight_indices,
                                                            uint                                          upsample_num_times = 0,
                                                            double                                        adjust_threshold = 0.0 );

AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

## dlib::simple_structural_svm_problem

### dlib::simple_structural_svm_problem::create

```cpp
static dlib::simple_structural_svm_problem dlib::simple_structural_svm_problem::create();

AutoIt:
    _Dlib_ObjCreate("dlib.structural_svm_problem").create() -> <dlib.simple_structural_svm_problem object>
```

```cpp
static dlib::simple_structural_svm_problem dlib::simple_structural_svm_problem::create();

AutoIt:
    _Dlib_ObjCreate("dlib.structural_svm_problem").create() -> <dlib.simple_structural_svm_problem object>
```

## dlib::mmod_rect

### dlib::mmod_rect::create

```cpp
static dlib::mmod_rect dlib::mmod_rect::create();

AutoIt:
    _Dlib_ObjCreate("dlib.mmod_rectangle").create() -> <dlib.mmod_rect object>
```

```cpp
static dlib::mmod_rect dlib::mmod_rect::create( dlib::rectangle rect = rectangle(),
                                                double          detection_confidence = 0,
                                                string          label = string() );

AutoIt:
    _Dlib_ObjCreate("dlib.mmod_rectangle").create( [$rect[, $detection_confidence[, $label]]] ) -> <dlib.mmod_rect object>
```

## dlib::cuda

### dlib::cuda::set_device

```cpp
void dlib::cuda::set_device( int device );

AutoIt:
    _Dlib_ObjCreate("dlib.cuda").set_device( $device ) -> None
```

### dlib::cuda::get_device

```cpp
int dlib::cuda::get_device();

AutoIt:
    _Dlib_ObjCreate("dlib.cuda").get_device() -> retval
```

### dlib::cuda::get_device_name

```cpp
string dlib::cuda::get_device_name( int device );

AutoIt:
    _Dlib_ObjCreate("dlib.cuda").get_device_name( $device ) -> retval
```

### dlib::cuda::set_current_device_blocking_sync

```cpp
void dlib::cuda::set_current_device_blocking_sync();

AutoIt:
    _Dlib_ObjCreate("dlib.cuda").set_current_device_blocking_sync() -> None
```

### dlib::cuda::can_access_peer

```cpp
bool dlib::cuda::can_access_peer( int device_id,
                                  int peer_device_id );

AutoIt:
    _Dlib_ObjCreate("dlib.cuda").can_access_peer( $device_id, $peer_device_id ) -> retval
```

### dlib::cuda::device_synchronize

```cpp
void dlib::cuda::device_synchronize( int device_id );

AutoIt:
    _Dlib_ObjCreate("dlib.cuda").device_synchronize( $device_id ) -> None
```

## dlib::correlation_tracker

### dlib::correlation_tracker::create

```cpp
static dlib::correlation_tracker dlib::correlation_tracker::create();

AutoIt:
    _Dlib_ObjCreate("dlib.correlation_tracker").create() -> <dlib.correlation_tracker object>
```

### dlib::correlation_tracker::start_track

```cpp
void dlib::correlation_tracker::start_track( cv::Mat          image,
                                             dlib::drectangle bounding_box );

AutoIt:
    $ocorrelation_tracker.start_track( $image, $bounding_box ) -> None
```

```cpp
void dlib::correlation_tracker::start_track( cv::Mat         image,
                                             dlib::rectangle bounding_box );

AutoIt:
    $ocorrelation_tracker.start_track( $image, $bounding_box ) -> None
```

### dlib::correlation_tracker::update

```cpp
double dlib::correlation_tracker::update( cv::Mat image );

AutoIt:
    $ocorrelation_tracker.update( $image ) -> retval
```

```cpp
double dlib::correlation_tracker::update( cv::Mat          image,
                                          dlib::drectangle bounding_box );

AutoIt:
    $ocorrelation_tracker.update( $image, $bounding_box ) -> retval
```

```cpp
double dlib::correlation_tracker::update( cv::Mat         image,
                                          dlib::rectangle bounding_box );

AutoIt:
    $ocorrelation_tracker.update( $image, $bounding_box ) -> retval
```

### dlib::correlation_tracker::get_position

```cpp
dlib::drectangle dlib::correlation_tracker::get_position();

AutoIt:
    $ocorrelation_tracker.get_position() -> retval
```

## dlib::_radial_basis_kernel

### dlib::_radial_basis_kernel::create

```cpp
static dlib::_radial_basis_kernel dlib::_radial_basis_kernel::create();

AutoIt:
    _Dlib_ObjCreate("dlib._radial_basis_kernel").create() -> <dlib._radial_basis_kernel object>
```

## dlib::_linear_kernel

### dlib::_linear_kernel::create

```cpp
static dlib::_linear_kernel dlib::_linear_kernel::create();

AutoIt:
    _Dlib_ObjCreate("dlib._linear_kernel").create() -> <dlib._linear_kernel object>
```

## dlib::_decision_function_linear

### dlib::_decision_function_linear::create

```cpp
static dlib::_decision_function_linear dlib::_decision_function_linear::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_linear").create() -> <dlib._decision_function_linear object>
```

### dlib::_decision_function_linear::get_call

```cpp
double dlib::_decision_function_linear::get_call( dlib::SpaceVector sample );

AutoIt:
    $o_decision_function_linear.call( $sample ) -> retval
    dlib._decision_function_linear( $sample ) -> retval
```

## dlib::_decision_function_sparse_linear

### dlib::_decision_function_sparse_linear::create

```cpp
static dlib::_decision_function_sparse_linear dlib::_decision_function_sparse_linear::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_linear").create() -> <dlib._decision_function_sparse_linear object>
```

### dlib::_decision_function_sparse_linear::get_call

```cpp
double dlib::_decision_function_sparse_linear::get_call( std::vector<std::pair<ULONG, double>> sample );

AutoIt:
    $o_decision_function_sparse_linear.call( $sample ) -> retval
    dlib._decision_function_sparse_linear( $sample ) -> retval
```

## dlib::_decision_function_histogram_intersection

### dlib::_decision_function_histogram_intersection::create

```cpp
static dlib::_decision_function_histogram_intersection dlib::_decision_function_histogram_intersection::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_histogram_intersection").create() -> <dlib._decision_function_histogram_intersection object>
```

### dlib::_decision_function_histogram_intersection::get_call

```cpp
double dlib::_decision_function_histogram_intersection::get_call( dlib::SpaceVector sample );

AutoIt:
    $o_decision_function_histogram_intersection.call( $sample ) -> retval
    dlib._decision_function_histogram_intersection( $sample ) -> retval
```

## dlib::_decision_function_sparse_histogram_intersection

### dlib::_decision_function_sparse_histogram_intersection::create

```cpp
static dlib::_decision_function_sparse_histogram_intersection dlib::_decision_function_sparse_histogram_intersection::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_histogram_intersection").create() -> <dlib._decision_function_sparse_histogram_intersection object>
```

### dlib::_decision_function_sparse_histogram_intersection::get_call

```cpp
double dlib::_decision_function_sparse_histogram_intersection::get_call( std::vector<std::pair<ULONG, double>> sample );

AutoIt:
    $o_decision_function_sparse_histogram_intersection.call( $sample ) -> retval
    dlib._decision_function_sparse_histogram_intersection( $sample ) -> retval
```

## dlib::_decision_function_polynomial

### dlib::_decision_function_polynomial::create

```cpp
static dlib::_decision_function_polynomial dlib::_decision_function_polynomial::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_polynomial").create() -> <dlib._decision_function_polynomial object>
```

### dlib::_decision_function_polynomial::get_call

```cpp
double dlib::_decision_function_polynomial::get_call( dlib::SpaceVector sample );

AutoIt:
    $o_decision_function_polynomial.call( $sample ) -> retval
    dlib._decision_function_polynomial( $sample ) -> retval
```

## dlib::_decision_function_sparse_polynomial

### dlib::_decision_function_sparse_polynomial::create

```cpp
static dlib::_decision_function_sparse_polynomial dlib::_decision_function_sparse_polynomial::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_polynomial").create() -> <dlib._decision_function_sparse_polynomial object>
```

### dlib::_decision_function_sparse_polynomial::get_call

```cpp
double dlib::_decision_function_sparse_polynomial::get_call( std::vector<std::pair<ULONG, double>> sample );

AutoIt:
    $o_decision_function_sparse_polynomial.call( $sample ) -> retval
    dlib._decision_function_sparse_polynomial( $sample ) -> retval
```

## dlib::_decision_function_radial_basis

### dlib::_decision_function_radial_basis::create

```cpp
static dlib::_decision_function_radial_basis dlib::_decision_function_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_radial_basis").create() -> <dlib._decision_function_radial_basis object>
```

### dlib::_decision_function_radial_basis::get_call

```cpp
double dlib::_decision_function_radial_basis::get_call( dlib::SpaceVector sample );

AutoIt:
    $o_decision_function_radial_basis.call( $sample ) -> retval
    dlib._decision_function_radial_basis( $sample ) -> retval
```

## dlib::_decision_function_sparse_radial_basis

### dlib::_decision_function_sparse_radial_basis::create

```cpp
static dlib::_decision_function_sparse_radial_basis dlib::_decision_function_sparse_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_radial_basis").create() -> <dlib._decision_function_sparse_radial_basis object>
```

### dlib::_decision_function_sparse_radial_basis::get_call

```cpp
double dlib::_decision_function_sparse_radial_basis::get_call( std::vector<std::pair<ULONG, double>> sample );

AutoIt:
    $o_decision_function_sparse_radial_basis.call( $sample ) -> retval
    dlib._decision_function_sparse_radial_basis( $sample ) -> retval
```

## dlib::_decision_function_sigmoid

### dlib::_decision_function_sigmoid::create

```cpp
static dlib::_decision_function_sigmoid dlib::_decision_function_sigmoid::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sigmoid").create() -> <dlib._decision_function_sigmoid object>
```

### dlib::_decision_function_sigmoid::get_call

```cpp
double dlib::_decision_function_sigmoid::get_call( dlib::SpaceVector sample );

AutoIt:
    $o_decision_function_sigmoid.call( $sample ) -> retval
    dlib._decision_function_sigmoid( $sample ) -> retval
```

## dlib::_decision_function_sparse_sigmoid

### dlib::_decision_function_sparse_sigmoid::create

```cpp
static dlib::_decision_function_sparse_sigmoid dlib::_decision_function_sparse_sigmoid::create();

AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_sigmoid").create() -> <dlib._decision_function_sparse_sigmoid object>
```

### dlib::_decision_function_sparse_sigmoid::get_call

```cpp
double dlib::_decision_function_sparse_sigmoid::get_call( std::vector<std::pair<ULONG, double>> sample );

AutoIt:
    $o_decision_function_sparse_sigmoid.call( $sample ) -> retval
    dlib._decision_function_sparse_sigmoid( $sample ) -> retval
```

## dlib::_normalized_decision_function_radial_basis

### dlib::_normalized_decision_function_radial_basis::create

```cpp
static dlib::_normalized_decision_function_radial_basis dlib::_normalized_decision_function_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib._normalized_decision_function_radial_basis").create() -> <dlib._normalized_decision_function_radial_basis object>
```

### dlib::_normalized_decision_function_radial_basis::get_call

```cpp
double dlib::_normalized_decision_function_radial_basis::get_call( dlib::SpaceVector& sample );

AutoIt:
    $o_normalized_decision_function_radial_basis.call( $sample ) -> retval
    dlib._normalized_decision_function_radial_basis( $sample ) -> retval
```

### dlib::_normalized_decision_function_radial_basis::batch_predict

```cpp
std::vector<double> dlib::_normalized_decision_function_radial_basis::batch_predict( std::vector<dlib::SpaceVector>& samples );

AutoIt:
    $o_normalized_decision_function_radial_basis.batch_predict( $samples ) -> retval
```

```cpp
std::vector<double> dlib::_normalized_decision_function_radial_basis::batch_predict( cv::Mat& samples );

AutoIt:
    $o_normalized_decision_function_radial_basis.batch_predict( $samples ) -> retval
```

## dlib::function_evaluation

### dlib::function_evaluation::create

```cpp
static dlib::function_evaluation dlib::function_evaluation::create();

AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create() -> <dlib.function_evaluation object>
```

```cpp
static dlib::function_evaluation dlib::function_evaluation::create();

AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create() -> <dlib.function_evaluation object>
```

```cpp
static dlib::function_evaluation dlib::function_evaluation::create( dlib::SpaceVector x,
                                                                    double            y );

AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create( $x, $y ) -> <dlib.function_evaluation object>
```

```cpp
static dlib::function_evaluation dlib::function_evaluation::create( std::vector<double> x,
                                                                    double              y );

AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create( $x, $y ) -> <dlib.function_evaluation object>
```

## dlib::function_spec

### dlib::function_spec::create

```cpp
static dlib::function_spec dlib::function_spec::create( dlib::SpaceVector bound1,
                                                        dlib::SpaceVector bound2 );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( dlib::SpaceVector bound1,
                                                        dlib::SpaceVector bound2,
                                                        std::vector<bool> is_integer );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( std::vector<double> bound1,
                                                        dlib::SpaceVector   bound2 );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( std::vector<double> bound1,
                                                        dlib::SpaceVector   bound2,
                                                        std::vector<bool>   is_integer );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( dlib::SpaceVector   bound1,
                                                        std::vector<double> bound2 );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( dlib::SpaceVector   bound1,
                                                        std::vector<double> bound2,
                                                        std::vector<bool>   is_integer );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( std::vector<double> bound1,
                                                        std::vector<double> bound2 );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::create( std::vector<double> bound1,
                                                        std::vector<double> bound2,
                                                        std::vector<bool>   is_integer );

AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

## dlib::function_evaluation_request

### dlib::function_evaluation_request::set

```cpp
void dlib::function_evaluation_request::set( double y );

AutoIt:
    $ofunction_evaluation_request.set( $y ) -> None
```

## dlib::global_function_search

### dlib::global_function_search::create

```cpp
static dlib::global_function_search dlib::global_function_search::create( dlib::function_spec& function );

AutoIt:
    _Dlib_ObjCreate("dlib.global_function_search").create( $function ) -> <dlib.global_function_search object>
```

```cpp
static dlib::global_function_search dlib::global_function_search::create( std::vector<dlib::function_spec>& functions );

AutoIt:
    _Dlib_ObjCreate("dlib.global_function_search").create( $functions ) -> <dlib.global_function_search object>
```

```cpp
static dlib::global_function_search dlib::global_function_search::create( std::vector<dlib::function_spec>                    functions,
                                                                          std::vector<std::vector<dlib::function_evaluation>> initial_function_evals,
                                                                          double                                              relative_noise_magnitude = 0.001 );

AutoIt:
    _Dlib_ObjCreate("dlib.global_function_search").create( $functions, $initial_function_evals[, $relative_noise_magnitude] ) -> <dlib.global_function_search object>
```

### dlib::global_function_search::set_seed

```cpp
void dlib::global_function_search::set_seed( LONGLONG seed );

AutoIt:
    $oglobal_function_search.set_seed( $seed ) -> None
```

### dlib::global_function_search::num_functions

```cpp
size_t dlib::global_function_search::num_functions();

AutoIt:
    $oglobal_function_search.num_functions() -> retval
```

### dlib::global_function_search::get_function_evaluations

```cpp
void dlib::global_function_search::get_function_evaluations( std::vector<dlib::function_spec>                    specs,
                                                             std::vector<std::vector<dlib::function_evaluation>> function_evals );

AutoIt:
    $oglobal_function_search.get_function_evaluations( [$specs[, $function_evals]] ) -> $specs, $function_evals
```

### dlib::global_function_search::get_best_function_eval

```cpp
void dlib::global_function_search::get_best_function_eval( dlib::SpaceVector& x,
                                                           double&            y,
                                                           size_t&            idx );

AutoIt:
    $oglobal_function_search.get_best_function_eval( [$x[, $y[, $idx]]] ) -> $x, $y, $idx
```

### dlib::global_function_search::get_next_x

```cpp
dlib::function_evaluation_request dlib::global_function_search::get_next_x();

AutoIt:
    $oglobal_function_search.get_next_x() -> retval
```

### dlib::global_function_search::get_pure_random_search_probability

```cpp
double dlib::global_function_search::get_pure_random_search_probability();

AutoIt:
    $oglobal_function_search.get_pure_random_search_probability() -> retval
```

### dlib::global_function_search::set_pure_random_search_probability

```cpp
void dlib::global_function_search::set_pure_random_search_probability( double prob );

AutoIt:
    $oglobal_function_search.set_pure_random_search_probability( $prob ) -> None
```

### dlib::global_function_search::get_solver_epsilon

```cpp
double dlib::global_function_search::get_solver_epsilon();

AutoIt:
    $oglobal_function_search.get_solver_epsilon() -> retval
```

### dlib::global_function_search::set_solver_epsilon

```cpp
void dlib::global_function_search::set_solver_epsilon( double eps );

AutoIt:
    $oglobal_function_search.set_solver_epsilon( $eps ) -> None
```

### dlib::global_function_search::get_relative_noise_magnitude

```cpp
double dlib::global_function_search::get_relative_noise_magnitude();

AutoIt:
    $oglobal_function_search.get_relative_noise_magnitude() -> retval
```

### dlib::global_function_search::set_relative_noise_magnitude

```cpp
void dlib::global_function_search::set_relative_noise_magnitude( double value );

AutoIt:
    $oglobal_function_search.set_relative_noise_magnitude( $value ) -> None
```

### dlib::global_function_search::get_monte_carlo_upper_bound_sample_num

```cpp
size_t dlib::global_function_search::get_monte_carlo_upper_bound_sample_num();

AutoIt:
    $oglobal_function_search.get_monte_carlo_upper_bound_sample_num() -> retval
```

### dlib::global_function_search::set_monte_carlo_upper_bound_sample_num

```cpp
void dlib::global_function_search::set_monte_carlo_upper_bound_sample_num( size_t num );

AutoIt:
    $oglobal_function_search.set_monte_carlo_upper_bound_sample_num( $num ) -> None
```

## dlib::image_window

### dlib::image_window::create

```cpp
static dlib::image_window dlib::image_window::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_window").create() -> <dlib.image_window object>
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::create( dlib::fhog_object_detector& detector );

AutoIt:
    $oimage_window.create( $detector ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::create( dlib::simple_object_detector_com& detector );

AutoIt:
    $oimage_window.create( $detector ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::create( dlib::fhog_object_detector& detector,
                                                                string                      title );

AutoIt:
    $oimage_window.create( $detector, $title ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::create( dlib::simple_object_detector_com& detector,
                                                                string                            title );

AutoIt:
    $oimage_window.create( $detector, $title ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::create( cv::Mat& img );

AutoIt:
    $oimage_window.create( $img ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::create( cv::Mat& img,
                                                                string   title );

AutoIt:
    $oimage_window.create( $img, $title ) -> retval
```

### dlib::image_window::set_image

```cpp
void dlib::image_window::set_image( dlib::fhog_object_detector& detector );

AutoIt:
    $oimage_window.set_image( $detector ) -> None
```

```cpp
void dlib::image_window::set_image( dlib::simple_object_detector_com& detector );

AutoIt:
    $oimage_window.set_image( $detector ) -> None
```

```cpp
void dlib::image_window::set_image( cv::Mat& img );

AutoIt:
    $oimage_window.set_image( $img ) -> None
```

### dlib::image_window::set_title

```cpp
void dlib::image_window::set_title( string title );

AutoIt:
    $oimage_window.set_title( $title ) -> None
```

### dlib::image_window::clear_overlay

```cpp
void dlib::image_window::clear_overlay();

AutoIt:
    $oimage_window.clear_overlay() -> None
```

### dlib::image_window::add_overlay

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::rectangle> rectangles,
                                      dlib::rgb_pixel              color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay( $rectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::rectangle>    rectangles,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay( $rectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::drectangle> drectangles,
                                      dlib::rgb_pixel               color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay( $drectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::drectangle>   drectangles,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay( $drectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<_variant_t> objs,
                                      dlib::rgb_pixel         color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay( $objs[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<_variant_t>         objs,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay( $objs[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::rectangle rect,
                                      dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay( $rect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::rectangle                 rect,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay( $rect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::drectangle drect,
                                      dlib::rgb_pixel  color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay( $drect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::drectangle                drect,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay( $drect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::full_object_detection& detection,
                                      dlib::rgb_pixel              color = rgb_pixel(0, 0, 255) );

AutoIt:
    $oimage_window.add_overlay( $detection[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::full_object_detection&    detection,
                                      std::tuple<uchar, uchar, uchar> color = {0, 0, 255} );

AutoIt:
    $oimage_window.add_overlay( $detection[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::line      l,
                                      dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay( $l[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::line                      l,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay( $l[, $color] ) -> None
```

### dlib::image_window::add_overlay_circle

```cpp
void dlib::image_window::add_overlay_circle( dlib::point     center,
                                             double          radius,
                                             dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay_circle( dlib::point                     center,
                                             double                          radius,
                                             std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay_circle( dlib::dpoint    center,
                                             double          radius,
                                             dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );

AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay_circle( dlib::dpoint                    center,
                                             double                          radius,
                                             std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );

AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

### dlib::image_window::wait_until_closed

```cpp
void dlib::image_window::wait_until_closed();

AutoIt:
    $oimage_window.wait_until_closed() -> None
```

### dlib::image_window::is_closed

```cpp
bool dlib::image_window::is_closed();

AutoIt:
    $oimage_window.is_closed() -> retval
```

### dlib::image_window::get_next_double_click

```cpp
bool dlib::image_window::get_next_double_click( dlib::point p );

AutoIt:
    $oimage_window.get_next_double_click( [$p] ) -> retval, $p
```

### dlib::image_window::wait_for_keypress

```cpp
void dlib::image_window::wait_for_keypress( char wait_key );

AutoIt:
    $oimage_window.wait_for_keypress( $wait_key ) -> None
```

```cpp
void dlib::image_window::wait_for_keypress( string wait_key );

AutoIt:
    $oimage_window.wait_for_keypress( $wait_key ) -> None
```

### dlib::image_window::get_next_keypress

```cpp
bool dlib::image_window::get_next_keypress( char*&           key,
                                            bool*&           is_printable,
                                            std::vector<int> mods,
                                            bool             get_keyboard_modifiers = false );

AutoIt:
    $oimage_window.get_next_keypress( [$get_keyboard_modifiers[, $key[, $is_printable[, $mods]]]] ) -> retval, $key, $is_printable, $mods
```

## dlib::rgb_pixel

### dlib::rgb_pixel::create

```cpp
static dlib::rgb_pixel dlib::rgb_pixel::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rgb_pixel").create() -> <dlib.rgb_pixel object>
```

```cpp
static dlib::rgb_pixel dlib::rgb_pixel::create( uchar red,
                                                uchar blue,
                                                uchar green );

AutoIt:
    _Dlib_ObjCreate("dlib.rgb_pixel").create( $red, $blue, $green ) -> <dlib.rgb_pixel object>
```

## cv

### cv::haveImageReader

```cpp
bool cv::haveImageReader( string filename );

AutoIt:
    _Dlib_ObjCreate("cv").haveImageReader( $filename ) -> retval
```

### cv::haveImageWriter

```cpp
bool cv::haveImageWriter( string filename );

AutoIt:
    _Dlib_ObjCreate("cv").haveImageWriter( $filename ) -> retval
```

### cv::imcount

```cpp
size_t cv::imcount( string filename,
                    int    flags = IMREAD_ANYCOLOR );

AutoIt:
    _Dlib_ObjCreate("cv").imcount( $filename[, $flags] ) -> retval
```

### cv::imdecode

```cpp
cv::Mat cv::imdecode( cv::Mat buf,
                      int     flags );

AutoIt:
    _Dlib_ObjCreate("cv").imdecode( $buf, $flags ) -> retval
```

### cv::imencode

```cpp
bool cv::imencode( string             ext,
                   cv::Mat            img,
                   std::vector<uchar> buf,
                   std::vector<int>   params = std::vector<int>() );

AutoIt:
    _Dlib_ObjCreate("cv").imencode( $ext, $img[, $params[, $buf]] ) -> retval, $buf
```

### cv::imread

```cpp
cv::Mat cv::imread( string filename,
                    int    flags = IMREAD_COLOR );

AutoIt:
    _Dlib_ObjCreate("cv").imread( $filename[, $flags] ) -> retval
```

### cv::imreadmulti

```cpp
bool cv::imreadmulti( string               filename,
                      std::vector<cv::Mat> mats,
                      int                  flags = IMREAD_ANYCOLOR );

AutoIt:
    _Dlib_ObjCreate("cv").imreadmulti( $filename[, $flags[, $mats]] ) -> retval, $mats
```

```cpp
bool cv::imreadmulti( string               filename,
                      std::vector<cv::Mat> mats,
                      int                  start,
                      int                  count,
                      int                  flags = IMREAD_ANYCOLOR );

AutoIt:
    _Dlib_ObjCreate("cv").imreadmulti( $filename, $start, $count[, $flags[, $mats]] ) -> retval, $mats
```

### cv::imwrite

```cpp
bool cv::imwrite( string           filename,
                  cv::Mat          img,
                  std::vector<int> params = std::vector<int>() );

AutoIt:
    _Dlib_ObjCreate("cv").imwrite( $filename, $img[, $params] ) -> retval
```

### cv::imwritemulti

```cpp
bool cv::imwritemulti( string               filename,
                       std::vector<cv::Mat> img,
                       std::vector<int>     params = std::vector<int>() );

AutoIt:
    _Dlib_ObjCreate("cv").imwritemulti( $filename, $img[, $params] ) -> retval
```

## cv::Mat

### cv::Mat::create

```cpp
static cv::Mat cv::Mat::create();

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create() -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( int rows,
                                int cols,
                                int type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $rows, $cols, $type ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( std::tuple<int, int> size,
                                int                  type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $size, $type ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( int                                        rows,
                                int                                        cols,
                                int                                        type,
                                std::tuple<double, double, double, double> s );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $rows, $cols, $type, $s ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( std::tuple<int, int>                       size,
                                int                                        type,
                                std::tuple<double, double, double, double> s );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $size, $type, $s ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( int    rows,
                                int    cols,
                                int    type,
                                void*  data,
                                size_t step = cv::Mat::AUTO_STEP );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $rows, $cols, $type, $data[, $step] ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( cv::Mat m );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $m ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( cv::Mat                        src,
                                std::tuple<int, int, int, int> roi );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $src, $roi ) -> <cv.Mat object>
```

### cv::Mat::isContinuous

```cpp
bool cv::Mat::isContinuous();

AutoIt:
    $oMat.isContinuous() -> retval
```

### cv::Mat::isSubmatrix

```cpp
bool cv::Mat::isSubmatrix();

AutoIt:
    $oMat.isSubmatrix() -> retval
```

### cv::Mat::elemSize

```cpp
size_t cv::Mat::elemSize();

AutoIt:
    $oMat.elemSize() -> retval
```

### cv::Mat::elemSize1

```cpp
size_t cv::Mat::elemSize1();

AutoIt:
    $oMat.elemSize1() -> retval
```

### cv::Mat::type

```cpp
int cv::Mat::type();

AutoIt:
    $oMat.type() -> retval
```

### cv::Mat::depth

```cpp
int cv::Mat::depth();

AutoIt:
    $oMat.depth() -> retval
```

### cv::Mat::channels

```cpp
int cv::Mat::channels();

AutoIt:
    $oMat.channels() -> retval
```

### cv::Mat::step1

```cpp
size_t cv::Mat::step1( int i = 0 );

AutoIt:
    $oMat.step1( [$i] ) -> retval
```

### cv::Mat::empty

```cpp
bool cv::Mat::empty();

AutoIt:
    $oMat.empty() -> retval
```

### cv::Mat::total

```cpp
size_t cv::Mat::total();

AutoIt:
    $oMat.total() -> retval
```

```cpp
size_t cv::Mat::total( int startDim,
                       int endDim = INT_MAX );

AutoIt:
    $oMat.total( $startDim[, $endDim] ) -> retval
```

### cv::Mat::checkVector

```cpp
int cv::Mat::checkVector( int elemChannels,
                          int depth = -1,
                          int requireContinuous = true );

AutoIt:
    $oMat.checkVector( $elemChannels[, $depth[, $requireContinuous]] ) -> retval
```

### cv::Mat::ptr

```cpp
uchar* cv::Mat::ptr( int y = 0 );

AutoIt:
    $oMat.ptr( [$y] ) -> retval
```

```cpp
uchar* cv::Mat::ptr( int i0,
                     int i1 );

AutoIt:
    $oMat.ptr( $i0, $i1 ) -> retval
```

```cpp
uchar* cv::Mat::ptr( int i0,
                     int i1,
                     int i2 );

AutoIt:
    $oMat.ptr( $i0, $i1, $i2 ) -> retval
```

### cv::Mat::pop_back

```cpp
void cv::Mat::pop_back( size_t value );

AutoIt:
    $oMat.pop_back( $value ) -> None
```

### cv::Mat::push_back

```cpp
void cv::Mat::push_back( cv::Mat value );

AutoIt:
    $oMat.push_back( $value ) -> None
```

### cv::Mat::reshape

```cpp
cv::Mat cv::Mat::reshape( int cn,
                          int rows = 0 );

AutoIt:
    $oMat.reshape( $cn[, $rows] ) -> retval
```

### cv::Mat::eye

```cpp
static cv::Mat cv::Mat::eye( int rows,
                             int cols,
                             int type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").eye( $rows, $cols, $type ) -> retval
```

### cv::Mat::zeros

```cpp
static cv::Mat cv::Mat::zeros( int rows,
                               int cols,
                               int type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $rows, $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::zeros( std::tuple<int, int> size,
                               int                  type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $size, $type ) -> retval
```

### cv::Mat::ones

```cpp
static cv::Mat cv::Mat::ones( int rows,
                              int cols,
                              int type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $rows, $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::ones( std::tuple<int, int> size,
                              int                  type );

AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $size, $type ) -> retval
```

## dlib::image_dataset_metadata

### dlib::image_dataset_metadata::save_image_dataset_metadata

```cpp
void dlib::image_dataset_metadata::save_image_dataset_metadata( dlib::image_dataset_metadata::dataset data,
                                                                string                                filename );

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata").save_image_dataset_metadata( $data, $filename ) -> None
```

### dlib::image_dataset_metadata::load_image_dataset_metadata

```cpp
void dlib::image_dataset_metadata::load_image_dataset_metadata( dlib::image_dataset_metadata::dataset& data,
                                                                string                                 filename );

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata").load_image_dataset_metadata( $filename[, $data] ) -> $data
```

### dlib::image_dataset_metadata::make_bounding_box_regression_training_data

```cpp
dlib::image_dataset_metadata::dataset dlib::image_dataset_metadata::make_bounding_box_regression_training_data( dlib::image_dataset_metadata::dataset&    truth,
                                                                                                                std::vector<std::vector<dlib::rectangle>> detections );

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata").make_bounding_box_regression_training_data( $truth, $detections ) -> retval
```

## dlib::image_dataset_metadata::box

### dlib::image_dataset_metadata::box::create

```cpp
static dlib::image_dataset_metadata::box dlib::image_dataset_metadata::box::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.box").create() -> <dlib.image_dataset_metadata.box object>
```

```cpp
static dlib::image_dataset_metadata::box dlib::image_dataset_metadata::box::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.box").create() -> <dlib.image_dataset_metadata.box object>
```

```cpp
static dlib::image_dataset_metadata::box dlib::image_dataset_metadata::box::create( dlib::rectangle rect );

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.box").create( $rect ) -> <dlib.image_dataset_metadata.box object>
```

### dlib::image_dataset_metadata::box::has_label

```cpp
bool dlib::image_dataset_metadata::box::has_label();

AutoIt:
    $obox.has_label() -> retval
```

## dlib::image_dataset_metadata::image

### dlib::image_dataset_metadata::image::create

```cpp
static dlib::image_dataset_metadata::image dlib::image_dataset_metadata::image::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.image").create() -> <dlib.image_dataset_metadata.image object>
```

```cpp
static dlib::image_dataset_metadata::image dlib::image_dataset_metadata::image::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.image").create() -> <dlib.image_dataset_metadata.image object>
```

```cpp
static dlib::image_dataset_metadata::image dlib::image_dataset_metadata::image::create( string filename );

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.image").create( $filename ) -> <dlib.image_dataset_metadata.image object>
```

## dlib::image_dataset_metadata::dataset

### dlib::image_dataset_metadata::dataset::create

```cpp
static dlib::image_dataset_metadata::dataset dlib::image_dataset_metadata::dataset::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.dataset").create() -> <dlib.image_dataset_metadata.dataset object>
```

```cpp
static dlib::image_dataset_metadata::dataset dlib::image_dataset_metadata::dataset::create();

AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.dataset").create() -> <dlib.image_dataset_metadata.dataset object>
```

## dlib::line

### dlib::line::create

```cpp
static dlib::line dlib::line::create();

AutoIt:
    _Dlib_ObjCreate("dlib.line").create() -> <dlib.line object>
```

```cpp
static dlib::line dlib::line::create( dlib::dpoint a,
                                      dlib::dpoint b );

AutoIt:
    _Dlib_ObjCreate("dlib.line").create( $a, $b ) -> <dlib.line object>
```

```cpp
static dlib::line dlib::line::create( dlib::point a,
                                      dlib::point b );

AutoIt:
    _Dlib_ObjCreate("dlib.line").create( $a, $b ) -> <dlib.line object>
```

## dlib::Matrix

### dlib::Matrix::create

```cpp
static dlib::Matrix dlib::Matrix::create();

AutoIt:
    _Dlib_ObjCreate("dlib.matrix").create() -> <dlib.Matrix object>
```

```cpp
std::shared_ptr<dlib::Matrix> dlib::Matrix::create( std::vector<double> list );

AutoIt:
    $oMatrix.create( $list ) -> retval
```

```cpp
std::shared_ptr<dlib::Matrix> dlib::Matrix::create( std::vector<std::vector<double>> list );

AutoIt:
    $oMatrix.create( $list ) -> retval
```

```cpp
std::shared_ptr<dlib::Matrix> dlib::Matrix::create( long rows,
                                                    long cols );

AutoIt:
    $oMatrix.create( $rows, $cols ) -> retval
```

### dlib::Matrix::set_size

```cpp
void dlib::Matrix::set_size( long rows,
                             long cols );

AutoIt:
    $oMatrix.set_size( $rows, $cols ) -> None
```

### dlib::Matrix::nr

```cpp
long dlib::Matrix::nr();

AutoIt:
    $oMatrix.nr() -> retval
```

### dlib::Matrix::nc

```cpp
long dlib::Matrix::nc();

AutoIt:
    $oMatrix.nc() -> retval
```

### dlib::Matrix::serialize

```cpp
void dlib::Matrix::serialize( string file );

AutoIt:
    $oMatrix.serialize( $file ) -> None
```

### dlib::Matrix::deserialize

```cpp
void dlib::Matrix::deserialize( string file );

AutoIt:
    $oMatrix.deserialize( $file ) -> None
```

### dlib::Matrix::get

```cpp
dlib::_row dlib::Matrix::get( long row );

AutoIt:
    $oMatrix.get( $row ) -> retval
```

### dlib::Matrix::ToString

```cpp
string dlib::Matrix::ToString();

AutoIt:
    $oMatrix.ToString() -> retval
```

## dlib::fhog_object_detector

### dlib::fhog_object_detector::create

```cpp
static dlib::fhog_object_detector dlib::fhog_object_detector::create();

AutoIt:
    _Dlib_ObjCreate("dlib.fhog_object_detector").create() -> <dlib.fhog_object_detector object>
```

```cpp
std::shared_ptr<dlib::fhog_object_detector> dlib::fhog_object_detector::create( string filename );

AutoIt:
    $ofhog_object_detector.create( $filename ) -> retval
```

### dlib::fhog_object_detector::run

```cpp
void dlib::fhog_object_detector::run( cv::Mat                      image,
                                      std::vector<dlib::rectangle> rectangles,
                                      std::vector<double>          detection_confidences,
                                      std::vector<ULONG>           weight_indices,
                                      uint                         upsample_num_times = 0,
                                      double                       adjust_threshold = 0.0 );

AutoIt:
    $ofhog_object_detector.run( $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

### dlib::fhog_object_detector::get_call

```cpp
void dlib::fhog_object_detector::get_call( cv::Mat                      image,
                                           std::vector<dlib::rectangle> rectangles,
                                           std::vector<double>          detection_confidences,
                                           std::vector<ULONG>           weight_indices,
                                           uint                         upsample_num_times = 0,
                                           double                       adjust_threshold = 0.0 );

AutoIt:
    $ofhog_object_detector.call( $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
    dlib.fhog_object_detector( $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

### dlib::fhog_object_detector::save

```cpp
void dlib::fhog_object_detector::save( string detector_output_filename );

AutoIt:
    $ofhog_object_detector.save( $detector_output_filename ) -> None
```

### dlib::fhog_object_detector::run_multiple

```cpp
static void dlib::fhog_object_detector::run_multiple( std::vector<dlib::fhog_object_detector> vectors,
                                                      cv::Mat                                 image,
                                                      std::vector<dlib::rectangle>            rectangles,
                                                      std::vector<double>                     detection_confidences,
                                                      std::vector<ULONG>                      weight_indices,
                                                      uint                                    upsample_num_times = 0,
                                                      double                                  adjust_threshold = 0.0 );

AutoIt:
    _Dlib_ObjCreate("dlib.fhog_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

```cpp
static void dlib::fhog_object_detector::run_multiple( std::vector<dlib::simple_object_detector_com> vectors,
                                                      cv::Mat                                       image,
                                                      std::vector<dlib::rectangle>                  rectangles,
                                                      std::vector<double>                           detection_confidences,
                                                      std::vector<ULONG>                            weight_indices,
                                                      uint                                          upsample_num_times = 0,
                                                      double                                        adjust_threshold = 0.0 );

AutoIt:
    _Dlib_ObjCreate("dlib.fhog_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

## dlib::rect_filter

### dlib::rect_filter::create

```cpp
static dlib::rect_filter dlib::rect_filter::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rect_filter").create() -> <dlib.rect_filter object>
```

```cpp
static dlib::rect_filter dlib::rect_filter::create( double measurement_noise,
                                                    double typical_acceleration,
                                                    double max_measurement_deviation );

AutoIt:
    _Dlib_ObjCreate("dlib.rect_filter").create( $measurement_noise, $typical_acceleration, $max_measurement_deviation ) -> <dlib.rect_filter object>
```

### dlib::rect_filter::measurement_noise

```cpp
double dlib::rect_filter::measurement_noise();

AutoIt:
    $orect_filter.measurement_noise() -> retval
```

### dlib::rect_filter::typical_acceleration

```cpp
double dlib::rect_filter::typical_acceleration();

AutoIt:
    $orect_filter.typical_acceleration() -> retval
```

### dlib::rect_filter::max_measurement_deviation

```cpp
double dlib::rect_filter::max_measurement_deviation();

AutoIt:
    $orect_filter.max_measurement_deviation() -> retval
```

### dlib::rect_filter::get_call

```cpp
dlib::drectangle dlib::rect_filter::get_call( dlib::rectangle rect );

AutoIt:
    $orect_filter.call( $rect ) -> retval
    dlib.rect_filter( $rect ) -> retval
```

```cpp
dlib::drectangle dlib::rect_filter::get_call( dlib::drectangle rect );

AutoIt:
    $orect_filter.call( $rect ) -> retval
    dlib.rect_filter( $rect ) -> retval
```

## dlib::rectangle

### dlib::rectangle::create

```cpp
static dlib::rectangle dlib::rectangle::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create() -> <dlib.rectangle object>
```

```cpp
static dlib::rectangle dlib::rectangle::create( long& left,
                                                long& top,
                                                long& right,
                                                long& bottom );

AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create( $left, $top, $right, $bottom ) -> <dlib.rectangle object>
```

```cpp
static dlib::rectangle dlib::rectangle::create( dlib::drectangle& rect );

AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create( $rect ) -> <dlib.rectangle object>
```

```cpp
static dlib::rectangle dlib::rectangle::create( dlib::rectangle& rect );

AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create( $rect ) -> <dlib.rectangle object>
```

### dlib::rectangle::area

```cpp
ULONG dlib::rectangle::area();

AutoIt:
    $orectangle.area() -> retval
```

### dlib::rectangle::left

```cpp
long dlib::rectangle::left();

AutoIt:
    $orectangle.left() -> retval
```

### dlib::rectangle::top

```cpp
long dlib::rectangle::top();

AutoIt:
    $orectangle.top() -> retval
```

### dlib::rectangle::right

```cpp
long dlib::rectangle::right();

AutoIt:
    $orectangle.right() -> retval
```

### dlib::rectangle::bottom

```cpp
long dlib::rectangle::bottom();

AutoIt:
    $orectangle.bottom() -> retval
```

### dlib::rectangle::width

```cpp
ULONG dlib::rectangle::width();

AutoIt:
    $orectangle.width() -> retval
```

### dlib::rectangle::height

```cpp
ULONG dlib::rectangle::height();

AutoIt:
    $orectangle.height() -> retval
```

### dlib::rectangle::tl_corner

```cpp
dlib::point dlib::rectangle::tl_corner();

AutoIt:
    $orectangle.tl_corner() -> retval
```

### dlib::rectangle::tr_corner

```cpp
dlib::point dlib::rectangle::tr_corner();

AutoIt:
    $orectangle.tr_corner() -> retval
```

### dlib::rectangle::bl_corner

```cpp
dlib::point dlib::rectangle::bl_corner();

AutoIt:
    $orectangle.bl_corner() -> retval
```

### dlib::rectangle::br_corner

```cpp
dlib::point dlib::rectangle::br_corner();

AutoIt:
    $orectangle.br_corner() -> retval
```

### dlib::rectangle::is_empty

```cpp
bool dlib::rectangle::is_empty();

AutoIt:
    $orectangle.is_empty() -> retval
```

### dlib::rectangle::center

```cpp
dlib::point dlib::rectangle::center();

AutoIt:
    $orectangle.center() -> retval
```

### dlib::rectangle::dcenter

```cpp
dlib::dpoint dlib::rectangle::dcenter();

AutoIt:
    $orectangle.dcenter() -> retval
```

### dlib::rectangle::contains

```cpp
bool dlib::rectangle::contains( dlib::dpoint& point );

AutoIt:
    $orectangle.contains( $point ) -> retval
```

```cpp
bool dlib::rectangle::contains( dlib::point& point );

AutoIt:
    $orectangle.contains( $point ) -> retval
```

```cpp
bool dlib::rectangle::contains( long& x,
                                long& y );

AutoIt:
    $orectangle.contains( $x, $y ) -> retval
```

```cpp
bool dlib::rectangle::contains( dlib::rectangle& rect );

AutoIt:
    $orectangle.contains( $rect ) -> retval
```

### dlib::rectangle::intersect

```cpp
dlib::rectangle dlib::rectangle::intersect( dlib::rectangle& rect );

AutoIt:
    $orectangle.intersect( $rect ) -> retval
```

### dlib::rectangle::ToString

```cpp
string dlib::rectangle::ToString();

AutoIt:
    $orectangle.ToString() -> retval
```

## dlib::drectangle

### dlib::drectangle::create

```cpp
static dlib::drectangle dlib::drectangle::create();

AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create() -> <dlib.drectangle object>
```

```cpp
static dlib::drectangle dlib::drectangle::create( double& left,
                                                  double& top,
                                                  double& right,
                                                  double& bottom );

AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create( $left, $top, $right, $bottom ) -> <dlib.drectangle object>
```

```cpp
static dlib::drectangle dlib::drectangle::create( dlib::drectangle& rect );

AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create( $rect ) -> <dlib.drectangle object>
```

```cpp
static dlib::drectangle dlib::drectangle::create( dlib::rectangle& rect );

AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create( $rect ) -> <dlib.drectangle object>
```

### dlib::drectangle::area

```cpp
double dlib::drectangle::area();

AutoIt:
    $odrectangle.area() -> retval
```

### dlib::drectangle::left

```cpp
double dlib::drectangle::left();

AutoIt:
    $odrectangle.left() -> retval
```

### dlib::drectangle::top

```cpp
double dlib::drectangle::top();

AutoIt:
    $odrectangle.top() -> retval
```

### dlib::drectangle::right

```cpp
double dlib::drectangle::right();

AutoIt:
    $odrectangle.right() -> retval
```

### dlib::drectangle::bottom

```cpp
double dlib::drectangle::bottom();

AutoIt:
    $odrectangle.bottom() -> retval
```

### dlib::drectangle::width

```cpp
double dlib::drectangle::width();

AutoIt:
    $odrectangle.width() -> retval
```

### dlib::drectangle::height

```cpp
double dlib::drectangle::height();

AutoIt:
    $odrectangle.height() -> retval
```

### dlib::drectangle::tl_corner

```cpp
dlib::dpoint dlib::drectangle::tl_corner();

AutoIt:
    $odrectangle.tl_corner() -> retval
```

### dlib::drectangle::tr_corner

```cpp
dlib::dpoint dlib::drectangle::tr_corner();

AutoIt:
    $odrectangle.tr_corner() -> retval
```

### dlib::drectangle::bl_corner

```cpp
dlib::dpoint dlib::drectangle::bl_corner();

AutoIt:
    $odrectangle.bl_corner() -> retval
```

### dlib::drectangle::br_corner

```cpp
dlib::dpoint dlib::drectangle::br_corner();

AutoIt:
    $odrectangle.br_corner() -> retval
```

### dlib::drectangle::is_empty

```cpp
bool dlib::drectangle::is_empty();

AutoIt:
    $odrectangle.is_empty() -> retval
```

### dlib::drectangle::center

```cpp
dlib::dpoint dlib::drectangle::center();

AutoIt:
    $odrectangle.center() -> retval
```

### dlib::drectangle::dcenter

```cpp
dlib::dpoint dlib::drectangle::dcenter();

AutoIt:
    $odrectangle.dcenter() -> retval
```

### dlib::drectangle::contains

```cpp
bool dlib::drectangle::contains( dlib::dpoint& point );

AutoIt:
    $odrectangle.contains( $point ) -> retval
```

```cpp
bool dlib::drectangle::contains( dlib::point& point );

AutoIt:
    $odrectangle.contains( $point ) -> retval
```

```cpp
bool dlib::drectangle::contains( long& x,
                                 long& y );

AutoIt:
    $odrectangle.contains( $x, $y ) -> retval
```

```cpp
bool dlib::drectangle::contains( dlib::drectangle& rect );

AutoIt:
    $odrectangle.contains( $rect ) -> retval
```

### dlib::drectangle::intersect

```cpp
dlib::drectangle dlib::drectangle::intersect( dlib::drectangle& rect );

AutoIt:
    $odrectangle.intersect( $rect ) -> retval
```

### dlib::drectangle::ToString

```cpp
string dlib::drectangle::ToString();

AutoIt:
    $odrectangle.ToString() -> retval
```

## dlib::full_object_detection

### dlib::full_object_detection::create

```cpp
static dlib::full_object_detection dlib::full_object_detection::create();

AutoIt:
    _Dlib_ObjCreate("dlib.full_object_detection").create() -> <dlib.full_object_detection object>
```

```cpp
static dlib::full_object_detection dlib::full_object_detection::create( dlib::rectangle          rect,
                                                                        std::vector<dlib::point> parts );

AutoIt:
    _Dlib_ObjCreate("dlib.full_object_detection").create( $rect, $parts ) -> <dlib.full_object_detection object>
```

### dlib::full_object_detection::part

```cpp
dlib::point dlib::full_object_detection::part( ULONG idx );

AutoIt:
    $ofull_object_detection.part( $idx ) -> retval
```

### dlib::full_object_detection::parts

```cpp
std::vector<dlib::point> dlib::full_object_detection::parts();

AutoIt:
    $ofull_object_detection.parts() -> retval
```

## dlib::shape_predictor

### dlib::shape_predictor::create

```cpp
static dlib::shape_predictor dlib::shape_predictor::create();

AutoIt:
    _Dlib_ObjCreate("dlib.shape_predictor").create() -> <dlib.shape_predictor object>
```

```cpp
std::shared_ptr<dlib::shape_predictor> dlib::shape_predictor::create( string filename );

AutoIt:
    $oshape_predictor.create( $filename ) -> retval
```

### dlib::shape_predictor::get_call

```cpp
dlib::full_object_detection dlib::shape_predictor::get_call( cv::Mat         img,
                                                             dlib::rectangle box );

AutoIt:
    $oshape_predictor.call( $img, $box ) -> retval
    dlib.shape_predictor( $img, $box ) -> retval
```

### dlib::shape_predictor::save

```cpp
void dlib::shape_predictor::save( string detector_output_filename );

AutoIt:
    $oshape_predictor.save( $detector_output_filename ) -> None
```

## dlib::svm_c_trainer_radial_basis

### dlib::svm_c_trainer_radial_basis::create

```cpp
static dlib::svm_c_trainer_radial_basis dlib::svm_c_trainer_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_radial_basis").create() -> <dlib.svm_c_trainer_radial_basis object>
```

### dlib::svm_c_trainer_radial_basis::train

```cpp
dlib::_decision_function_radial_basis dlib::svm_c_trainer_radial_basis::train( std::vector<dlib::SpaceVector> samples,
                                                                               std::vector<double>            labels );

AutoIt:
    $osvm_c_trainer_radial_basis.train( $samples, $labels ) -> retval
```

### dlib::svm_c_trainer_radial_basis::set_c

```cpp
void dlib::svm_c_trainer_radial_basis::set_c( double c );

AutoIt:
    $osvm_c_trainer_radial_basis.set_c( $c ) -> None
```

## dlib::svm_c_trainer_sparse_radial_basis

### dlib::svm_c_trainer_sparse_radial_basis::create

```cpp
static dlib::svm_c_trainer_sparse_radial_basis dlib::svm_c_trainer_sparse_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_sparse_radial_basis").create() -> <dlib.svm_c_trainer_sparse_radial_basis object>
```

### dlib::svm_c_trainer_sparse_radial_basis::train

```cpp
dlib::_decision_function_sparse_radial_basis dlib::svm_c_trainer_sparse_radial_basis::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                             std::vector<double>                                labels );

AutoIt:
    $osvm_c_trainer_sparse_radial_basis.train( $samples, $labels ) -> retval
```

### dlib::svm_c_trainer_sparse_radial_basis::set_c

```cpp
void dlib::svm_c_trainer_sparse_radial_basis::set_c( double c );

AutoIt:
    $osvm_c_trainer_sparse_radial_basis.set_c( $c ) -> None
```

## dlib::svm_c_trainer_histogram_intersection

### dlib::svm_c_trainer_histogram_intersection::create

```cpp
static dlib::svm_c_trainer_histogram_intersection dlib::svm_c_trainer_histogram_intersection::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_histogram_intersection").create() -> <dlib.svm_c_trainer_histogram_intersection object>
```

### dlib::svm_c_trainer_histogram_intersection::train

```cpp
dlib::_decision_function_histogram_intersection dlib::svm_c_trainer_histogram_intersection::train( std::vector<dlib::SpaceVector> samples,
                                                                                                   std::vector<double>            labels );

AutoIt:
    $osvm_c_trainer_histogram_intersection.train( $samples, $labels ) -> retval
```

### dlib::svm_c_trainer_histogram_intersection::set_c

```cpp
void dlib::svm_c_trainer_histogram_intersection::set_c( double c );

AutoIt:
    $osvm_c_trainer_histogram_intersection.set_c( $c ) -> None
```

## dlib::svm_c_trainer_sparse_histogram_intersection

### dlib::svm_c_trainer_sparse_histogram_intersection::create

```cpp
static dlib::svm_c_trainer_sparse_histogram_intersection dlib::svm_c_trainer_sparse_histogram_intersection::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_sparse_histogram_intersection").create() -> <dlib.svm_c_trainer_sparse_histogram_intersection object>
```

### dlib::svm_c_trainer_sparse_histogram_intersection::train

```cpp
dlib::_decision_function_sparse_histogram_intersection dlib::svm_c_trainer_sparse_histogram_intersection::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                                                 std::vector<double>                                labels );

AutoIt:
    $osvm_c_trainer_sparse_histogram_intersection.train( $samples, $labels ) -> retval
```

### dlib::svm_c_trainer_sparse_histogram_intersection::set_c

```cpp
void dlib::svm_c_trainer_sparse_histogram_intersection::set_c( double c );

AutoIt:
    $osvm_c_trainer_sparse_histogram_intersection.set_c( $c ) -> None
```

## dlib::svm_c_trainer_linear

### dlib::svm_c_trainer_linear::create

```cpp
static dlib::svm_c_trainer_linear dlib::svm_c_trainer_linear::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_linear").create() -> <dlib.svm_c_trainer_linear object>
```

### dlib::svm_c_trainer_linear::train

```cpp
dlib::_decision_function_linear dlib::svm_c_trainer_linear::train( std::vector<dlib::SpaceVector> samples,
                                                                   std::vector<double>            labels );

AutoIt:
    $osvm_c_trainer_linear.train( $samples, $labels ) -> retval
```

### dlib::svm_c_trainer_linear::set_c

```cpp
void dlib::svm_c_trainer_linear::set_c( double c );

AutoIt:
    $osvm_c_trainer_linear.set_c( $c ) -> None
```

### dlib::svm_c_trainer_linear::set_prior

```cpp
void dlib::svm_c_trainer_linear::set_prior( dlib::_decision_function_linear prior_ );

AutoIt:
    $osvm_c_trainer_linear.set_prior( $prior_ ) -> None
```

### dlib::svm_c_trainer_linear::be_verbose

```cpp
void dlib::svm_c_trainer_linear::be_verbose();

AutoIt:
    $osvm_c_trainer_linear.be_verbose() -> None
```

### dlib::svm_c_trainer_linear::be_quiet

```cpp
void dlib::svm_c_trainer_linear::be_quiet();

AutoIt:
    $osvm_c_trainer_linear.be_quiet() -> None
```

## dlib::svm_c_trainer_sparse_linear

### dlib::svm_c_trainer_sparse_linear::create

```cpp
static dlib::svm_c_trainer_sparse_linear dlib::svm_c_trainer_sparse_linear::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_sparse_linear").create() -> <dlib.svm_c_trainer_sparse_linear object>
```

### dlib::svm_c_trainer_sparse_linear::train

```cpp
dlib::_decision_function_sparse_linear dlib::svm_c_trainer_sparse_linear::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                 std::vector<double>                                labels );

AutoIt:
    $osvm_c_trainer_sparse_linear.train( $samples, $labels ) -> retval
```

### dlib::svm_c_trainer_sparse_linear::set_c

```cpp
void dlib::svm_c_trainer_sparse_linear::set_c( double c );

AutoIt:
    $osvm_c_trainer_sparse_linear.set_c( $c ) -> None
```

### dlib::svm_c_trainer_sparse_linear::set_prior

```cpp
void dlib::svm_c_trainer_sparse_linear::set_prior( dlib::_decision_function_sparse_linear prior_ );

AutoIt:
    $osvm_c_trainer_sparse_linear.set_prior( $prior_ ) -> None
```

### dlib::svm_c_trainer_sparse_linear::be_verbose

```cpp
void dlib::svm_c_trainer_sparse_linear::be_verbose();

AutoIt:
    $osvm_c_trainer_sparse_linear.be_verbose() -> None
```

### dlib::svm_c_trainer_sparse_linear::be_quiet

```cpp
void dlib::svm_c_trainer_sparse_linear::be_quiet();

AutoIt:
    $osvm_c_trainer_sparse_linear.be_quiet() -> None
```

## dlib::rvm_trainer_radial_basis

### dlib::rvm_trainer_radial_basis::create

```cpp
static dlib::rvm_trainer_radial_basis dlib::rvm_trainer_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_radial_basis").create() -> <dlib.rvm_trainer_radial_basis object>
```

### dlib::rvm_trainer_radial_basis::train

```cpp
dlib::_decision_function_radial_basis dlib::rvm_trainer_radial_basis::train( std::vector<dlib::SpaceVector> samples,
                                                                             std::vector<double>            labels );

AutoIt:
    $orvm_trainer_radial_basis.train( $samples, $labels ) -> retval
```

## dlib::rvm_trainer_sparse_radial_basis

### dlib::rvm_trainer_sparse_radial_basis::create

```cpp
static dlib::rvm_trainer_sparse_radial_basis dlib::rvm_trainer_sparse_radial_basis::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_sparse_radial_basis").create() -> <dlib.rvm_trainer_sparse_radial_basis object>
```

### dlib::rvm_trainer_sparse_radial_basis::train

```cpp
dlib::_decision_function_sparse_radial_basis dlib::rvm_trainer_sparse_radial_basis::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                           std::vector<double>                                labels );

AutoIt:
    $orvm_trainer_sparse_radial_basis.train( $samples, $labels ) -> retval
```

## dlib::rvm_trainer_histogram_intersection

### dlib::rvm_trainer_histogram_intersection::create

```cpp
static dlib::rvm_trainer_histogram_intersection dlib::rvm_trainer_histogram_intersection::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_histogram_intersection").create() -> <dlib.rvm_trainer_histogram_intersection object>
```

### dlib::rvm_trainer_histogram_intersection::train

```cpp
dlib::_decision_function_histogram_intersection dlib::rvm_trainer_histogram_intersection::train( std::vector<dlib::SpaceVector> samples,
                                                                                                 std::vector<double>            labels );

AutoIt:
    $orvm_trainer_histogram_intersection.train( $samples, $labels ) -> retval
```

## dlib::rvm_trainer_sparse_histogram_intersection

### dlib::rvm_trainer_sparse_histogram_intersection::create

```cpp
static dlib::rvm_trainer_sparse_histogram_intersection dlib::rvm_trainer_sparse_histogram_intersection::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_sparse_histogram_intersection").create() -> <dlib.rvm_trainer_sparse_histogram_intersection object>
```

### dlib::rvm_trainer_sparse_histogram_intersection::train

```cpp
dlib::_decision_function_sparse_histogram_intersection dlib::rvm_trainer_sparse_histogram_intersection::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                                               std::vector<double>                                labels );

AutoIt:
    $orvm_trainer_sparse_histogram_intersection.train( $samples, $labels ) -> retval
```

## dlib::rvm_trainer_linear

### dlib::rvm_trainer_linear::create

```cpp
static dlib::rvm_trainer_linear dlib::rvm_trainer_linear::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_linear").create() -> <dlib.rvm_trainer_linear object>
```

### dlib::rvm_trainer_linear::train

```cpp
dlib::_decision_function_linear dlib::rvm_trainer_linear::train( std::vector<dlib::SpaceVector> samples,
                                                                 std::vector<double>            labels );

AutoIt:
    $orvm_trainer_linear.train( $samples, $labels ) -> retval
```

## dlib::rvm_trainer_sparse_linear

### dlib::rvm_trainer_sparse_linear::create

```cpp
static dlib::rvm_trainer_sparse_linear dlib::rvm_trainer_sparse_linear::create();

AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_sparse_linear").create() -> <dlib.rvm_trainer_sparse_linear object>
```

### dlib::rvm_trainer_sparse_linear::train

```cpp
dlib::_decision_function_sparse_linear dlib::rvm_trainer_sparse_linear::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                               std::vector<double>                                labels );

AutoIt:
    $orvm_trainer_sparse_linear.train( $samples, $labels ) -> retval
```

## dlib::vec_ranking_pair

### dlib::vec_ranking_pair::create

```cpp
static dlib::vec_ranking_pair dlib::vec_ranking_pair::create();

AutoIt:
    _Dlib_ObjCreate("dlib.ranking_pair").create() -> <dlib.vec_ranking_pair object>
```

```cpp
static dlib::vec_ranking_pair dlib::vec_ranking_pair::create();

AutoIt:
    _Dlib_ObjCreate("dlib.ranking_pair").create() -> <dlib.vec_ranking_pair object>
```

```cpp
static dlib::vec_ranking_pair dlib::vec_ranking_pair::create( std::vector<dlib::SpaceVector> relevant,
                                                              std::vector<dlib::SpaceVector> nonrelevant );

AutoIt:
    _Dlib_ObjCreate("dlib.ranking_pair").create( $relevant, $nonrelevant ) -> <dlib.vec_ranking_pair object>
```

## dlib::sparse_ranking_pair

### dlib::sparse_ranking_pair::create

```cpp
static dlib::sparse_ranking_pair dlib::sparse_ranking_pair::create();

AutoIt:
    _Dlib_ObjCreate("dlib.sparse_ranking_pair").create() -> <dlib.sparse_ranking_pair object>
```

```cpp
static dlib::sparse_ranking_pair dlib::sparse_ranking_pair::create();

AutoIt:
    _Dlib_ObjCreate("dlib.sparse_ranking_pair").create() -> <dlib.sparse_ranking_pair object>
```

```cpp
static dlib::sparse_ranking_pair dlib::sparse_ranking_pair::create( std::vector<std::vector<std::pair<ULONG, double>>> relevant,
                                                                    std::vector<std::vector<std::pair<ULONG, double>>> nonrelevant );

AutoIt:
    _Dlib_ObjCreate("dlib.sparse_ranking_pair").create( $relevant, $nonrelevant ) -> <dlib.sparse_ranking_pair object>
```

## dlib::vec_svm_rank_trainer

### dlib::vec_svm_rank_trainer::create

```cpp
static dlib::vec_svm_rank_trainer dlib::vec_svm_rank_trainer::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_rank_trainer").create() -> <dlib.vec_svm_rank_trainer object>
```

### dlib::vec_svm_rank_trainer::train

```cpp
dlib::_decision_function_linear dlib::vec_svm_rank_trainer::train( dlib::vec_ranking_pair sample );

AutoIt:
    $ovec_svm_rank_trainer.train( $sample ) -> retval
```

```cpp
dlib::_decision_function_linear dlib::vec_svm_rank_trainer::train( std::vector<dlib::vec_ranking_pair> samples );

AutoIt:
    $ovec_svm_rank_trainer.train( $samples ) -> retval
```

### dlib::vec_svm_rank_trainer::set_prior

```cpp
void dlib::vec_svm_rank_trainer::set_prior( dlib::_decision_function_linear prior_ );

AutoIt:
    $ovec_svm_rank_trainer.set_prior( $prior_ ) -> None
```

### dlib::vec_svm_rank_trainer::be_verbose

```cpp
void dlib::vec_svm_rank_trainer::be_verbose();

AutoIt:
    $ovec_svm_rank_trainer.be_verbose() -> None
```

### dlib::vec_svm_rank_trainer::be_quiet

```cpp
void dlib::vec_svm_rank_trainer::be_quiet();

AutoIt:
    $ovec_svm_rank_trainer.be_quiet() -> None
```

## dlib::svm_rank_trainer_sparse

### dlib::svm_rank_trainer_sparse::create

```cpp
static dlib::svm_rank_trainer_sparse dlib::svm_rank_trainer_sparse::create();

AutoIt:
    _Dlib_ObjCreate("dlib.svm_rank_trainer_sparse").create() -> <dlib.svm_rank_trainer_sparse object>
```

### dlib::svm_rank_trainer_sparse::train

```cpp
dlib::_decision_function_sparse_linear dlib::svm_rank_trainer_sparse::train( dlib::sparse_ranking_pair sample );

AutoIt:
    $osvm_rank_trainer_sparse.train( $sample ) -> retval
```

```cpp
dlib::_decision_function_sparse_linear dlib::svm_rank_trainer_sparse::train( std::vector<dlib::sparse_ranking_pair> samples );

AutoIt:
    $osvm_rank_trainer_sparse.train( $samples ) -> retval
```

### dlib::svm_rank_trainer_sparse::set_prior

```cpp
void dlib::svm_rank_trainer_sparse::set_prior( dlib::_decision_function_sparse_linear prior_ );

AutoIt:
    $osvm_rank_trainer_sparse.set_prior( $prior_ ) -> None
```

### dlib::svm_rank_trainer_sparse::be_verbose

```cpp
void dlib::svm_rank_trainer_sparse::be_verbose();

AutoIt:
    $osvm_rank_trainer_sparse.be_verbose() -> None
```

### dlib::svm_rank_trainer_sparse::be_quiet

```cpp
void dlib::svm_rank_trainer_sparse::be_quiet();

AutoIt:
    $osvm_rank_trainer_sparse.be_quiet() -> None
```

## dlib::SpaceVector

### dlib::SpaceVector::create

```cpp
static dlib::SpaceVector dlib::SpaceVector::create();

AutoIt:
    _Dlib_ObjCreate("dlib.vector").create() -> <dlib.SpaceVector object>
```

```cpp
std::shared_ptr<dlib::SpaceVector> dlib::SpaceVector::create( std::vector<double> list );

AutoIt:
    $oSpaceVector.create( $list ) -> retval
```

```cpp
std::shared_ptr<dlib::SpaceVector> dlib::SpaceVector::create( long rows );

AutoIt:
    $oSpaceVector.create( $rows ) -> retval
```

### dlib::SpaceVector::set_size

```cpp
void dlib::SpaceVector::set_size( long rows );

AutoIt:
    $oSpaceVector.set_size( $rows ) -> None
```

### dlib::SpaceVector::resize

```cpp
void dlib::SpaceVector::resize( long rows );

AutoIt:
    $oSpaceVector.resize( $rows ) -> None
```

### dlib::SpaceVector::size

```cpp
long dlib::SpaceVector::size();

AutoIt:
    $oSpaceVector.size() -> retval
```

### dlib::SpaceVector::get

```cpp
double dlib::SpaceVector::get( long row );

AutoIt:
    $oSpaceVector.get( $row ) -> retval
```

### dlib::SpaceVector::set

```cpp
void dlib::SpaceVector::set( long   row,
                             double val );

AutoIt:
    $oSpaceVector.set( $row, $val ) -> None
```

### dlib::SpaceVector::get_Item

```cpp
double dlib::SpaceVector::get_Item( long row );

AutoIt:
    $oSpaceVector.Item( $row ) -> retval
    dlib.vector( $row ) -> retval
```

### dlib::SpaceVector::put_Item

```cpp
void dlib::SpaceVector::put_Item( long   row,
                                  double val );

AutoIt:
    $oSpaceVector.Item( $row ) = $val
```

### dlib::SpaceVector::slice

```cpp
dlib::SpaceVector dlib::SpaceVector::slice( long start,
                                            long stop = this->__self->get()->size(),
                                            long step = 1 );

AutoIt:
    $oSpaceVector.slice( $start[, $stop[, $step]] ) -> retval
```

### dlib::SpaceVector::ToString

```cpp
string dlib::SpaceVector::ToString();

AutoIt:
    $oSpaceVector.ToString() -> retval
```

## dlib::point_transform_projective

### dlib::point_transform_projective::create

```cpp
static dlib::point_transform_projective dlib::point_transform_projective::create();

AutoIt:
    _Dlib_ObjCreate("dlib.point_transform_projective").create() -> <dlib.point_transform_projective object>
```

```cpp
std::shared_ptr<dlib::point_transform_projective> dlib::point_transform_projective::create( dlib::Matrix m );

AutoIt:
    $opoint_transform_projective.create( $m ) -> retval
```

```cpp
std::shared_ptr<dlib::point_transform_projective> dlib::point_transform_projective::create( cv::Mat m );

AutoIt:
    $opoint_transform_projective.create( $m ) -> retval
```

## dlib::dpoint

### dlib::dpoint::create

```cpp
static dlib::dpoint dlib::dpoint::create( double& x = 0,
                                          double& y = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib.dpoint").create( [$x[, $y]] ) -> <dlib.dpoint object>
```

```cpp
static dlib::dpoint dlib::dpoint::create( dlib::point& p );

AutoIt:
    _Dlib_ObjCreate("dlib.dpoint").create( $p ) -> <dlib.dpoint object>
```

### dlib::dpoint::normalize

```cpp
dlib::dpoint dlib::dpoint::normalize();

AutoIt:
    $odpoint.normalize() -> retval
```

### dlib::dpoint::add

```cpp
dlib::dpoint dlib::dpoint::add( dlib::dpoint& other );

AutoIt:
    $odpoint.add( $other ) -> retval
```

### dlib::dpoint::sub

```cpp
dlib::dpoint dlib::dpoint::sub( dlib::dpoint& other );

AutoIt:
    $odpoint.sub( $other ) -> retval
```

### dlib::dpoint::divide

```cpp
dlib::dpoint dlib::dpoint::divide( double& scalar );

AutoIt:
    $odpoint.divide( $scalar ) -> retval
```

### dlib::dpoint::multiply

```cpp
dlib::dpoint dlib::dpoint::multiply( double& scalar );

AutoIt:
    $odpoint.multiply( $scalar ) -> retval
```

### dlib::dpoint::ToString

```cpp
string dlib::dpoint::ToString();

AutoIt:
    $odpoint.ToString() -> retval
```

## dlib::point

### dlib::point::create

```cpp
static dlib::point dlib::point::create( long& x = 0,
                                        long& y = 0 );

AutoIt:
    _Dlib_ObjCreate("dlib.point").create( [$x[, $y]] ) -> <dlib.point object>
```

```cpp
static dlib::point dlib::point::create( dlib::dpoint& p );

AutoIt:
    _Dlib_ObjCreate("dlib.point").create( $p ) -> <dlib.point object>
```

### dlib::point::normalize

```cpp
dlib::point dlib::point::normalize();

AutoIt:
    $opoint.normalize() -> retval
```

### dlib::point::add

```cpp
dlib::point dlib::point::add( dlib::point& other );

AutoIt:
    $opoint.add( $other ) -> retval
```

### dlib::point::sub

```cpp
dlib::point dlib::point::sub( dlib::point& other );

AutoIt:
    $opoint.sub( $other ) -> retval
```

### dlib::point::divide

```cpp
dlib::point dlib::point::divide( double& scalar );

AutoIt:
    $opoint.divide( $scalar ) -> retval
```

### dlib::point::multiply

```cpp
dlib::point dlib::point::multiply( double& scalar );

AutoIt:
    $opoint.multiply( $scalar ) -> retval
```

### dlib::point::ToString

```cpp
string dlib::point::ToString();

AutoIt:
    $opoint.ToString() -> retval
```

## VectorOfVariant

### VectorOfVariant::create

```cpp
static VectorOfVariant VectorOfVariant::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVariant").create() -> <VectorOfVariant object>
```

```cpp
static VectorOfVariant VectorOfVariant::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVariant").create( $size ) -> <VectorOfVariant object>
```

```cpp
static VectorOfVariant VectorOfVariant::create( VectorOfVariant other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVariant").create( $other ) -> <VectorOfVariant object>
```

### VectorOfVariant::Keys

```cpp
std::vector<int> VectorOfVariant::Keys();

AutoIt:
    $oVectorOfVariant.Keys() -> retval
```

### VectorOfVariant::Items

```cpp
VectorOfVariant VectorOfVariant::Items();

AutoIt:
    $oVectorOfVariant.Items() -> retval
```

### VectorOfVariant::push_back

```cpp
void VectorOfVariant::push_back( _variant_t value );

AutoIt:
    $oVectorOfVariant.push_back( $value ) -> None
```

### VectorOfVariant::Add

```cpp
void VectorOfVariant::Add( _variant_t value );

AutoIt:
    $oVectorOfVariant.Add( $value ) -> None
```

### VectorOfVariant::Remove

```cpp
void VectorOfVariant::Remove( size_t index );

AutoIt:
    $oVectorOfVariant.Remove( $index ) -> None
```

### VectorOfVariant::at

```cpp
_variant_t VectorOfVariant::at( size_t index );

AutoIt:
    $oVectorOfVariant.at( $index ) -> retval
```

```cpp
void VectorOfVariant::at( size_t     index,
                          _variant_t value );

AutoIt:
    $oVectorOfVariant.at( $index, $value ) -> None
```

### VectorOfVariant::size

```cpp
size_t VectorOfVariant::size();

AutoIt:
    $oVectorOfVariant.size() -> retval
```

### VectorOfVariant::empty

```cpp
bool VectorOfVariant::empty();

AutoIt:
    $oVectorOfVariant.empty() -> retval
```

### VectorOfVariant::clear

```cpp
void VectorOfVariant::clear();

AutoIt:
    $oVectorOfVariant.clear() -> None
```

### VectorOfVariant::push_vector

```cpp
void VectorOfVariant::push_vector( VectorOfVariant other );

AutoIt:
    $oVectorOfVariant.push_vector( $other ) -> None
```

```cpp
void VectorOfVariant::push_vector( VectorOfVariant other,
                                   size_t          count,
                                   size_t          start = 0 );

AutoIt:
    $oVectorOfVariant.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVariant::slice

```cpp
VectorOfVariant VectorOfVariant::slice( size_t start = 0,
                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVariant.slice( [$start[, $count]] ) -> retval
```

### VectorOfVariant::sort

```cpp
void VectorOfVariant::sort( void*  comparator,
                            size_t start = 0,
                            size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVariant.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVariant::sort_variant

```cpp
void VectorOfVariant::sort_variant( void*  comparator,
                                    size_t start = 0,
                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVariant.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVariant::start

```cpp
void* VectorOfVariant::start();

AutoIt:
    $oVectorOfVariant.start() -> retval
```

### VectorOfVariant::end

```cpp
void* VectorOfVariant::end();

AutoIt:
    $oVectorOfVariant.end() -> retval
```

### VectorOfVariant::get_Item

```cpp
_variant_t VectorOfVariant::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVariant.Item( $vIndex ) -> retval
    VectorOfVariant( $vIndex ) -> retval
```

### VectorOfVariant::put_Item

```cpp
void VectorOfVariant::put_Item( size_t     vIndex,
                                _variant_t vItem );

AutoIt:
    $oVectorOfVariant.Item( $vIndex ) = $vItem
```

## VectorOfPairOfULONGAndDouble

### VectorOfPairOfULONGAndDouble::create

```cpp
static VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble").create() -> <VectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble").create( $size ) -> <VectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::create( VectorOfPairOfULONGAndDouble other );

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble").create( $other ) -> <VectorOfPairOfULONGAndDouble object>
```

### VectorOfPairOfULONGAndDouble::Keys

```cpp
std::vector<int> VectorOfPairOfULONGAndDouble::Keys();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.Keys() -> retval
```

### VectorOfPairOfULONGAndDouble::Items

```cpp
VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::Items();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.Items() -> retval
```

### VectorOfPairOfULONGAndDouble::push_back

```cpp
void VectorOfPairOfULONGAndDouble::push_back( std::pair<ULONG, double> value );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.push_back( $value ) -> None
```

### VectorOfPairOfULONGAndDouble::Add

```cpp
void VectorOfPairOfULONGAndDouble::Add( std::pair<ULONG, double> value );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.Add( $value ) -> None
```

### VectorOfPairOfULONGAndDouble::Remove

```cpp
void VectorOfPairOfULONGAndDouble::Remove( size_t index );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.Remove( $index ) -> None
```

### VectorOfPairOfULONGAndDouble::at

```cpp
std::pair<ULONG, double> VectorOfPairOfULONGAndDouble::at( size_t index );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.at( $index ) -> retval
```

```cpp
void VectorOfPairOfULONGAndDouble::at( size_t                   index,
                                       std::pair<ULONG, double> value );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.at( $index, $value ) -> None
```

### VectorOfPairOfULONGAndDouble::size

```cpp
size_t VectorOfPairOfULONGAndDouble::size();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.size() -> retval
```

### VectorOfPairOfULONGAndDouble::empty

```cpp
bool VectorOfPairOfULONGAndDouble::empty();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.empty() -> retval
```

### VectorOfPairOfULONGAndDouble::clear

```cpp
void VectorOfPairOfULONGAndDouble::clear();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.clear() -> None
```

### VectorOfPairOfULONGAndDouble::push_vector

```cpp
void VectorOfPairOfULONGAndDouble::push_vector( VectorOfPairOfULONGAndDouble other );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfPairOfULONGAndDouble::push_vector( VectorOfPairOfULONGAndDouble other,
                                                size_t                       count,
                                                size_t                       start = 0 );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPairOfULONGAndDouble::slice

```cpp
VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::slice( size_t start = 0,
                                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfPairOfULONGAndDouble::sort

```cpp
void VectorOfPairOfULONGAndDouble::sort( void*  comparator,
                                         size_t start = 0,
                                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndDouble::sort_variant

```cpp
void VectorOfPairOfULONGAndDouble::sort_variant( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndDouble::start

```cpp
void* VectorOfPairOfULONGAndDouble::start();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.start() -> retval
```

### VectorOfPairOfULONGAndDouble::end

```cpp
void* VectorOfPairOfULONGAndDouble::end();

AutoIt:
    $oVectorOfPairOfULONGAndDouble.end() -> retval
```

### VectorOfPairOfULONGAndDouble::get_Item

```cpp
std::pair<ULONG, double> VectorOfPairOfULONGAndDouble::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.Item( $vIndex ) -> retval
    VectorOfPairOfULONGAndDouble( $vIndex ) -> retval
```

### VectorOfPairOfULONGAndDouble::put_Item

```cpp
void VectorOfPairOfULONGAndDouble::put_Item( size_t                   vIndex,
                                             std::pair<ULONG, double> vItem );

AutoIt:
    $oVectorOfPairOfULONGAndDouble.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfPairOfULONGAndDouble

### VectorOfVectorOfPairOfULONGAndDouble::create

```cpp
static VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble").create() -> <VectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble").create( $size ) -> <VectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::create( VectorOfVectorOfPairOfULONGAndDouble other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble").create( $other ) -> <VectorOfVectorOfPairOfULONGAndDouble object>
```

### VectorOfVectorOfPairOfULONGAndDouble::Keys

```cpp
std::vector<int> VectorOfVectorOfPairOfULONGAndDouble::Keys();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Keys() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::Items

```cpp
VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::Items();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Items() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::push_back

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::push_back( std::vector<std::pair<ULONG, double>> value );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.push_back( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::Add

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::Add( std::vector<std::pair<ULONG, double>> value );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Add( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::Remove

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Remove( $index ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::at

```cpp
std::vector<std::pair<ULONG, double>> VectorOfVectorOfPairOfULONGAndDouble::at( size_t index );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::at( size_t                                index,
                                               std::vector<std::pair<ULONG, double>> value );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.at( $index, $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::size

```cpp
size_t VectorOfVectorOfPairOfULONGAndDouble::size();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.size() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::empty

```cpp
bool VectorOfVectorOfPairOfULONGAndDouble::empty();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.empty() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::clear

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::clear();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.clear() -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::push_vector

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfPairOfULONGAndDouble other );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfPairOfULONGAndDouble other,
                                                        size_t                               count,
                                                        size_t                               start = 0 );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::slice

```cpp
VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::slice( size_t start = 0,
                                                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::sort

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::sort( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::sort_variant

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::sort_variant( void*  comparator,
                                                         size_t start = 0,
                                                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::start

```cpp
void* VectorOfVectorOfPairOfULONGAndDouble::start();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.start() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::end

```cpp
void* VectorOfVectorOfPairOfULONGAndDouble::end();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.end() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::get_Item

```cpp
std::vector<std::pair<ULONG, double>> VectorOfVectorOfPairOfULONGAndDouble::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Item( $vIndex ) -> retval
    VectorOfVectorOfPairOfULONGAndDouble( $vIndex ) -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::put_Item

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::put_Item( size_t                                vIndex,
                                                     std::vector<std::pair<ULONG, double>> vItem );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Item( $vIndex ) = $vItem
```

## VectorOfMat

### VectorOfMat::create

```cpp
static VectorOfMat VectorOfMat::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfMat").create() -> <VectorOfMat object>
```

```cpp
static VectorOfMat VectorOfMat::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfMat").create( $size ) -> <VectorOfMat object>
```

```cpp
static VectorOfMat VectorOfMat::create( VectorOfMat other );

AutoIt:
    _Dlib_ObjCreate("VectorOfMat").create( $other ) -> <VectorOfMat object>
```

### VectorOfMat::Keys

```cpp
std::vector<int> VectorOfMat::Keys();

AutoIt:
    $oVectorOfMat.Keys() -> retval
```

### VectorOfMat::Items

```cpp
VectorOfMat VectorOfMat::Items();

AutoIt:
    $oVectorOfMat.Items() -> retval
```

### VectorOfMat::push_back

```cpp
void VectorOfMat::push_back( cv::Mat value );

AutoIt:
    $oVectorOfMat.push_back( $value ) -> None
```

### VectorOfMat::Add

```cpp
void VectorOfMat::Add( cv::Mat value );

AutoIt:
    $oVectorOfMat.Add( $value ) -> None
```

### VectorOfMat::Remove

```cpp
void VectorOfMat::Remove( size_t index );

AutoIt:
    $oVectorOfMat.Remove( $index ) -> None
```

### VectorOfMat::at

```cpp
cv::Mat VectorOfMat::at( size_t index );

AutoIt:
    $oVectorOfMat.at( $index ) -> retval
```

```cpp
void VectorOfMat::at( size_t  index,
                      cv::Mat value );

AutoIt:
    $oVectorOfMat.at( $index, $value ) -> None
```

### VectorOfMat::size

```cpp
size_t VectorOfMat::size();

AutoIt:
    $oVectorOfMat.size() -> retval
```

### VectorOfMat::empty

```cpp
bool VectorOfMat::empty();

AutoIt:
    $oVectorOfMat.empty() -> retval
```

### VectorOfMat::clear

```cpp
void VectorOfMat::clear();

AutoIt:
    $oVectorOfMat.clear() -> None
```

### VectorOfMat::push_vector

```cpp
void VectorOfMat::push_vector( VectorOfMat other );

AutoIt:
    $oVectorOfMat.push_vector( $other ) -> None
```

```cpp
void VectorOfMat::push_vector( VectorOfMat other,
                               size_t      count,
                               size_t      start = 0 );

AutoIt:
    $oVectorOfMat.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfMat::slice

```cpp
VectorOfMat VectorOfMat::slice( size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfMat.slice( [$start[, $count]] ) -> retval
```

### VectorOfMat::sort

```cpp
void VectorOfMat::sort( void*  comparator,
                        size_t start = 0,
                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfMat.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMat::sort_variant

```cpp
void VectorOfMat::sort_variant( void*  comparator,
                                size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfMat.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMat::start

```cpp
void* VectorOfMat::start();

AutoIt:
    $oVectorOfMat.start() -> retval
```

### VectorOfMat::end

```cpp
void* VectorOfMat::end();

AutoIt:
    $oVectorOfMat.end() -> retval
```

### VectorOfMat::get_Item

```cpp
cv::Mat VectorOfMat::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfMat.Item( $vIndex ) -> retval
    VectorOfMat( $vIndex ) -> retval
```

### VectorOfMat::put_Item

```cpp
void VectorOfMat::put_Item( size_t  vIndex,
                            cv::Mat vItem );

AutoIt:
    $oVectorOfMat.Item( $vIndex ) = $vItem
```

## VectorOfFull_object_detection

### VectorOfFull_object_detection::create

```cpp
static VectorOfFull_object_detection VectorOfFull_object_detection::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfFull_object_detection").create() -> <VectorOfFull_object_detection object>
```

```cpp
static VectorOfFull_object_detection VectorOfFull_object_detection::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfFull_object_detection").create( $size ) -> <VectorOfFull_object_detection object>
```

```cpp
static VectorOfFull_object_detection VectorOfFull_object_detection::create( VectorOfFull_object_detection other );

AutoIt:
    _Dlib_ObjCreate("VectorOfFull_object_detection").create( $other ) -> <VectorOfFull_object_detection object>
```

### VectorOfFull_object_detection::Keys

```cpp
std::vector<int> VectorOfFull_object_detection::Keys();

AutoIt:
    $oVectorOfFull_object_detection.Keys() -> retval
```

### VectorOfFull_object_detection::Items

```cpp
VectorOfFull_object_detection VectorOfFull_object_detection::Items();

AutoIt:
    $oVectorOfFull_object_detection.Items() -> retval
```

### VectorOfFull_object_detection::push_back

```cpp
void VectorOfFull_object_detection::push_back( dlib::full_object_detection value );

AutoIt:
    $oVectorOfFull_object_detection.push_back( $value ) -> None
```

### VectorOfFull_object_detection::Add

```cpp
void VectorOfFull_object_detection::Add( dlib::full_object_detection value );

AutoIt:
    $oVectorOfFull_object_detection.Add( $value ) -> None
```

### VectorOfFull_object_detection::Remove

```cpp
void VectorOfFull_object_detection::Remove( size_t index );

AutoIt:
    $oVectorOfFull_object_detection.Remove( $index ) -> None
```

### VectorOfFull_object_detection::at

```cpp
dlib::full_object_detection VectorOfFull_object_detection::at( size_t index );

AutoIt:
    $oVectorOfFull_object_detection.at( $index ) -> retval
```

```cpp
void VectorOfFull_object_detection::at( size_t                      index,
                                        dlib::full_object_detection value );

AutoIt:
    $oVectorOfFull_object_detection.at( $index, $value ) -> None
```

### VectorOfFull_object_detection::size

```cpp
size_t VectorOfFull_object_detection::size();

AutoIt:
    $oVectorOfFull_object_detection.size() -> retval
```

### VectorOfFull_object_detection::empty

```cpp
bool VectorOfFull_object_detection::empty();

AutoIt:
    $oVectorOfFull_object_detection.empty() -> retval
```

### VectorOfFull_object_detection::clear

```cpp
void VectorOfFull_object_detection::clear();

AutoIt:
    $oVectorOfFull_object_detection.clear() -> None
```

### VectorOfFull_object_detection::push_vector

```cpp
void VectorOfFull_object_detection::push_vector( VectorOfFull_object_detection other );

AutoIt:
    $oVectorOfFull_object_detection.push_vector( $other ) -> None
```

```cpp
void VectorOfFull_object_detection::push_vector( VectorOfFull_object_detection other,
                                                 size_t                        count,
                                                 size_t                        start = 0 );

AutoIt:
    $oVectorOfFull_object_detection.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFull_object_detection::slice

```cpp
VectorOfFull_object_detection VectorOfFull_object_detection::slice( size_t start = 0,
                                                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFull_object_detection.slice( [$start[, $count]] ) -> retval
```

### VectorOfFull_object_detection::sort

```cpp
void VectorOfFull_object_detection::sort( void*  comparator,
                                          size_t start = 0,
                                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFull_object_detection.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFull_object_detection::sort_variant

```cpp
void VectorOfFull_object_detection::sort_variant( void*  comparator,
                                                  size_t start = 0,
                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFull_object_detection.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFull_object_detection::start

```cpp
void* VectorOfFull_object_detection::start();

AutoIt:
    $oVectorOfFull_object_detection.start() -> retval
```

### VectorOfFull_object_detection::end

```cpp
void* VectorOfFull_object_detection::end();

AutoIt:
    $oVectorOfFull_object_detection.end() -> retval
```

### VectorOfFull_object_detection::get_Item

```cpp
dlib::full_object_detection VectorOfFull_object_detection::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfFull_object_detection.Item( $vIndex ) -> retval
    VectorOfFull_object_detection( $vIndex ) -> retval
```

### VectorOfFull_object_detection::put_Item

```cpp
void VectorOfFull_object_detection::put_Item( size_t                      vIndex,
                                              dlib::full_object_detection vItem );

AutoIt:
    $oVectorOfFull_object_detection.Item( $vIndex ) = $vItem
```

## VectorOfSpaceVector

### VectorOfSpaceVector::create

```cpp
static VectorOfSpaceVector VectorOfSpaceVector::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfSpaceVector").create() -> <VectorOfSpaceVector object>
```

```cpp
static VectorOfSpaceVector VectorOfSpaceVector::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfSpaceVector").create( $size ) -> <VectorOfSpaceVector object>
```

```cpp
static VectorOfSpaceVector VectorOfSpaceVector::create( VectorOfSpaceVector other );

AutoIt:
    _Dlib_ObjCreate("VectorOfSpaceVector").create( $other ) -> <VectorOfSpaceVector object>
```

### VectorOfSpaceVector::Keys

```cpp
std::vector<int> VectorOfSpaceVector::Keys();

AutoIt:
    $oVectorOfSpaceVector.Keys() -> retval
```

### VectorOfSpaceVector::Items

```cpp
VectorOfSpaceVector VectorOfSpaceVector::Items();

AutoIt:
    $oVectorOfSpaceVector.Items() -> retval
```

### VectorOfSpaceVector::push_back

```cpp
void VectorOfSpaceVector::push_back( dlib::SpaceVector value );

AutoIt:
    $oVectorOfSpaceVector.push_back( $value ) -> None
```

### VectorOfSpaceVector::Add

```cpp
void VectorOfSpaceVector::Add( dlib::SpaceVector value );

AutoIt:
    $oVectorOfSpaceVector.Add( $value ) -> None
```

### VectorOfSpaceVector::Remove

```cpp
void VectorOfSpaceVector::Remove( size_t index );

AutoIt:
    $oVectorOfSpaceVector.Remove( $index ) -> None
```

### VectorOfSpaceVector::at

```cpp
dlib::SpaceVector VectorOfSpaceVector::at( size_t index );

AutoIt:
    $oVectorOfSpaceVector.at( $index ) -> retval
```

```cpp
void VectorOfSpaceVector::at( size_t            index,
                              dlib::SpaceVector value );

AutoIt:
    $oVectorOfSpaceVector.at( $index, $value ) -> None
```

### VectorOfSpaceVector::size

```cpp
size_t VectorOfSpaceVector::size();

AutoIt:
    $oVectorOfSpaceVector.size() -> retval
```

### VectorOfSpaceVector::empty

```cpp
bool VectorOfSpaceVector::empty();

AutoIt:
    $oVectorOfSpaceVector.empty() -> retval
```

### VectorOfSpaceVector::clear

```cpp
void VectorOfSpaceVector::clear();

AutoIt:
    $oVectorOfSpaceVector.clear() -> None
```

### VectorOfSpaceVector::push_vector

```cpp
void VectorOfSpaceVector::push_vector( VectorOfSpaceVector other );

AutoIt:
    $oVectorOfSpaceVector.push_vector( $other ) -> None
```

```cpp
void VectorOfSpaceVector::push_vector( VectorOfSpaceVector other,
                                       size_t              count,
                                       size_t              start = 0 );

AutoIt:
    $oVectorOfSpaceVector.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSpaceVector::slice

```cpp
VectorOfSpaceVector VectorOfSpaceVector::slice( size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSpaceVector.slice( [$start[, $count]] ) -> retval
```

### VectorOfSpaceVector::sort

```cpp
void VectorOfSpaceVector::sort( void*  comparator,
                                size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSpaceVector.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSpaceVector::sort_variant

```cpp
void VectorOfSpaceVector::sort_variant( void*  comparator,
                                        size_t start = 0,
                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSpaceVector.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSpaceVector::start

```cpp
void* VectorOfSpaceVector::start();

AutoIt:
    $oVectorOfSpaceVector.start() -> retval
```

### VectorOfSpaceVector::end

```cpp
void* VectorOfSpaceVector::end();

AutoIt:
    $oVectorOfSpaceVector.end() -> retval
```

### VectorOfSpaceVector::get_Item

```cpp
dlib::SpaceVector VectorOfSpaceVector::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfSpaceVector.Item( $vIndex ) -> retval
    VectorOfSpaceVector( $vIndex ) -> retval
```

### VectorOfSpaceVector::put_Item

```cpp
void VectorOfSpaceVector::put_Item( size_t            vIndex,
                                    dlib::SpaceVector vItem );

AutoIt:
    $oVectorOfSpaceVector.Item( $vIndex ) = $vItem
```

## VectorOfULONG

### VectorOfULONG::create

```cpp
static VectorOfULONG VectorOfULONG::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfULONG").create() -> <VectorOfULONG object>
```

```cpp
static VectorOfULONG VectorOfULONG::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfULONG").create( $size ) -> <VectorOfULONG object>
```

```cpp
static VectorOfULONG VectorOfULONG::create( VectorOfULONG other );

AutoIt:
    _Dlib_ObjCreate("VectorOfULONG").create( $other ) -> <VectorOfULONG object>
```

### VectorOfULONG::Keys

```cpp
std::vector<int> VectorOfULONG::Keys();

AutoIt:
    $oVectorOfULONG.Keys() -> retval
```

### VectorOfULONG::Items

```cpp
VectorOfULONG VectorOfULONG::Items();

AutoIt:
    $oVectorOfULONG.Items() -> retval
```

### VectorOfULONG::push_back

```cpp
void VectorOfULONG::push_back( ULONG value );

AutoIt:
    $oVectorOfULONG.push_back( $value ) -> None
```

### VectorOfULONG::Add

```cpp
void VectorOfULONG::Add( ULONG value );

AutoIt:
    $oVectorOfULONG.Add( $value ) -> None
```

### VectorOfULONG::Remove

```cpp
void VectorOfULONG::Remove( size_t index );

AutoIt:
    $oVectorOfULONG.Remove( $index ) -> None
```

### VectorOfULONG::at

```cpp
ULONG VectorOfULONG::at( size_t index );

AutoIt:
    $oVectorOfULONG.at( $index ) -> retval
```

```cpp
void VectorOfULONG::at( size_t index,
                        ULONG  value );

AutoIt:
    $oVectorOfULONG.at( $index, $value ) -> None
```

### VectorOfULONG::size

```cpp
size_t VectorOfULONG::size();

AutoIt:
    $oVectorOfULONG.size() -> retval
```

### VectorOfULONG::empty

```cpp
bool VectorOfULONG::empty();

AutoIt:
    $oVectorOfULONG.empty() -> retval
```

### VectorOfULONG::clear

```cpp
void VectorOfULONG::clear();

AutoIt:
    $oVectorOfULONG.clear() -> None
```

### VectorOfULONG::push_vector

```cpp
void VectorOfULONG::push_vector( VectorOfULONG other );

AutoIt:
    $oVectorOfULONG.push_vector( $other ) -> None
```

```cpp
void VectorOfULONG::push_vector( VectorOfULONG other,
                                 size_t        count,
                                 size_t        start = 0 );

AutoIt:
    $oVectorOfULONG.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfULONG::slice

```cpp
VectorOfULONG VectorOfULONG::slice( size_t start = 0,
                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfULONG.slice( [$start[, $count]] ) -> retval
```

### VectorOfULONG::sort

```cpp
void VectorOfULONG::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfULONG.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfULONG::sort_variant

```cpp
void VectorOfULONG::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfULONG.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfULONG::start

```cpp
void* VectorOfULONG::start();

AutoIt:
    $oVectorOfULONG.start() -> retval
```

### VectorOfULONG::end

```cpp
void* VectorOfULONG::end();

AutoIt:
    $oVectorOfULONG.end() -> retval
```

### VectorOfULONG::get_Item

```cpp
ULONG VectorOfULONG::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfULONG.Item( $vIndex ) -> retval
    VectorOfULONG( $vIndex ) -> retval
```

### VectorOfULONG::put_Item

```cpp
void VectorOfULONG::put_Item( size_t vIndex,
                              ULONG  vItem );

AutoIt:
    $oVectorOfULONG.Item( $vIndex ) = $vItem
```

## VectorOfDouble

### VectorOfDouble::create

```cpp
static VectorOfDouble VectorOfDouble::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfDouble").create() -> <VectorOfDouble object>
```

```cpp
static VectorOfDouble VectorOfDouble::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfDouble").create( $size ) -> <VectorOfDouble object>
```

```cpp
static VectorOfDouble VectorOfDouble::create( VectorOfDouble other );

AutoIt:
    _Dlib_ObjCreate("VectorOfDouble").create( $other ) -> <VectorOfDouble object>
```

### VectorOfDouble::Keys

```cpp
std::vector<int> VectorOfDouble::Keys();

AutoIt:
    $oVectorOfDouble.Keys() -> retval
```

### VectorOfDouble::Items

```cpp
VectorOfDouble VectorOfDouble::Items();

AutoIt:
    $oVectorOfDouble.Items() -> retval
```

### VectorOfDouble::push_back

```cpp
void VectorOfDouble::push_back( double value );

AutoIt:
    $oVectorOfDouble.push_back( $value ) -> None
```

### VectorOfDouble::Add

```cpp
void VectorOfDouble::Add( double value );

AutoIt:
    $oVectorOfDouble.Add( $value ) -> None
```

### VectorOfDouble::Remove

```cpp
void VectorOfDouble::Remove( size_t index );

AutoIt:
    $oVectorOfDouble.Remove( $index ) -> None
```

### VectorOfDouble::at

```cpp
double VectorOfDouble::at( size_t index );

AutoIt:
    $oVectorOfDouble.at( $index ) -> retval
```

```cpp
void VectorOfDouble::at( size_t index,
                         double value );

AutoIt:
    $oVectorOfDouble.at( $index, $value ) -> None
```

### VectorOfDouble::size

```cpp
size_t VectorOfDouble::size();

AutoIt:
    $oVectorOfDouble.size() -> retval
```

### VectorOfDouble::empty

```cpp
bool VectorOfDouble::empty();

AutoIt:
    $oVectorOfDouble.empty() -> retval
```

### VectorOfDouble::clear

```cpp
void VectorOfDouble::clear();

AutoIt:
    $oVectorOfDouble.clear() -> None
```

### VectorOfDouble::push_vector

```cpp
void VectorOfDouble::push_vector( VectorOfDouble other );

AutoIt:
    $oVectorOfDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfDouble::push_vector( VectorOfDouble other,
                                  size_t         count,
                                  size_t         start = 0 );

AutoIt:
    $oVectorOfDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfDouble::slice

```cpp
VectorOfDouble VectorOfDouble::slice( size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfDouble::sort

```cpp
void VectorOfDouble::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDouble::sort_variant

```cpp
void VectorOfDouble::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDouble::start

```cpp
void* VectorOfDouble::start();

AutoIt:
    $oVectorOfDouble.start() -> retval
```

### VectorOfDouble::end

```cpp
void* VectorOfDouble::end();

AutoIt:
    $oVectorOfDouble.end() -> retval
```

### VectorOfDouble::get_Item

```cpp
double VectorOfDouble::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfDouble.Item( $vIndex ) -> retval
    VectorOfDouble( $vIndex ) -> retval
```

### VectorOfDouble::put_Item

```cpp
void VectorOfDouble::put_Item( size_t vIndex,
                               double vItem );

AutoIt:
    $oVectorOfDouble.Item( $vIndex ) = $vItem
```

## VectorOfBool

### VectorOfBool::create

```cpp
static VectorOfBool VectorOfBool::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfBool").create() -> <VectorOfBool object>
```

```cpp
static VectorOfBool VectorOfBool::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfBool").create( $size ) -> <VectorOfBool object>
```

```cpp
static VectorOfBool VectorOfBool::create( VectorOfBool other );

AutoIt:
    _Dlib_ObjCreate("VectorOfBool").create( $other ) -> <VectorOfBool object>
```

### VectorOfBool::Keys

```cpp
std::vector<int> VectorOfBool::Keys();

AutoIt:
    $oVectorOfBool.Keys() -> retval
```

### VectorOfBool::Items

```cpp
VectorOfBool VectorOfBool::Items();

AutoIt:
    $oVectorOfBool.Items() -> retval
```

### VectorOfBool::push_back

```cpp
void VectorOfBool::push_back( bool value );

AutoIt:
    $oVectorOfBool.push_back( $value ) -> None
```

### VectorOfBool::Add

```cpp
void VectorOfBool::Add( bool value );

AutoIt:
    $oVectorOfBool.Add( $value ) -> None
```

### VectorOfBool::Remove

```cpp
void VectorOfBool::Remove( size_t index );

AutoIt:
    $oVectorOfBool.Remove( $index ) -> None
```

### VectorOfBool::at

```cpp
bool VectorOfBool::at( size_t index );

AutoIt:
    $oVectorOfBool.at( $index ) -> retval
```

```cpp
void VectorOfBool::at( size_t index,
                       bool   value );

AutoIt:
    $oVectorOfBool.at( $index, $value ) -> None
```

### VectorOfBool::size

```cpp
size_t VectorOfBool::size();

AutoIt:
    $oVectorOfBool.size() -> retval
```

### VectorOfBool::empty

```cpp
bool VectorOfBool::empty();

AutoIt:
    $oVectorOfBool.empty() -> retval
```

### VectorOfBool::clear

```cpp
void VectorOfBool::clear();

AutoIt:
    $oVectorOfBool.clear() -> None
```

### VectorOfBool::push_vector

```cpp
void VectorOfBool::push_vector( VectorOfBool other );

AutoIt:
    $oVectorOfBool.push_vector( $other ) -> None
```

```cpp
void VectorOfBool::push_vector( VectorOfBool other,
                                size_t       count,
                                size_t       start = 0 );

AutoIt:
    $oVectorOfBool.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfBool::slice

```cpp
VectorOfBool VectorOfBool::slice( size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfBool.slice( [$start[, $count]] ) -> retval
```

### VectorOfBool::sort

```cpp
void VectorOfBool::sort( void*  comparator,
                         size_t start = 0,
                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfBool.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfBool::sort_variant

```cpp
void VectorOfBool::sort_variant( void*  comparator,
                                 size_t start = 0,
                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfBool.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfBool::start

```cpp
void* VectorOfBool::start();

AutoIt:
    $oVectorOfBool.start() -> retval
```

### VectorOfBool::end

```cpp
void* VectorOfBool::end();

AutoIt:
    $oVectorOfBool.end() -> retval
```

### VectorOfBool::get_Item

```cpp
bool VectorOfBool::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfBool.Item( $vIndex ) -> retval
    VectorOfBool( $vIndex ) -> retval
```

### VectorOfBool::put_Item

```cpp
void VectorOfBool::put_Item( size_t vIndex,
                             bool   vItem );

AutoIt:
    $oVectorOfBool.Item( $vIndex ) = $vItem
```

## VectorOfRectangle

### VectorOfRectangle::create

```cpp
static VectorOfRectangle VectorOfRectangle::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfRectangle").create() -> <VectorOfRectangle object>
```

```cpp
static VectorOfRectangle VectorOfRectangle::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfRectangle").create( $size ) -> <VectorOfRectangle object>
```

```cpp
static VectorOfRectangle VectorOfRectangle::create( VectorOfRectangle other );

AutoIt:
    _Dlib_ObjCreate("VectorOfRectangle").create( $other ) -> <VectorOfRectangle object>
```

### VectorOfRectangle::Keys

```cpp
std::vector<int> VectorOfRectangle::Keys();

AutoIt:
    $oVectorOfRectangle.Keys() -> retval
```

### VectorOfRectangle::Items

```cpp
VectorOfRectangle VectorOfRectangle::Items();

AutoIt:
    $oVectorOfRectangle.Items() -> retval
```

### VectorOfRectangle::push_back

```cpp
void VectorOfRectangle::push_back( dlib::rectangle value );

AutoIt:
    $oVectorOfRectangle.push_back( $value ) -> None
```

### VectorOfRectangle::Add

```cpp
void VectorOfRectangle::Add( dlib::rectangle value );

AutoIt:
    $oVectorOfRectangle.Add( $value ) -> None
```

### VectorOfRectangle::Remove

```cpp
void VectorOfRectangle::Remove( size_t index );

AutoIt:
    $oVectorOfRectangle.Remove( $index ) -> None
```

### VectorOfRectangle::at

```cpp
dlib::rectangle VectorOfRectangle::at( size_t index );

AutoIt:
    $oVectorOfRectangle.at( $index ) -> retval
```

```cpp
void VectorOfRectangle::at( size_t          index,
                            dlib::rectangle value );

AutoIt:
    $oVectorOfRectangle.at( $index, $value ) -> None
```

### VectorOfRectangle::size

```cpp
size_t VectorOfRectangle::size();

AutoIt:
    $oVectorOfRectangle.size() -> retval
```

### VectorOfRectangle::empty

```cpp
bool VectorOfRectangle::empty();

AutoIt:
    $oVectorOfRectangle.empty() -> retval
```

### VectorOfRectangle::clear

```cpp
void VectorOfRectangle::clear();

AutoIt:
    $oVectorOfRectangle.clear() -> None
```

### VectorOfRectangle::push_vector

```cpp
void VectorOfRectangle::push_vector( VectorOfRectangle other );

AutoIt:
    $oVectorOfRectangle.push_vector( $other ) -> None
```

```cpp
void VectorOfRectangle::push_vector( VectorOfRectangle other,
                                     size_t            count,
                                     size_t            start = 0 );

AutoIt:
    $oVectorOfRectangle.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfRectangle::slice

```cpp
VectorOfRectangle VectorOfRectangle::slice( size_t start = 0,
                                            size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfRectangle.slice( [$start[, $count]] ) -> retval
```

### VectorOfRectangle::sort

```cpp
void VectorOfRectangle::sort( void*  comparator,
                              size_t start = 0,
                              size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfRectangle.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfRectangle::sort_variant

```cpp
void VectorOfRectangle::sort_variant( void*  comparator,
                                      size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfRectangle.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfRectangle::start

```cpp
void* VectorOfRectangle::start();

AutoIt:
    $oVectorOfRectangle.start() -> retval
```

### VectorOfRectangle::end

```cpp
void* VectorOfRectangle::end();

AutoIt:
    $oVectorOfRectangle.end() -> retval
```

### VectorOfRectangle::get_Item

```cpp
dlib::rectangle VectorOfRectangle::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfRectangle.Item( $vIndex ) -> retval
    VectorOfRectangle( $vIndex ) -> retval
```

### VectorOfRectangle::put_Item

```cpp
void VectorOfRectangle::put_Item( size_t          vIndex,
                                  dlib::rectangle vItem );

AutoIt:
    $oVectorOfRectangle.Item( $vIndex ) = $vItem
```

## VectorOfLong

### VectorOfLong::create

```cpp
static VectorOfLong VectorOfLong::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfLong").create() -> <VectorOfLong object>
```

```cpp
static VectorOfLong VectorOfLong::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfLong").create( $size ) -> <VectorOfLong object>
```

```cpp
static VectorOfLong VectorOfLong::create( VectorOfLong other );

AutoIt:
    _Dlib_ObjCreate("VectorOfLong").create( $other ) -> <VectorOfLong object>
```

### VectorOfLong::Keys

```cpp
std::vector<int> VectorOfLong::Keys();

AutoIt:
    $oVectorOfLong.Keys() -> retval
```

### VectorOfLong::Items

```cpp
VectorOfLong VectorOfLong::Items();

AutoIt:
    $oVectorOfLong.Items() -> retval
```

### VectorOfLong::push_back

```cpp
void VectorOfLong::push_back( long value );

AutoIt:
    $oVectorOfLong.push_back( $value ) -> None
```

### VectorOfLong::Add

```cpp
void VectorOfLong::Add( long value );

AutoIt:
    $oVectorOfLong.Add( $value ) -> None
```

### VectorOfLong::Remove

```cpp
void VectorOfLong::Remove( size_t index );

AutoIt:
    $oVectorOfLong.Remove( $index ) -> None
```

### VectorOfLong::at

```cpp
long VectorOfLong::at( size_t index );

AutoIt:
    $oVectorOfLong.at( $index ) -> retval
```

```cpp
void VectorOfLong::at( size_t index,
                       long   value );

AutoIt:
    $oVectorOfLong.at( $index, $value ) -> None
```

### VectorOfLong::size

```cpp
size_t VectorOfLong::size();

AutoIt:
    $oVectorOfLong.size() -> retval
```

### VectorOfLong::empty

```cpp
bool VectorOfLong::empty();

AutoIt:
    $oVectorOfLong.empty() -> retval
```

### VectorOfLong::clear

```cpp
void VectorOfLong::clear();

AutoIt:
    $oVectorOfLong.clear() -> None
```

### VectorOfLong::push_vector

```cpp
void VectorOfLong::push_vector( VectorOfLong other );

AutoIt:
    $oVectorOfLong.push_vector( $other ) -> None
```

```cpp
void VectorOfLong::push_vector( VectorOfLong other,
                                size_t       count,
                                size_t       start = 0 );

AutoIt:
    $oVectorOfLong.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfLong::slice

```cpp
VectorOfLong VectorOfLong::slice( size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfLong.slice( [$start[, $count]] ) -> retval
```

### VectorOfLong::sort

```cpp
void VectorOfLong::sort( void*  comparator,
                         size_t start = 0,
                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfLong.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfLong::sort_variant

```cpp
void VectorOfLong::sort_variant( void*  comparator,
                                 size_t start = 0,
                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfLong.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfLong::start

```cpp
void* VectorOfLong::start();

AutoIt:
    $oVectorOfLong.start() -> retval
```

### VectorOfLong::end

```cpp
void* VectorOfLong::end();

AutoIt:
    $oVectorOfLong.end() -> retval
```

### VectorOfLong::get_Item

```cpp
long VectorOfLong::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfLong.Item( $vIndex ) -> retval
    VectorOfLong( $vIndex ) -> retval
```

### VectorOfLong::put_Item

```cpp
void VectorOfLong::put_Item( size_t vIndex,
                             long   vItem );

AutoIt:
    $oVectorOfLong.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfSpaceVector

### VectorOfVectorOfSpaceVector::create

```cpp
static VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfSpaceVector").create() -> <VectorOfVectorOfSpaceVector object>
```

```cpp
static VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfSpaceVector").create( $size ) -> <VectorOfVectorOfSpaceVector object>
```

```cpp
static VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::create( VectorOfVectorOfSpaceVector other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfSpaceVector").create( $other ) -> <VectorOfVectorOfSpaceVector object>
```

### VectorOfVectorOfSpaceVector::Keys

```cpp
std::vector<int> VectorOfVectorOfSpaceVector::Keys();

AutoIt:
    $oVectorOfVectorOfSpaceVector.Keys() -> retval
```

### VectorOfVectorOfSpaceVector::Items

```cpp
VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::Items();

AutoIt:
    $oVectorOfVectorOfSpaceVector.Items() -> retval
```

### VectorOfVectorOfSpaceVector::push_back

```cpp
void VectorOfVectorOfSpaceVector::push_back( std::vector<dlib::SpaceVector> value );

AutoIt:
    $oVectorOfVectorOfSpaceVector.push_back( $value ) -> None
```

### VectorOfVectorOfSpaceVector::Add

```cpp
void VectorOfVectorOfSpaceVector::Add( std::vector<dlib::SpaceVector> value );

AutoIt:
    $oVectorOfVectorOfSpaceVector.Add( $value ) -> None
```

### VectorOfVectorOfSpaceVector::Remove

```cpp
void VectorOfVectorOfSpaceVector::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfSpaceVector.Remove( $index ) -> None
```

### VectorOfVectorOfSpaceVector::at

```cpp
std::vector<dlib::SpaceVector> VectorOfVectorOfSpaceVector::at( size_t index );

AutoIt:
    $oVectorOfVectorOfSpaceVector.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfSpaceVector::at( size_t                         index,
                                      std::vector<dlib::SpaceVector> value );

AutoIt:
    $oVectorOfVectorOfSpaceVector.at( $index, $value ) -> None
```

### VectorOfVectorOfSpaceVector::size

```cpp
size_t VectorOfVectorOfSpaceVector::size();

AutoIt:
    $oVectorOfVectorOfSpaceVector.size() -> retval
```

### VectorOfVectorOfSpaceVector::empty

```cpp
bool VectorOfVectorOfSpaceVector::empty();

AutoIt:
    $oVectorOfVectorOfSpaceVector.empty() -> retval
```

### VectorOfVectorOfSpaceVector::clear

```cpp
void VectorOfVectorOfSpaceVector::clear();

AutoIt:
    $oVectorOfVectorOfSpaceVector.clear() -> None
```

### VectorOfVectorOfSpaceVector::push_vector

```cpp
void VectorOfVectorOfSpaceVector::push_vector( VectorOfVectorOfSpaceVector other );

AutoIt:
    $oVectorOfVectorOfSpaceVector.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfSpaceVector::push_vector( VectorOfVectorOfSpaceVector other,
                                               size_t                      count,
                                               size_t                      start = 0 );

AutoIt:
    $oVectorOfVectorOfSpaceVector.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfSpaceVector::slice

```cpp
VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::slice( size_t start = 0,
                                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfSpaceVector.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfSpaceVector::sort

```cpp
void VectorOfVectorOfSpaceVector::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfSpaceVector.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfSpaceVector::sort_variant

```cpp
void VectorOfVectorOfSpaceVector::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfSpaceVector.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfSpaceVector::start

```cpp
void* VectorOfVectorOfSpaceVector::start();

AutoIt:
    $oVectorOfVectorOfSpaceVector.start() -> retval
```

### VectorOfVectorOfSpaceVector::end

```cpp
void* VectorOfVectorOfSpaceVector::end();

AutoIt:
    $oVectorOfVectorOfSpaceVector.end() -> retval
```

### VectorOfVectorOfSpaceVector::get_Item

```cpp
std::vector<dlib::SpaceVector> VectorOfVectorOfSpaceVector::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfSpaceVector.Item( $vIndex ) -> retval
    VectorOfVectorOfSpaceVector( $vIndex ) -> retval
```

### VectorOfVectorOfSpaceVector::put_Item

```cpp
void VectorOfVectorOfSpaceVector::put_Item( size_t                         vIndex,
                                            std::vector<dlib::SpaceVector> vItem );

AutoIt:
    $oVectorOfVectorOfSpaceVector.Item( $vIndex ) = $vItem
```

## VectorOfPairOfULONGAndULONG

### VectorOfPairOfULONGAndULONG::create

```cpp
static VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG").create() -> <VectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG").create( $size ) -> <VectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::create( VectorOfPairOfULONGAndULONG other );

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG").create( $other ) -> <VectorOfPairOfULONGAndULONG object>
```

### VectorOfPairOfULONGAndULONG::Keys

```cpp
std::vector<int> VectorOfPairOfULONGAndULONG::Keys();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.Keys() -> retval
```

### VectorOfPairOfULONGAndULONG::Items

```cpp
VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::Items();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.Items() -> retval
```

### VectorOfPairOfULONGAndULONG::push_back

```cpp
void VectorOfPairOfULONGAndULONG::push_back( std::pair<ULONG, ULONG> value );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.push_back( $value ) -> None
```

### VectorOfPairOfULONGAndULONG::Add

```cpp
void VectorOfPairOfULONGAndULONG::Add( std::pair<ULONG, ULONG> value );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.Add( $value ) -> None
```

### VectorOfPairOfULONGAndULONG::Remove

```cpp
void VectorOfPairOfULONGAndULONG::Remove( size_t index );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.Remove( $index ) -> None
```

### VectorOfPairOfULONGAndULONG::at

```cpp
std::pair<ULONG, ULONG> VectorOfPairOfULONGAndULONG::at( size_t index );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.at( $index ) -> retval
```

```cpp
void VectorOfPairOfULONGAndULONG::at( size_t                  index,
                                      std::pair<ULONG, ULONG> value );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.at( $index, $value ) -> None
```

### VectorOfPairOfULONGAndULONG::size

```cpp
size_t VectorOfPairOfULONGAndULONG::size();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.size() -> retval
```

### VectorOfPairOfULONGAndULONG::empty

```cpp
bool VectorOfPairOfULONGAndULONG::empty();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.empty() -> retval
```

### VectorOfPairOfULONGAndULONG::clear

```cpp
void VectorOfPairOfULONGAndULONG::clear();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.clear() -> None
```

### VectorOfPairOfULONGAndULONG::push_vector

```cpp
void VectorOfPairOfULONGAndULONG::push_vector( VectorOfPairOfULONGAndULONG other );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.push_vector( $other ) -> None
```

```cpp
void VectorOfPairOfULONGAndULONG::push_vector( VectorOfPairOfULONGAndULONG other,
                                               size_t                      count,
                                               size_t                      start = 0 );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPairOfULONGAndULONG::slice

```cpp
VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::slice( size_t start = 0,
                                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.slice( [$start[, $count]] ) -> retval
```

### VectorOfPairOfULONGAndULONG::sort

```cpp
void VectorOfPairOfULONGAndULONG::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndULONG::sort_variant

```cpp
void VectorOfPairOfULONGAndULONG::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndULONG::start

```cpp
void* VectorOfPairOfULONGAndULONG::start();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.start() -> retval
```

### VectorOfPairOfULONGAndULONG::end

```cpp
void* VectorOfPairOfULONGAndULONG::end();

AutoIt:
    $oVectorOfPairOfULONGAndULONG.end() -> retval
```

### VectorOfPairOfULONGAndULONG::get_Item

```cpp
std::pair<ULONG, ULONG> VectorOfPairOfULONGAndULONG::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.Item( $vIndex ) -> retval
    VectorOfPairOfULONGAndULONG( $vIndex ) -> retval
```

### VectorOfPairOfULONGAndULONG::put_Item

```cpp
void VectorOfPairOfULONGAndULONG::put_Item( size_t                  vIndex,
                                            std::pair<ULONG, ULONG> vItem );

AutoIt:
    $oVectorOfPairOfULONGAndULONG.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfPairOfULONGAndULONG

### VectorOfVectorOfPairOfULONGAndULONG::create

```cpp
static VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG").create() -> <VectorOfVectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG").create( $size ) -> <VectorOfVectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::create( VectorOfVectorOfPairOfULONGAndULONG other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG").create( $other ) -> <VectorOfVectorOfPairOfULONGAndULONG object>
```

### VectorOfVectorOfPairOfULONGAndULONG::Keys

```cpp
std::vector<int> VectorOfVectorOfPairOfULONGAndULONG::Keys();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Keys() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::Items

```cpp
VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::Items();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Items() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::push_back

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::push_back( std::vector<std::pair<ULONG, ULONG>> value );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.push_back( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::Add

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::Add( std::vector<std::pair<ULONG, ULONG>> value );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Add( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::Remove

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Remove( $index ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::at

```cpp
std::vector<std::pair<ULONG, ULONG>> VectorOfVectorOfPairOfULONGAndULONG::at( size_t index );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::at( size_t                               index,
                                              std::vector<std::pair<ULONG, ULONG>> value );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.at( $index, $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::size

```cpp
size_t VectorOfVectorOfPairOfULONGAndULONG::size();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.size() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::empty

```cpp
bool VectorOfVectorOfPairOfULONGAndULONG::empty();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.empty() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::clear

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::clear();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.clear() -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::push_vector

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::push_vector( VectorOfVectorOfPairOfULONGAndULONG other );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::push_vector( VectorOfVectorOfPairOfULONGAndULONG other,
                                                       size_t                              count,
                                                       size_t                              start = 0 );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::slice

```cpp
VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::slice( size_t start = 0,
                                                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::sort

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::sort( void*  comparator,
                                                size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::sort_variant

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::sort_variant( void*  comparator,
                                                        size_t start = 0,
                                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::start

```cpp
void* VectorOfVectorOfPairOfULONGAndULONG::start();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.start() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::end

```cpp
void* VectorOfVectorOfPairOfULONGAndULONG::end();

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.end() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::get_Item

```cpp
std::vector<std::pair<ULONG, ULONG>> VectorOfVectorOfPairOfULONGAndULONG::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Item( $vIndex ) -> retval
    VectorOfVectorOfPairOfULONGAndULONG( $vIndex ) -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::put_Item

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::put_Item( size_t                               vIndex,
                                                    std::vector<std::pair<ULONG, ULONG>> vItem );

AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfVectorOfPairOfULONGAndDouble

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::create

```cpp
static VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble").create() -> <VectorOfVectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble").create( $size ) -> <VectorOfVectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::create( VectorOfVectorOfVectorOfPairOfULONGAndDouble other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble").create( $other ) -> <VectorOfVectorOfVectorOfPairOfULONGAndDouble object>
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Keys

```cpp
std::vector<int> VectorOfVectorOfVectorOfPairOfULONGAndDouble::Keys();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Keys() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Items

```cpp
VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::Items();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Items() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_back

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_back( std::vector<std::vector<std::pair<ULONG, double>>> value );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.push_back( $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Add

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::Add( std::vector<std::vector<std::pair<ULONG, double>>> value );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Add( $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Remove

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Remove( $index ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::at

```cpp
std::vector<std::vector<std::pair<ULONG, double>>> VectorOfVectorOfVectorOfPairOfULONGAndDouble::at( size_t index );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::at( size_t                                             index,
                                                       std::vector<std::vector<std::pair<ULONG, double>>> value );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.at( $index, $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::size

```cpp
size_t VectorOfVectorOfVectorOfPairOfULONGAndDouble::size();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.size() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::empty

```cpp
bool VectorOfVectorOfVectorOfPairOfULONGAndDouble::empty();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.empty() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::clear

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::clear();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.clear() -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_vector

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfVectorOfPairOfULONGAndDouble other );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfVectorOfPairOfULONGAndDouble other,
                                                                size_t                                       count,
                                                                size_t                                       start = 0 );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::slice

```cpp
VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::slice( size_t start = 0,
                                                                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort( void*  comparator,
                                                         size_t start = 0,
                                                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort_variant

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort_variant( void*  comparator,
                                                                 size_t start = 0,
                                                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::start

```cpp
void* VectorOfVectorOfVectorOfPairOfULONGAndDouble::start();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.start() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::end

```cpp
void* VectorOfVectorOfVectorOfPairOfULONGAndDouble::end();

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.end() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::get_Item

```cpp
std::vector<std::vector<std::pair<ULONG, double>>> VectorOfVectorOfVectorOfPairOfULONGAndDouble::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Item( $vIndex ) -> retval
    VectorOfVectorOfVectorOfPairOfULONGAndDouble( $vIndex ) -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::put_Item

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::put_Item( size_t                                             vIndex,
                                                             std::vector<std::vector<std::pair<ULONG, double>>> vItem );

AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfFull_object_detection

### VectorOfVectorOfFull_object_detection::create

```cpp
static VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFull_object_detection").create() -> <VectorOfVectorOfFull_object_detection object>
```

```cpp
static VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFull_object_detection").create( $size ) -> <VectorOfVectorOfFull_object_detection object>
```

```cpp
static VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::create( VectorOfVectorOfFull_object_detection other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFull_object_detection").create( $other ) -> <VectorOfVectorOfFull_object_detection object>
```

### VectorOfVectorOfFull_object_detection::Keys

```cpp
std::vector<int> VectorOfVectorOfFull_object_detection::Keys();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.Keys() -> retval
```

### VectorOfVectorOfFull_object_detection::Items

```cpp
VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::Items();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.Items() -> retval
```

### VectorOfVectorOfFull_object_detection::push_back

```cpp
void VectorOfVectorOfFull_object_detection::push_back( std::vector<dlib::full_object_detection> value );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.push_back( $value ) -> None
```

### VectorOfVectorOfFull_object_detection::Add

```cpp
void VectorOfVectorOfFull_object_detection::Add( std::vector<dlib::full_object_detection> value );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.Add( $value ) -> None
```

### VectorOfVectorOfFull_object_detection::Remove

```cpp
void VectorOfVectorOfFull_object_detection::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.Remove( $index ) -> None
```

### VectorOfVectorOfFull_object_detection::at

```cpp
std::vector<dlib::full_object_detection> VectorOfVectorOfFull_object_detection::at( size_t index );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfFull_object_detection::at( size_t                                   index,
                                                std::vector<dlib::full_object_detection> value );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.at( $index, $value ) -> None
```

### VectorOfVectorOfFull_object_detection::size

```cpp
size_t VectorOfVectorOfFull_object_detection::size();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.size() -> retval
```

### VectorOfVectorOfFull_object_detection::empty

```cpp
bool VectorOfVectorOfFull_object_detection::empty();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.empty() -> retval
```

### VectorOfVectorOfFull_object_detection::clear

```cpp
void VectorOfVectorOfFull_object_detection::clear();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.clear() -> None
```

### VectorOfVectorOfFull_object_detection::push_vector

```cpp
void VectorOfVectorOfFull_object_detection::push_vector( VectorOfVectorOfFull_object_detection other );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfFull_object_detection::push_vector( VectorOfVectorOfFull_object_detection other,
                                                         size_t                                count,
                                                         size_t                                start = 0 );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfFull_object_detection::slice

```cpp
VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::slice( size_t start = 0,
                                                                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfFull_object_detection::sort

```cpp
void VectorOfVectorOfFull_object_detection::sort( void*  comparator,
                                                  size_t start = 0,
                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFull_object_detection::sort_variant

```cpp
void VectorOfVectorOfFull_object_detection::sort_variant( void*  comparator,
                                                          size_t start = 0,
                                                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFull_object_detection::start

```cpp
void* VectorOfVectorOfFull_object_detection::start();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.start() -> retval
```

### VectorOfVectorOfFull_object_detection::end

```cpp
void* VectorOfVectorOfFull_object_detection::end();

AutoIt:
    $oVectorOfVectorOfFull_object_detection.end() -> retval
```

### VectorOfVectorOfFull_object_detection::get_Item

```cpp
std::vector<dlib::full_object_detection> VectorOfVectorOfFull_object_detection::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.Item( $vIndex ) -> retval
    VectorOfVectorOfFull_object_detection( $vIndex ) -> retval
```

### VectorOfVectorOfFull_object_detection::put_Item

```cpp
void VectorOfVectorOfFull_object_detection::put_Item( size_t                                   vIndex,
                                                      std::vector<dlib::full_object_detection> vItem );

AutoIt:
    $oVectorOfVectorOfFull_object_detection.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfRectangle

### VectorOfVectorOfRectangle::create

```cpp
static VectorOfVectorOfRectangle VectorOfVectorOfRectangle::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfRectangle").create() -> <VectorOfVectorOfRectangle object>
```

```cpp
static VectorOfVectorOfRectangle VectorOfVectorOfRectangle::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfRectangle").create( $size ) -> <VectorOfVectorOfRectangle object>
```

```cpp
static VectorOfVectorOfRectangle VectorOfVectorOfRectangle::create( VectorOfVectorOfRectangle other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfRectangle").create( $other ) -> <VectorOfVectorOfRectangle object>
```

### VectorOfVectorOfRectangle::Keys

```cpp
std::vector<int> VectorOfVectorOfRectangle::Keys();

AutoIt:
    $oVectorOfVectorOfRectangle.Keys() -> retval
```

### VectorOfVectorOfRectangle::Items

```cpp
VectorOfVectorOfRectangle VectorOfVectorOfRectangle::Items();

AutoIt:
    $oVectorOfVectorOfRectangle.Items() -> retval
```

### VectorOfVectorOfRectangle::push_back

```cpp
void VectorOfVectorOfRectangle::push_back( std::vector<dlib::rectangle> value );

AutoIt:
    $oVectorOfVectorOfRectangle.push_back( $value ) -> None
```

### VectorOfVectorOfRectangle::Add

```cpp
void VectorOfVectorOfRectangle::Add( std::vector<dlib::rectangle> value );

AutoIt:
    $oVectorOfVectorOfRectangle.Add( $value ) -> None
```

### VectorOfVectorOfRectangle::Remove

```cpp
void VectorOfVectorOfRectangle::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfRectangle.Remove( $index ) -> None
```

### VectorOfVectorOfRectangle::at

```cpp
std::vector<dlib::rectangle> VectorOfVectorOfRectangle::at( size_t index );

AutoIt:
    $oVectorOfVectorOfRectangle.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfRectangle::at( size_t                       index,
                                    std::vector<dlib::rectangle> value );

AutoIt:
    $oVectorOfVectorOfRectangle.at( $index, $value ) -> None
```

### VectorOfVectorOfRectangle::size

```cpp
size_t VectorOfVectorOfRectangle::size();

AutoIt:
    $oVectorOfVectorOfRectangle.size() -> retval
```

### VectorOfVectorOfRectangle::empty

```cpp
bool VectorOfVectorOfRectangle::empty();

AutoIt:
    $oVectorOfVectorOfRectangle.empty() -> retval
```

### VectorOfVectorOfRectangle::clear

```cpp
void VectorOfVectorOfRectangle::clear();

AutoIt:
    $oVectorOfVectorOfRectangle.clear() -> None
```

### VectorOfVectorOfRectangle::push_vector

```cpp
void VectorOfVectorOfRectangle::push_vector( VectorOfVectorOfRectangle other );

AutoIt:
    $oVectorOfVectorOfRectangle.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfRectangle::push_vector( VectorOfVectorOfRectangle other,
                                             size_t                    count,
                                             size_t                    start = 0 );

AutoIt:
    $oVectorOfVectorOfRectangle.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfRectangle::slice

```cpp
VectorOfVectorOfRectangle VectorOfVectorOfRectangle::slice( size_t start = 0,
                                                            size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfRectangle.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfRectangle::sort

```cpp
void VectorOfVectorOfRectangle::sort( void*  comparator,
                                      size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfRectangle.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfRectangle::sort_variant

```cpp
void VectorOfVectorOfRectangle::sort_variant( void*  comparator,
                                              size_t start = 0,
                                              size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfRectangle.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfRectangle::start

```cpp
void* VectorOfVectorOfRectangle::start();

AutoIt:
    $oVectorOfVectorOfRectangle.start() -> retval
```

### VectorOfVectorOfRectangle::end

```cpp
void* VectorOfVectorOfRectangle::end();

AutoIt:
    $oVectorOfVectorOfRectangle.end() -> retval
```

### VectorOfVectorOfRectangle::get_Item

```cpp
std::vector<dlib::rectangle> VectorOfVectorOfRectangle::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfRectangle.Item( $vIndex ) -> retval
    VectorOfVectorOfRectangle( $vIndex ) -> retval
```

### VectorOfVectorOfRectangle::put_Item

```cpp
void VectorOfVectorOfRectangle::put_Item( size_t                       vIndex,
                                          std::vector<dlib::rectangle> vItem );

AutoIt:
    $oVectorOfVectorOfRectangle.Item( $vIndex ) = $vItem
```

## VectorOfVec_ranking_pair

### VectorOfVec_ranking_pair::create

```cpp
static VectorOfVec_ranking_pair VectorOfVec_ranking_pair::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVec_ranking_pair").create() -> <VectorOfVec_ranking_pair object>
```

```cpp
static VectorOfVec_ranking_pair VectorOfVec_ranking_pair::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVec_ranking_pair").create( $size ) -> <VectorOfVec_ranking_pair object>
```

```cpp
static VectorOfVec_ranking_pair VectorOfVec_ranking_pair::create( VectorOfVec_ranking_pair other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVec_ranking_pair").create( $other ) -> <VectorOfVec_ranking_pair object>
```

### VectorOfVec_ranking_pair::Keys

```cpp
std::vector<int> VectorOfVec_ranking_pair::Keys();

AutoIt:
    $oVectorOfVec_ranking_pair.Keys() -> retval
```

### VectorOfVec_ranking_pair::Items

```cpp
VectorOfVec_ranking_pair VectorOfVec_ranking_pair::Items();

AutoIt:
    $oVectorOfVec_ranking_pair.Items() -> retval
```

### VectorOfVec_ranking_pair::push_back

```cpp
void VectorOfVec_ranking_pair::push_back( dlib::vec_ranking_pair value );

AutoIt:
    $oVectorOfVec_ranking_pair.push_back( $value ) -> None
```

### VectorOfVec_ranking_pair::Add

```cpp
void VectorOfVec_ranking_pair::Add( dlib::vec_ranking_pair value );

AutoIt:
    $oVectorOfVec_ranking_pair.Add( $value ) -> None
```

### VectorOfVec_ranking_pair::Remove

```cpp
void VectorOfVec_ranking_pair::Remove( size_t index );

AutoIt:
    $oVectorOfVec_ranking_pair.Remove( $index ) -> None
```

### VectorOfVec_ranking_pair::at

```cpp
dlib::vec_ranking_pair VectorOfVec_ranking_pair::at( size_t index );

AutoIt:
    $oVectorOfVec_ranking_pair.at( $index ) -> retval
```

```cpp
void VectorOfVec_ranking_pair::at( size_t                 index,
                                   dlib::vec_ranking_pair value );

AutoIt:
    $oVectorOfVec_ranking_pair.at( $index, $value ) -> None
```

### VectorOfVec_ranking_pair::size

```cpp
size_t VectorOfVec_ranking_pair::size();

AutoIt:
    $oVectorOfVec_ranking_pair.size() -> retval
```

### VectorOfVec_ranking_pair::empty

```cpp
bool VectorOfVec_ranking_pair::empty();

AutoIt:
    $oVectorOfVec_ranking_pair.empty() -> retval
```

### VectorOfVec_ranking_pair::clear

```cpp
void VectorOfVec_ranking_pair::clear();

AutoIt:
    $oVectorOfVec_ranking_pair.clear() -> None
```

### VectorOfVec_ranking_pair::push_vector

```cpp
void VectorOfVec_ranking_pair::push_vector( VectorOfVec_ranking_pair other );

AutoIt:
    $oVectorOfVec_ranking_pair.push_vector( $other ) -> None
```

```cpp
void VectorOfVec_ranking_pair::push_vector( VectorOfVec_ranking_pair other,
                                            size_t                   count,
                                            size_t                   start = 0 );

AutoIt:
    $oVectorOfVec_ranking_pair.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec_ranking_pair::slice

```cpp
VectorOfVec_ranking_pair VectorOfVec_ranking_pair::slice( size_t start = 0,
                                                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVec_ranking_pair.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec_ranking_pair::sort

```cpp
void VectorOfVec_ranking_pair::sort( void*  comparator,
                                     size_t start = 0,
                                     size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVec_ranking_pair.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec_ranking_pair::sort_variant

```cpp
void VectorOfVec_ranking_pair::sort_variant( void*  comparator,
                                             size_t start = 0,
                                             size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVec_ranking_pair.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec_ranking_pair::start

```cpp
void* VectorOfVec_ranking_pair::start();

AutoIt:
    $oVectorOfVec_ranking_pair.start() -> retval
```

### VectorOfVec_ranking_pair::end

```cpp
void* VectorOfVec_ranking_pair::end();

AutoIt:
    $oVectorOfVec_ranking_pair.end() -> retval
```

### VectorOfVec_ranking_pair::get_Item

```cpp
dlib::vec_ranking_pair VectorOfVec_ranking_pair::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVec_ranking_pair.Item( $vIndex ) -> retval
    VectorOfVec_ranking_pair( $vIndex ) -> retval
```

### VectorOfVec_ranking_pair::put_Item

```cpp
void VectorOfVec_ranking_pair::put_Item( size_t                 vIndex,
                                         dlib::vec_ranking_pair vItem );

AutoIt:
    $oVectorOfVec_ranking_pair.Item( $vIndex ) = $vItem
```

## VectorOfSparse_ranking_pair

### VectorOfSparse_ranking_pair::create

```cpp
static VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfSparse_ranking_pair").create() -> <VectorOfSparse_ranking_pair object>
```

```cpp
static VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfSparse_ranking_pair").create( $size ) -> <VectorOfSparse_ranking_pair object>
```

```cpp
static VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::create( VectorOfSparse_ranking_pair other );

AutoIt:
    _Dlib_ObjCreate("VectorOfSparse_ranking_pair").create( $other ) -> <VectorOfSparse_ranking_pair object>
```

### VectorOfSparse_ranking_pair::Keys

```cpp
std::vector<int> VectorOfSparse_ranking_pair::Keys();

AutoIt:
    $oVectorOfSparse_ranking_pair.Keys() -> retval
```

### VectorOfSparse_ranking_pair::Items

```cpp
VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::Items();

AutoIt:
    $oVectorOfSparse_ranking_pair.Items() -> retval
```

### VectorOfSparse_ranking_pair::push_back

```cpp
void VectorOfSparse_ranking_pair::push_back( dlib::sparse_ranking_pair value );

AutoIt:
    $oVectorOfSparse_ranking_pair.push_back( $value ) -> None
```

### VectorOfSparse_ranking_pair::Add

```cpp
void VectorOfSparse_ranking_pair::Add( dlib::sparse_ranking_pair value );

AutoIt:
    $oVectorOfSparse_ranking_pair.Add( $value ) -> None
```

### VectorOfSparse_ranking_pair::Remove

```cpp
void VectorOfSparse_ranking_pair::Remove( size_t index );

AutoIt:
    $oVectorOfSparse_ranking_pair.Remove( $index ) -> None
```

### VectorOfSparse_ranking_pair::at

```cpp
dlib::sparse_ranking_pair VectorOfSparse_ranking_pair::at( size_t index );

AutoIt:
    $oVectorOfSparse_ranking_pair.at( $index ) -> retval
```

```cpp
void VectorOfSparse_ranking_pair::at( size_t                    index,
                                      dlib::sparse_ranking_pair value );

AutoIt:
    $oVectorOfSparse_ranking_pair.at( $index, $value ) -> None
```

### VectorOfSparse_ranking_pair::size

```cpp
size_t VectorOfSparse_ranking_pair::size();

AutoIt:
    $oVectorOfSparse_ranking_pair.size() -> retval
```

### VectorOfSparse_ranking_pair::empty

```cpp
bool VectorOfSparse_ranking_pair::empty();

AutoIt:
    $oVectorOfSparse_ranking_pair.empty() -> retval
```

### VectorOfSparse_ranking_pair::clear

```cpp
void VectorOfSparse_ranking_pair::clear();

AutoIt:
    $oVectorOfSparse_ranking_pair.clear() -> None
```

### VectorOfSparse_ranking_pair::push_vector

```cpp
void VectorOfSparse_ranking_pair::push_vector( VectorOfSparse_ranking_pair other );

AutoIt:
    $oVectorOfSparse_ranking_pair.push_vector( $other ) -> None
```

```cpp
void VectorOfSparse_ranking_pair::push_vector( VectorOfSparse_ranking_pair other,
                                               size_t                      count,
                                               size_t                      start = 0 );

AutoIt:
    $oVectorOfSparse_ranking_pair.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSparse_ranking_pair::slice

```cpp
VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::slice( size_t start = 0,
                                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSparse_ranking_pair.slice( [$start[, $count]] ) -> retval
```

### VectorOfSparse_ranking_pair::sort

```cpp
void VectorOfSparse_ranking_pair::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSparse_ranking_pair.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSparse_ranking_pair::sort_variant

```cpp
void VectorOfSparse_ranking_pair::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSparse_ranking_pair.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSparse_ranking_pair::start

```cpp
void* VectorOfSparse_ranking_pair::start();

AutoIt:
    $oVectorOfSparse_ranking_pair.start() -> retval
```

### VectorOfSparse_ranking_pair::end

```cpp
void* VectorOfSparse_ranking_pair::end();

AutoIt:
    $oVectorOfSparse_ranking_pair.end() -> retval
```

### VectorOfSparse_ranking_pair::get_Item

```cpp
dlib::sparse_ranking_pair VectorOfSparse_ranking_pair::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfSparse_ranking_pair.Item( $vIndex ) -> retval
    VectorOfSparse_ranking_pair( $vIndex ) -> retval
```

### VectorOfSparse_ranking_pair::put_Item

```cpp
void VectorOfSparse_ranking_pair::put_Item( size_t                    vIndex,
                                            dlib::sparse_ranking_pair vItem );

AutoIt:
    $oVectorOfSparse_ranking_pair.Item( $vIndex ) = $vItem
```

## VectorOfDpoint

### VectorOfDpoint::create

```cpp
static VectorOfDpoint VectorOfDpoint::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfDpoint").create() -> <VectorOfDpoint object>
```

```cpp
static VectorOfDpoint VectorOfDpoint::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfDpoint").create( $size ) -> <VectorOfDpoint object>
```

```cpp
static VectorOfDpoint VectorOfDpoint::create( VectorOfDpoint other );

AutoIt:
    _Dlib_ObjCreate("VectorOfDpoint").create( $other ) -> <VectorOfDpoint object>
```

### VectorOfDpoint::Keys

```cpp
std::vector<int> VectorOfDpoint::Keys();

AutoIt:
    $oVectorOfDpoint.Keys() -> retval
```

### VectorOfDpoint::Items

```cpp
VectorOfDpoint VectorOfDpoint::Items();

AutoIt:
    $oVectorOfDpoint.Items() -> retval
```

### VectorOfDpoint::push_back

```cpp
void VectorOfDpoint::push_back( dlib::dpoint value );

AutoIt:
    $oVectorOfDpoint.push_back( $value ) -> None
```

### VectorOfDpoint::Add

```cpp
void VectorOfDpoint::Add( dlib::dpoint value );

AutoIt:
    $oVectorOfDpoint.Add( $value ) -> None
```

### VectorOfDpoint::Remove

```cpp
void VectorOfDpoint::Remove( size_t index );

AutoIt:
    $oVectorOfDpoint.Remove( $index ) -> None
```

### VectorOfDpoint::at

```cpp
dlib::dpoint VectorOfDpoint::at( size_t index );

AutoIt:
    $oVectorOfDpoint.at( $index ) -> retval
```

```cpp
void VectorOfDpoint::at( size_t       index,
                         dlib::dpoint value );

AutoIt:
    $oVectorOfDpoint.at( $index, $value ) -> None
```

### VectorOfDpoint::size

```cpp
size_t VectorOfDpoint::size();

AutoIt:
    $oVectorOfDpoint.size() -> retval
```

### VectorOfDpoint::empty

```cpp
bool VectorOfDpoint::empty();

AutoIt:
    $oVectorOfDpoint.empty() -> retval
```

### VectorOfDpoint::clear

```cpp
void VectorOfDpoint::clear();

AutoIt:
    $oVectorOfDpoint.clear() -> None
```

### VectorOfDpoint::push_vector

```cpp
void VectorOfDpoint::push_vector( VectorOfDpoint other );

AutoIt:
    $oVectorOfDpoint.push_vector( $other ) -> None
```

```cpp
void VectorOfDpoint::push_vector( VectorOfDpoint other,
                                  size_t         count,
                                  size_t         start = 0 );

AutoIt:
    $oVectorOfDpoint.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfDpoint::slice

```cpp
VectorOfDpoint VectorOfDpoint::slice( size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDpoint.slice( [$start[, $count]] ) -> retval
```

### VectorOfDpoint::sort

```cpp
void VectorOfDpoint::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDpoint.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDpoint::sort_variant

```cpp
void VectorOfDpoint::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDpoint.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDpoint::start

```cpp
void* VectorOfDpoint::start();

AutoIt:
    $oVectorOfDpoint.start() -> retval
```

### VectorOfDpoint::end

```cpp
void* VectorOfDpoint::end();

AutoIt:
    $oVectorOfDpoint.end() -> retval
```

### VectorOfDpoint::get_Item

```cpp
dlib::dpoint VectorOfDpoint::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfDpoint.Item( $vIndex ) -> retval
    VectorOfDpoint( $vIndex ) -> retval
```

### VectorOfDpoint::put_Item

```cpp
void VectorOfDpoint::put_Item( size_t       vIndex,
                               dlib::dpoint vItem );

AutoIt:
    $oVectorOfDpoint.Item( $vIndex ) = $vItem
```

## VectorOfPoint

### VectorOfPoint::create

```cpp
static VectorOfPoint VectorOfPoint::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfPoint").create() -> <VectorOfPoint object>
```

```cpp
static VectorOfPoint VectorOfPoint::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfPoint").create( $size ) -> <VectorOfPoint object>
```

```cpp
static VectorOfPoint VectorOfPoint::create( VectorOfPoint other );

AutoIt:
    _Dlib_ObjCreate("VectorOfPoint").create( $other ) -> <VectorOfPoint object>
```

### VectorOfPoint::Keys

```cpp
std::vector<int> VectorOfPoint::Keys();

AutoIt:
    $oVectorOfPoint.Keys() -> retval
```

### VectorOfPoint::Items

```cpp
VectorOfPoint VectorOfPoint::Items();

AutoIt:
    $oVectorOfPoint.Items() -> retval
```

### VectorOfPoint::push_back

```cpp
void VectorOfPoint::push_back( dlib::point value );

AutoIt:
    $oVectorOfPoint.push_back( $value ) -> None
```

### VectorOfPoint::Add

```cpp
void VectorOfPoint::Add( dlib::point value );

AutoIt:
    $oVectorOfPoint.Add( $value ) -> None
```

### VectorOfPoint::Remove

```cpp
void VectorOfPoint::Remove( size_t index );

AutoIt:
    $oVectorOfPoint.Remove( $index ) -> None
```

### VectorOfPoint::at

```cpp
dlib::point VectorOfPoint::at( size_t index );

AutoIt:
    $oVectorOfPoint.at( $index ) -> retval
```

```cpp
void VectorOfPoint::at( size_t      index,
                        dlib::point value );

AutoIt:
    $oVectorOfPoint.at( $index, $value ) -> None
```

### VectorOfPoint::size

```cpp
size_t VectorOfPoint::size();

AutoIt:
    $oVectorOfPoint.size() -> retval
```

### VectorOfPoint::empty

```cpp
bool VectorOfPoint::empty();

AutoIt:
    $oVectorOfPoint.empty() -> retval
```

### VectorOfPoint::clear

```cpp
void VectorOfPoint::clear();

AutoIt:
    $oVectorOfPoint.clear() -> None
```

### VectorOfPoint::push_vector

```cpp
void VectorOfPoint::push_vector( VectorOfPoint other );

AutoIt:
    $oVectorOfPoint.push_vector( $other ) -> None
```

```cpp
void VectorOfPoint::push_vector( VectorOfPoint other,
                                 size_t        count,
                                 size_t        start = 0 );

AutoIt:
    $oVectorOfPoint.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPoint::slice

```cpp
VectorOfPoint VectorOfPoint::slice( size_t start = 0,
                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPoint.slice( [$start[, $count]] ) -> retval
```

### VectorOfPoint::sort

```cpp
void VectorOfPoint::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPoint.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPoint::sort_variant

```cpp
void VectorOfPoint::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPoint.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPoint::start

```cpp
void* VectorOfPoint::start();

AutoIt:
    $oVectorOfPoint.start() -> retval
```

### VectorOfPoint::end

```cpp
void* VectorOfPoint::end();

AutoIt:
    $oVectorOfPoint.end() -> retval
```

### VectorOfPoint::get_Item

```cpp
dlib::point VectorOfPoint::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfPoint.Item( $vIndex ) -> retval
    VectorOfPoint( $vIndex ) -> retval
```

### VectorOfPoint::put_Item

```cpp
void VectorOfPoint::put_Item( size_t      vIndex,
                              dlib::point vItem );

AutoIt:
    $oVectorOfPoint.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfDouble

### VectorOfVectorOfDouble::create

```cpp
static VectorOfVectorOfDouble VectorOfVectorOfDouble::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfDouble").create() -> <VectorOfVectorOfDouble object>
```

```cpp
static VectorOfVectorOfDouble VectorOfVectorOfDouble::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfDouble").create( $size ) -> <VectorOfVectorOfDouble object>
```

```cpp
static VectorOfVectorOfDouble VectorOfVectorOfDouble::create( VectorOfVectorOfDouble other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfDouble").create( $other ) -> <VectorOfVectorOfDouble object>
```

### VectorOfVectorOfDouble::Keys

```cpp
std::vector<int> VectorOfVectorOfDouble::Keys();

AutoIt:
    $oVectorOfVectorOfDouble.Keys() -> retval
```

### VectorOfVectorOfDouble::Items

```cpp
VectorOfVectorOfDouble VectorOfVectorOfDouble::Items();

AutoIt:
    $oVectorOfVectorOfDouble.Items() -> retval
```

### VectorOfVectorOfDouble::push_back

```cpp
void VectorOfVectorOfDouble::push_back( std::vector<double> value );

AutoIt:
    $oVectorOfVectorOfDouble.push_back( $value ) -> None
```

### VectorOfVectorOfDouble::Add

```cpp
void VectorOfVectorOfDouble::Add( std::vector<double> value );

AutoIt:
    $oVectorOfVectorOfDouble.Add( $value ) -> None
```

### VectorOfVectorOfDouble::Remove

```cpp
void VectorOfVectorOfDouble::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfDouble.Remove( $index ) -> None
```

### VectorOfVectorOfDouble::at

```cpp
std::vector<double> VectorOfVectorOfDouble::at( size_t index );

AutoIt:
    $oVectorOfVectorOfDouble.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfDouble::at( size_t              index,
                                 std::vector<double> value );

AutoIt:
    $oVectorOfVectorOfDouble.at( $index, $value ) -> None
```

### VectorOfVectorOfDouble::size

```cpp
size_t VectorOfVectorOfDouble::size();

AutoIt:
    $oVectorOfVectorOfDouble.size() -> retval
```

### VectorOfVectorOfDouble::empty

```cpp
bool VectorOfVectorOfDouble::empty();

AutoIt:
    $oVectorOfVectorOfDouble.empty() -> retval
```

### VectorOfVectorOfDouble::clear

```cpp
void VectorOfVectorOfDouble::clear();

AutoIt:
    $oVectorOfVectorOfDouble.clear() -> None
```

### VectorOfVectorOfDouble::push_vector

```cpp
void VectorOfVectorOfDouble::push_vector( VectorOfVectorOfDouble other );

AutoIt:
    $oVectorOfVectorOfDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfDouble::push_vector( VectorOfVectorOfDouble other,
                                          size_t                 count,
                                          size_t                 start = 0 );

AutoIt:
    $oVectorOfVectorOfDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfDouble::slice

```cpp
VectorOfVectorOfDouble VectorOfVectorOfDouble::slice( size_t start = 0,
                                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfDouble::sort

```cpp
void VectorOfVectorOfDouble::sort( void*  comparator,
                                   size_t start = 0,
                                   size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfDouble::sort_variant

```cpp
void VectorOfVectorOfDouble::sort_variant( void*  comparator,
                                           size_t start = 0,
                                           size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfDouble::start

```cpp
void* VectorOfVectorOfDouble::start();

AutoIt:
    $oVectorOfVectorOfDouble.start() -> retval
```

### VectorOfVectorOfDouble::end

```cpp
void* VectorOfVectorOfDouble::end();

AutoIt:
    $oVectorOfVectorOfDouble.end() -> retval
```

### VectorOfVectorOfDouble::get_Item

```cpp
std::vector<double> VectorOfVectorOfDouble::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfDouble.Item( $vIndex ) -> retval
    VectorOfVectorOfDouble( $vIndex ) -> retval
```

### VectorOfVectorOfDouble::put_Item

```cpp
void VectorOfVectorOfDouble::put_Item( size_t              vIndex,
                                       std::vector<double> vItem );

AutoIt:
    $oVectorOfVectorOfDouble.Item( $vIndex ) = $vItem
```

## VectorOfMmod_rect

### VectorOfMmod_rect::create

```cpp
static VectorOfMmod_rect VectorOfMmod_rect::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfMmod_rect").create() -> <VectorOfMmod_rect object>
```

```cpp
static VectorOfMmod_rect VectorOfMmod_rect::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfMmod_rect").create( $size ) -> <VectorOfMmod_rect object>
```

```cpp
static VectorOfMmod_rect VectorOfMmod_rect::create( VectorOfMmod_rect other );

AutoIt:
    _Dlib_ObjCreate("VectorOfMmod_rect").create( $other ) -> <VectorOfMmod_rect object>
```

### VectorOfMmod_rect::Keys

```cpp
std::vector<int> VectorOfMmod_rect::Keys();

AutoIt:
    $oVectorOfMmod_rect.Keys() -> retval
```

### VectorOfMmod_rect::Items

```cpp
VectorOfMmod_rect VectorOfMmod_rect::Items();

AutoIt:
    $oVectorOfMmod_rect.Items() -> retval
```

### VectorOfMmod_rect::push_back

```cpp
void VectorOfMmod_rect::push_back( dlib::mmod_rect value );

AutoIt:
    $oVectorOfMmod_rect.push_back( $value ) -> None
```

### VectorOfMmod_rect::Add

```cpp
void VectorOfMmod_rect::Add( dlib::mmod_rect value );

AutoIt:
    $oVectorOfMmod_rect.Add( $value ) -> None
```

### VectorOfMmod_rect::Remove

```cpp
void VectorOfMmod_rect::Remove( size_t index );

AutoIt:
    $oVectorOfMmod_rect.Remove( $index ) -> None
```

### VectorOfMmod_rect::at

```cpp
dlib::mmod_rect VectorOfMmod_rect::at( size_t index );

AutoIt:
    $oVectorOfMmod_rect.at( $index ) -> retval
```

```cpp
void VectorOfMmod_rect::at( size_t          index,
                            dlib::mmod_rect value );

AutoIt:
    $oVectorOfMmod_rect.at( $index, $value ) -> None
```

### VectorOfMmod_rect::size

```cpp
size_t VectorOfMmod_rect::size();

AutoIt:
    $oVectorOfMmod_rect.size() -> retval
```

### VectorOfMmod_rect::empty

```cpp
bool VectorOfMmod_rect::empty();

AutoIt:
    $oVectorOfMmod_rect.empty() -> retval
```

### VectorOfMmod_rect::clear

```cpp
void VectorOfMmod_rect::clear();

AutoIt:
    $oVectorOfMmod_rect.clear() -> None
```

### VectorOfMmod_rect::push_vector

```cpp
void VectorOfMmod_rect::push_vector( VectorOfMmod_rect other );

AutoIt:
    $oVectorOfMmod_rect.push_vector( $other ) -> None
```

```cpp
void VectorOfMmod_rect::push_vector( VectorOfMmod_rect other,
                                     size_t            count,
                                     size_t            start = 0 );

AutoIt:
    $oVectorOfMmod_rect.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfMmod_rect::slice

```cpp
VectorOfMmod_rect VectorOfMmod_rect::slice( size_t start = 0,
                                            size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfMmod_rect.slice( [$start[, $count]] ) -> retval
```

### VectorOfMmod_rect::sort

```cpp
void VectorOfMmod_rect::sort( void*  comparator,
                              size_t start = 0,
                              size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfMmod_rect.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMmod_rect::sort_variant

```cpp
void VectorOfMmod_rect::sort_variant( void*  comparator,
                                      size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfMmod_rect.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMmod_rect::start

```cpp
void* VectorOfMmod_rect::start();

AutoIt:
    $oVectorOfMmod_rect.start() -> retval
```

### VectorOfMmod_rect::end

```cpp
void* VectorOfMmod_rect::end();

AutoIt:
    $oVectorOfMmod_rect.end() -> retval
```

### VectorOfMmod_rect::get_Item

```cpp
dlib::mmod_rect VectorOfMmod_rect::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfMmod_rect.Item( $vIndex ) -> retval
    VectorOfMmod_rect( $vIndex ) -> retval
```

### VectorOfMmod_rect::put_Item

```cpp
void VectorOfMmod_rect::put_Item( size_t          vIndex,
                                  dlib::mmod_rect vItem );

AutoIt:
    $oVectorOfMmod_rect.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfMmod_rect

### VectorOfVectorOfMmod_rect::create

```cpp
static VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfMmod_rect").create() -> <VectorOfVectorOfMmod_rect object>
```

```cpp
static VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfMmod_rect").create( $size ) -> <VectorOfVectorOfMmod_rect object>
```

```cpp
static VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::create( VectorOfVectorOfMmod_rect other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfMmod_rect").create( $other ) -> <VectorOfVectorOfMmod_rect object>
```

### VectorOfVectorOfMmod_rect::Keys

```cpp
std::vector<int> VectorOfVectorOfMmod_rect::Keys();

AutoIt:
    $oVectorOfVectorOfMmod_rect.Keys() -> retval
```

### VectorOfVectorOfMmod_rect::Items

```cpp
VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::Items();

AutoIt:
    $oVectorOfVectorOfMmod_rect.Items() -> retval
```

### VectorOfVectorOfMmod_rect::push_back

```cpp
void VectorOfVectorOfMmod_rect::push_back( std::vector<dlib::mmod_rect> value );

AutoIt:
    $oVectorOfVectorOfMmod_rect.push_back( $value ) -> None
```

### VectorOfVectorOfMmod_rect::Add

```cpp
void VectorOfVectorOfMmod_rect::Add( std::vector<dlib::mmod_rect> value );

AutoIt:
    $oVectorOfVectorOfMmod_rect.Add( $value ) -> None
```

### VectorOfVectorOfMmod_rect::Remove

```cpp
void VectorOfVectorOfMmod_rect::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfMmod_rect.Remove( $index ) -> None
```

### VectorOfVectorOfMmod_rect::at

```cpp
std::vector<dlib::mmod_rect> VectorOfVectorOfMmod_rect::at( size_t index );

AutoIt:
    $oVectorOfVectorOfMmod_rect.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfMmod_rect::at( size_t                       index,
                                    std::vector<dlib::mmod_rect> value );

AutoIt:
    $oVectorOfVectorOfMmod_rect.at( $index, $value ) -> None
```

### VectorOfVectorOfMmod_rect::size

```cpp
size_t VectorOfVectorOfMmod_rect::size();

AutoIt:
    $oVectorOfVectorOfMmod_rect.size() -> retval
```

### VectorOfVectorOfMmod_rect::empty

```cpp
bool VectorOfVectorOfMmod_rect::empty();

AutoIt:
    $oVectorOfVectorOfMmod_rect.empty() -> retval
```

### VectorOfVectorOfMmod_rect::clear

```cpp
void VectorOfVectorOfMmod_rect::clear();

AutoIt:
    $oVectorOfVectorOfMmod_rect.clear() -> None
```

### VectorOfVectorOfMmod_rect::push_vector

```cpp
void VectorOfVectorOfMmod_rect::push_vector( VectorOfVectorOfMmod_rect other );

AutoIt:
    $oVectorOfVectorOfMmod_rect.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfMmod_rect::push_vector( VectorOfVectorOfMmod_rect other,
                                             size_t                    count,
                                             size_t                    start = 0 );

AutoIt:
    $oVectorOfVectorOfMmod_rect.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfMmod_rect::slice

```cpp
VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::slice( size_t start = 0,
                                                            size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfMmod_rect.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfMmod_rect::sort

```cpp
void VectorOfVectorOfMmod_rect::sort( void*  comparator,
                                      size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfMmod_rect.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfMmod_rect::sort_variant

```cpp
void VectorOfVectorOfMmod_rect::sort_variant( void*  comparator,
                                              size_t start = 0,
                                              size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfMmod_rect.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfMmod_rect::start

```cpp
void* VectorOfVectorOfMmod_rect::start();

AutoIt:
    $oVectorOfVectorOfMmod_rect.start() -> retval
```

### VectorOfVectorOfMmod_rect::end

```cpp
void* VectorOfVectorOfMmod_rect::end();

AutoIt:
    $oVectorOfVectorOfMmod_rect.end() -> retval
```

### VectorOfVectorOfMmod_rect::get_Item

```cpp
std::vector<dlib::mmod_rect> VectorOfVectorOfMmod_rect::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfMmod_rect.Item( $vIndex ) -> retval
    VectorOfVectorOfMmod_rect( $vIndex ) -> retval
```

### VectorOfVectorOfMmod_rect::put_Item

```cpp
void VectorOfVectorOfMmod_rect::put_Item( size_t                       vIndex,
                                          std::vector<dlib::mmod_rect> vItem );

AutoIt:
    $oVectorOfVectorOfMmod_rect.Item( $vIndex ) = $vItem
```

## VectorOfSimple_object_detector_com

### VectorOfSimple_object_detector_com::create

```cpp
static VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfSimple_object_detector_com").create() -> <VectorOfSimple_object_detector_com object>
```

```cpp
static VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfSimple_object_detector_com").create( $size ) -> <VectorOfSimple_object_detector_com object>
```

```cpp
static VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::create( VectorOfSimple_object_detector_com other );

AutoIt:
    _Dlib_ObjCreate("VectorOfSimple_object_detector_com").create( $other ) -> <VectorOfSimple_object_detector_com object>
```

### VectorOfSimple_object_detector_com::Keys

```cpp
std::vector<int> VectorOfSimple_object_detector_com::Keys();

AutoIt:
    $oVectorOfSimple_object_detector_com.Keys() -> retval
```

### VectorOfSimple_object_detector_com::Items

```cpp
VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::Items();

AutoIt:
    $oVectorOfSimple_object_detector_com.Items() -> retval
```

### VectorOfSimple_object_detector_com::push_back

```cpp
void VectorOfSimple_object_detector_com::push_back( dlib::simple_object_detector_com value );

AutoIt:
    $oVectorOfSimple_object_detector_com.push_back( $value ) -> None
```

### VectorOfSimple_object_detector_com::Add

```cpp
void VectorOfSimple_object_detector_com::Add( dlib::simple_object_detector_com value );

AutoIt:
    $oVectorOfSimple_object_detector_com.Add( $value ) -> None
```

### VectorOfSimple_object_detector_com::Remove

```cpp
void VectorOfSimple_object_detector_com::Remove( size_t index );

AutoIt:
    $oVectorOfSimple_object_detector_com.Remove( $index ) -> None
```

### VectorOfSimple_object_detector_com::at

```cpp
dlib::simple_object_detector_com VectorOfSimple_object_detector_com::at( size_t index );

AutoIt:
    $oVectorOfSimple_object_detector_com.at( $index ) -> retval
```

```cpp
void VectorOfSimple_object_detector_com::at( size_t                           index,
                                             dlib::simple_object_detector_com value );

AutoIt:
    $oVectorOfSimple_object_detector_com.at( $index, $value ) -> None
```

### VectorOfSimple_object_detector_com::size

```cpp
size_t VectorOfSimple_object_detector_com::size();

AutoIt:
    $oVectorOfSimple_object_detector_com.size() -> retval
```

### VectorOfSimple_object_detector_com::empty

```cpp
bool VectorOfSimple_object_detector_com::empty();

AutoIt:
    $oVectorOfSimple_object_detector_com.empty() -> retval
```

### VectorOfSimple_object_detector_com::clear

```cpp
void VectorOfSimple_object_detector_com::clear();

AutoIt:
    $oVectorOfSimple_object_detector_com.clear() -> None
```

### VectorOfSimple_object_detector_com::push_vector

```cpp
void VectorOfSimple_object_detector_com::push_vector( VectorOfSimple_object_detector_com other );

AutoIt:
    $oVectorOfSimple_object_detector_com.push_vector( $other ) -> None
```

```cpp
void VectorOfSimple_object_detector_com::push_vector( VectorOfSimple_object_detector_com other,
                                                      size_t                             count,
                                                      size_t                             start = 0 );

AutoIt:
    $oVectorOfSimple_object_detector_com.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSimple_object_detector_com::slice

```cpp
VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::slice( size_t start = 0,
                                                                              size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSimple_object_detector_com.slice( [$start[, $count]] ) -> retval
```

### VectorOfSimple_object_detector_com::sort

```cpp
void VectorOfSimple_object_detector_com::sort( void*  comparator,
                                               size_t start = 0,
                                               size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSimple_object_detector_com.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSimple_object_detector_com::sort_variant

```cpp
void VectorOfSimple_object_detector_com::sort_variant( void*  comparator,
                                                       size_t start = 0,
                                                       size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfSimple_object_detector_com.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSimple_object_detector_com::start

```cpp
void* VectorOfSimple_object_detector_com::start();

AutoIt:
    $oVectorOfSimple_object_detector_com.start() -> retval
```

### VectorOfSimple_object_detector_com::end

```cpp
void* VectorOfSimple_object_detector_com::end();

AutoIt:
    $oVectorOfSimple_object_detector_com.end() -> retval
```

### VectorOfSimple_object_detector_com::get_Item

```cpp
dlib::simple_object_detector_com VectorOfSimple_object_detector_com::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfSimple_object_detector_com.Item( $vIndex ) -> retval
    VectorOfSimple_object_detector_com( $vIndex ) -> retval
```

### VectorOfSimple_object_detector_com::put_Item

```cpp
void VectorOfSimple_object_detector_com::put_Item( size_t                           vIndex,
                                                   dlib::simple_object_detector_com vItem );

AutoIt:
    $oVectorOfSimple_object_detector_com.Item( $vIndex ) = $vItem
```

## VectorOfFhog_object_detector

### VectorOfFhog_object_detector::create

```cpp
static VectorOfFhog_object_detector VectorOfFhog_object_detector::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfFhog_object_detector").create() -> <VectorOfFhog_object_detector object>
```

```cpp
static VectorOfFhog_object_detector VectorOfFhog_object_detector::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfFhog_object_detector").create( $size ) -> <VectorOfFhog_object_detector object>
```

```cpp
static VectorOfFhog_object_detector VectorOfFhog_object_detector::create( VectorOfFhog_object_detector other );

AutoIt:
    _Dlib_ObjCreate("VectorOfFhog_object_detector").create( $other ) -> <VectorOfFhog_object_detector object>
```

### VectorOfFhog_object_detector::Keys

```cpp
std::vector<int> VectorOfFhog_object_detector::Keys();

AutoIt:
    $oVectorOfFhog_object_detector.Keys() -> retval
```

### VectorOfFhog_object_detector::Items

```cpp
VectorOfFhog_object_detector VectorOfFhog_object_detector::Items();

AutoIt:
    $oVectorOfFhog_object_detector.Items() -> retval
```

### VectorOfFhog_object_detector::push_back

```cpp
void VectorOfFhog_object_detector::push_back( dlib::fhog_object_detector value );

AutoIt:
    $oVectorOfFhog_object_detector.push_back( $value ) -> None
```

### VectorOfFhog_object_detector::Add

```cpp
void VectorOfFhog_object_detector::Add( dlib::fhog_object_detector value );

AutoIt:
    $oVectorOfFhog_object_detector.Add( $value ) -> None
```

### VectorOfFhog_object_detector::Remove

```cpp
void VectorOfFhog_object_detector::Remove( size_t index );

AutoIt:
    $oVectorOfFhog_object_detector.Remove( $index ) -> None
```

### VectorOfFhog_object_detector::at

```cpp
dlib::fhog_object_detector VectorOfFhog_object_detector::at( size_t index );

AutoIt:
    $oVectorOfFhog_object_detector.at( $index ) -> retval
```

```cpp
void VectorOfFhog_object_detector::at( size_t                     index,
                                       dlib::fhog_object_detector value );

AutoIt:
    $oVectorOfFhog_object_detector.at( $index, $value ) -> None
```

### VectorOfFhog_object_detector::size

```cpp
size_t VectorOfFhog_object_detector::size();

AutoIt:
    $oVectorOfFhog_object_detector.size() -> retval
```

### VectorOfFhog_object_detector::empty

```cpp
bool VectorOfFhog_object_detector::empty();

AutoIt:
    $oVectorOfFhog_object_detector.empty() -> retval
```

### VectorOfFhog_object_detector::clear

```cpp
void VectorOfFhog_object_detector::clear();

AutoIt:
    $oVectorOfFhog_object_detector.clear() -> None
```

### VectorOfFhog_object_detector::push_vector

```cpp
void VectorOfFhog_object_detector::push_vector( VectorOfFhog_object_detector other );

AutoIt:
    $oVectorOfFhog_object_detector.push_vector( $other ) -> None
```

```cpp
void VectorOfFhog_object_detector::push_vector( VectorOfFhog_object_detector other,
                                                size_t                       count,
                                                size_t                       start = 0 );

AutoIt:
    $oVectorOfFhog_object_detector.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFhog_object_detector::slice

```cpp
VectorOfFhog_object_detector VectorOfFhog_object_detector::slice( size_t start = 0,
                                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFhog_object_detector.slice( [$start[, $count]] ) -> retval
```

### VectorOfFhog_object_detector::sort

```cpp
void VectorOfFhog_object_detector::sort( void*  comparator,
                                         size_t start = 0,
                                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFhog_object_detector.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFhog_object_detector::sort_variant

```cpp
void VectorOfFhog_object_detector::sort_variant( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFhog_object_detector.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFhog_object_detector::start

```cpp
void* VectorOfFhog_object_detector::start();

AutoIt:
    $oVectorOfFhog_object_detector.start() -> retval
```

### VectorOfFhog_object_detector::end

```cpp
void* VectorOfFhog_object_detector::end();

AutoIt:
    $oVectorOfFhog_object_detector.end() -> retval
```

### VectorOfFhog_object_detector::get_Item

```cpp
dlib::fhog_object_detector VectorOfFhog_object_detector::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfFhog_object_detector.Item( $vIndex ) -> retval
    VectorOfFhog_object_detector( $vIndex ) -> retval
```

### VectorOfFhog_object_detector::put_Item

```cpp
void VectorOfFhog_object_detector::put_Item( size_t                     vIndex,
                                             dlib::fhog_object_detector vItem );

AutoIt:
    $oVectorOfFhog_object_detector.Item( $vIndex ) = $vItem
```

## VectorOfFunction_spec

### VectorOfFunction_spec::create

```cpp
static VectorOfFunction_spec VectorOfFunction_spec::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_spec").create() -> <VectorOfFunction_spec object>
```

```cpp
static VectorOfFunction_spec VectorOfFunction_spec::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_spec").create( $size ) -> <VectorOfFunction_spec object>
```

```cpp
static VectorOfFunction_spec VectorOfFunction_spec::create( VectorOfFunction_spec other );

AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_spec").create( $other ) -> <VectorOfFunction_spec object>
```

### VectorOfFunction_spec::Keys

```cpp
std::vector<int> VectorOfFunction_spec::Keys();

AutoIt:
    $oVectorOfFunction_spec.Keys() -> retval
```

### VectorOfFunction_spec::Items

```cpp
VectorOfFunction_spec VectorOfFunction_spec::Items();

AutoIt:
    $oVectorOfFunction_spec.Items() -> retval
```

### VectorOfFunction_spec::push_back

```cpp
void VectorOfFunction_spec::push_back( dlib::function_spec value );

AutoIt:
    $oVectorOfFunction_spec.push_back( $value ) -> None
```

### VectorOfFunction_spec::Add

```cpp
void VectorOfFunction_spec::Add( dlib::function_spec value );

AutoIt:
    $oVectorOfFunction_spec.Add( $value ) -> None
```

### VectorOfFunction_spec::Remove

```cpp
void VectorOfFunction_spec::Remove( size_t index );

AutoIt:
    $oVectorOfFunction_spec.Remove( $index ) -> None
```

### VectorOfFunction_spec::at

```cpp
dlib::function_spec VectorOfFunction_spec::at( size_t index );

AutoIt:
    $oVectorOfFunction_spec.at( $index ) -> retval
```

```cpp
void VectorOfFunction_spec::at( size_t              index,
                                dlib::function_spec value );

AutoIt:
    $oVectorOfFunction_spec.at( $index, $value ) -> None
```

### VectorOfFunction_spec::size

```cpp
size_t VectorOfFunction_spec::size();

AutoIt:
    $oVectorOfFunction_spec.size() -> retval
```

### VectorOfFunction_spec::empty

```cpp
bool VectorOfFunction_spec::empty();

AutoIt:
    $oVectorOfFunction_spec.empty() -> retval
```

### VectorOfFunction_spec::clear

```cpp
void VectorOfFunction_spec::clear();

AutoIt:
    $oVectorOfFunction_spec.clear() -> None
```

### VectorOfFunction_spec::push_vector

```cpp
void VectorOfFunction_spec::push_vector( VectorOfFunction_spec other );

AutoIt:
    $oVectorOfFunction_spec.push_vector( $other ) -> None
```

```cpp
void VectorOfFunction_spec::push_vector( VectorOfFunction_spec other,
                                         size_t                count,
                                         size_t                start = 0 );

AutoIt:
    $oVectorOfFunction_spec.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFunction_spec::slice

```cpp
VectorOfFunction_spec VectorOfFunction_spec::slice( size_t start = 0,
                                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFunction_spec.slice( [$start[, $count]] ) -> retval
```

### VectorOfFunction_spec::sort

```cpp
void VectorOfFunction_spec::sort( void*  comparator,
                                  size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFunction_spec.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction_spec::sort_variant

```cpp
void VectorOfFunction_spec::sort_variant( void*  comparator,
                                          size_t start = 0,
                                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFunction_spec.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction_spec::start

```cpp
void* VectorOfFunction_spec::start();

AutoIt:
    $oVectorOfFunction_spec.start() -> retval
```

### VectorOfFunction_spec::end

```cpp
void* VectorOfFunction_spec::end();

AutoIt:
    $oVectorOfFunction_spec.end() -> retval
```

### VectorOfFunction_spec::get_Item

```cpp
dlib::function_spec VectorOfFunction_spec::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfFunction_spec.Item( $vIndex ) -> retval
    VectorOfFunction_spec( $vIndex ) -> retval
```

### VectorOfFunction_spec::put_Item

```cpp
void VectorOfFunction_spec::put_Item( size_t              vIndex,
                                      dlib::function_spec vItem );

AutoIt:
    $oVectorOfFunction_spec.Item( $vIndex ) = $vItem
```

## VectorOfFunction_evaluation

### VectorOfFunction_evaluation::create

```cpp
static VectorOfFunction_evaluation VectorOfFunction_evaluation::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_evaluation").create() -> <VectorOfFunction_evaluation object>
```

```cpp
static VectorOfFunction_evaluation VectorOfFunction_evaluation::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_evaluation").create( $size ) -> <VectorOfFunction_evaluation object>
```

```cpp
static VectorOfFunction_evaluation VectorOfFunction_evaluation::create( VectorOfFunction_evaluation other );

AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_evaluation").create( $other ) -> <VectorOfFunction_evaluation object>
```

### VectorOfFunction_evaluation::Keys

```cpp
std::vector<int> VectorOfFunction_evaluation::Keys();

AutoIt:
    $oVectorOfFunction_evaluation.Keys() -> retval
```

### VectorOfFunction_evaluation::Items

```cpp
VectorOfFunction_evaluation VectorOfFunction_evaluation::Items();

AutoIt:
    $oVectorOfFunction_evaluation.Items() -> retval
```

### VectorOfFunction_evaluation::push_back

```cpp
void VectorOfFunction_evaluation::push_back( dlib::function_evaluation value );

AutoIt:
    $oVectorOfFunction_evaluation.push_back( $value ) -> None
```

### VectorOfFunction_evaluation::Add

```cpp
void VectorOfFunction_evaluation::Add( dlib::function_evaluation value );

AutoIt:
    $oVectorOfFunction_evaluation.Add( $value ) -> None
```

### VectorOfFunction_evaluation::Remove

```cpp
void VectorOfFunction_evaluation::Remove( size_t index );

AutoIt:
    $oVectorOfFunction_evaluation.Remove( $index ) -> None
```

### VectorOfFunction_evaluation::at

```cpp
dlib::function_evaluation VectorOfFunction_evaluation::at( size_t index );

AutoIt:
    $oVectorOfFunction_evaluation.at( $index ) -> retval
```

```cpp
void VectorOfFunction_evaluation::at( size_t                    index,
                                      dlib::function_evaluation value );

AutoIt:
    $oVectorOfFunction_evaluation.at( $index, $value ) -> None
```

### VectorOfFunction_evaluation::size

```cpp
size_t VectorOfFunction_evaluation::size();

AutoIt:
    $oVectorOfFunction_evaluation.size() -> retval
```

### VectorOfFunction_evaluation::empty

```cpp
bool VectorOfFunction_evaluation::empty();

AutoIt:
    $oVectorOfFunction_evaluation.empty() -> retval
```

### VectorOfFunction_evaluation::clear

```cpp
void VectorOfFunction_evaluation::clear();

AutoIt:
    $oVectorOfFunction_evaluation.clear() -> None
```

### VectorOfFunction_evaluation::push_vector

```cpp
void VectorOfFunction_evaluation::push_vector( VectorOfFunction_evaluation other );

AutoIt:
    $oVectorOfFunction_evaluation.push_vector( $other ) -> None
```

```cpp
void VectorOfFunction_evaluation::push_vector( VectorOfFunction_evaluation other,
                                               size_t                      count,
                                               size_t                      start = 0 );

AutoIt:
    $oVectorOfFunction_evaluation.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFunction_evaluation::slice

```cpp
VectorOfFunction_evaluation VectorOfFunction_evaluation::slice( size_t start = 0,
                                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFunction_evaluation.slice( [$start[, $count]] ) -> retval
```

### VectorOfFunction_evaluation::sort

```cpp
void VectorOfFunction_evaluation::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFunction_evaluation.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction_evaluation::sort_variant

```cpp
void VectorOfFunction_evaluation::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfFunction_evaluation.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction_evaluation::start

```cpp
void* VectorOfFunction_evaluation::start();

AutoIt:
    $oVectorOfFunction_evaluation.start() -> retval
```

### VectorOfFunction_evaluation::end

```cpp
void* VectorOfFunction_evaluation::end();

AutoIt:
    $oVectorOfFunction_evaluation.end() -> retval
```

### VectorOfFunction_evaluation::get_Item

```cpp
dlib::function_evaluation VectorOfFunction_evaluation::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfFunction_evaluation.Item( $vIndex ) -> retval
    VectorOfFunction_evaluation( $vIndex ) -> retval
```

### VectorOfFunction_evaluation::put_Item

```cpp
void VectorOfFunction_evaluation::put_Item( size_t                    vIndex,
                                            dlib::function_evaluation vItem );

AutoIt:
    $oVectorOfFunction_evaluation.Item( $vIndex ) = $vItem
```

## VectorOfVectorOfFunction_evaluation

### VectorOfVectorOfFunction_evaluation::create

```cpp
static VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFunction_evaluation").create() -> <VectorOfVectorOfFunction_evaluation object>
```

```cpp
static VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFunction_evaluation").create( $size ) -> <VectorOfVectorOfFunction_evaluation object>
```

```cpp
static VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::create( VectorOfVectorOfFunction_evaluation other );

AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFunction_evaluation").create( $other ) -> <VectorOfVectorOfFunction_evaluation object>
```

### VectorOfVectorOfFunction_evaluation::Keys

```cpp
std::vector<int> VectorOfVectorOfFunction_evaluation::Keys();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Keys() -> retval
```

### VectorOfVectorOfFunction_evaluation::Items

```cpp
VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::Items();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Items() -> retval
```

### VectorOfVectorOfFunction_evaluation::push_back

```cpp
void VectorOfVectorOfFunction_evaluation::push_back( std::vector<dlib::function_evaluation> value );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.push_back( $value ) -> None
```

### VectorOfVectorOfFunction_evaluation::Add

```cpp
void VectorOfVectorOfFunction_evaluation::Add( std::vector<dlib::function_evaluation> value );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Add( $value ) -> None
```

### VectorOfVectorOfFunction_evaluation::Remove

```cpp
void VectorOfVectorOfFunction_evaluation::Remove( size_t index );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Remove( $index ) -> None
```

### VectorOfVectorOfFunction_evaluation::at

```cpp
std::vector<dlib::function_evaluation> VectorOfVectorOfFunction_evaluation::at( size_t index );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfFunction_evaluation::at( size_t                                 index,
                                              std::vector<dlib::function_evaluation> value );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.at( $index, $value ) -> None
```

### VectorOfVectorOfFunction_evaluation::size

```cpp
size_t VectorOfVectorOfFunction_evaluation::size();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.size() -> retval
```

### VectorOfVectorOfFunction_evaluation::empty

```cpp
bool VectorOfVectorOfFunction_evaluation::empty();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.empty() -> retval
```

### VectorOfVectorOfFunction_evaluation::clear

```cpp
void VectorOfVectorOfFunction_evaluation::clear();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.clear() -> None
```

### VectorOfVectorOfFunction_evaluation::push_vector

```cpp
void VectorOfVectorOfFunction_evaluation::push_vector( VectorOfVectorOfFunction_evaluation other );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfFunction_evaluation::push_vector( VectorOfVectorOfFunction_evaluation other,
                                                       size_t                              count,
                                                       size_t                              start = 0 );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfFunction_evaluation::slice

```cpp
VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::slice( size_t start = 0,
                                                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfFunction_evaluation::sort

```cpp
void VectorOfVectorOfFunction_evaluation::sort( void*  comparator,
                                                size_t start = 0,
                                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFunction_evaluation::sort_variant

```cpp
void VectorOfVectorOfFunction_evaluation::sort_variant( void*  comparator,
                                                        size_t start = 0,
                                                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFunction_evaluation::start

```cpp
void* VectorOfVectorOfFunction_evaluation::start();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.start() -> retval
```

### VectorOfVectorOfFunction_evaluation::end

```cpp
void* VectorOfVectorOfFunction_evaluation::end();

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.end() -> retval
```

### VectorOfVectorOfFunction_evaluation::get_Item

```cpp
std::vector<dlib::function_evaluation> VectorOfVectorOfFunction_evaluation::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Item( $vIndex ) -> retval
    VectorOfVectorOfFunction_evaluation( $vIndex ) -> retval
```

### VectorOfVectorOfFunction_evaluation::put_Item

```cpp
void VectorOfVectorOfFunction_evaluation::put_Item( size_t                                 vIndex,
                                                    std::vector<dlib::function_evaluation> vItem );

AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Item( $vIndex ) = $vItem
```

## VectorOfDrectangle

### VectorOfDrectangle::create

```cpp
static VectorOfDrectangle VectorOfDrectangle::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfDrectangle").create() -> <VectorOfDrectangle object>
```

```cpp
static VectorOfDrectangle VectorOfDrectangle::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfDrectangle").create( $size ) -> <VectorOfDrectangle object>
```

```cpp
static VectorOfDrectangle VectorOfDrectangle::create( VectorOfDrectangle other );

AutoIt:
    _Dlib_ObjCreate("VectorOfDrectangle").create( $other ) -> <VectorOfDrectangle object>
```

### VectorOfDrectangle::Keys

```cpp
std::vector<int> VectorOfDrectangle::Keys();

AutoIt:
    $oVectorOfDrectangle.Keys() -> retval
```

### VectorOfDrectangle::Items

```cpp
VectorOfDrectangle VectorOfDrectangle::Items();

AutoIt:
    $oVectorOfDrectangle.Items() -> retval
```

### VectorOfDrectangle::push_back

```cpp
void VectorOfDrectangle::push_back( dlib::drectangle value );

AutoIt:
    $oVectorOfDrectangle.push_back( $value ) -> None
```

### VectorOfDrectangle::Add

```cpp
void VectorOfDrectangle::Add( dlib::drectangle value );

AutoIt:
    $oVectorOfDrectangle.Add( $value ) -> None
```

### VectorOfDrectangle::Remove

```cpp
void VectorOfDrectangle::Remove( size_t index );

AutoIt:
    $oVectorOfDrectangle.Remove( $index ) -> None
```

### VectorOfDrectangle::at

```cpp
dlib::drectangle VectorOfDrectangle::at( size_t index );

AutoIt:
    $oVectorOfDrectangle.at( $index ) -> retval
```

```cpp
void VectorOfDrectangle::at( size_t           index,
                             dlib::drectangle value );

AutoIt:
    $oVectorOfDrectangle.at( $index, $value ) -> None
```

### VectorOfDrectangle::size

```cpp
size_t VectorOfDrectangle::size();

AutoIt:
    $oVectorOfDrectangle.size() -> retval
```

### VectorOfDrectangle::empty

```cpp
bool VectorOfDrectangle::empty();

AutoIt:
    $oVectorOfDrectangle.empty() -> retval
```

### VectorOfDrectangle::clear

```cpp
void VectorOfDrectangle::clear();

AutoIt:
    $oVectorOfDrectangle.clear() -> None
```

### VectorOfDrectangle::push_vector

```cpp
void VectorOfDrectangle::push_vector( VectorOfDrectangle other );

AutoIt:
    $oVectorOfDrectangle.push_vector( $other ) -> None
```

```cpp
void VectorOfDrectangle::push_vector( VectorOfDrectangle other,
                                      size_t             count,
                                      size_t             start = 0 );

AutoIt:
    $oVectorOfDrectangle.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfDrectangle::slice

```cpp
VectorOfDrectangle VectorOfDrectangle::slice( size_t start = 0,
                                              size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDrectangle.slice( [$start[, $count]] ) -> retval
```

### VectorOfDrectangle::sort

```cpp
void VectorOfDrectangle::sort( void*  comparator,
                               size_t start = 0,
                               size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDrectangle.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDrectangle::sort_variant

```cpp
void VectorOfDrectangle::sort_variant( void*  comparator,
                                       size_t start = 0,
                                       size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfDrectangle.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDrectangle::start

```cpp
void* VectorOfDrectangle::start();

AutoIt:
    $oVectorOfDrectangle.start() -> retval
```

### VectorOfDrectangle::end

```cpp
void* VectorOfDrectangle::end();

AutoIt:
    $oVectorOfDrectangle.end() -> retval
```

### VectorOfDrectangle::get_Item

```cpp
dlib::drectangle VectorOfDrectangle::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfDrectangle.Item( $vIndex ) -> retval
    VectorOfDrectangle( $vIndex ) -> retval
```

### VectorOfDrectangle::put_Item

```cpp
void VectorOfDrectangle::put_Item( size_t           vIndex,
                                   dlib::drectangle vItem );

AutoIt:
    $oVectorOfDrectangle.Item( $vIndex ) = $vItem
```

## VectorOfInt

### VectorOfInt::create

```cpp
static VectorOfInt VectorOfInt::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfInt").create() -> <VectorOfInt object>
```

```cpp
static VectorOfInt VectorOfInt::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfInt").create( $size ) -> <VectorOfInt object>
```

```cpp
static VectorOfInt VectorOfInt::create( VectorOfInt other );

AutoIt:
    _Dlib_ObjCreate("VectorOfInt").create( $other ) -> <VectorOfInt object>
```

### VectorOfInt::Keys

```cpp
std::vector<int> VectorOfInt::Keys();

AutoIt:
    $oVectorOfInt.Keys() -> retval
```

### VectorOfInt::Items

```cpp
VectorOfInt VectorOfInt::Items();

AutoIt:
    $oVectorOfInt.Items() -> retval
```

### VectorOfInt::push_back

```cpp
void VectorOfInt::push_back( int value );

AutoIt:
    $oVectorOfInt.push_back( $value ) -> None
```

### VectorOfInt::Add

```cpp
void VectorOfInt::Add( int value );

AutoIt:
    $oVectorOfInt.Add( $value ) -> None
```

### VectorOfInt::Remove

```cpp
void VectorOfInt::Remove( size_t index );

AutoIt:
    $oVectorOfInt.Remove( $index ) -> None
```

### VectorOfInt::at

```cpp
int VectorOfInt::at( size_t index );

AutoIt:
    $oVectorOfInt.at( $index ) -> retval
```

```cpp
void VectorOfInt::at( size_t index,
                      int    value );

AutoIt:
    $oVectorOfInt.at( $index, $value ) -> None
```

### VectorOfInt::size

```cpp
size_t VectorOfInt::size();

AutoIt:
    $oVectorOfInt.size() -> retval
```

### VectorOfInt::empty

```cpp
bool VectorOfInt::empty();

AutoIt:
    $oVectorOfInt.empty() -> retval
```

### VectorOfInt::clear

```cpp
void VectorOfInt::clear();

AutoIt:
    $oVectorOfInt.clear() -> None
```

### VectorOfInt::push_vector

```cpp
void VectorOfInt::push_vector( VectorOfInt other );

AutoIt:
    $oVectorOfInt.push_vector( $other ) -> None
```

```cpp
void VectorOfInt::push_vector( VectorOfInt other,
                               size_t      count,
                               size_t      start = 0 );

AutoIt:
    $oVectorOfInt.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfInt::slice

```cpp
VectorOfInt VectorOfInt::slice( size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfInt.slice( [$start[, $count]] ) -> retval
```

### VectorOfInt::sort

```cpp
void VectorOfInt::sort( void*  comparator,
                        size_t start = 0,
                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfInt.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfInt::sort_variant

```cpp
void VectorOfInt::sort_variant( void*  comparator,
                                size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfInt.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfInt::start

```cpp
void* VectorOfInt::start();

AutoIt:
    $oVectorOfInt.start() -> retval
```

### VectorOfInt::end

```cpp
void* VectorOfInt::end();

AutoIt:
    $oVectorOfInt.end() -> retval
```

### VectorOfInt::get_Item

```cpp
int VectorOfInt::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfInt.Item( $vIndex ) -> retval
    VectorOfInt( $vIndex ) -> retval
```

### VectorOfInt::put_Item

```cpp
void VectorOfInt::put_Item( size_t vIndex,
                            int    vItem );

AutoIt:
    $oVectorOfInt.Item( $vIndex ) = $vItem
```

## VectorOfUchar

### VectorOfUchar::create

```cpp
static VectorOfUchar VectorOfUchar::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfUchar").create() -> <VectorOfUchar object>
```

```cpp
static VectorOfUchar VectorOfUchar::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfUchar").create( $size ) -> <VectorOfUchar object>
```

```cpp
static VectorOfUchar VectorOfUchar::create( VectorOfUchar other );

AutoIt:
    _Dlib_ObjCreate("VectorOfUchar").create( $other ) -> <VectorOfUchar object>
```

### VectorOfUchar::Keys

```cpp
std::vector<int> VectorOfUchar::Keys();

AutoIt:
    $oVectorOfUchar.Keys() -> retval
```

### VectorOfUchar::Items

```cpp
VectorOfUchar VectorOfUchar::Items();

AutoIt:
    $oVectorOfUchar.Items() -> retval
```

### VectorOfUchar::push_back

```cpp
void VectorOfUchar::push_back( uchar value );

AutoIt:
    $oVectorOfUchar.push_back( $value ) -> None
```

### VectorOfUchar::Add

```cpp
void VectorOfUchar::Add( uchar value );

AutoIt:
    $oVectorOfUchar.Add( $value ) -> None
```

### VectorOfUchar::Remove

```cpp
void VectorOfUchar::Remove( size_t index );

AutoIt:
    $oVectorOfUchar.Remove( $index ) -> None
```

### VectorOfUchar::at

```cpp
uchar VectorOfUchar::at( size_t index );

AutoIt:
    $oVectorOfUchar.at( $index ) -> retval
```

```cpp
void VectorOfUchar::at( size_t index,
                        uchar  value );

AutoIt:
    $oVectorOfUchar.at( $index, $value ) -> None
```

### VectorOfUchar::size

```cpp
size_t VectorOfUchar::size();

AutoIt:
    $oVectorOfUchar.size() -> retval
```

### VectorOfUchar::empty

```cpp
bool VectorOfUchar::empty();

AutoIt:
    $oVectorOfUchar.empty() -> retval
```

### VectorOfUchar::clear

```cpp
void VectorOfUchar::clear();

AutoIt:
    $oVectorOfUchar.clear() -> None
```

### VectorOfUchar::push_vector

```cpp
void VectorOfUchar::push_vector( VectorOfUchar other );

AutoIt:
    $oVectorOfUchar.push_vector( $other ) -> None
```

```cpp
void VectorOfUchar::push_vector( VectorOfUchar other,
                                 size_t        count,
                                 size_t        start = 0 );

AutoIt:
    $oVectorOfUchar.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfUchar::slice

```cpp
VectorOfUchar VectorOfUchar::slice( size_t start = 0,
                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfUchar.slice( [$start[, $count]] ) -> retval
```

### VectorOfUchar::sort

```cpp
void VectorOfUchar::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfUchar.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfUchar::sort_variant

```cpp
void VectorOfUchar::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfUchar.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfUchar::start

```cpp
void* VectorOfUchar::start();

AutoIt:
    $oVectorOfUchar.start() -> retval
```

### VectorOfUchar::end

```cpp
void* VectorOfUchar::end();

AutoIt:
    $oVectorOfUchar.end() -> retval
```

### VectorOfUchar::get_Item

```cpp
uchar VectorOfUchar::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfUchar.Item( $vIndex ) -> retval
    VectorOfUchar( $vIndex ) -> retval
```

### VectorOfUchar::put_Item

```cpp
void VectorOfUchar::put_Item( size_t vIndex,
                              uchar  vItem );

AutoIt:
    $oVectorOfUchar.Item( $vIndex ) = $vItem
```

## MapOfStringAndPoint

### MapOfStringAndPoint::create

```cpp
static MapOfStringAndPoint MapOfStringAndPoint::create();

AutoIt:
    _Dlib_ObjCreate("MapOfStringAndPoint").create() -> <MapOfStringAndPoint object>
```

```cpp
static std::shared_ptr<MapOfStringAndPoint> MapOfStringAndPoint::create( std::vector<std::pair<string, dlib::point>> pairs );

AutoIt:
    _Dlib_ObjCreate("MapOfStringAndPoint").create( $pairs ) -> retval
```

### MapOfStringAndPoint::Get

```cpp
dlib::point MapOfStringAndPoint::Get( string key );

AutoIt:
    $oMapOfStringAndPoint.Get( $key ) -> retval
```

### MapOfStringAndPoint::Keys

```cpp
std::vector<string> MapOfStringAndPoint::Keys();

AutoIt:
    $oMapOfStringAndPoint.Keys() -> retval
```

### MapOfStringAndPoint::Items

```cpp
std::vector<dlib::point> MapOfStringAndPoint::Items();

AutoIt:
    $oMapOfStringAndPoint.Items() -> retval
```

### MapOfStringAndPoint::empty

```cpp
bool MapOfStringAndPoint::empty();

AutoIt:
    $oMapOfStringAndPoint.empty() -> retval
```

### MapOfStringAndPoint::size

```cpp
size_t MapOfStringAndPoint::size();

AutoIt:
    $oMapOfStringAndPoint.size() -> retval
```

### MapOfStringAndPoint::max_size

```cpp
size_t MapOfStringAndPoint::max_size();

AutoIt:
    $oMapOfStringAndPoint.max_size() -> retval
```

### MapOfStringAndPoint::clear

```cpp
void MapOfStringAndPoint::clear();

AutoIt:
    $oMapOfStringAndPoint.clear() -> None
```

### MapOfStringAndPoint::Add

```cpp
void MapOfStringAndPoint::Add( string      key,
                               dlib::point value );

AutoIt:
    $oMapOfStringAndPoint.Add( $key, $value ) -> None
```

### MapOfStringAndPoint::erase

```cpp
size_t MapOfStringAndPoint::erase( string key );

AutoIt:
    $oMapOfStringAndPoint.erase( $key ) -> retval
```

### MapOfStringAndPoint::Remove

```cpp
size_t MapOfStringAndPoint::Remove( string key );

AutoIt:
    $oMapOfStringAndPoint.Remove( $key ) -> retval
```

### MapOfStringAndPoint::merge

```cpp
void MapOfStringAndPoint::merge( MapOfStringAndPoint other );

AutoIt:
    $oMapOfStringAndPoint.merge( $other ) -> None
```

### MapOfStringAndPoint::count

```cpp
size_t MapOfStringAndPoint::count( string key );

AutoIt:
    $oMapOfStringAndPoint.count( $key ) -> retval
```

### MapOfStringAndPoint::contains

```cpp
bool MapOfStringAndPoint::contains( string key );

AutoIt:
    $oMapOfStringAndPoint.contains( $key ) -> retval
```

### MapOfStringAndPoint::has

```cpp
bool MapOfStringAndPoint::has( string key );

AutoIt:
    $oMapOfStringAndPoint.has( $key ) -> retval
```

### MapOfStringAndPoint::get_Item

```cpp
dlib::point MapOfStringAndPoint::get_Item( string vKey );

AutoIt:
    $oMapOfStringAndPoint.Item( $vKey ) -> retval
    MapOfStringAndPoint( $vKey ) -> retval
```

### MapOfStringAndPoint::put_Item

```cpp
void MapOfStringAndPoint::put_Item( string      vKey,
                                    dlib::point vItem );

AutoIt:
    $oMapOfStringAndPoint.Item( $vKey ) = $vItem
```

## VectorOfBox

### VectorOfBox::create

```cpp
static VectorOfBox VectorOfBox::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfBox").create() -> <VectorOfBox object>
```

```cpp
static VectorOfBox VectorOfBox::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfBox").create( $size ) -> <VectorOfBox object>
```

```cpp
static VectorOfBox VectorOfBox::create( VectorOfBox other );

AutoIt:
    _Dlib_ObjCreate("VectorOfBox").create( $other ) -> <VectorOfBox object>
```

### VectorOfBox::Keys

```cpp
std::vector<int> VectorOfBox::Keys();

AutoIt:
    $oVectorOfBox.Keys() -> retval
```

### VectorOfBox::Items

```cpp
VectorOfBox VectorOfBox::Items();

AutoIt:
    $oVectorOfBox.Items() -> retval
```

### VectorOfBox::push_back

```cpp
void VectorOfBox::push_back( dlib::image_dataset_metadata::box value );

AutoIt:
    $oVectorOfBox.push_back( $value ) -> None
```

### VectorOfBox::Add

```cpp
void VectorOfBox::Add( dlib::image_dataset_metadata::box value );

AutoIt:
    $oVectorOfBox.Add( $value ) -> None
```

### VectorOfBox::Remove

```cpp
void VectorOfBox::Remove( size_t index );

AutoIt:
    $oVectorOfBox.Remove( $index ) -> None
```

### VectorOfBox::at

```cpp
dlib::image_dataset_metadata::box VectorOfBox::at( size_t index );

AutoIt:
    $oVectorOfBox.at( $index ) -> retval
```

```cpp
void VectorOfBox::at( size_t                            index,
                      dlib::image_dataset_metadata::box value );

AutoIt:
    $oVectorOfBox.at( $index, $value ) -> None
```

### VectorOfBox::size

```cpp
size_t VectorOfBox::size();

AutoIt:
    $oVectorOfBox.size() -> retval
```

### VectorOfBox::empty

```cpp
bool VectorOfBox::empty();

AutoIt:
    $oVectorOfBox.empty() -> retval
```

### VectorOfBox::clear

```cpp
void VectorOfBox::clear();

AutoIt:
    $oVectorOfBox.clear() -> None
```

### VectorOfBox::push_vector

```cpp
void VectorOfBox::push_vector( VectorOfBox other );

AutoIt:
    $oVectorOfBox.push_vector( $other ) -> None
```

```cpp
void VectorOfBox::push_vector( VectorOfBox other,
                               size_t      count,
                               size_t      start = 0 );

AutoIt:
    $oVectorOfBox.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfBox::slice

```cpp
VectorOfBox VectorOfBox::slice( size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfBox.slice( [$start[, $count]] ) -> retval
```

### VectorOfBox::sort

```cpp
void VectorOfBox::sort( void*  comparator,
                        size_t start = 0,
                        size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfBox.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfBox::sort_variant

```cpp
void VectorOfBox::sort_variant( void*  comparator,
                                size_t start = 0,
                                size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfBox.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfBox::start

```cpp
void* VectorOfBox::start();

AutoIt:
    $oVectorOfBox.start() -> retval
```

### VectorOfBox::end

```cpp
void* VectorOfBox::end();

AutoIt:
    $oVectorOfBox.end() -> retval
```

### VectorOfBox::get_Item

```cpp
dlib::image_dataset_metadata::box VectorOfBox::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfBox.Item( $vIndex ) -> retval
    VectorOfBox( $vIndex ) -> retval
```

### VectorOfBox::put_Item

```cpp
void VectorOfBox::put_Item( size_t                            vIndex,
                            dlib::image_dataset_metadata::box vItem );

AutoIt:
    $oVectorOfBox.Item( $vIndex ) = $vItem
```

## VectorOfImage

### VectorOfImage::create

```cpp
static VectorOfImage VectorOfImage::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfImage").create() -> <VectorOfImage object>
```

```cpp
static VectorOfImage VectorOfImage::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfImage").create( $size ) -> <VectorOfImage object>
```

```cpp
static VectorOfImage VectorOfImage::create( VectorOfImage other );

AutoIt:
    _Dlib_ObjCreate("VectorOfImage").create( $other ) -> <VectorOfImage object>
```

### VectorOfImage::Keys

```cpp
std::vector<int> VectorOfImage::Keys();

AutoIt:
    $oVectorOfImage.Keys() -> retval
```

### VectorOfImage::Items

```cpp
VectorOfImage VectorOfImage::Items();

AutoIt:
    $oVectorOfImage.Items() -> retval
```

### VectorOfImage::push_back

```cpp
void VectorOfImage::push_back( dlib::image_dataset_metadata::image value );

AutoIt:
    $oVectorOfImage.push_back( $value ) -> None
```

### VectorOfImage::Add

```cpp
void VectorOfImage::Add( dlib::image_dataset_metadata::image value );

AutoIt:
    $oVectorOfImage.Add( $value ) -> None
```

### VectorOfImage::Remove

```cpp
void VectorOfImage::Remove( size_t index );

AutoIt:
    $oVectorOfImage.Remove( $index ) -> None
```

### VectorOfImage::at

```cpp
dlib::image_dataset_metadata::image VectorOfImage::at( size_t index );

AutoIt:
    $oVectorOfImage.at( $index ) -> retval
```

```cpp
void VectorOfImage::at( size_t                              index,
                        dlib::image_dataset_metadata::image value );

AutoIt:
    $oVectorOfImage.at( $index, $value ) -> None
```

### VectorOfImage::size

```cpp
size_t VectorOfImage::size();

AutoIt:
    $oVectorOfImage.size() -> retval
```

### VectorOfImage::empty

```cpp
bool VectorOfImage::empty();

AutoIt:
    $oVectorOfImage.empty() -> retval
```

### VectorOfImage::clear

```cpp
void VectorOfImage::clear();

AutoIt:
    $oVectorOfImage.clear() -> None
```

### VectorOfImage::push_vector

```cpp
void VectorOfImage::push_vector( VectorOfImage other );

AutoIt:
    $oVectorOfImage.push_vector( $other ) -> None
```

```cpp
void VectorOfImage::push_vector( VectorOfImage other,
                                 size_t        count,
                                 size_t        start = 0 );

AutoIt:
    $oVectorOfImage.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfImage::slice

```cpp
VectorOfImage VectorOfImage::slice( size_t start = 0,
                                    size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfImage.slice( [$start[, $count]] ) -> retval
```

### VectorOfImage::sort

```cpp
void VectorOfImage::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfImage.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage::sort_variant

```cpp
void VectorOfImage::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfImage.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage::start

```cpp
void* VectorOfImage::start();

AutoIt:
    $oVectorOfImage.start() -> retval
```

### VectorOfImage::end

```cpp
void* VectorOfImage::end();

AutoIt:
    $oVectorOfImage.end() -> retval
```

### VectorOfImage::get_Item

```cpp
dlib::image_dataset_metadata::image VectorOfImage::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfImage.Item( $vIndex ) -> retval
    VectorOfImage( $vIndex ) -> retval
```

### VectorOfImage::put_Item

```cpp
void VectorOfImage::put_Item( size_t                              vIndex,
                              dlib::image_dataset_metadata::image vItem );

AutoIt:
    $oVectorOfImage.Item( $vIndex ) = $vItem
```

## VectorOfPairOfStringAndPoint

### VectorOfPairOfStringAndPoint::create

```cpp
static VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfStringAndPoint").create() -> <VectorOfPairOfStringAndPoint object>
```

```cpp
static VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfStringAndPoint").create( $size ) -> <VectorOfPairOfStringAndPoint object>
```

```cpp
static VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::create( VectorOfPairOfStringAndPoint other );

AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfStringAndPoint").create( $other ) -> <VectorOfPairOfStringAndPoint object>
```

### VectorOfPairOfStringAndPoint::Keys

```cpp
std::vector<int> VectorOfPairOfStringAndPoint::Keys();

AutoIt:
    $oVectorOfPairOfStringAndPoint.Keys() -> retval
```

### VectorOfPairOfStringAndPoint::Items

```cpp
VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::Items();

AutoIt:
    $oVectorOfPairOfStringAndPoint.Items() -> retval
```

### VectorOfPairOfStringAndPoint::push_back

```cpp
void VectorOfPairOfStringAndPoint::push_back( std::pair<string, dlib::point> value );

AutoIt:
    $oVectorOfPairOfStringAndPoint.push_back( $value ) -> None
```

### VectorOfPairOfStringAndPoint::Add

```cpp
void VectorOfPairOfStringAndPoint::Add( std::pair<string, dlib::point> value );

AutoIt:
    $oVectorOfPairOfStringAndPoint.Add( $value ) -> None
```

### VectorOfPairOfStringAndPoint::Remove

```cpp
void VectorOfPairOfStringAndPoint::Remove( size_t index );

AutoIt:
    $oVectorOfPairOfStringAndPoint.Remove( $index ) -> None
```

### VectorOfPairOfStringAndPoint::at

```cpp
std::pair<string, dlib::point> VectorOfPairOfStringAndPoint::at( size_t index );

AutoIt:
    $oVectorOfPairOfStringAndPoint.at( $index ) -> retval
```

```cpp
void VectorOfPairOfStringAndPoint::at( size_t                         index,
                                       std::pair<string, dlib::point> value );

AutoIt:
    $oVectorOfPairOfStringAndPoint.at( $index, $value ) -> None
```

### VectorOfPairOfStringAndPoint::size

```cpp
size_t VectorOfPairOfStringAndPoint::size();

AutoIt:
    $oVectorOfPairOfStringAndPoint.size() -> retval
```

### VectorOfPairOfStringAndPoint::empty

```cpp
bool VectorOfPairOfStringAndPoint::empty();

AutoIt:
    $oVectorOfPairOfStringAndPoint.empty() -> retval
```

### VectorOfPairOfStringAndPoint::clear

```cpp
void VectorOfPairOfStringAndPoint::clear();

AutoIt:
    $oVectorOfPairOfStringAndPoint.clear() -> None
```

### VectorOfPairOfStringAndPoint::push_vector

```cpp
void VectorOfPairOfStringAndPoint::push_vector( VectorOfPairOfStringAndPoint other );

AutoIt:
    $oVectorOfPairOfStringAndPoint.push_vector( $other ) -> None
```

```cpp
void VectorOfPairOfStringAndPoint::push_vector( VectorOfPairOfStringAndPoint other,
                                                size_t                       count,
                                                size_t                       start = 0 );

AutoIt:
    $oVectorOfPairOfStringAndPoint.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPairOfStringAndPoint::slice

```cpp
VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::slice( size_t start = 0,
                                                                  size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfStringAndPoint.slice( [$start[, $count]] ) -> retval
```

### VectorOfPairOfStringAndPoint::sort

```cpp
void VectorOfPairOfStringAndPoint::sort( void*  comparator,
                                         size_t start = 0,
                                         size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfStringAndPoint.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfStringAndPoint::sort_variant

```cpp
void VectorOfPairOfStringAndPoint::sort_variant( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfPairOfStringAndPoint.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfStringAndPoint::start

```cpp
void* VectorOfPairOfStringAndPoint::start();

AutoIt:
    $oVectorOfPairOfStringAndPoint.start() -> retval
```

### VectorOfPairOfStringAndPoint::end

```cpp
void* VectorOfPairOfStringAndPoint::end();

AutoIt:
    $oVectorOfPairOfStringAndPoint.end() -> retval
```

### VectorOfPairOfStringAndPoint::get_Item

```cpp
std::pair<string, dlib::point> VectorOfPairOfStringAndPoint::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfPairOfStringAndPoint.Item( $vIndex ) -> retval
    VectorOfPairOfStringAndPoint( $vIndex ) -> retval
```

### VectorOfPairOfStringAndPoint::put_Item

```cpp
void VectorOfPairOfStringAndPoint::put_Item( size_t                         vIndex,
                                             std::pair<string, dlib::point> vItem );

AutoIt:
    $oVectorOfPairOfStringAndPoint.Item( $vIndex ) = $vItem
```

## VectorOfString

### VectorOfString::create

```cpp
static VectorOfString VectorOfString::create();

AutoIt:
    _Dlib_ObjCreate("VectorOfString").create() -> <VectorOfString object>
```

```cpp
static VectorOfString VectorOfString::create( size_t size );

AutoIt:
    _Dlib_ObjCreate("VectorOfString").create( $size ) -> <VectorOfString object>
```

```cpp
static VectorOfString VectorOfString::create( VectorOfString other );

AutoIt:
    _Dlib_ObjCreate("VectorOfString").create( $other ) -> <VectorOfString object>
```

### VectorOfString::Keys

```cpp
std::vector<int> VectorOfString::Keys();

AutoIt:
    $oVectorOfString.Keys() -> retval
```

### VectorOfString::Items

```cpp
VectorOfString VectorOfString::Items();

AutoIt:
    $oVectorOfString.Items() -> retval
```

### VectorOfString::push_back

```cpp
void VectorOfString::push_back( string value );

AutoIt:
    $oVectorOfString.push_back( $value ) -> None
```

### VectorOfString::Add

```cpp
void VectorOfString::Add( string value );

AutoIt:
    $oVectorOfString.Add( $value ) -> None
```

### VectorOfString::Remove

```cpp
void VectorOfString::Remove( size_t index );

AutoIt:
    $oVectorOfString.Remove( $index ) -> None
```

### VectorOfString::at

```cpp
string VectorOfString::at( size_t index );

AutoIt:
    $oVectorOfString.at( $index ) -> retval
```

```cpp
void VectorOfString::at( size_t index,
                         string value );

AutoIt:
    $oVectorOfString.at( $index, $value ) -> None
```

### VectorOfString::size

```cpp
size_t VectorOfString::size();

AutoIt:
    $oVectorOfString.size() -> retval
```

### VectorOfString::empty

```cpp
bool VectorOfString::empty();

AutoIt:
    $oVectorOfString.empty() -> retval
```

### VectorOfString::clear

```cpp
void VectorOfString::clear();

AutoIt:
    $oVectorOfString.clear() -> None
```

### VectorOfString::push_vector

```cpp
void VectorOfString::push_vector( VectorOfString other );

AutoIt:
    $oVectorOfString.push_vector( $other ) -> None
```

```cpp
void VectorOfString::push_vector( VectorOfString other,
                                  size_t         count,
                                  size_t         start = 0 );

AutoIt:
    $oVectorOfString.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfString::slice

```cpp
VectorOfString VectorOfString::slice( size_t start = 0,
                                      size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfString.slice( [$start[, $count]] ) -> retval
```

### VectorOfString::sort

```cpp
void VectorOfString::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfString.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfString::sort_variant

```cpp
void VectorOfString::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = this->__self->get()->size() );

AutoIt:
    $oVectorOfString.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfString::start

```cpp
void* VectorOfString::start();

AutoIt:
    $oVectorOfString.start() -> retval
```

### VectorOfString::end

```cpp
void* VectorOfString::end();

AutoIt:
    $oVectorOfString.end() -> retval
```

### VectorOfString::get_Item

```cpp
string VectorOfString::get_Item( size_t vIndex );

AutoIt:
    $oVectorOfString.Item( $vIndex ) -> retval
    VectorOfString( $vIndex ) -> retval
```

### VectorOfString::put_Item

```cpp
void VectorOfString::put_Item( size_t vIndex,
                               string vItem );

AutoIt:
    $oVectorOfString.Item( $vIndex ) = $vItem
```
