// Copyright (C) 2017  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

#pragma once

#include <dlib/geometry/vector.h>
#include <dlib/dnn.h>
#include <dlib/image_transforms.h>
#include <dlib/image_io.h>
#include <dlib/clustering.h>
#include "base.h"

using namespace std;

namespace dlib {
	class CV_EXPORTS_W face_recognition_model_v1
	{

	public:

		CV_WRAP face_recognition_model_v1(const std::string& model_filename);

		CV_WRAP dense_vect compute_face_descriptor(
			const cv::Mat& image,
			const full_object_detection& face,
			const int num_jitters = 0,
			float padding = 0.25
		);

		CV_WRAP dense_vect compute_face_descriptor(
			const cv::Mat& image,
			const int num_jitters = 0
		);

		CV_WRAP std::vector<dense_vect> compute_face_descriptor(
			const cv::Mat& image,
			const std::vector<full_object_detection>& faces,
			const int num_jitters = 0,
			float padding = 0.25
		);

		CV_WRAP std::vector<std::vector<dense_vect>> compute_face_descriptor(
			const std::vector<cv::Mat>& images,
			const std::vector<std::vector<full_object_detection>>& batch_faces,
			const int num_jitters = 0,
			float padding = 0.25
		);

		CV_WRAP std::vector<dense_vect> compute_face_descriptor(
			const std::vector<cv::Mat>& images,
			const int num_jitters = 0
		);

	private:

		dlib::rand rnd;

		std::vector<matrix<rgb_pixel>> jitter_image(
			const matrix<rgb_pixel>& image,
			const int num_jitters
		);

		template <template <int, template<typename>class, int, typename> class block, int N, template<typename>class BN, typename SUBNET>
		using residual = add_prev1<block<N, BN, 1, tag1<SUBNET>>>;

		template <template <int, template<typename>class, int, typename> class block, int N, template<typename>class BN, typename SUBNET>
		using residual_down = add_prev2<avg_pool<2, 2, 2, 2, skip1<tag2<block<N, BN, 2, tag1<SUBNET>>>>>>;

		template <int N, template <typename> class BN, int stride, typename SUBNET>
		using block = BN<con<N, 3, 3, 1, 1, relu<BN<con<N, 3, 3, stride, stride, SUBNET>>>>>;

		template <int N, typename SUBNET> using ares = relu<residual<block, N, affine, SUBNET>>;
		template <int N, typename SUBNET> using ares_down = relu<residual_down<block, N, affine, SUBNET>>;

		template <typename SUBNET> using alevel0 = ares_down<256, SUBNET>;
		template <typename SUBNET> using alevel1 = ares<256, ares<256, ares_down<256, SUBNET>>>;
		template <typename SUBNET> using alevel2 = ares<128, ares<128, ares_down<128, SUBNET>>>;
		template <typename SUBNET> using alevel3 = ares<64, ares<64, ares<64, ares_down<64, SUBNET>>>>;
		template <typename SUBNET> using alevel4 = ares<32, ares<32, ares<32, SUBNET>>>;

		using anet_type = loss_metric<fc_no_bias<128, avg_pool_everything<
			alevel0<
			alevel1<
			alevel2<
			alevel3<
			alevel4<
			max_pool<3, 3, 2, 2, relu<affine<con<32, 7, 7, 2, 2,
			input_rgb_image_sized<150>
			>>>>>>>>>>>>;
		anet_type net;
	};

	CV_EXPORTS_W void save_face_chip(
		const cv::Mat& img,
		const full_object_detection& face,
		const std::string& chip_filename,
		size_t size = 150,
		float padding = 0.25
	);

	CV_EXPORTS_W void save_face_chips(
		const cv::Mat& img,
		const std::vector<full_object_detection>& faces,
		const std::string& chip_filename,
		size_t size = 150,
		float padding = 0.25
	);

	CV_EXPORTS_W std::vector<ULONG> chinese_whispers_clustering(
		std::vector<dense_vect> descriptors,
		float threshold
	);

	CV_EXPORTS_AS(chinese_whispers) std::vector<ULONG> chinese_whispers_raw(
		std::vector<dense_vect> edges
	);
}
