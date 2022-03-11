#include "sequence_segmenter.h"

using namespace dlib;
using namespace std;

const std::string segmenter_params::ToString() const
{
	const auto& p = *this;

	ostringstream sout;
	if (p.use_BIO_model)
		sout << "BIO,";
	else
		sout << "BILOU,";

	if (p.use_high_order_features)
		sout << "highFeats,";
	else
		sout << "lowFeats,";

	if (p.allow_negative_weights)
		sout << "signed,";
	else
		sout << "non-negative,";

	sout << "win=" << p.window_size << ",";
	sout << "threads=" << p.num_threads << ",";
	sout << "eps=" << p.epsilon << ",";
	sout << "cache=" << p.max_cache_size << ",";
	if (p.be_verbose)
		sout << "verbose,";
	else
		sout << "non-verbose,";
	sout << "C=" << p.C;
	return trim(sout.str());
}

const std::string segmenter_test::ToString() const
{
	const auto& item = *this;
	std::ostringstream sout;
	sout << "precision: " << item.precision << "  recall: " << item.recall << "  f1-score: " << item.f1;
	return sout.str();
}

void dlib::serialize(const segmenter_type& item, std::ostream& out) {
	serialize(item.mode, out);
	switch (item.mode)
	{
	case 0: serialize(item.segmenter0, out); break;
	case 1: serialize(item.segmenter1, out); break;
	case 2: serialize(item.segmenter2, out); break;
	case 3: serialize(item.segmenter3, out); break;
	case 4: serialize(item.segmenter4, out); break;
	case 5: serialize(item.segmenter5, out); break;
	case 6: serialize(item.segmenter6, out); break;
	case 7: serialize(item.segmenter7, out); break;

	case 8: serialize(item.segmenter8, out); break;
	case 9: serialize(item.segmenter9, out); break;
	case 10: serialize(item.segmenter10, out); break;
	case 11: serialize(item.segmenter11, out); break;
	case 12: serialize(item.segmenter12, out); break;
	case 13: serialize(item.segmenter13, out); break;
	case 14: serialize(item.segmenter14, out); break;
	case 15: serialize(item.segmenter15, out); break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}
}

void dlib::deserialize(segmenter_type& item, std::istream& in) {
	deserialize(item.mode, in);
	switch (item.mode)
	{
	case 0: deserialize(item.segmenter0, in); break;
	case 1: deserialize(item.segmenter1, in); break;
	case 2: deserialize(item.segmenter2, in); break;
	case 3: deserialize(item.segmenter3, in); break;
	case 4: deserialize(item.segmenter4, in); break;
	case 5: deserialize(item.segmenter5, in); break;
	case 6: deserialize(item.segmenter6, in); break;
	case 7: deserialize(item.segmenter7, in); break;

	case 8: deserialize(item.segmenter8, in); break;
	case 9: deserialize(item.segmenter9, in); break;
	case 10: deserialize(item.segmenter10, in); break;
	case 11: deserialize(item.segmenter11, in); break;
	case 12: deserialize(item.segmenter12, in); break;
	case 13: deserialize(item.segmenter13, in); break;
	case 14: deserialize(item.segmenter14, in); break;
	case 15: deserialize(item.segmenter15, in); break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}
}

void dlib::serialize(const segmenter_params& item, std::ostream& out)
{
	serialize(item.use_BIO_model, out);
	serialize(item.use_high_order_features, out);
	serialize(item.allow_negative_weights, out);
	serialize(item.window_size, out);
	serialize(item.num_threads, out);
	serialize(item.epsilon, out);
	serialize(item.max_cache_size, out);
	serialize(item.be_verbose, out);
	serialize(item.C, out);
}

void dlib::deserialize(segmenter_params& item, std::istream& in)
{
	deserialize(item.use_BIO_model, in);
	deserialize(item.use_high_order_features, in);
	deserialize(item.allow_negative_weights, in);
	deserialize(item.window_size, in);
	deserialize(item.num_threads, in);
	deserialize(item.epsilon, in);
	deserialize(item.max_cache_size, in);
	deserialize(item.be_verbose, in);
	deserialize(item.C, in);
}

