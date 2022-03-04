const declarations = [
    ["class dlib.fhog_object_detector", "", ["/Simple"], [
        ["ULONG", "detection_window_width", "", ["/R", "=get_scanner().get_detection_window_width()"]],
        ["ULONG", "detection_window_height", "", ["/R", "=get_scanner().get_detection_window_height()"]],
        ["ULONG", "num_detectors", "", ["/R", "=num_detectors()"]],
    ], "", ""],

    ["dlib.fhog_object_detector.fhog_object_detector", "", [], [], "", ""],

    ["dlib.fhog_object_detector.create", "shared_ptr_fhog_object_detector", ["/Call=dlib::load_object_from_file<fhog_object_detector>"], [
        ["string", "filename", "", []],
    ], "", ""],

    ["dlib.fhog_object_detector.run", "void", ["/External"], [
        ["cv::Mat", "image", "", []],
        ["vector_rectangle", "rectangles", "", ["/O"]],
        ["vector_double", "detection_confidences", "", ["/O"]],
        ["vector_ULONG", "weight_indices", "", ["/O"]],
        ["uint", "upsample_num_times", "0", []],
        ["double", "adjust_threshold", "0.0", []],
    ], "", ""],

    ["dlib.fhog_object_detector.save", "void", ["/Call=dlib::save_object_to_file<fhog_object_detector>", "/Expr=*this->__self->get(), $0"], [
        ["string", "detector_output_filename", "", []],
    ], "", ""],

    ["dlib.get_frontal_face_detector", "fhog_object_detector", [], [], "", ""],

    ["dlib.num_separable_filters", "ULONG", [], [
        ["fhog_object_detector", "detector", "", ["/Ref"]]
    ], "", ""],

    ["dlib.num_separable_filters", "ULONG", [], [
        ["simple_object_detector_com", "detector", "", ["/Ref", "/Expr=detector.detector"]]
    ], "", ""],

    ["dlib.threshold_filter_singular_values", "fhog_object_detector", [], [
        ["fhog_object_detector", "detector", "", ["/Ref"]],
        ["double", "thresh", "", []],
        ["ULONG", "weight_index", "0", []],
    ], "", ""],

    ["dlib.threshold_filter_singular_values", "simple_object_detector_com", ["/WrapAs=simple_object_detector_com"], [
        ["simple_object_detector_com", "detector", "", ["/Ref", "/Expr=detector.detector"]],
        ["double", "thresh", "", []],
        ["ULONG", "weight_index", "0", []],
    ], "", ""],

    ["dlib.simple_object_detector_com.", "", ["/Properties"], [
        ["ULONG", "detection_window_width", "", ["/R", "=detector.get_scanner().get_detection_window_width()"]],
        ["ULONG", "detection_window_height", "", ["/R", "=detector.get_scanner().get_detection_window_height()"]],
        ["ULONG", "num_detectors", "", ["/R", "=detector.num_detectors()"]],
    ], "", ""],
];

for (const clazz of ["fhog_object_detector", "simple_object_detector_com"]) {
    for (const detector of ["fhog_object_detector", "simple_object_detector_com"]) {
        declarations.push(...[
            [`dlib.${ clazz }.run_multiple`, "void", ["/External", "/S"], [
                [`vector_${ detector }`, "vectors", "", []],
                ["cv::Mat", "image", "", []],
                ["vector_rectangle", "rectangles", "", ["/O"]],
                ["vector_double", "detection_confidences", "", ["/O"]],
                ["vector_ULONG", "weight_indices", "", ["/O"]],
                ["uint", "upsample_num_times", "0", []],
                ["double", "adjust_threshold", "0.0", []],
            ], "", ""],
        ]);
    }
}

module.exports = declarations;
