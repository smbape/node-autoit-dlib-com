#include "test.h"
#include <semaphore>

#import "dlibCOM.tlb"

#include <opencv2/core/core.hpp>

template<typename T>
inline auto to_variant_t(const T& in_val) {
	return cv::Ptr<_variant_t>(new _variant_t(in_val));
}

/**
 * @param  str std::string
 * @return     std::wstring
 * @see https://stackoverflow.com/a/59617138
 */
inline auto ConvertUtf8ToWide(const std::string& str) {
	int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
	std::wstring wstr(count, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &wstr[0], count);
	return wstr;
}

inline void string_to_bstr(const std::string& in_val, _bstr_t& out_val) {
	std::wstring ws = ConvertUtf8ToWide(in_val);
	BSTR bstr = SysAllocStringLen(ws.data(), ws.size());
	out_val = _bstr_t(bstr);
	SysFreeString(bstr);
}

template<typename... T>
inline auto _Dlib_Tuple(T... args) {

	const int size = sizeof...(args);
	CComSafeArray<VARIANT> arr(size);

	int i = 0;
	for (auto& arg : { args... }) {
		arr.SetAt(i++, _variant_t(arg));
	}

	auto safeArray = arr.Detach();
	VARIANT variant = { VT_ARRAY | VT_VARIANT };
	V_ARRAY(&variant) = safeArray;

	return variant;
}

using namespace std;

static void testMatrix() {
	dlibCOM::IDlib_Matrix_ObjectPtr MatrixPtr;
	auto hr = MatrixPtr.CreateInstance(__uuidof(dlibCOM::Dlib_Matrix_Object));
	assert(SUCCEEDED(hr));

	std::wcout << MatrixPtr->ToString() << std::endl;

	auto _result = MatrixPtr->create();
	assert(V_VT(&_result) == VT_DISPATCH);
	auto matrix = static_cast<dlibCOM::IDlib_Matrix_Object*>(V_DISPATCH(&_result));
	std::wcout << matrix->ToString() << std::endl;

	_result = MatrixPtr->create(to_variant_t(3), to_variant_t(2));
	assert(V_VT(&_result) == VT_DISPATCH);
	matrix = static_cast<dlibCOM::IDlib_Matrix_Object*>(V_DISPATCH(&_result));
	std::wcout << matrix->ToString() << std::endl;

	_variant_t values = _Dlib_Tuple(1, 2, 3, 4);
	_result = MatrixPtr->create(&values);
	assert(V_VT(&_result) == VT_DISPATCH);
	matrix = static_cast<dlibCOM::IDlib_Matrix_Object*>(V_DISPATCH(&_result));
	std::wcout << matrix->ToString() << std::endl;
}

static void test_cv_returns() {
	dlibCOM::IDlib_ObjectPtr dlib;
	auto hr = dlib.CreateInstance(__uuidof(dlibCOM::Dlib_Object));
	assert(SUCCEEDED(hr));

	_bstr_t image_path;
	string_to_bstr("_deps\\dlib-src\\examples\\faces\\2007_007763.jpg", image_path);

	auto img = dlib->load_rgb_image(to_variant_t(image_path));
	assert(img->width == 500);
	assert(img->height == 375);
}

static void test_cnn_face_detector() {
	dlibCOM::IDlib_ObjectPtr dlib;
	auto hr = dlib.CreateInstance(__uuidof(dlibCOM::Dlib_Object));
	assert(SUCCEEDED(hr));

	dlibCOM::IDlib_Cnn_face_detection_model_v1_ObjectPtr Cnn_face_detection_model_v1;
	hr = Cnn_face_detection_model_v1.CreateInstance(__uuidof(dlibCOM::Dlib_Cnn_face_detection_model_v1_Object));
	assert(SUCCEEDED(hr));

	_bstr_t dat_path;
	string_to_bstr("..\\..\\examples\\mmod_human_face_detector.dat", dat_path);
	auto cnn_face_detector = Cnn_face_detection_model_v1->create(to_variant_t(dat_path));

	dlibCOM::IDlib_Image_window_ObjectPtr win;
	hr = win.CreateInstance(__uuidof(dlibCOM::Dlib_Image_window_Object));
	assert(SUCCEEDED(hr));

	_bstr_t image_path;
	string_to_bstr("_deps\\dlib-src\\examples\\faces\\2007_007763.jpg", image_path);

	auto img = dlib->load_rgb_image(to_variant_t(image_path));

	auto dets = cnn_face_detector->call(to_variant_t(img.GetInterfacePtr()), to_variant_t(1));

	assert((V_VT(&dets) & VT_ARRAY) == VT_ARRAY);
	assert((V_VT(&dets) ^ VT_ARRAY) == VT_VARIANT);

	CComSafeArray<VARIANT> vArray;
	vArray.Attach(V_ARRAY(&dets));
	assert(vArray.GetCount() == 7);
	vArray.Detach();

}

static _variant_t vtDefault;
static _variant_t vtEmpty;

static int perform() {
	V_VT(&vtDefault) = VT_ERROR;
	V_ERROR(&vtDefault) = DISP_E_PARAMNOTFOUND;

	VariantInit(&vtEmpty);

	testMatrix();
	test_cv_returns();
	test_cnn_face_detector();

	return 0;
}

int main(int argc, char* argv[])
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr)) {
		std::wcout << L"could not initialize COM\n";
		return 1;
	}

	int code = perform();

	CoUninitialize();

	return code;
}
