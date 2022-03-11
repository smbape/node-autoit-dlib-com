#include "other.h"

using namespace dlib;
using namespace std;

std::vector<long> dlib::_max_cost_assignment(const matrix<double>& cost) {
	AUTOIT_ASSERT_THROW(cost.nr() == cost.nc(), "The input matrix must be square.");

	// max_cost_assignment() only works with integer matrices, so convert from
	// double to integer.
	const double scale = (std::numeric_limits<dlib::int64>::max() / 1000) / max(abs(cost));
	matrix<dlib::int64> int_cost = matrix_cast<dlib::int64>(round(cost * scale));
	return max_cost_assignment(int_cost);
}

double dlib::_assignment_cost(const matrix<double>& cost, std::vector<long>& assignment) {
	return assignment_cost(cost, assignment);
}

void dlib::_make_sparse_vector(sparse_vect& v) {
	make_sparse_vector_inplace(v);
}

void dlib::_make_sparse_vector(std::vector<sparse_vect>& v) {
	for (unsigned long i = 0; i < v.size(); ++i)
		make_sparse_vector_inplace(v[i]);
}

void dlib::_save_libsvm_formatted_data(const std::string& file_name, const std::vector<sparse_vect>& samples, const std::vector<double>& labels) {
	AUTOIT_ASSERT_THROW(samples.size() == labels.size(), "Invalid inputs");
	save_libsvm_formatted_data(file_name, samples, labels);
}

void dlib::hit_enter_to_continue() {
	std::cout << "Hit enter to continue";
	std::cin.get();
}
