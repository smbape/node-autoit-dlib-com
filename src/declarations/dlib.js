module.exports = [
    ["dlib.", "", ["/Properties"], [
        ["_variant_t", "extended", "", ["/R", "/External"]],
    ], "", ""],

    ["dlib.", "", ["/Properties"], [
        ["string", "version", "", ["/R"]],
        ["string", "time_compiled", "", ["/R"]],
        ["bool", "DLIB_USE_CUDA", "", ["/RExpr=dlib::_DLIB_USE_CUDA"]],
        ["bool", "DLIB_USE_BLAS", "", ["/RExpr=dlib::_DLIB_USE_BLAS"]],
        ["bool", "DLIB_USE_LAPACK", "", ["/RExpr=dlib::_DLIB_USE_LAPACK"]],
        ["bool", "USE_AVX_INSTRUCTIONS", "", ["/RExpr=dlib::_DLIB_HAVE_AVX"]],
        ["bool", "USE_NEON_INSTRUCTIONS", "", ["/RExpr=dlib::_DLIB_HAVE_NEON"]],
    ], "", ""],

    ["dlib.variant", "_variant_t", ["/External"], [
        ["void*", "ptr", "", []],
    ], "", ""],
];
