#include "Dlib_Image_window_Object.h"
#include <dlib/image_processing/render_face_detections.h>

using namespace dlib;
using namespace std;

template <typename T>
std::shared_ptr<image_window> make_image_window_from_image(const cv_image<T>& img)
{
	auto win = std::make_shared<image_window>();
	win->set_image(img);
	return win;
}

template <typename T>
std::shared_ptr<image_window> make_image_window_from_image_and_title(const cv_image<T>& img, const string& title)
{
	auto win = std::make_shared<image_window>();
	win->set_image(img);
	win->set_title(title);
	return win;
}

void image_window_set_image(image_window& win, const cv::Mat& img) {
	if (img.channels() == 1) {
		switch (img.depth()) {
		case cv::DataType<uint8_t>::depth:
			win.set_image(cv_image<uint8_t>(img));
			return;
		case cv::DataType<uint16_t>::depth:
			win.set_image(cv_image<uint16_t>(img));
			return;
		case cv::DataType<int8_t>::depth:
			win.set_image(cv_image<int8_t>(img));
			return;
		case cv::DataType<int16_t>::depth:
			win.set_image(cv_image<int16_t>(img));
			return;
		case cv::DataType<int32_t>::depth:
			win.set_image(cv_image<int32_t>(img));
			return;
		case cv::DataType<float>::depth:
			win.set_image(cv_image<float>(img));
			return;
		case cv::DataType<double>::depth:
			win.set_image(cv_image<double>(img));
			return;
		default:
			throw error("Unsupported image type");
		}
	}

	AUTOIT_ASSERT_THROW(img.channels() == 3 && img.depth() == CV_8U, "Unsupported image type");
	win.set_image(cv_image<bgr_pixel>(img));
}

std::shared_ptr<image_window> make_image_window_from_image(const cv::Mat& img) {
	if (img.channels() == 1) {
		switch (img.depth()) {
		case cv::DataType<uint8_t>::depth:
			return make_image_window_from_image<uint8_t>(cv_image<uint8_t>(img));
		case cv::DataType<uint16_t>::depth:
			return make_image_window_from_image<uint16_t>(cv_image<uint16_t>(img));
		case cv::DataType<int8_t>::depth:
			return make_image_window_from_image<int8_t>(cv_image<int8_t>(img));
		case cv::DataType<int16_t>::depth:
			return make_image_window_from_image<int16_t>(cv_image<int16_t>(img));
		case cv::DataType<int32_t>::depth:
			return make_image_window_from_image<int32_t>(cv_image<int32_t>(img));
		case cv::DataType<float>::depth:
			return make_image_window_from_image<float>(cv_image<float>(img));
		case cv::DataType<double>::depth:
			return make_image_window_from_image<double>(cv_image<double>(img));
		default:
			throw error("Unsupported image type");
		}
	}

	AUTOIT_ASSERT_THROW(img.channels() == 3 && img.depth() == CV_8U, "Unsupported image type");
	return make_image_window_from_image<bgr_pixel>(cv_image<bgr_pixel>(img));
}

std::shared_ptr<image_window> make_image_window_from_image_and_title(const cv::Mat& img, const string& title) {
	if (img.channels() == 1) {
		switch (img.depth()) {
		case cv::DataType<uint8_t>::depth:
			return make_image_window_from_image_and_title<uint8_t>(cv_image<uint8_t>(img), title);
		case cv::DataType<uint16_t>::depth:
			return make_image_window_from_image_and_title<uint16_t>(cv_image<uint16_t>(img), title);
		case cv::DataType<int8_t>::depth:
			return make_image_window_from_image_and_title<int8_t>(cv_image<int8_t>(img), title);
		case cv::DataType<int16_t>::depth:
			return make_image_window_from_image_and_title<int16_t>(cv_image<int16_t>(img), title);
		case cv::DataType<int32_t>::depth:
			return make_image_window_from_image_and_title<int32_t>(cv_image<int32_t>(img), title);
		case cv::DataType<float>::depth:
			return make_image_window_from_image_and_title<float>(cv_image<float>(img), title);
		case cv::DataType<double>::depth:
			return make_image_window_from_image_and_title<double>(cv_image<double>(img), title);
		default:
			throw error("Unsupported image type");
		}
	}

	AUTOIT_ASSERT_THROW(img.channels() == 3 && img.depth() == CV_8U, "Unsupported image type");
	return make_image_window_from_image_and_title<bgr_pixel>(cv_image<bgr_pixel>(img), title);
}

