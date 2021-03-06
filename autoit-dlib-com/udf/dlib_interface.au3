#include-once

; ImreadModes
Global Const $DLIB_CV_IMREAD_UNCHANGED = -1
Global Const $DLIB_CV_IMREAD_GRAYSCALE = 0
Global Const $DLIB_CV_IMREAD_COLOR = 1
Global Const $DLIB_CV_IMREAD_ANYDEPTH = 2
Global Const $DLIB_CV_IMREAD_ANYCOLOR = 4
Global Const $DLIB_CV_IMREAD_LOAD_GDAL = 8
Global Const $DLIB_CV_IMREAD_REDUCED_GRAYSCALE_2 = 16
Global Const $DLIB_CV_IMREAD_REDUCED_COLOR_2 = 17
Global Const $DLIB_CV_IMREAD_REDUCED_GRAYSCALE_4 = 32
Global Const $DLIB_CV_IMREAD_REDUCED_COLOR_4 = 33
Global Const $DLIB_CV_IMREAD_REDUCED_GRAYSCALE_8 = 64
Global Const $DLIB_CV_IMREAD_REDUCED_COLOR_8 = 65
Global Const $DLIB_CV_IMREAD_IGNORE_ORIENTATION = 128

; ImwriteFlags
Global Const $DLIB_CV_IMWRITE_JPEG_QUALITY = 1
Global Const $DLIB_CV_IMWRITE_JPEG_PROGRESSIVE = 2
Global Const $DLIB_CV_IMWRITE_JPEG_OPTIMIZE = 3
Global Const $DLIB_CV_IMWRITE_JPEG_RST_INTERVAL = 4
Global Const $DLIB_CV_IMWRITE_JPEG_LUMA_QUALITY = 5
Global Const $DLIB_CV_IMWRITE_JPEG_CHROMA_QUALITY = 6
Global Const $DLIB_CV_IMWRITE_PNG_COMPRESSION = 16
Global Const $DLIB_CV_IMWRITE_PNG_STRATEGY = 17
Global Const $DLIB_CV_IMWRITE_PNG_BILEVEL = 18
Global Const $DLIB_CV_IMWRITE_PXM_BINARY = 32
Global Const $DLIB_CV_IMWRITE_EXR_TYPE = (BitShift(3, -4)) + 0
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION = (BitShift(3, -4)) + 1
Global Const $DLIB_CV_IMWRITE_WEBP_QUALITY = 64
Global Const $DLIB_CV_IMWRITE_PAM_TUPLETYPE = 128
Global Const $DLIB_CV_IMWRITE_TIFF_RESUNIT = 256
Global Const $DLIB_CV_IMWRITE_TIFF_XDPI = 257
Global Const $DLIB_CV_IMWRITE_TIFF_YDPI = 258
Global Const $DLIB_CV_IMWRITE_TIFF_COMPRESSION = 259
Global Const $DLIB_CV_IMWRITE_JPEG2000_COMPRESSION_X1000 = 272

; ImwriteEXRTypeFlags
Global Const $DLIB_CV_IMWRITE_EXR_TYPE_HALF = 1
Global Const $DLIB_CV_IMWRITE_EXR_TYPE_FLOAT = 2

; ImwriteEXRCompressionFlags
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_NO = 0
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_RLE = 1
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_ZIPS = 2
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_ZIP = 3
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_PIZ = 4
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_PXR24 = 5
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_B44 = 6
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_B44A = 7
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_DWAA = 8
Global Const $DLIB_CV_IMWRITE_EXR_COMPRESSION_DWAB = 9

; ImwritePNGFlags
Global Const $DLIB_CV_IMWRITE_PNG_STRATEGY_DEFAULT = 0
Global Const $DLIB_CV_IMWRITE_PNG_STRATEGY_FILTERED = 1
Global Const $DLIB_CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY = 2
Global Const $DLIB_CV_IMWRITE_PNG_STRATEGY_RLE = 3
Global Const $DLIB_CV_IMWRITE_PNG_STRATEGY_FIXED = 4

; ImwritePAMFlags
Global Const $DLIB_CV_IMWRITE_PAM_FORMAT_NULL = 0
Global Const $DLIB_CV_IMWRITE_PAM_FORMAT_BLACKANDWHITE = 1
Global Const $DLIB_CV_IMWRITE_PAM_FORMAT_GRAYSCALE = 2
Global Const $DLIB_CV_IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA = 3
Global Const $DLIB_CV_IMWRITE_PAM_FORMAT_RGB = 4
Global Const $DLIB_CV_IMWRITE_PAM_FORMAT_RGB_ALPHA = 5
