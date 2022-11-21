exports.SIMPLE_ARGTYPE_DEFAULTS = new Map([
    ["bool", "0"],
    ["size_t", "0"],
    ["SSIZE_T", "0"],
    ["int", "0"],
    ["float", "0.f"],
    ["double", "0"],
    ["c_string", "(char*)\"\""],
]);

exports.IDL_TYPES = new Map([
    ["bool", "VARIANT_BOOL"],
    ["float", "FLOAT"],
    ["int64", "LONGLONG"],
    ["int", "LONG"],
    ["uint", "ULONG"],
    ["uint32", "ULONG"],
    ["long", "LONG"],
    ["ulong", "ULONG"],
    ["SSIZE_T", "LONGLONG"],
    ["size_t", "ULONGLONG"],
    ["uint64", "ULONGLONG"],
    ["String", "BSTR"],
    ["string", "BSTR"],
    ["uchar", "BYTE"],
    ["cv::String", "BSTR"],
    ["std::string", "BSTR"],

    ["InputArray", "VARIANT"],
    ["InputArrayOfArrays", "VARIANT"],
    ["InputOutputArray", "VARIANT"],
    ["InputOutputArrayOfArrays", "VARIANT"],
    ["OutputArray", "VARIANT"],
    ["OutputArrayOfArrays", "VARIANT"],
]);

exports.CPP_TYPES = new Map([
    ["InputArray", "cv::_InputArray"],
    ["InputArrayOfArrays", "cv::_InputArray"],
    ["InputOutputArray", "cv::_InputOutputArray"],
    ["InputOutputArrayOfArrays", "cv::_InputOutputArray"],
    ["OutputArray", "cv::_OutputArray"],
    ["OutputArrayOfArrays", "cv::_OutputArray"],

    ["string", "std::string"],
]);

exports.ALIASES = new Map([
    ["dense_vect", "SpaceVector"],
    ["sample_type", "SpaceVector"],
    ["matrix_double_0_1", "SpaceVector"],
    ["matrix_double", "Matrix"],
    ["sparse_vect", "vector_pair_ULONG_and_double"],
    ["ranges", "vector_pair_ULONG_and_ULONG"],
    ["simple_object_detector", "fhog_object_detector"],
]);

exports.CLASS_PTR = new Set([
]);

exports.PTR = new Set([
    "void*",
    "uchar*",
    "HWND",
    "get_truth_joint_feature_vector_function",
    "separation_oracle_function",
]);

exports.CUSTOM_CLASSES = [
];

exports.ARRAY_CLASSES = new Set([
]);

exports.ARRAYS_CLASSES = new Set([
]);

exports.IGNORED_CLASSES = new Set([
]);

for (const type of exports.CPP_TYPES.keys()) {
    const cpptype = exports.CPP_TYPES.get(type);
    if (cpptype[0] !== "_" &&
        !cpptype.startsWith("cv::_")
        && !cpptype.includes("<")
        && !type.includes("string")
        && !type.includes("String")
        && !exports.ALIASES.has(cpptype)
    ) {
        exports.ALIASES.set(type, cpptype);
    }
}