void add_overlay_parts(
	image_window& win,
	const full_object_detection& detection,
	const rgb_pixel& color
)
{
	if (detection.num_parts() == 5 || detection.num_parts() == 68)
	{
		win.add_overlay(render_face_detections(detection, color));
	}
	else
	{
		std::vector<image_display::overlay_circle> tmp;
		for (unsigned long i = 0; i < detection.num_parts(); ++i)
			tmp.emplace_back(detection.part(i), 0.5, color, std::to_string(i));
		win.add_overlay(tmp);
		win.add_overlay(detection.get_rect());
	}
}

void add_overlay_vector_variant(
	image_window& win,
	const std::vector<_variant_t>& objs,
	const rgb_pixel& color
) {
	shared_ptr<rectangle> prect;
	shared_ptr<drectangle> pdrect;
	shared_ptr<line> pline;
	shared_ptr<full_object_detection> pdetection;

	for (const auto& obj : objs) {
		if (is_assignable_from(prect, &obj, false)) {
			autoit_to(&obj, prect);
			win.add_overlay(*prect.get(), color);
		}
		else if (is_assignable_from(pdrect, &obj, false)) {
			autoit_to(&obj, pdrect);
			win.add_overlay(rectangle(*pdrect.get()), color);
		}
		else if (is_assignable_from(pline, &obj, false)) {
			autoit_to(&obj, pline);
			win.add_overlay(*pline.get(), color);
		}
		else if (is_assignable_from(pdetection, &obj, false)) {
			autoit_to(&obj, pdetection);
			add_overlay_parts(win, *pdetection.get(), color);
		}
		else {
			throw dlib::error("Unsupported overlay");
		}
	}
}

const std::shared_ptr<dlib::image_window> CDlib_Image_window_Object::create(dlib::fhog_object_detector& detector, HRESULT& hr) {
	hr = S_OK;
	auto win = std::make_shared<image_window>();
	win->set_image(draw_fhog(detector));
	return win;
}

const std::shared_ptr<dlib::image_window> CDlib_Image_window_Object::create(dlib::simple_object_detector_com& detector, HRESULT& hr) {
	hr = S_OK;
	auto win = std::make_shared<image_window>();
	win->set_image(draw_fhog(detector.detector));
	return win;
}

const std::shared_ptr<dlib::image_window> CDlib_Image_window_Object::create(dlib::fhog_object_detector& detector, string title, HRESULT& hr) {
	hr = S_OK;
	auto win = std::make_shared<image_window>();
	win->set_image(draw_fhog(detector));
	win->set_title(title);
	return win;
}

const std::shared_ptr<dlib::image_window> CDlib_Image_window_Object::create(dlib::simple_object_detector_com& detector, string title, HRESULT& hr) {
	hr = S_OK;
	auto win = std::make_shared<image_window>();
	win->set_image(draw_fhog(detector.detector));
	win->set_title(title);
	return win;
}

const std::shared_ptr<dlib::image_window> CDlib_Image_window_Object::create(cv::Mat& img, HRESULT& hr) {
	hr = S_OK;
	return make_image_window_from_image(img);
}

const std::shared_ptr<dlib::image_window> CDlib_Image_window_Object::create(cv::Mat& img, string title, HRESULT& hr) {
	hr = S_OK;
	return make_image_window_from_image_and_title(img, title);
}

void CDlib_Image_window_Object::set_image(cv::Mat& img, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();
	image_window_set_image(win, img);
}

void CDlib_Image_window_Object::add_overlay(dlib::full_object_detection& detection, dlib::rgb_pixel& color, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();
	add_overlay_parts(win, detection, color);
}

void CDlib_Image_window_Object::add_overlay(dlib::full_object_detection& detection, std::tuple<uchar, uchar, uchar>& color, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();
	add_overlay_parts(win, detection, rgb_pixel(std::get<0>(color), std::get<1>(color), std::get<2>(color)));
}

void CDlib_Image_window_Object::add_overlay(std::vector<_variant_t>& objs, dlib::rgb_pixel& color, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();
	add_overlay_vector_variant(win, objs, color);
}

void CDlib_Image_window_Object::add_overlay(std::vector<_variant_t>& objs, std::tuple<uchar, uchar, uchar>& color, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();
	add_overlay_vector_variant(win, objs, rgb_pixel(std::get<0>(color), std::get<1>(color), std::get<2>(color)));
}

