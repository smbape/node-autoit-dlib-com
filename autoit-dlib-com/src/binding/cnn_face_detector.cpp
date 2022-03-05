// Copyright (C) 2017  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

#include "cnn_face_detector.h"

using namespace dlib;
using namespace std;

cnn_face_detection_model_v1::cnn_face_detection_model_v1(const std::string& model_filename)
{
	deserialize(model_filename) >> net;
}

std::vector<mmod_rect> cnn_face_detection_model_v1::detect(
	const cv::Mat& img,
	const int upsample_num_times
)
{
	AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
	AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

	pyramid_down<2> pyr;
	std::vector<mmod_rect> rects;

	// Copy the data into dlib based objects
	matrix<rgb_pixel> image;
	if (img.channels() == 1) {
		assign_image(image, cv_image<unsigned char>(img));
	}
	else {
		assign_image(image, cv_image<rgb_pixel>(img));
	}

	// Upsampling the image will allow us to detect smaller faces but will cause the
	// program to use more RAM and run longer.
	unsigned int levels = upsample_num_times;
	while (levels > 0)
	{
		levels--;
		pyramid_up(image, pyr);
	}

	auto dets = net(image);

	// Scale the detection locations back to the original image size
	// if the image was upscaled.
	for (auto&& d : dets) {
		d.rect = pyr.rect_down(d.rect, upsample_num_times);
		rects.push_back(d);
	}

	return rects;
}

std::vector<mmod_rect> cnn_face_detection_model_v1::call(
	const cv::Mat& img,
	const int upsample_num_times
)
{
	return detect(img, upsample_num_times);
}

std::vector<std::vector<mmod_rect>> cnn_face_detection_model_v1::detect_multi(
	const std::vector<cv::Mat>& images,
	const int upsample_num_times,
	const int batch_size
)
{
	pyramid_down<2> pyr;
	std::vector<matrix<rgb_pixel>> dimgs;
	dimgs.reserve(images.size());

	for (const auto& tmp : images)
	{
		AUTOIT_ASSERT_THROW(tmp.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
		AUTOIT_ASSERT_THROW(tmp.channels() == 1 || tmp.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

        // Copy the data into dlib based objects
        matrix<rgb_pixel> image;

		if (tmp.channels() == 1) {
			assign_image(image, cv_image<unsigned char>(tmp));
		}
		else {
			assign_image(image, cv_image<rgb_pixel>(tmp));
		}

		for (int i = 0; i < upsample_num_times; i++)
		{
			pyramid_up(image);
		}
		dimgs.emplace_back(std::move(image));
	}

	for (int i = 1; i < dimgs.size(); i++)
	{
		AUTOIT_ASSERT_THROW(dimgs[i - 1].nc() == dimgs[i].nc() && dimgs[i - 1].nr() == dimgs[i].nr(),
			"Images in list must all have the same dimensions.");
	}

	auto dets = net(dimgs, batch_size);
	std::vector<std::vector<mmod_rect> > all_rects;

	for (auto&& im_dets : dets)
	{
		std::vector<mmod_rect> rects;
		rects.reserve(im_dets.size());
		for (auto&& d : im_dets) {
			d.rect = pyr.rect_down(d.rect, upsample_num_times);
			rects.push_back(d);
		}
		all_rects.push_back(rects);
	}

	return all_rects;
}
std::vector<std::vector<mmod_rect>> cnn_face_detection_model_v1::call(
	const std::vector<cv::Mat>& images,
	const int upsample_num_times,
	const int batch_size
)
{
	return detect_multi(images, upsample_num_times, batch_size);
}
