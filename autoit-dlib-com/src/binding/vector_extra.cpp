#include "Dlib_Dpoint_Object.h"
#include "Dlib_Object.h"
#include "Dlib_Point_Object.h"
#include "Dlib_point_transform_projective_Object.h"
#include "Dlib_SpaceVector_Object.h"

using namespace dlib;
using namespace std;
using std::ostringstream;

// SpaceVector

STDMETHODIMP CDlib_SpaceVector_Object::get_shape(VARIANT* pVal) {
	CActCtxActivator ScopedContext(ExtendedHolder::_ActCtx);

	if (__self) {
		auto& m = *__self->get();
		autoit_from(std::make_tuple(m.nr(), m.nc()), pVal);
		return S_OK;
	}
	return E_FAIL;
}

const std::shared_ptr<SpaceVector> CDlib_SpaceVector_Object::create(std::vector<double>& list, HRESULT& hr) {
	auto nr = list.size();
	auto temp = std::make_shared<SpaceVector>(nr);

	for (long r = 0; r < nr; ++r) {
		(*temp)(r) = list[r];
	}

	hr = S_OK;
	return temp;
}

const std::shared_ptr<SpaceVector> CDlib_SpaceVector_Object::create(long rows, HRESULT& hr) {
	AUTOIT_ASSERT_SET_HR(rows >= 0);
	auto temp = std::make_shared<SpaceVector>(rows);
	*temp = 0;
	return temp;
}

void CDlib_SpaceVector_Object::set_size(long rows, HRESULT& hr) {
	auto& m = *__self->get();
	m.set_size(rows);
	m = 0;
	hr = S_OK;
}

void CDlib_SpaceVector_Object::resize(long rows, HRESULT& hr) {
	set_size(rows, hr);
}

void CDlib_SpaceVector_Object::set(long row, double val, HRESULT& hr) {
	auto& m = *__self->get();
	if (row < 0) {
		row = m.size() + row; // negative index
	}
	AUTOIT_ASSERT_THROW(row >= 0 && row <= m.size() - 1, "index out of range");
	m(row) = val;
	hr = S_OK;
}

const double CDlib_SpaceVector_Object::get(long row, HRESULT& hr) {
	auto& m = *__self->get();
	if (row < 0) {
		row = m.size() + row; // negative index
	}
	AUTOIT_ASSERT_THROW(row >= 0 && row <= m.size() - 1, "index out of range");
	hr = S_OK;
	return m(row);
}

const SpaceVector CDlib_SpaceVector_Object::slice(long start, long stop, long step, HRESULT& hr) {
	auto& m = *__self->get();

	AUTOIT_ASSERT_THROW(step != 0, "step must not be 0");

	if (stop < 0) {
		stop += m.size();
	}
	else if (step < 0 && stop == m.size()) {
		stop = -1;
	}

	if (start < 0) {
		start += m.size();
	}

	AUTOIT_ASSERT_THROW((step > 0 ? start < stop : start > stop), "start connot reach stop with step");
	AUTOIT_ASSERT_THROW(start >= 0 && start < m.size(), "start is out of range");
	AUTOIT_ASSERT_THROW(stop >= -1 && stop <= m.size(), "stop is out of range");

	hr = S_OK;

	size_t slicelength = ceil(((double)stop - start) / step);

	SpaceVector temp(slicelength);

	for (size_t i = 0; i < slicelength; ++i) {
		temp(i) = m(start); start += step;
	}

	return temp;
}

const string CDlib_SpaceVector_Object::ToString(HRESULT& hr) {
	hr = S_OK;
	auto& v = *__self->get();
	ostringstream sout;
	for (long i = 0; i < v.size(); ++i)
	{
		sout << v(i);
		if (i + 1 < v.size())
			sout << "\n";
	}
	return sout.str();
}


// point_transform_projective

const std::shared_ptr<point_transform_projective> CDlib_Point_transform_projective_Object::create(Matrix& m, HRESULT& hr) {
	AUTOIT_ASSERT_THROW(m.nr() == 3 && m.nc() == 3, "The matrix used to construct a point_transform_projective object must be 3x3.");
	hr = S_OK;
	return std::make_shared<point_transform_projective>(m);
}

