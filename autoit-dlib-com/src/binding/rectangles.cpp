#include "Dlib_Drectangle_Object.h"
#include "Dlib_Rectangle_Object.h"

using namespace dlib;

const string CDlib_Drectangle_Object::ToString(HRESULT& hr) {
	hr = S_OK;
	auto& r = *this->__self->get();
	std::ostringstream sout;
	sout << r;
	return sout.str();
}

const string CDlib_Rectangle_Object::ToString(HRESULT& hr) {
	hr = S_OK;
	auto& r = *this->__self->get();
	std::ostringstream sout;
	sout << r;
	return sout.str();
}
