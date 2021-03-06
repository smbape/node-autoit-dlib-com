module.exports = [
    ["struct dlib.rgb_pixel", "", ["/Simple"], [
        ["uchar", "red", "", ["/RW"]],
        ["uchar", "blue", "", ["/RW"]],
        ["uchar", "green", "", ["/RW"]],
    ], "", ""],

    ["dlib.rgb_pixel.rgb_pixel", "", [], [
        ["uchar", "red", "", []],
        ["uchar", "blue", "", []],
        ["uchar", "green", "", []],
    ], "", ""],

    // cv::Mat Class Reference

    ["class cv.Mat", "", ["/Simple"], [
        ["int", "flags", "", ["/RW"]],
        ["int", "dims", "", ["/RW"]],
        ["int", "rows", "", ["/RW"]],
        ["int", "cols", "", ["/RW"]],
        ["uchar*", "data", "", ["/RW"]],
        ["size_t", "step", "", ["/RW"]],
        ["int", "width", "", ["/RW", "=cols"]],
        ["int", "height", "", ["/RW", "=rows"]]
    ], "", ""],

    ["cv.Mat.Mat", "", [], [], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["int", "rows", "", []],
        ["int", "cols", "", []],
        ["int", "type", "", []]
    ], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["tuple_int_and_int", "size", "", ["/Expr=std::get<0>(size), std::get<1>(size)", "/Cast=Size"]],
        ["int", "type", "", []]
    ], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["int", "rows", "", []],
        ["int", "cols", "", []],
        ["int", "type", "", []],
        ["tuple_double_and_double_and_double_and_double", "s", "", ["/Expr=std::get<0>(s), std::get<1>(s), std::get<2>(s), std::get<3>(s)", "/Cast=Scalar"]],
    ], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["tuple_int_and_int", "size", "", ["/Expr=std::get<0>(size), std::get<1>(size)", "/Cast=Size"]],
        ["int", "type", "", []],
        ["tuple_double_and_double_and_double_and_double", "s", "", ["/Expr=std::get<0>(s), std::get<1>(s), std::get<2>(s), std::get<3>(s)", "/Cast=Scalar"]],
    ], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["int", "rows", "", []],
        ["int", "cols", "", []],
        ["int", "type", "", []],
        ["void*", "data", "", []],
        ["size_t", "step", "cv::Mat::AUTO_STEP", []]
    ], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["Mat", "m", "", []]
    ], "", ""],

    ["cv.Mat.Mat", "", [], [
        ["Mat", "src", "", []],
        ["tuple_int_and_int_and_int_and_int", "roi", "", ["/Expr=std::get<0>(roi), std::get<1>(roi), std::get<2>(roi), std::get<3>(roi)", "/Cast=Rect"]]
    ], "", ""],

    ["cv.Mat.isContinuous", "bool", [], [], "", ""],
    ["cv.Mat.isSubmatrix", "bool", [], [], "", ""],
    ["cv.Mat.elemSize", "size_t", [], [], "", ""],
    ["cv.Mat.elemSize1", "size_t", [], [], "", ""],

    ["cv.Mat.type", "int", [], [], "", ""],
    ["cv.Mat.depth", "int", [], [], "", ""],
    ["cv.Mat.channels", "int", [], [], "", ""],

    ["cv.Mat.step1", "size_t", [], [
        ["int", "i", "0", []]
    ], "", ""],

    ["cv.Mat.empty", "bool", [], [], "", ""],
    ["cv.Mat.total", "size_t", [], [], "", ""],
    ["cv.Mat.total", "size_t", [], [
        ["int", "startDim", "", []],
        ["int", "endDim", "INT_MAX", []],
    ], "", ""],

    ["cv.Mat.checkVector", "int", [], [
        ["int", "elemChannels", "", []],
        ["int", "depth", "-1", []],
        ["int", "requireContinuous", "true", []],
    ], "", ""],

    ["cv.Mat.ptr", "uchar*", [], [
        ["int", "y", "0", []]
    ], "", ""],
    ["cv.Mat.ptr", "uchar*", [], [
        ["int", "i0", "", []],
        ["int", "i1", "", []],
    ], "", ""],
    ["cv.Mat.ptr", "uchar*", [], [
        ["int", "i0", "", []],
        ["int", "i1", "", []],
        ["int", "i2", "", []],
    ], "", ""],

    ["cv.Mat.pop_back", "void", [], [
        ["size_t", "value", "", []]
    ], "", ""],
    ["cv.Mat.push_back", "void", [], [
        ["Mat", "value", "", []]
    ], "", ""],

    ["cv.Mat.reshape", "cv::Mat", [], [
        ["int", "cn", "", []],
        ["int", "rows", "0", []],
    ], "", ""],

    ["cv.Mat.eye", "cv::Mat", ["/S"], [
        ["int", "rows", "", []],
        ["int", "cols", "", []],
        ["int", "type", "", []],
    ], "", ""],

    ["cv.Mat.zeros", "cv::Mat", ["/S"], [
        ["int", "rows", "", []],
        ["int", "cols", "", []],
        ["int", "type", "", []],
    ], "", ""],

    ["cv.Mat.zeros", "cv::Mat", ["/S"], [
        ["tuple_int_and_int", "size", "", ["/Expr=std::get<0>(size), std::get<1>(size)", "/Cast=Size"]],
        ["int", "type", "", []],
    ], "", ""],

    ["cv.Mat.ones", "cv::Mat", ["/S"], [
        ["int", "rows", "", []],
        ["int", "cols", "", []],
        ["int", "type", "", []],
    ], "", ""],

    ["cv.Mat.ones", "cv::Mat", ["/S"], [
        ["tuple_int_and_int", "size", "", ["/Expr=std::get<0>(size), std::get<1>(size)", "/Cast=Size"]],
        ["int", "type", "", []],
    ], "", ""],

    // Image file reading and writing

    ["cv.haveImageReader", "bool", [], [
        ["string", "filename", "", []],
    ], "", ""],

    ["cv.haveImageWriter", "bool", [], [
        ["string", "filename", "", []],
    ], "", ""],

    ["cv.imcount", "size_t", [], [
        ["string", "filename", "", []],
        ["int", "flags", "IMREAD_ANYCOLOR", []],
    ], "", ""],

    ["cv.imdecode", "Mat", [], [
        ["Mat", "buf", "", []],
        ["int", "flags", "", []],
    ], "", ""],

    ["cv.imencode", "bool", [], [
        ["string", "ext", "", []],
        ["Mat", "img", "", []],
        ["vector_uchar", "buf", "", ["/O"]],
        ["vector_int", "params", "std::vector<int>()", []],
    ], "", ""],

    ["cv.imread", "Mat", [], [
        ["string", "filename", "", []],
        ["int", "flags", "IMREAD_COLOR", []],
    ], "", ""],

    ["cv.imreadmulti", "bool", [], [
        ["string", "filename", "", []],
        ["vector_Mat", "mats", "", ["/O"]],
        ["int", "flags", "IMREAD_ANYCOLOR", []],
    ], "", ""],

    ["cv.imreadmulti", "bool", [], [
        ["string", "filename", "", []],
        ["vector_Mat", "mats", "", ["/O"]],
        ["int", "start", "", []],
        ["int", "count", "", []],
        ["int", "flags", "IMREAD_ANYCOLOR", []],
    ], "", ""],

    ["cv.imwrite", "bool", [], [
        ["string", "filename", "", []],
        ["Mat", "img", "", []],
        ["vector_int", "params", "std::vector<int>()", []],
    ], "", ""],

    ["cv.imwritemulti", "bool", [], [
        ["string", "filename", "", []],
        ["vector_Mat", "img", "", []],
        ["vector_int", "params", "std::vector<int>()", []],
    ], "", ""],
];
