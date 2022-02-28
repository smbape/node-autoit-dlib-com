#include "./basic.h"

std::string dlib::version(AUTOIT_QUOTE_STRING(DLIB_VERSION));
std::string dlib::time_compiled = std::string(__DATE__) + " " + std::string(__TIME__);

#ifdef DLIB_USE_CUDA
   bool dlib::DLIB_USE_CUDA = true;
#else
   bool dlib::DLIB_USE_CUDA = false;
#endif
#ifdef DLIB_USE_BLAS 
   bool dlib::DLIB_USE_BLAS = true;
#else
   bool dlib::DLIB_USE_BLAS = false;
#endif
#ifdef DLIB_USE_LAPACK
   bool dlib::DLIB_USE_LAPACK = true;
#else
   bool dlib::DLIB_USE_LAPACK = false;
#endif
#ifdef DLIB_HAVE_AVX
   bool dlib::USE_AVX_INSTRUCTIONS = true;
#else
   bool dlib::USE_AVX_INSTRUCTIONS = false;
#endif
#ifdef DLIB_HAVE_NEON 
   bool dlib::USE_NEON_INSTRUCTIONS = true;
#else
   bool dlib::USE_NEON_INSTRUCTIONS = false;
#endif
