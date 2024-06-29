module.exports = ({ self, shared_ptr }) => [
    ["class dlib.full_object_detection", "", [], [
        ["rectangle", "rect", "", ["/R", "=get_rect()"]],
        ["ULONG", "num_parts", "", ["/R", "=num_parts()"]],
    ], "", ""],

    ["dlib.full_object_detection.full_object_detection", "", [], [], "", ""],

    ["dlib.full_object_detection.full_object_detection", "", [], [
        ["rectangle", "rect", "", []],
        ["std::vector<point>", "parts", "", []],
    ], "", ""],

    ["dlib.full_object_detection.part", "point", [], [
        ["ULONG", "idx", "", []],
    ], "", ""],

    ["dlib.full_object_detection.parts", "std::vector<point>", ["/External"], [], "", ""],

    ["class dlib.shape_predictor", "", [], [], "", ""],

    ["dlib.shape_predictor.shape_predictor", "", [], [], "", ""],

    ["dlib.shape_predictor.create", `${ shared_ptr }<shape_predictor>`, ["/Call=dlib::load_object_from_file<shape_predictor>"], [
        ["string", "filename", "", []],
    ], "", ""],

    ["dlib.shape_predictor.call", "full_object_detection", ["/Call=dlib::run_predictor", `/Expr=${ self }, $0`, "/attr=propget", "=get_call", "/idlname=call", "/id=DISPID_VALUE"], [
        ["Mat", "img", "", []],
        ["rectangle", "box", "", []],
    ], "", ""],

    ["dlib.shape_predictor.save", "void", ["/Call=dlib::save_object_to_file<shape_predictor>", `/Expr=${ self }, $0`], [
        ["string", "detector_output_filename", "", []],
    ], "", ""],

    ["dlib.train_shape_predictor_on_images<dlib::array<cv_image<unsigned char>>>", "shape_predictor", ["=train_shape_predictor"], [
        ["std::vector<Mat>", "images", "", ["/Ref", "/Cast=vector_Mat_to_dlib<unsigned char>"]],
        ["std::vector<std::vector<full_object_detection>>", "detections", "", ["/Ref"]],
        ["shape_predictor_training_options", "options", "", ["/Ref"]],
    ], "", ""],

    ["dlib.test_shape_predictor_with_images", "double", ["=test_shape_predictor"], [
        ["string", "dataset_filename", "", []],
        ["string", "predictor_filename", "", []],
    ], "", ""],

    ["dlib.test_shape_predictor_with_images", "double", ["=test_shape_predictor"], [
        ["std::vector<Mat>", "images", "", ["/Ref", "/Cast=vector_Mat_to_dlib<unsigned char>"]],
        ["std::vector<std::vector<full_object_detection>>", "detections", "", ["/Ref"]],
        ["std::vector<std::vector<double>>", "scales", "", ["/Ref"]],
        ["shape_predictor", "predictor", "", ["/Ref"]],
    ], "", ""],

    ["dlib.test_shape_predictor_with_images", "double", ["=test_shape_predictor", "/Expr=vector_Mat_to_dlib<unsigned char>(images), detections, scales, predictor"], [
        ["std::vector<Mat>", "images", "", ["/Ref"]],
        ["std::vector<std::vector<full_object_detection>>", "detections", "", ["/Ref"]],
        ["shape_predictor", "predictor", "", ["/Ref"]],
        ["std::vector<std::vector<double>>", "scales", "std::vector<std::vector<double>>()", ["/Ref"]],
    ], "", ""],
];
