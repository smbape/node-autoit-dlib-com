#pragma once

#include <comutil.h>
#include "./basic.h"

namespace dlib {
	struct CV_EXPORTS_W_SIMPLE simple_structural_svm_problem {
		typedef void (*get_truth_joint_feature_vector_function)(VARIANT* self, long idx);
		typedef void (*separation_oracle_function)(VARIANT* self, long idx, VARIANT* current_solution);

		CV_WRAP simple_structural_svm_problem() = default;

		CV_PROP_RW double C = 0.0;
		CV_PROP_RW long num_samples = 0;
		CV_PROP_RW long num_dimensions = 0;
		CV_PROP_RW get_truth_joint_feature_vector_function get_truth_joint_feature_vector;
		CV_PROP_RW separation_oracle_function separation_oracle;

		CV_PROP_RW double epsilon = 0.001;
		CV_PROP_RW ULONG max_cache_size = 10;
		CV_PROP_RW bool be_verbose = false;
		CV_PROP_RW bool use_sparse_feature_vectors = false;
		CV_PROP_RW bool learns_nonnegative_weights = false;

		CV_PROP_RW _variant_t result;
	};


	CV_EXPORTS_W dense_vect solve_structural_svm_problem(simple_structural_svm_problem& problem);
}
