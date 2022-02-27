#include "Dlib_Object.h"
#include "Dlib_Svm_rank_trainer_sparse_Object.h"
#include "Dlib_Vec_svm_rank_trainer_Object.h"

using namespace dlib;

const _decision_function_linear CDlib_Vec_svm_rank_trainer_Object::train(vec_ranking_pair& sample, HRESULT& hr) {
	auto& trainer = *this->__self->get();
	AUTOIT_ASSERT_THROW(is_ranking_problem(std::vector<vec_ranking_pair>(1, sample)), "Invalid inputs");
	hr = S_OK;
	return trainer.train(sample);
}

const _decision_function_linear CDlib_Vec_svm_rank_trainer_Object::train(std::vector<vec_ranking_pair>& samples, HRESULT& hr) {
	auto& trainer = *this->__self->get();
	AUTOIT_ASSERT_THROW(is_ranking_problem(samples), "Invalid inputs");
	hr = S_OK;
	return trainer.train(samples);
}

const _decision_function_sparse_linear CDlib_Svm_rank_trainer_sparse_Object::train(sparse_ranking_pair& sample, HRESULT& hr) {
	auto& trainer = *this->__self->get();
	AUTOIT_ASSERT_THROW(is_ranking_problem(std::vector<sparse_ranking_pair>(1, sample)), "Invalid inputs");
	hr = S_OK;
	return trainer.train(sample);
}

const _decision_function_sparse_linear CDlib_Svm_rank_trainer_sparse_Object::train(std::vector<sparse_ranking_pair>& samples, HRESULT& hr) {
	auto& trainer = *this->__self->get();
	AUTOIT_ASSERT_THROW(is_ranking_problem(samples), "Invalid inputs");
	hr = S_OK;
	return trainer.train(samples);
}

template <
    typename trainer_type,
    typename T
    >
const ranking_test _cross_ranking_validate_trainer (
    const trainer_type& trainer,
    const std::vector<T>& samples,
    const unsigned long folds
)
{
    AUTOIT_ASSERT_THROW(is_ranking_problem(samples), "Training data does not make a valid training set.");
    AUTOIT_ASSERT_THROW(1 < folds && folds <= samples.size(), "Invalid number of folds given.");
    return cross_validate_ranking_trainer(trainer, samples, folds);
}

const ranking_test CDlib_Object::cross_validate_ranking_trainer(vec_svm_rank_trainer& trainer, std::vector<vec_ranking_pair>& samples, ULONG folds, HRESULT& hr) {
	hr = S_OK;
	return _cross_ranking_validate_trainer<vec_svm_rank_trainer, vec_ranking_pair>(trainer, samples, folds);
}

const ranking_test CDlib_Object::cross_validate_ranking_trainer(svm_rank_trainer_sparse& trainer, std::vector<sparse_ranking_pair>& samples, ULONG folds, HRESULT& hr) {
	hr = S_OK;
	return _cross_ranking_validate_trainer<svm_rank_trainer_sparse, sparse_ranking_pair>(trainer, samples, folds);
}
