#pragma once

#include <opencv2/core/core.hpp>

#ifdef AutoIt_Func
// keep current value (through OpenCV port file)
#elif defined __GNUC__ || (defined (__cpluscplus) && (__cpluscplus >= 201103))
#define AutoIt_Func __func__
#elif defined __clang__ && (__clang_minor__ * 100 + __clang_major__ >= 305)
#define AutoIt_Func __func__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION >= 199901)
#define AutoIt_Func __func__
#elif defined _MSC_VER
#define AutoIt_Func __FUNCTION__
#elif defined(__INTEL_COMPILER) && (_INTEL_COMPILER >= 600)
#define AutoIt_Func __FUNCTION__
#elif defined __IBMCPP__ && __IBMCPP__ >=500
#define AutoIt_Func __FUNCTION__
#elif defined __BORLAND__ && (__BORLANDC__ >= 0x550)
#define AutoIt_Func __FUNC__
#else
#define AutoIt_Func "<unknown>"
#endif

#ifndef AUTOIT_QUOTE_STRING2
#define AUTOIT_QUOTE_STRING2(x) #x
#endif
#ifndef AUTOIT_QUOTE_STRING
#define AUTOIT_QUOTE_STRING(x) AUTOIT_QUOTE_STRING2(x)
#endif

#ifndef AUTOIT_ASSERT_THROW
#define AUTOIT_ASSERT_THROW( expr, msg ) do { if(!!(expr)) ; else { \
fflush(stdout); fflush(stderr); \
fprintf(stderr, "dlib(%s) Error: %s (%s) in %s, file %s, line %d\n", AUTOIT_QUOTE_STRING(DLIB_VERSION), msg, #expr, AutoIt_Func, __FILE__, __LINE__); \
fflush(stdout); fflush(stderr); \
throw dlib::error(msg); } \
} while(0)
#endif

#ifndef AUTOIT_ASSERT_SET_HR
#define AUTOIT_ASSERT_SET_HR( expr ) do { if(!!(expr)) { hr = S_OK; } else { \
fprintf(stderr, "dlib(%s) Error: (%s) in %s, file %s, line %d\n", AUTOIT_QUOTE_STRING(DLIB_VERSION), #expr, AutoIt_Func, __FILE__, __LINE__); \
hr = E_FAIL; } \
} while(0)
#endif