const std::shared_ptr<point_transform_projective> CDlib_Point_transform_projective_Object::create(cv::Mat& img, HRESULT& hr) {
	const cv_image<double> m_(img);
	const_image_view<cv_image<double>> m(m_);
	AUTOIT_ASSERT_THROW(m.nr() == 3 && m.nc() == 3, "The matrix used to construct a point_transform_projective object must be 3x3.");
	hr = S_OK;
	return std::make_shared<point_transform_projective>(mat(m));
}

const point_transform_projective CDlib_Object::find_projective_transform(std::vector<dpoint>& from_points, std::vector<dpoint>& to_points, HRESULT& hr) {
	AUTOIT_ASSERT_THROW(from_points.size() == to_points.size(),
		"from_points and to_points must have the same number of points.");
	AUTOIT_ASSERT_THROW(from_points.size() >= 4,
		"You need at least 4 points to find a projective transform.");
	hr = S_OK;
	return dlib::find_projective_transform(from_points, to_points);
}

const string CDlib_Dpoint_Object::ToString(HRESULT& hr) {
	hr = S_OK;
	auto& p = *__self->get();
	std::ostringstream sout;
	sout << "(" << p.x() << ", " << p.y() << ")";
	return sout.str();
}

const string CDlib_Point_Object::ToString(HRESULT& hr) {
	hr = S_OK;
	auto& p = *__self->get();
	std::ostringstream sout;
	sout << "(" << p.x() << ", " << p.y() << ")";
	return sout.str();
}

const point_transform_projective CDlib_Object::find_projective_transform(Matrix& from_points, Matrix& to_points, HRESULT& hr) {
	AUTOIT_ASSERT_THROW(from_points.nc() == 2 && to_points.nc() == 2,
		"Both from_points and to_points must be arrays with 2 columns.");
	AUTOIT_ASSERT_THROW(from_points.nr() == to_points.nr(),
		"from_points and to_points must have the same number of rows.");
	AUTOIT_ASSERT_THROW(from_points.nr() >= 4,
		"You need at least 4 rows in the input matrices to find a projective transform.");

	hr = S_OK;

	std::vector<dpoint> from, to;
	for (long r = 0; r < from_points.nr(); ++r)
	{
		from.push_back(dpoint(from_points(r, 0), from_points(r, 1)));
		to.push_back(dpoint(to_points(r, 0), to_points(r, 1)));
	}

	return dlib::find_projective_transform(from, to);
}

template<typename T>
point_transform_projective find_projective_transform_impl(
	const cv_image<T>& from_points_,
	const cv_image<T>& to_points_
)
{
	const_image_view<cv_image<T>> from_points(from_points_);
	const_image_view<cv_image<T>> to_points(to_points_);

	DLIB_CASSERT(from_points.nc() == 2 && to_points.nc() == 2,
		"Both from_points and to_points must be arrays with 2 columns.");
	DLIB_CASSERT(from_points.nr() == to_points.nr(),
		"from_points and to_points must have the same number of rows.");
	DLIB_CASSERT(from_points.nr() >= 4,
		"You need at least 4 rows in the input matrices to find a projective transform.");

	std::vector<dpoint> from, to;
	for (long r = 0; r < from_points.nr(); ++r)
	{
		from.push_back(dpoint(from_points[r][0], from_points[r][1]));
		to.push_back(dpoint(to_points[r][0], to_points[r][1]));
	}

	return find_projective_transform(from, to);
}

const point_transform_projective CDlib_Object::find_projective_transform(cv::Mat& from_points, cv::Mat& to_points, HRESULT& hr) {
	hr = S_OK;

	AUTOIT_ASSERT_THROW(from_points.depth() == to_points.depth(),
		"from_points and to_points must be of the same type");

	AUTOIT_ASSERT_THROW(from_points.depth() == CV_32F || from_points.depth() == CV_64F,
		"Both from_points  must be of type CV_32F or CV_64F");

	if (from_points.depth() == CV_32F && to_points.depth() == CV_32F) {
		cv_image<float> _from_points(from_points);
		cv_image<float> _to_points(to_points);
		return find_projective_transform_impl(_from_points, _to_points);
	}

	cv_image<double> _from_points(from_points);
	cv_image<double> _to_points(to_points);
	return find_projective_transform_impl(_from_points, _to_points);
}
