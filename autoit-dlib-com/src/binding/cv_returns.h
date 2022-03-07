#pragma once

#include <dlib/pixel.h>
#include <dlib/image_transforms.h>
#include <dlib/image_io.h>
#include "base.h"

using namespace std;

namespace dlib {
	CV_EXPORTS_W cv::Mat load_rgb_image(const std::string& path);

	CV_EXPORTS_W cv::Mat load_grayscale_image(const std::string& path);

	CV_EXPORTS_W void save_image(const cv::Mat& img, const std::string& path);

	CV_EXPORTS_W std::vector<cv::Mat> jitter_image(const cv::Mat& img, size_t num_jitters = 1, bool disturb_colors = false);

	CV_EXPORTS_W cv::Mat get_face_chip(const cv::Mat& img, const full_object_detection& face, size_t size = 150, float padding = 0.25);

	CV_EXPORTS_W std::vector<cv::Mat> get_face_chips(const cv::Mat& img, const std::vector<full_object_detection>& faces, size_t size = 150, float padding = 0.25);
}
