#pragma once

#include <dlib/data_io.h>
#include <dlib/filtering.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/matrix.h>
#include <dlib/string.h>
#include <dlib/svm.h>
#include <dlib/svm_threaded.h>
#include <vector>
#include "cv_image.h"

using namespace std;

namespace dlib {
	// ----------------------------------------------------------------------------------------

	typedef matrix<double, 0, 1> dense_vect;
	typedef matrix<double, 0, 1> sample_type;
	typedef matrix<double, 0, 1> SpaceVector;
	typedef matrix<double> Matrix;

	typedef std::vector<std::pair<unsigned long, double>> sparse_vect;
	typedef std::vector<std::pair<unsigned long, unsigned long>> ranges;

	typedef ranking_pair<sample_type> vec_ranking_pair;
	typedef std::vector<vec_ranking_pair> ranking_pairs;
	typedef svm_rank_trainer<linear_kernel<sample_type>> vec_svm_rank_trainer;
	typedef decision_function<linear_kernel<sample_type>> _decision_function_linear;

	typedef ranking_pair<sparse_vect> sparse_ranking_pair;
	typedef std::vector<sparse_ranking_pair> sparse_ranking_pairs;
	typedef svm_rank_trainer<sparse_linear_kernel<sparse_vect>> svm_rank_trainer_sparse;
	typedef decision_function<sparse_linear_kernel<sparse_vect>> _decision_function_sparse_linear;

	typedef decision_function<histogram_intersection_kernel<sample_type>> _decision_function_histogram_intersection;
	typedef decision_function<sparse_histogram_intersection_kernel<sparse_vect>> _decision_function_sparse_histogram_intersection;
	typedef decision_function<polynomial_kernel<sample_type>> _decision_function_polynomial;
	typedef decision_function<sparse_polynomial_kernel<sparse_vect>> _decision_function_sparse_polynomial;
	typedef decision_function<radial_basis_kernel<sample_type>> _decision_function_radial_basis;
	typedef decision_function<sparse_radial_basis_kernel<sparse_vect>> _decision_function_sparse_radial_basis;
	typedef decision_function<sigmoid_kernel<sample_type>> _decision_function_sigmoid;
	typedef decision_function<sparse_sigmoid_kernel<sparse_vect>> _decision_function_sparse_sigmoid;

	typedef radial_basis_kernel<sample_type> _radial_basis_kernel;
	typedef linear_kernel<sample_type> _linear_kernel;

	typedef normalized_function<decision_function<radial_basis_kernel<sample_type>>> _normalized_decision_function_radial_basis;

	typedef frontal_face_detector fhog_object_detector;
	typedef frontal_face_detector simple_object_detector;

	typedef svm_c_trainer<radial_basis_kernel<sample_type>> svm_c_trainer_radial_basis;
	typedef svm_c_trainer<sparse_radial_basis_kernel<sparse_vect>> svm_c_trainer_sparse_radial_basis;
	typedef svm_c_trainer<histogram_intersection_kernel<sample_type>> svm_c_trainer_histogram_intersection;
	typedef svm_c_trainer<sparse_histogram_intersection_kernel<sparse_vect>> svm_c_trainer_sparse_histogram_intersection;
	typedef svm_c_linear_trainer<linear_kernel<sample_type>> svm_c_trainer_linear;
	typedef svm_c_linear_trainer<sparse_linear_kernel<sparse_vect>> svm_c_trainer_sparse_linear;

	typedef rvm_trainer<radial_basis_kernel<sample_type>> rvm_trainer_radial_basis;
	typedef rvm_trainer<sparse_radial_basis_kernel<sparse_vect>> rvm_trainer_sparse_radial_basis;
	typedef rvm_trainer<histogram_intersection_kernel<sample_type>> rvm_trainer_histogram_intersection;
	typedef rvm_trainer<sparse_histogram_intersection_kernel<sparse_vect>> rvm_trainer_sparse_histogram_intersection;
	typedef rvm_trainer<linear_kernel<sample_type>> rvm_trainer_linear;
	typedef rvm_trainer<sparse_linear_kernel<sparse_vect>> rvm_trainer_sparse_linear;

	// ----------------------------------------------------------------------------------------

	inline void Mat_to_vector_sample_type(const cv::Mat& img, std::vector<sample_type>& samples)
	{
		auto const x_ = cv_image<double>(img);
		auto x = make_image_view(x_);
		AUTOIT_ASSERT_THROW(x.nc() > 0 && x.nr() > 0, "matrix must not be empty");

		samples.resize(x.nr());

		for (long r = 0; r < x.nr(); ++r)
		{
			samples[r].set_size(x.nc());
			for (long c = 0; c < x.nc(); ++c)
			{
				samples[r](c) = x[r][c];
			}
		}
	}

	inline const std::vector<sample_type> Mat_to_vector_sample_type(const cv::Mat& img)
	{
		std::vector<sample_type> samples;
		Mat_to_vector_sample_type(img, samples);
		return samples;
	}

	template <typename image_type>
	inline const array<cv_image<image_type>> vector_Mat_to_dlib(
		const std::vector<cv::Mat>& _images
	)
	{
		array<cv_image<image_type>> images(_images.size());
		vector_Mat_to_dlib(_images, images);
		return images;
	}

	template <typename image_type>
	inline void vector_Mat_to_dlib(
		const std::vector<cv::Mat>& _images,
		array<cv_image<image_type>>& images
	)
	{
		unsigned long image_idx = 0;
		for (const auto& image : _images) {
			images[image_idx++] = cv_image<image_type>(image);
		}
	}
}
