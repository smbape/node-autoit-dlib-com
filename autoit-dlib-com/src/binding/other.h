// Copyright (C) 2013  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

#include <dlib/data_io.h>
#include <dlib/sparse_vector.h>
#include <dlib/optimization.h>
#include <dlib/statistics/running_gradient.h>
#include "base.h"

using namespace std;

namespace dlib {
	CV_EXPORTS_AS(max_cost_assignment) std::vector<long> _max_cost_assignment(const matrix<double>& cost);
	CV_EXPORTS_AS(assignment_cost) double _assignment_cost(const matrix<double>& cost, std::vector<long>& assignment);
	CV_EXPORTS_AS(make_sparse_vector) void _make_sparse_vector(CV_OUT sparse_vect& v);
	CV_EXPORTS_AS(make_sparse_vector) void _make_sparse_vector(CV_OUT std::vector<sparse_vect>& v);
	CV_EXPORTS_AS(save_libsvm_formatted_data) void _save_libsvm_formatted_data(const std::string& file_name, const std::vector<sparse_vect>& samples, const std::vector<double>& labels);
}
