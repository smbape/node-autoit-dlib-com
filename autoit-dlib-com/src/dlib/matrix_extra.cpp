#include "Dlib_Matrix_Object.h"

using namespace dlib;
using std::ostringstream;

STDMETHODIMP CDlib_Matrix_Object::get_shape(VARIANT* pVal) {
	if (this->__self) {
		auto& m = *this->__self->get();
		autoit_from(std::make_tuple(m.nr(), m.nc()), pVal);
		return S_OK;
	}
	return E_FAIL;
}

string mat_row::ToString() {
	auto& c = *this;
	ostringstream sout;
	sout << mat(c.data, 1, c.size);
	return sout.str();
}

double mat_row::get(long r) {
	auto& m = *this;
	if (r < 0) {
		r = m.size + r; // negative index
	}
	AUTOIT_ASSERT_THROW(r >= 0 && r <= m.size - 1, "1 index out of range");
	return m.data[r];
}

void mat_row::set(long r, double val) {
	auto& m = *this;
	if (r < 0) {
		r = m.size + r; // negative index
	}
	AUTOIT_ASSERT_THROW(r >= 0 && r <= m.size - 1, "3 index out of range");
	m.data[r] = val;
}

const Ptr<Matrix> CDlib_Matrix_Object::create(std::vector<double>& list, HRESULT& hr) {
	auto nr = list.size();
	auto temp = std::make_shared<Matrix>(nr, 1);

	for (long r = 0; r < nr; ++r) {
		(*temp)(r) = list[r];
	}

	hr = S_OK;
	return temp;
}

const Ptr<Matrix> CDlib_Matrix_Object::create(std::vector<std::vector<double>>& list, HRESULT& hr) {
	auto nr = list.size();
	if (nr == 0) {
		hr = S_OK;
		return std::make_shared<Matrix>(0, 0);
	}

	// make sure all the other rows have the same length
	auto nc = list[0].size();
	for (int r = 1; r < nr; r++) {
		AUTOIT_ASSERT_SET_HR(list[r].size() == nc);
		if (FAILED(hr)) {
			return Ptr<Matrix>();
		}
	}

	auto temp = std::make_shared<Matrix>(nr, nc);
	for (long r = 0; r < nr; ++r) {
		for (long c = 0; c < nc; ++c) {
			(*temp)(r, c) = list[r][c];
		}
	}

	return temp;
}

const Ptr<Matrix> CDlib_Matrix_Object::create(long rows, long cols, HRESULT& hr) {
	AUTOIT_ASSERT_SET_HR(rows >= 0 && cols >= 0);
	auto temp = std::make_shared<Matrix>(rows, cols);
	*temp = 0;
	return temp;
}

void CDlib_Matrix_Object::set_size(long rows, long cols, HRESULT& hr) {
	auto& m = *this->__self->get();
	m.set_size(rows, cols);
	m = 0;
	hr = S_OK;
}

void CDlib_Matrix_Object::serialize(const std::string file, HRESULT& hr) {
	auto& m = *this->__self->get();
	dlib::serialize(file) << m;
	hr = S_OK;
}

void CDlib_Matrix_Object::deserialize(const std::string file, HRESULT& hr) {
	auto& m = *this->__self->get();
	dlib::deserialize(file) >> m;
	hr = S_OK;
}

const mat_row CDlib_Matrix_Object::get(long r, HRESULT& hr) {
	auto& m = *this->__self->get();
	if (r < 0) {
		r = m.nr() + r; // negative index
	}

	AUTOIT_ASSERT_SET_HR(r >= 0 && r <= m.nr() - 1);
	if (FAILED(hr)) {
		r = 0;
	}

	return mat_row(&m(r, 0), m.nc());
}

const string CDlib_Matrix_Object::ToString(HRESULT& hr) {
	hr = S_OK;
	auto& m = *this->__self->get();
	ostringstream sout;
	sout << m;
	return trim(sout.str());
}
