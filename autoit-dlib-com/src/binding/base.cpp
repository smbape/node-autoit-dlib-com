#include "base.h"

std::string dlib::version(AUTOIT_QUOTE_STRING(DLIB_VERSION));
std::string dlib::time_compiled = std::string(__DATE__) + " " + std::string(__TIME__);

#ifdef DLIB_USE_CUDA
bool dlib::_DLIB_USE_CUDA = true;
#else
bool dlib::_DLIB_USE_CUDA = false;
#endif
#ifdef DLIB_USE_BLAS 
bool dlib::_DLIB_USE_BLAS = true;
#else
bool dlib::_DLIB_USE_BLAS = false;
#endif
#ifdef DLIB_USE_LAPACK
bool dlib::_DLIB_USE_LAPACK = true;
#else
bool dlib::_DLIB_USE_LAPACK = false;
#endif
#ifdef DLIB_HAVE_AVX
bool dlib::_DLIB_HAVE_AVX = true;
#else
bool dlib::_DLIB_HAVE_AVX = false;
#endif
#ifdef DLIB_HAVE_NEON 
bool dlib::_DLIB_HAVE_NEON = true;
#else
bool dlib::_DLIB_HAVE_NEON = false;
#endif