void dlib::serialize(const segmenter_test& item, std::ostream& out)
{
	serialize(item.precision, out);
	serialize(item.recall, out);
	serialize(item.f1, out);
}

void dlib::deserialize(segmenter_test& item, std::istream& in)
{
	deserialize(item.precision, in);
	deserialize(item.recall, in);
	deserialize(item.f1, in);
}

// ----------------------------------------------------------------------------------------

template <typename T>
void configure_trainer(
	const std::vector<std::vector<dense_vect>>& samples,
	structural_sequence_segmentation_trainer<T>& trainer,
	const segmenter_params& params
)
{
	AUTOIT_ASSERT_THROW(samples.size() != 0, "Invalid arguments.  You must give some training sequences.");
	AUTOIT_ASSERT_THROW(samples[0].size() != 0, "Invalid arguments. You can't have zero length training sequences.");
	AUTOIT_ASSERT_THROW(params.window_size != 0, "Invalid window_size parameter, it must be > 0.");
	AUTOIT_ASSERT_THROW(params.epsilon > 0, "Invalid epsilon parameter, it must be > 0.");
	AUTOIT_ASSERT_THROW(params.C > 0, "Invalid C parameter, it must be > 0.");
	const long dims = samples[0][0].size();

	trainer = structural_sequence_segmentation_trainer<T>(T(dims, params.window_size));
	trainer.set_num_threads(params.num_threads);
	trainer.set_epsilon(params.epsilon);
	trainer.set_max_cache_size(params.max_cache_size);
	trainer.set_c(params.C);
	if (params.be_verbose)
		trainer.be_verbose();
}

// ----------------------------------------------------------------------------------------

template <typename T>
void configure_trainer(
	const std::vector<std::vector<sparse_vect>>& samples,
	structural_sequence_segmentation_trainer<T>& trainer,
	const segmenter_params& params
)
{
	AUTOIT_ASSERT_THROW(samples.size() != 0, "Invalid arguments.  You must give some training sequences.");
	AUTOIT_ASSERT_THROW(samples[0].size() != 0, "Invalid arguments. You can't have zero length training sequences.");

	unsigned long dims = 0;
	for (unsigned long i = 0; i < samples.size(); ++i)
	{
		dims = std::max(dims, max_index_plus_one(samples[i]));
	}

	trainer = structural_sequence_segmentation_trainer<T>(T(dims, params.window_size));
	trainer.set_num_threads(params.num_threads);
	trainer.set_epsilon(params.epsilon);
	trainer.set_max_cache_size(params.max_cache_size);
	trainer.set_c(params.C);
	if (params.be_verbose)
		trainer.be_verbose();
}

// ----------------------------------------------------------------------------------------

segmenter_type dlib::train_dense(
	const std::vector<std::vector<dense_vect>>& samples,
	const std::vector<ranges>& segments,
	segmenter_params params
)
{
	AUTOIT_ASSERT_THROW(is_sequence_segmentation_problem(samples, segments), "Invalid inputs");

	int mode = 0;
	if (params.use_BIO_model)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.use_high_order_features)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.allow_negative_weights)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;


	segmenter_type res;
	res.mode = mode;
	switch (mode)
	{
	case 0: { structural_sequence_segmentation_trainer<segmenter_type::fe0> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter0 = trainer.train(samples, segments);
	} break;
	case 1: { structural_sequence_segmentation_trainer<segmenter_type::fe1> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter1 = trainer.train(samples, segments);
	} break;
	case 2: { structural_sequence_segmentation_trainer<segmenter_type::fe2> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter2 = trainer.train(samples, segments);
	} break;
	case 3: { structural_sequence_segmentation_trainer<segmenter_type::fe3> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter3 = trainer.train(samples, segments);
	} break;
	case 4: { structural_sequence_segmentation_trainer<segmenter_type::fe4> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter4 = trainer.train(samples, segments);
	} break;
	case 5: { structural_sequence_segmentation_trainer<segmenter_type::fe5> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter5 = trainer.train(samples, segments);
	} break;
	case 6: { structural_sequence_segmentation_trainer<segmenter_type::fe6> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter6 = trainer.train(samples, segments);
	} break;
	case 7: { structural_sequence_segmentation_trainer<segmenter_type::fe7> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter7 = trainer.train(samples, segments);
	} break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}


	return res;
}

