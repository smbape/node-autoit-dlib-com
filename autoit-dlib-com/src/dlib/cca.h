#pragma once

#include <dlib/statistics.h>
#include "basic.h"

namespace dlib {
	struct CV_EXPORTS_W_SIMPLE cca_outputs
	{
		CV_PROP_RW SpaceVector correlations;
		CV_PROP_RW Matrix Ltrans;
		CV_PROP_RW Matrix Rtrans;
	};

	CV_EXPORTS_AS(cca) cca_outputs _cca1(
		const std::vector<sparse_vect>& L,
		const std::vector<sparse_vect>& R,
		ULONG num_correlations,
		ULONG extra_rank = 5,
		ULONG q = 2,
		double regularization = 0
	);

	CV_EXPORTS_W sample_type apply_cca_transform(
		const matrix<double>& m,
		const sparse_vect& v
	);
}
