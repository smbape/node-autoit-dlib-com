module.exports = [
    // ["dlib.", "", ["/Properties"], [
    //     ["_variant_t", "extended", "", ["/R", "/External"]],
    // ], "", ""],

    ["dlib.", "", ["/Properties"], [
        ["string", "version", "", ["/R"]],
        ["string", "time_compiled", "", ["/R"]],
        ["bool", "DLIB_USE_CUDA", "", ["/R"]],
        ["bool", "DLIB_USE_BLAS", "", ["/R"]],
        ["bool", "DLIB_USE_LAPACK", "", ["/R"]],
        ["bool", "USE_AVX_INSTRUCTIONS", "", ["/R"]],
        ["bool", "USE_NEON_INSTRUCTIONS", "", ["/R"]],
    ], "", ""],

    ["dlib.variant", "_variant_t", ["/External"], [
        ["void*", "ptr", "", []],
    ], "", ""],
];
