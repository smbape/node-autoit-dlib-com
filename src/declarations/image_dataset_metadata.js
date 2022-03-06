module.exports = [
    ["enum dlib.image_dataset_metadata.gender_t", "", [], [
        ["const dlib.image_dataset_metadata.UNKNOWN", "0", []],
        ["const dlib.image_dataset_metadata.MALE", "1", []],
        ["const dlib.image_dataset_metadata.FEMALE", "2", []],
    ], "", ""],

    ["struct dlib.image_dataset_metadata.box", "", ["/Simple"], [
        ["rectangle", "rect", "", ["/RW"]],
        ["map_string_and_point", "parts", "", ["/RW"]],
        ["string", "label", "", ["/RW"]],
        ["bool", "difficult", "", ["/RW"]],
        ["bool", "truncated", "", ["/RW"]],
        ["bool", "occluded", "", ["/RW"]],
        ["bool", "ignore", "", ["/RW"]],
        ["double", "pose", "", ["/RW"]],
        ["double", "detection_score", "", ["/RW"]],
        ["double", "angle", "", ["/RW"]],
        ["gender_t", "gender", "", ["/RW"]],
        ["double", "age", "", ["/RW"]],
    ], "", ""],

    ["dlib.image_dataset_metadata.box.box", "", [], [], "", ""],

    ["dlib.image_dataset_metadata.box.box", "", [], [
        ["rectangle", "rect", "", []],
    ], "", ""],

    ["dlib.image_dataset_metadata.box.has_label", "bool", [], [], "", ""],

    ["struct dlib.image_dataset_metadata.image", "", ["/Simple"], [
        ["string", "filename", "", ["/RW"]],
        ["vector_box", "boxes", "", ["/RW"]],
    ], "", ""],

    ["dlib.image_dataset_metadata.image.image", "", [], [], "", ""],

    ["dlib.image_dataset_metadata.image.image", "", [], [
        ["string", "filename", "", []],
    ], "", ""],

    ["struct dlib.image_dataset_metadata.dataset", "", ["/Simple"], [
        ["vector_image", "images", "", ["/RW"]],
        ["string", "comment", "", ["/RW"]],
        ["string", "name", "", ["/RW"]],
    ], "", ""],

    ["dlib.image_dataset_metadata.dataset.dataset", "", [], [], "", ""],

    ["dlib.image_dataset_metadata.save_image_dataset_metadata", "void", [], [
        ["dataset", "data", "", []],
        ["string", "filename", "", []],
    ], "", ""],

    ["dlib.image_dataset_metadata.load_image_dataset_metadata", "void", [], [
        ["dataset", "data", "", ["/Ref", "/O"]],
        ["string", "filename", "", []],
    ], "", ""],

    ["dlib.image_dataset_metadata.make_bounding_box_regression_training_data", "dataset", ["/Call=dlib::make_bounding_box_regression_training_data"], [
        ["dataset", "truth", "", ["/Ref"]],
        ["vector_vector_rectangle", "detections", "", []],
    ], "", ""],

];
