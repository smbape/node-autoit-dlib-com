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

namespace dlib {
	// ----------------------------------------------------------------------------------------

	using dense_vect = matrix<double, 0, 1>;
	using sample_type = matrix<double, 0, 1>;
	using SpaceVector = matrix<double, 0, 1>;
	using Matrix = matrix<double>;

	using sparse_vect = std::vector<std::pair<unsigned long, double>>;
	using ranges = std::vector<std::pair<unsigned long, unsigned long>>;

	using vec_ranking_pair = ranking_pair<sample_type>;
	using ranking_pairs = std::vector<vec_ranking_pair>;
	using vec_svm_rank_trainer = svm_rank_trainer<linear_kernel<sample_type>>;
	using _decision_function_linear = decision_function<linear_kernel<sample_type>>;

	using sparse_ranking_pair = ranking_pair<sparse_vect>;
	using sparse_ranking_pairs = std::vector<sparse_ranking_pair>;
	using svm_rank_trainer_sparse = svm_rank_trainer<sparse_linear_kernel<sparse_vect>>;
	using _decision_function_sparse_linear = decision_function<sparse_linear_kernel<sparse_vect>>;

	using _decision_function_histogram_intersection = decision_function<histogram_intersection_kernel<sample_type>>;
	using _decision_function_sparse_histogram_intersection = decision_function<sparse_histogram_intersection_kernel<sparse_vect>>;
	using _decision_function_polynomial = decision_function<polynomial_kernel<sample_type>>;
	using _decision_function_sparse_polynomial = decision_function<sparse_polynomial_kernel<sparse_vect>>;
	using _decision_function_radial_basis = decision_function<radial_basis_kernel<sample_type>>;
	using _decision_function_sparse_radial_basis = decision_function<sparse_radial_basis_kernel<sparse_vect>>;
	using _decision_function_sigmoid = decision_function<sigmoid_kernel<sample_type>>;
	using _decision_function_sparse_sigmoid = decision_function<sparse_sigmoid_kernel<sparse_vect>>;

	using _radial_basis_kernel = radial_basis_kernel<sample_type>;
	using _linear_kernel = linear_kernel<sample_type>;

	using _normalized_decision_function_radial_basis = normalized_function<decision_function<radial_basis_kernel<sample_type>>>;

	using fhog_object_detector = frontal_face_detector;
	using simple_object_detector = frontal_face_detector;

	using svm_c_trainer_radial_basis = svm_c_trainer<radial_basis_kernel<sample_type>>;
	using svm_c_trainer_sparse_radial_basis = svm_c_trainer<sparse_radial_basis_kernel<sparse_vect>>;
	using svm_c_trainer_histogram_intersection = svm_c_trainer<histogram_intersection_kernel<sample_type>>;
	using svm_c_trainer_sparse_histogram_intersection = svm_c_trainer<sparse_histogram_intersection_kernel<sparse_vect>>;
	using svm_c_trainer_linear = svm_c_linear_trainer<linear_kernel<sample_type>>;
	using svm_c_trainer_sparse_linear = svm_c_linear_trainer<sparse_linear_kernel<sparse_vect>>;

	using rvm_trainer_radial_basis = rvm_trainer<radial_basis_kernel<sample_type>>;
	using rvm_trainer_sparse_radial_basis = rvm_trainer<sparse_radial_basis_kernel<sparse_vect>>;
	using rvm_trainer_histogram_intersection = rvm_trainer<histogram_intersection_kernel<sample_type>>;
	using rvm_trainer_sparse_histogram_intersection = rvm_trainer<sparse_histogram_intersection_kernel<sparse_vect>>;
	using rvm_trainer_linear = rvm_trainer<linear_kernel<sample_type>>;
	using rvm_trainer_sparse_linear = rvm_trainer<sparse_linear_kernel<sparse_vect>>;

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

	template<typename image_type>
	inline const array<cv_image<image_type>> vector_Mat_to_dlib(
		const std::vector<cv::Mat>& _images
	)
	{
		array<cv_image<image_type>> images(_images.size());
		vector_Mat_to_dlib(_images, images);
		return images;
	}

	template<typename image_type>
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

	inline void vector_drectangle_to_vector_rectangle(const std::vector<drectangle>& drectangles, std::vector<rectangle>& rectangles)
	{
		rectangles.clear();
		for (const auto& drect : drectangles) {
			rectangles.push_back(rectangle(drect));
		}
	}

	inline const std::vector<rectangle> vector_drectangle_to_vector_rectangle(const std::vector<drectangle>& drectangles)
	{
		std::vector<rectangle> rectangles;
		vector_drectangle_to_vector_rectangle(drectangles, rectangles);
		return rectangles;
	}

	inline matrix<double, 0, 1> list_to_mat(const std::vector<double>& l)
	{
		matrix<double, 0, 1> result(l.size());
		for (long i = 0; i < result.size(); ++i)
			result(i) = l[i];
		return result;
	}

	inline void mat_to_list(const matrix<double, 0, 1>& m, std::vector<double>& l)
	{
		for (long i = 0; i < m.size(); ++i)
			l.push_back(m(i));
	}

}
