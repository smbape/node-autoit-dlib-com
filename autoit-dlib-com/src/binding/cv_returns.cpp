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

template<typename pixel_type>
void save_image_impl(cv_image<pixel_type> img, const std::string& path, const float quality)
{
	std::string lowered_path = path;
	std::transform(lowered_path.begin(), lowered_path.end(), lowered_path.begin(), ::tolower);

	std::string error_message = "Unsupported image type, image path must end with one of [.bmp, .dng";
#if DLIB_PNG_SUPPORT
	error_message += ", .png";
#endif
#if DLIB_JPEG_SUPPORT
	error_message += ", .jpg, jpeg";
#endif
#if DLIB_WEBP_SUPPORT
	error_message += ", .webp";
#endif
#if DLIB_JXL_SUPPORT
	error_message += ", .jxl";
#endif
	error_message += "]";

	if (has_ending(lowered_path, ".bmp")) {
		save_bmp(img, path);
	}
	else if (has_ending(lowered_path, ".dng")) {
		save_dng(img, path);
	}
#if DLIB_PNG_SUPPORT
	else if (has_ending(lowered_path, ".png")) {
		save_png(img, path);
	}
#endif
#if DLIB_JPEG_SUPPORT
	else if (has_ending(lowered_path, ".jpg") || has_ending(lowered_path, ".jpeg")) {
		save_jpeg(img, path, put_in_range(0, 100, std::lround(quality)));
	}
#endif
#if DLIB_WEBP_SUPPORT
    } else if(has_ending(lowered_path, ".webp")) {
        save_webp(img, path, std::max(0.f, quality));
#endif
#if DLIB_JXL_SUPPORT
    } else if(has_ending(lowered_path, ".jxl")) {
        save_jxl(img, path, put_in_range(0, 100, quality));
#endif
	else {
		throw dlib::error(error_message);
	}
	return;
}

cv::Mat dlib::load_rgb_image(const std::string& path) {
	cv_image<bgr_pixel> img;
	load_image(img, path);
	return img.image;
}

cv::Mat dlib::load_rgb_alpha_image(const std::string& path) {
	cv_image<bgr_alpha_pixel> img;
	load_image(img, path);
	return img.image;
}

cv::Mat dlib::load_grayscale_image(const std::string& path) {
	cv_image<uint8_t> img;
	load_image(img, path);
	return img.image;
}

void dlib::save_image(const cv::Mat& img, const std::string& path, const float quality) {
	AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
	AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3 || img.channels() == 4, "Unsupported image type, must be 8bit gray or RGB image or RGBA image.");

	if (img.channels() == 1) {
		save_image_impl(cv_image<uint8_t>(img), path, quality);
	} else if (img.channels() == 4) {
		save_image_impl(cv_image<bgr_alpha_pixel>(img), path, quality);
	}
	else {
		save_image_impl(cv_image<bgr_pixel>(img), path, quality);
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

namespace {
	template <typename T>
	cv::Mat _get_face_chip(const cv::Mat& _img, const full_object_detection& face, size_t size, float padding) {
		cv_image<T> img(_img);
		cv_image<T> chip;
		extract_image_chip(img, get_face_chip_details(face, size, padding), chip);
		return chip.image;
	}
}

cv::Mat dlib::get_face_chip(const cv::Mat& img, const full_object_detection& face, size_t size, float padding) {
	const auto channels = img.channels();
	const auto dims = img.dims;
	const auto rows = img.rows;
	const auto cols = img.cols;
	const auto total = img.total();
	const auto is1D = dims == 1 || dims == 2 && (rows == total || cols == total);

	switch (img.depth()) {
	case CV_8U:
		if (is1D) {
			return ::_get_face_chip<uint8_t>(img, face, size, padding);
		}

		if (channels == 3) {
			return ::_get_face_chip<bgr_pixel>(img, face, size, padding);
		}

		break;
	case CV_8S:
		if (is1D) {
			return ::_get_face_chip<int8_t>(img, face, size, padding);
		}
		break;
	case CV_16U:
		if (is1D) {
			return ::_get_face_chip<uint16_t>(img, face, size, padding);
		}
		break;
	case CV_16S:
		if (is1D) {
			return ::_get_face_chip<int16_t>(img, face, size, padding);
		}
		break;
	case CV_32S:
		if (is1D) {
			return ::_get_face_chip<int32_t>(img, face, size, padding);
		}
		break;
	case CV_32F:
		if (is1D) {
			return ::_get_face_chip<float>(img, face, size, padding);
		}
		break;
	case CV_64F:
		if (is1D) {
			return ::_get_face_chip<double>(img, face, size, padding);
		}
		break;
	default:
		break;
	}

	AUTOIT_ASSERT_THROW(false, "image must be one dimision of CV_8U CV_8S CV_16U CV_16S CV_32S CV_32F CV_64F, or an RGB image");
}

namespace {
	template <typename T>
	std::vector<cv::Mat> _get_face_chips(const cv::Mat& _img, const std::vector<full_object_detection>& faces, size_t size, float padding) {
		cv_image<T> img(_img);

		std::vector<chip_details> dets;
		for (const auto& f : faces)
			dets.push_back(get_face_chip_details(f, size, padding));
		dlib::array<cv_image<T>> face_chips;
		extract_image_chips(img, dets, face_chips);

		std::vector<cv::Mat> chips_list;
		for (const auto& chip : face_chips) {
			// Append image to chips list
			chips_list.push_back(chip.image);
		}

		return chips_list;
	}
}

std::vector<cv::Mat> dlib::get_face_chips(const cv::Mat& img, const std::vector<full_object_detection>& faces, size_t size, float padding) {
	AUTOIT_ASSERT_THROW(faces.size() > 0, "No face were specified in the faces array.");

	const auto channels = img.channels();
	const auto dims = img.dims;
	const auto rows = img.rows;
	const auto cols = img.cols;
	const auto total = img.total();
	const auto is1D = dims == 1 || dims == 2 && (rows == total || cols == total);

	switch (img.depth()) {
	case CV_8U:
		if (is1D) {
			return ::_get_face_chips<uint8_t>(img, faces, size, padding);
		}

		if (channels == 3) {
			return ::_get_face_chips<bgr_pixel>(img, faces, size, padding);
		}

		break;
	case CV_8S:
		if (is1D) {
			return ::_get_face_chips<int8_t>(img, faces, size, padding);
		}
		break;
	case CV_16U:
		if (is1D) {
			return ::_get_face_chips<uint16_t>(img, faces, size, padding);
		}
		break;
	case CV_16S:
		if (is1D) {
			return ::_get_face_chips<int16_t>(img, faces, size, padding);
		}
		break;
	case CV_32S:
		if (is1D) {
			return ::_get_face_chips<int32_t>(img, faces, size, padding);
		}
		break;
	case CV_32F:
		if (is1D) {
			return ::_get_face_chips<float>(img, faces, size, padding);
		}
		break;
	case CV_64F:
		if (is1D) {
			return ::_get_face_chips<double>(img, faces, size, padding);
		}
		break;
	default:
		break;
	}

	AUTOIT_ASSERT_THROW(false, "image must be one dimision of CV_8U CV_8S CV_16U CV_16S CV_32S CV_32F CV_64F, or an RGB image");
}
