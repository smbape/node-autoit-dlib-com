#include "Dlib_Simple_structural_svm_problem_Object.h"
#include "Dlib_SpaceVector_Object.h"
#include "VectorOfPairOfULONGAndDouble_Object.h"
#include "svm_struct.h"

using namespace dlib;
using namespace std;

template <class T> struct TInfo;

#define TINFO(type)                                \
template <> struct TInfo<type> {                   \
  inline static char const* getName() {                   \
    return #type;                                  \
  }                                                \
};

template<typename _Tp>
inline const _variant_t _to_variant_t(const _Tp& element) {
	_variant_t _var;
	auto pvar = static_cast<VARIANT*>(&_var);
	auto in_val = std::shared_ptr<_Tp>(std::shared_ptr<_Tp>{}, const_cast<_Tp*>(&element));
	autoit_from(in_val, pvar);
	return _var;
}

template<typename psi_type>
class svm_struct_prob : public structural_svm_problem<dense_vect, psi_type>
{
	typedef structural_svm_problem<dense_vect, psi_type> base;
	typedef typename base::feature_vector_type feature_vector_type;
	typedef typename base::matrix_type matrix_type;
	typedef typename base::scalar_type scalar_type;
public:
	svm_struct_prob(
		simple_structural_svm_problem& problem_,
		long num_dimensions_,
		long num_samples_
	) :
		num_dimensions(num_dimensions_),
		num_samples(num_samples_),
		problem(problem_)
	{
		vproblem = _to_variant_t<simple_structural_svm_problem>(problem);
		pvproblem = &vproblem;
	}

	virtual long get_num_dimensions(
	) const {
		return num_dimensions;
	}

	virtual long get_num_samples(
	) const {
		return num_samples;
	}

	virtual void get_truth_joint_feature_vector(
		long idx,
		feature_vector_type& psi
	) const
	{
		auto result = static_cast<VARIANT*>(&problem.result);
		VariantInit(result);
		problem.get_truth_joint_feature_vector(pvproblem, idx);

		HRESULT hr = is_assignable_from(psi, result, false) ? S_OK : E_INVALIDARG;

		if (SUCCEEDED(hr)) {
			hr = autoit_to(result, psi);
		}

		AUTOIT_ASSERT_THROW(SUCCEEDED(hr), "Input should be a " << TInfo<feature_vector_type>::getName() << ".");
	}

	virtual void separation_oracle(
		const long idx,
		const matrix_type& current_solution,
		scalar_type& loss,
		feature_vector_type& psi
	) const
	{
		auto result = static_cast<VARIANT*>(&problem.result);
		VariantInit(result);

		_variant_t _current_solution = _to_variant_t<matrix_type>(current_solution);
		auto pcurrent_solution = static_cast<VARIANT*>(&_current_solution);
		problem.separation_oracle(pvproblem, idx, pcurrent_solution);

		std::tuple<scalar_type, feature_vector_type> res1;
		std::tuple<feature_vector_type, scalar_type> res2;

		HRESULT hr = E_INVALIDARG;

		if (is_assignable_from(res1, result, false)) {
			hr = autoit_to(result, res1);
			if (SUCCEEDED(hr)) {
				loss = std::get<0>(res1);
				psi = std::get<1>(res1);
			}
		}
		else if (is_assignable_from(res2, result, false)) {
			hr = autoit_to(result, res2);
			if (SUCCEEDED(hr)) {
				psi = std::get<0>(res2);
				loss = std::get<1>(res2);
			}
		}

		AUTOIT_ASSERT_THROW(SUCCEEDED(hr), "Input should be a "
			<< "tuple<" << TInfo<feature_vector_type>::getName() << ", " << TInfo<scalar_type>::getName() << "> "
			<< "or a tuple<" << TInfo<scalar_type>::getName() << ", " << TInfo<feature_vector_type>::getName() << ">"
			<< ".");
	}

private:

	const long num_dimensions;
	const long num_samples;
	simple_structural_svm_problem& problem;
	_variant_t vproblem;
	VARIANT* pvproblem;
};

// ----------------------------------------------------------------------------------------

template<typename psi_type>
dense_vect solve_structural_svm_problem_impl(
	simple_structural_svm_problem& problem
)
{
	const double C = problem.C;
	const bool be_verbose = problem.be_verbose;
	const bool use_sparse_feature_vectors = problem.use_sparse_feature_vectors;
	const bool learns_nonnegative_weights = problem.learns_nonnegative_weights;

	const double eps = problem.epsilon;
	const unsigned long max_cache_size = problem.max_cache_size;
	const long num_samples = problem.num_samples;
	const long num_dimensions = problem.num_dimensions;

	AUTOIT_ASSERT_THROW(num_samples > 0, "You can't train a Structural-SVM if you don't have any training samples.");

	if (be_verbose)
	{
		cout << "C:              " << C << endl;
		cout << "epsilon:        " << eps << endl;
		cout << "max_cache_size: " << max_cache_size << endl;
		cout << "num_samples:    " << num_samples << endl;
		cout << "num_dimensions: " << num_dimensions << endl;
		cout << "use_sparse_feature_vectors: " << std::boolalpha << use_sparse_feature_vectors << endl;
		cout << "learns_nonnegative_weights: " << std::boolalpha << learns_nonnegative_weights << endl;
		cout << endl;
	}

	svm_struct_prob<psi_type> prob(problem, num_dimensions, num_samples);
	prob.set_c(C);
	prob.set_epsilon(eps);
	prob.set_max_cache_size(max_cache_size);
	if (be_verbose)
		prob.be_verbose();

	oca solver;
	dense_vect w;
	if (learns_nonnegative_weights)
		solver(prob, w, prob.get_num_dimensions());
	else
		solver(prob, w);
	return w;

	// return dense_vect();
}

TINFO(double);
TINFO(dense_vect);
TINFO(sparse_vect);

dense_vect dlib::solve_structural_svm_problem(simple_structural_svm_problem& problem) {
	dense_vect psi;
	problem.result = _variant_t();
	auto vproblem = _to_variant_t<simple_structural_svm_problem>(problem);
	auto pvproblem = &vproblem;
	problem.get_truth_joint_feature_vector(pvproblem, 0);
	if (is_assignable_from(psi, static_cast<VARIANT*>(&problem.result), false)) {
		return solve_structural_svm_problem_impl<dense_vect>(problem);
	}
	return solve_structural_svm_problem_impl<sparse_vect>(problem);
}
