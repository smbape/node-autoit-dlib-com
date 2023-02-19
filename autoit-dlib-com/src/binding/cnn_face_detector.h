// Copyright (C) 2017  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

#pragma once

#include <dlib/dnn.h>
#include <dlib/image_transforms.h>
#include "base.h"

namespace dlib {
	class CV_EXPORTS_W cnn_face_detection_model_v1
	{

	public:

		CV_WRAP cnn_face_detection_model_v1(const std::string& model_filename);

		CV_WRAP std::vector<mmod_rect> detect(
			const cv::Mat& img,
			const int upsample_num_times = 0
		);

		CV_WRAP_AS(get_default call) std::vector<mmod_rect> call(
			const cv::Mat& img,
			const int upsample_num_times = 0
		);

		CV_WRAP std::vector<std::vector<mmod_rect>> detect_multi(
			const std::vector<cv::Mat>& imgs,
			const int upsample_num_times = 0,
			const int batch_size = 128
		);

		CV_WRAP_AS(get_default call) std::vector<std::vector<mmod_rect>> call(
			const std::vector<cv::Mat>& imgs,
			const int upsample_num_times = 0,
			const int batch_size = 128
		);

	private:

		template <long num_filters, typename SUBNET> using con5d = con<num_filters, 5, 5, 2, 2, SUBNET>;
		template <long num_filters, typename SUBNET> using con5 = con<num_filters, 5, 5, 1, 1, SUBNET>;

		template <typename SUBNET> using downsampler = relu<affine<con5d<32, relu<affine<con5d<32, relu<affine<con5d<16, SUBNET>>>>>>>>>;
		template <typename SUBNET> using rcon5 = relu<affine<con5<45, SUBNET>>>;

		using net_type = loss_mmod<con<1, 9, 9, 1, 1, rcon5<rcon5<rcon5<downsampler<input_rgb_image_pyramid<pyramid_down<6>>>>>>>>;

		net_type net;
	};
}