// ----------------------------------------------------------------------------------------

segmenter_type dlib::train_sparse(
	const std::vector<std::vector<sparse_vect>>& samples,
	const std::vector<ranges>& segments,
	segmenter_params params
)
{
	AUTOIT_ASSERT_THROW(is_sequence_segmentation_problem(samples, segments), "Invalid inputs");

	int mode = 0;
	if (params.use_BIO_model)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.use_high_order_features)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.allow_negative_weights)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;

	mode += 8;

	segmenter_type res;
	res.mode = mode;
	switch (mode)
	{
	case 8: { structural_sequence_segmentation_trainer<segmenter_type::fe8> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter8 = trainer.train(samples, segments);
	} break;
	case 9: { structural_sequence_segmentation_trainer<segmenter_type::fe9> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter9 = trainer.train(samples, segments);
	} break;
	case 10: { structural_sequence_segmentation_trainer<segmenter_type::fe10> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter10 = trainer.train(samples, segments);
	} break;
	case 11: { structural_sequence_segmentation_trainer<segmenter_type::fe11> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter11 = trainer.train(samples, segments);
	} break;
	case 12: { structural_sequence_segmentation_trainer<segmenter_type::fe12> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter12 = trainer.train(samples, segments);
	} break;
	case 13: { structural_sequence_segmentation_trainer<segmenter_type::fe13> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter13 = trainer.train(samples, segments);
	} break;
	case 14: { structural_sequence_segmentation_trainer<segmenter_type::fe14> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter14 = trainer.train(samples, segments);
	} break;
	case 15: { structural_sequence_segmentation_trainer<segmenter_type::fe15> trainer;
		configure_trainer(samples, trainer, params);
		res.segmenter15 = trainer.train(samples, segments);
	} break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}


	return res;
}

// ----------------------------------------------------------------------------------------

const segmenter_test dlib::test_sequence_segmenter1(
	const segmenter_type& segmenter,
	const std::vector<std::vector<dense_vect>>& samples,
	const std::vector<ranges>& segments
)
{
	AUTOIT_ASSERT_THROW(is_sequence_segmentation_problem(samples, segments), "Invalid inputs");
	matrix<double, 1, 3> res;

	switch (segmenter.mode)
	{
	case 0: res = test_sequence_segmenter(segmenter.segmenter0, samples, segments); break;
	case 1: res = test_sequence_segmenter(segmenter.segmenter1, samples, segments); break;
	case 2: res = test_sequence_segmenter(segmenter.segmenter2, samples, segments); break;
	case 3: res = test_sequence_segmenter(segmenter.segmenter3, samples, segments); break;
	case 4: res = test_sequence_segmenter(segmenter.segmenter4, samples, segments); break;
	case 5: res = test_sequence_segmenter(segmenter.segmenter5, samples, segments); break;
	case 6: res = test_sequence_segmenter(segmenter.segmenter6, samples, segments); break;
	case 7: res = test_sequence_segmenter(segmenter.segmenter7, samples, segments); break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}


	segmenter_test temp;
	temp.precision = res(0);
	temp.recall = res(1);
	temp.f1 = res(2);
	return temp;
}

