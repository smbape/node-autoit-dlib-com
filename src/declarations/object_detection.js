module.exports = [
    ["class dlib.fhog_object_detector", "", ["/Simple"], [
        ["ULONG", "detection_window_width", "", ["/R", "=get_scanner().get_detection_window_width()"]],
        ["ULONG", "detection_window_height", "", ["/R", "=get_scanner().get_detection_window_height()"]],
        ["ULONG", "num_detectors", "", ["/R", "=num_detectors()"]],
    ], "", ""],

    ["dlib.fhog_object_detector.fhog_object_detector", "", [], [], "", ""],

    ["dlib.fhog_object_detector.create", "shared_ptr_fhog_object_detector", ["/External"], [
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

    ["dlib.fhog_object_detector.save", "void", ["/Call=dlib::save_simple_object_detector", "/Expr=*this->__self->get(), $0"], [
        ["string", "detector_output_filename", "", []],
    ], "", ""],

    ["dlib.get_frontal_face_detector", "fhog_object_detector", [], [], "", ""],
];