void CDlib_Image_window_Object::wait_for_keypress(char wait_key, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();

	unsigned long key;
	bool is_printable;
	while (win.get_next_keypress(key, is_printable))
	{
		if (is_printable && (char)key == wait_key)
			return;
	}
}

void CDlib_Image_window_Object::wait_for_keypress(string _wait_key, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();

	static std::map<std::string, base_window::non_printable_keyboard_keys> str_to_key;

	if (str_to_key.size() == 0) {
		str_to_key["BACKSPACE"] = base_window::KEY_BACKSPACE;
		str_to_key["SHIFT"] = base_window::KEY_SHIFT;
		str_to_key["CTRL"] = base_window::KEY_CTRL;
		str_to_key["ALT"] = base_window::KEY_ALT;
		str_to_key["PAUSE"] = base_window::KEY_PAUSE;
		str_to_key["CAPS_LOCK"] = base_window::KEY_CAPS_LOCK;
		str_to_key["ESC"] = base_window::KEY_ESC;
		str_to_key["PAGE_UP"] = base_window::KEY_PAGE_UP;
		str_to_key["PAGE_DOWN"] = base_window::KEY_PAGE_DOWN;
		str_to_key["END"] = base_window::KEY_END;
		str_to_key["HOME"] = base_window::KEY_HOME;
		str_to_key["LEFT"] = base_window::KEY_LEFT;
		str_to_key["RIGHT"] = base_window::KEY_RIGHT;
		str_to_key["UP"] = base_window::KEY_UP;
		str_to_key["DOWN"] = base_window::KEY_DOWN;
		str_to_key["INSERT"] = base_window::KEY_INSERT;
		str_to_key["DELETE"] = base_window::KEY_DELETE;
		str_to_key["SCROLL_LOCK"] = base_window::KEY_SCROLL_LOCK;
		str_to_key["F1"] = base_window::KEY_F1;
		str_to_key["F2"] = base_window::KEY_F2;
		str_to_key["F3"] = base_window::KEY_F3;
		str_to_key["F4"] = base_window::KEY_F4;
		str_to_key["F5"] = base_window::KEY_F5;
		str_to_key["F6"] = base_window::KEY_F6;
		str_to_key["F7"] = base_window::KEY_F7;
		str_to_key["F8"] = base_window::KEY_F8;
		str_to_key["F9"] = base_window::KEY_F9;
		str_to_key["F10"] = base_window::KEY_F10;
		str_to_key["F11"] = base_window::KEY_F11;
		str_to_key["F12"] = base_window::KEY_F12;
	}

	if (str_to_key.find(_wait_key) == str_to_key.end()) {
		return;
	}

	const base_window::non_printable_keyboard_keys wait_key = str_to_key[_wait_key];

	unsigned long key;
	bool is_printable;
	while (win.get_next_keypress(key, is_printable))
	{
		if (!is_printable && key == wait_key)
			return;
	}
}

const bool CDlib_Image_window_Object::get_next_keypress(char* _key, bool* _is_printable, std::vector<int>& mods, bool get_keyboard_modifiers, HRESULT& hr) {
	hr = S_OK;
	auto& win = *this->__self->get();

	unsigned long key;
	auto& is_printable = *_is_printable;
	unsigned long state;

	if (!win.get_next_keypress(key, is_printable, state)) {
		return false;
	}

	*_key = (char)key;

	if (get_keyboard_modifiers) {
		if (state & base_window::KBD_MOD_SHIFT) mods.push_back(static_cast<int>(base_window::KBD_MOD_SHIFT));
		if (state & base_window::KBD_MOD_CONTROL) mods.push_back(static_cast<int>(base_window::KBD_MOD_CONTROL));
		if (state & base_window::KBD_MOD_ALT) mods.push_back(static_cast<int>(base_window::KBD_MOD_ALT));
		if (state & base_window::KBD_MOD_META) mods.push_back(static_cast<int>(base_window::KBD_MOD_META));
		if (state & base_window::KBD_MOD_CAPS_LOCK) mods.push_back(static_cast<int>(base_window::KBD_MOD_CAPS_LOCK));
		if (state & base_window::KBD_MOD_NUM_LOCK) mods.push_back(static_cast<int>(base_window::KBD_MOD_NUM_LOCK));
		if (state & base_window::KBD_MOD_SCROLL_LOCK) mods.push_back(static_cast<int>(base_window::KBD_MOD_SCROLL_LOCK));
	}

	return true;
}