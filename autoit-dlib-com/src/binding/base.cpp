#include "base.h"

const std::string dlib::version(AUTOIT_QUOTE_STRING(DLIB_VERSION));
const std::string dlib::time_compiled = std::string(__DATE__) + " " + std::string(__TIME__);

#ifdef DLIB_USE_CUDA
const bool dlib::_DLIB_USE_CUDA = true;
#else
const bool dlib::_DLIB_USE_CUDA = false;
#endif
#ifdef DLIB_USE_BLAS 
const bool dlib::_DLIB_USE_BLAS = true;
#else
const bool dlib::_DLIB_USE_BLAS = false;
#endif
#ifdef DLIB_USE_LAPACK
const bool dlib::_DLIB_USE_LAPACK = true;
#else
const bool dlib::_DLIB_USE_LAPACK = false;
#endif
#ifdef DLIB_HAVE_AVX
const bool dlib::_DLIB_HAVE_AVX = true;
#else
const bool dlib::_DLIB_HAVE_AVX = false;
#endif
#ifdef DLIB_HAVE_NEON 
const bool dlib::_DLIB_HAVE_NEON = true;
#else
const bool dlib::_DLIB_HAVE_NEON = false;
#endif
