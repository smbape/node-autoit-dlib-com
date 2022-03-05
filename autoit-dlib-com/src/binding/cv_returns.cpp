#include "cv_returns.h"

using namespace dlib;
using namespace std;
using namespace cv;

bool has_ending(std::string const full_string, std::string const& ending) {
	const auto& ending_len = ending.length();
	const auto& full_string_len = full_string.length();

	return full_string_len >= ending_len &&
		full_string.compare(full_string_len - ending_len, ending_len, ending) == 0;
}

// ----------------------------------------------------------------------------------------

template <typename pixel_type>
void save_image_impl(cv_image<pixel_type> img, const std::string& path)
{
	std::string lowered_path = path;
	std::transform(lowered_path.begin(), lowered_path.end(), lowered_path.begin(), ::tolower);

	if (has_ending(lowered_path, ".bmp")) {
		save_bmp(img, path);
	}
	else if (has_ending(lowered_path, ".dng")) {
		save_dng(img, path);
	}
	else if (has_ending(lowered_path, ".png")) {
		save_png(img, path);
	}
	else if (has_ending(lowered_path, ".jpg") || has_ending(lowered_path, ".jpeg")) {
		save_jpeg(img, path);
	}
	else {
		throw dlib::error("Unsupported image type, image path must end with one of [.bmp, .png, .dng, .jpg, .jpeg]");
	}
	return;
}

cv::Mat dlib::load_rgb_image(const std::string& path) {
	cv_image<bgr_pixel> img;
	load_image(img, path);
	return img.image;
}

cv::Mat dlib::load_grayscale_image(const std::string& path) {
	cv_image<unsigned char> img;
	load_image(img, path);
	return img.image;
}

void dlib::save_image(const cv::Mat& img, const std::string& path) {
	AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
	AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

	if (img.channels() == 1) {
		save_image_impl(cv_image<unsigned char>(img), path);
	}
	else {
		save_image_impl(cv_image<bgr_pixel>(img), path);
	}
}

std::vector<cv::Mat> dlib::jitter_image(const cv::Mat& _img, size_t num_jitters, bool disturb_colors) {
	static dlib::rand rnd_jitter;

	cv_image<bgr_pixel> img(_img);

	std::vector<cv::Mat> jitter_list(num_jitters);

	for (int i = 0; i < num_jitters; ++i) {
		// Get a jittered crop
		cv_image<bgr_pixel> crop = dlib::jitter_image(img, rnd_jitter);

		// If required disturb colors of the image
		if (disturb_colors)
			dlib::disturb_colors(crop, rnd_jitter);

		// Append image to jittered image list
		jitter_list[i] = crop.image;
	}

	return jitter_list;
}

cv::Mat dlib::get_face_chip(const cv::Mat& _img, const full_object_detection& face, size_t size, float padding) {
	cv_image<bgr_pixel> img(_img);
	cv_image<bgr_pixel> chip;
	extract_image_chip(img, get_face_chip_details(face, size, padding), chip);
	return chip.image;
}

std::vector<cv::Mat> dlib::get_face_chips(const cv::Mat& _img, const std::vector<full_object_detection>& faces, size_t size, float padding) {
	AUTOIT_ASSERT_THROW(faces.size() > 0, "No face were specified in the faces array.");

	cv_image<bgr_pixel> img(_img);

	std::vector<chip_details> dets;
	for (const auto& f : faces)
		dets.push_back(get_face_chip_details(f, size, padding));
	dlib::array<cv_image<bgr_pixel>> face_chips;
	extract_image_chips(img, dets, face_chips);

	std::vector<cv::Mat> chips_list;
	for (const auto& chip : face_chips) {
		// Append image to chips list
		chips_list.push_back(chip.image);
	}

	return chips_list;
}
