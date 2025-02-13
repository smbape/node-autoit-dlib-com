#include "cca.h"

using namespace dlib;

cca_outputs dlib::_cca1(
	const std::vector<sparse_vect>& L,
	const std::vector<sparse_vect>& R,
	unsigned long num_correlations,
	unsigned long extra_rank,
	unsigned long q,
	double regularization
) {
	AUTOIT_ASSERT_THROW(num_correlations > 0 && L.size() > 0 && R.size() > 0 && L.size() == R.size() && regularization >= 0,
		"Invalid inputs");

	cca_outputs temp;
	temp.correlations = cca(L, R, temp.Ltrans, temp.Rtrans, num_correlations, extra_rank, q, regularization);
	return temp;
}

sample_type dlib::apply_cca_transform(
	const matrix<double>& m,
	const sparse_vect& v
)
{
	AUTOIT_ASSERT_THROW((long)max_index_plus_one(v) <= m.nr(), "Invalid Inputs");
	return sparse_matrix_vector_multiply(trans(m), v);
}