const segmenter_test dlib::test_sequence_segmenter2(
	const segmenter_type& segmenter,
	const std::vector<std::vector<sparse_vect>>& samples,
	const std::vector<ranges>& segments
)
{
	AUTOIT_ASSERT_THROW(is_sequence_segmentation_problem(samples, segments), "Invalid inputs");
	matrix<double, 1, 3> res;

	switch (segmenter.mode)
	{
	case 8: res = test_sequence_segmenter(segmenter.segmenter8, samples, segments); break;
	case 9: res = test_sequence_segmenter(segmenter.segmenter9, samples, segments); break;
	case 10: res = test_sequence_segmenter(segmenter.segmenter10, samples, segments); break;
	case 11: res = test_sequence_segmenter(segmenter.segmenter11, samples, segments); break;
	case 12: res = test_sequence_segmenter(segmenter.segmenter12, samples, segments); break;
	case 13: res = test_sequence_segmenter(segmenter.segmenter13, samples, segments); break;
	case 14: res = test_sequence_segmenter(segmenter.segmenter14, samples, segments); break;
	case 15: res = test_sequence_segmenter(segmenter.segmenter15, samples, segments); break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}


	segmenter_test temp;
	temp.precision = res(0);
	temp.recall = res(1);
	temp.f1 = res(2);
	return temp;
}

// ----------------------------------------------------------------------------------------

const segmenter_test dlib::cross_validate_sequence_segmenter1(
	const std::vector<std::vector<dense_vect>>& samples,
	const std::vector<ranges>& segments,
	long folds,
	segmenter_params params
)
{
	AUTOIT_ASSERT_THROW(is_sequence_segmentation_problem(samples, segments), "Invalid inputs");
	AUTOIT_ASSERT_THROW(1 < folds && folds <= static_cast<long>(samples.size()), "folds argument is outside the valid range.");

	matrix<double, 1, 3> res;

	int mode = 0;
	if (params.use_BIO_model)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.use_high_order_features)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.allow_negative_weights)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;


	switch (mode)
	{
	case 0: { structural_sequence_segmentation_trainer<segmenter_type::fe0> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 1: { structural_sequence_segmentation_trainer<segmenter_type::fe1> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 2: { structural_sequence_segmentation_trainer<segmenter_type::fe2> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 3: { structural_sequence_segmentation_trainer<segmenter_type::fe3> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 4: { structural_sequence_segmentation_trainer<segmenter_type::fe4> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 5: { structural_sequence_segmentation_trainer<segmenter_type::fe5> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 6: { structural_sequence_segmentation_trainer<segmenter_type::fe6> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 7: { structural_sequence_segmentation_trainer<segmenter_type::fe7> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}


	segmenter_test temp;
	temp.precision = res(0);
	temp.recall = res(1);
	temp.f1 = res(2);
	return temp;
}

const segmenter_test dlib::cross_validate_sequence_segmenter2(
	const std::vector<std::vector<sparse_vect>>& samples,
	const std::vector<ranges>& segments,
	long folds,
	segmenter_params params
)
{
	AUTOIT_ASSERT_THROW(is_sequence_segmentation_problem(samples, segments), "Invalid inputs");
	AUTOIT_ASSERT_THROW(1 < folds && folds <= static_cast<long>(samples.size()), "folds argument is outside the valid range.");

	matrix<double, 1, 3> res;

	int mode = 0;
	if (params.use_BIO_model)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.use_high_order_features)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;
	if (params.allow_negative_weights)
		mode = mode * 2 + 1;
	else
		mode = mode * 2;

	mode += 8;

	switch (mode)
	{
	case 8: { structural_sequence_segmentation_trainer<segmenter_type::fe8> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 9: { structural_sequence_segmentation_trainer<segmenter_type::fe9> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 10: { structural_sequence_segmentation_trainer<segmenter_type::fe10> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 11: { structural_sequence_segmentation_trainer<segmenter_type::fe11> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 12: { structural_sequence_segmentation_trainer<segmenter_type::fe12> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 13: { structural_sequence_segmentation_trainer<segmenter_type::fe13> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 14: { structural_sequence_segmentation_trainer<segmenter_type::fe14> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	case 15: { structural_sequence_segmentation_trainer<segmenter_type::fe15> trainer;
		configure_trainer(samples, trainer, params);
		res = cross_validate_sequence_segmenter(trainer, samples, segments, folds);
	} break;
	default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
	}


	segmenter_test temp;
	temp.precision = res(0);
	temp.recall = res(1);
	temp.f1 = res(2);
	return temp;
}
