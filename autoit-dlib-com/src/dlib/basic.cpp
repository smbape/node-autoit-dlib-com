#include "dlib/basic.h"

#define DLIB_QUOTE_STRING(x) DLIB_QUOTE_STRING2(x)
#define DLIB_QUOTE_STRING2(x) #x

std::string dlib::version() {
    return DLIB_QUOTE_STRING(DLIB_VERSION);
}
