#include "Dlib_Object.h"

const _variant_t CDlib_Object::variant(void* ptr, HRESULT& hr) {
    return _variant_t(static_cast<VARIANT*>(ptr));
}
