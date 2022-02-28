#pragma once

#include <dlib/filtering.h>
#include <dlib/matrix.h>
#include <dlib/string.h>
#include <dlib/svm.h>
#include <chrono>
#include <vector>
#include "./cvdef.h"

using std::string;

namespace dlib {
	extern std::string version;
	extern std::string time_compiled;
	extern bool DLIB_USE_CUDA;
	extern bool DLIB_USE_BLAS;
	extern bool DLIB_USE_LAPACK;
	extern bool USE_AVX_INSTRUCTIONS;
	extern bool USE_NEON_INSTRUCTIONS;

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

	struct CV_EXPORTS_W_SIMPLE binary_test
	{
		CV_WRAP binary_test() : class1_accuracy(0), class2_accuracy(0) {}
		binary_test(
			const dlib::matrix<double, 1, 2>& m
		) : class1_accuracy(m(0)),
			class2_accuracy(m(1)) {}

		CV_PROP_RW double class1_accuracy;
		CV_PROP_RW double class2_accuracy;
	};

	struct CV_EXPORTS_W_SIMPLE regression_test
	{
		CV_WRAP regression_test() = default;
		regression_test(
			const dlib::matrix<double, 1, 4>& m
		) : mean_squared_error(m(0)),
			R_squared(m(1)),
			mean_average_error(m(2)),
			mean_error_stddev(m(3))
		{}

		CV_PROP_RW double mean_squared_error = 0;
		CV_PROP_RW double R_squared = 0;
		CV_PROP_RW double mean_average_error = 0;
		CV_PROP_RW double mean_error_stddev = 0;
	};

	struct CV_EXPORTS_W_SIMPLE ranking_test
	{
		CV_WRAP ranking_test() : ranking_accuracy(0), mean_ap(0) {}
		ranking_test(
			const dlib::matrix<double, 1, 2>& m
		) : ranking_accuracy(m(0)),
			mean_ap(m(1)) {}

		CV_PROP_RW double ranking_accuracy;
		CV_PROP_RW double mean_ap;
	};

}
