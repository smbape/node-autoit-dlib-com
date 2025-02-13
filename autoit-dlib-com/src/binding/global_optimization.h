#pragma once

#include <dlib/global_optimization.h>
#include "base.h"

namespace dlib {
	CV_EXPORTS_W void find_max_global(
		void* f,
		std::vector<double>& bound1,
		std::vector<double>& bound2,
		std::vector<bool>& is_integer_variable,
		ULONG num_function_calls,
		double solver_epsilon CV_WRAP_DEFAULT(0),
		CV_OUT std::vector<double>& x,
		CV_OUT float* y
	);

	CV_EXPORTS_W void find_max_global(
		void* f,
		std::vector<double>& bound1,
		std::vector<double>& bound2,
		ULONG num_function_calls,
		double solver_epsilon CV_WRAP_DEFAULT(0),
		CV_OUT std::vector<double>& x,
		CV_OUT float* y
	);

	CV_EXPORTS_W void find_min_global(
		void* f,
		std::vector<double>& bound1,
		std::vector<double>& bound2,
		std::vector<bool>& is_integer_variable,
		ULONG num_function_calls,
		double solver_epsilon CV_WRAP_DEFAULT(0),
		CV_OUT std::vector<double>& x,
		CV_OUT float* y
	);

	CV_EXPORTS_W void find_min_global(
		void* f,
		std::vector<double>& bound1,
		std::vector<double>& bound2,
		ULONG num_function_calls,
		double solver_epsilon CV_WRAP_DEFAULT(0),
		CV_OUT std::vector<double>& x,
		CV_OUT float* y
	);
}
