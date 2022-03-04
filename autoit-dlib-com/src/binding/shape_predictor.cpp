#include "Dlib_Full_object_detection_Object.h"
#include "Dlib_Shape_predictor_Object.h"
#include "shape_predictor.h"

using namespace cv;
using namespace dlib;
using namespace std;

void dlib::serialize(const shape_predictor_training_options& item, std::ostream& out) {
	try
	{
		serialize("shape_predictor_training_options_v2", out);
		serialize(item.be_verbose, out);
		serialize(item.cascade_depth, out);
		serialize(item.tree_depth, out);
		serialize(item.num_trees_per_cascade_level, out);
		serialize(item.nu, out);
		serialize(item.oversampling_amount, out);
		serialize(item.oversampling_translation_jitter, out);
		serialize(item.feature_pool_size, out);
		serialize(item.lambda_param, out);
		serialize(item.num_test_splits, out);
		serialize(item.feature_pool_region_padding, out);
		serialize(item.random_seed, out);
		serialize(item.landmark_relative_padding_mode, out);
	}
	catch (serialization_error& e)
	{
		throw serialization_error(e.info + "\n   while serializing an object of type shape_predictor_training_options");
	}
}

void dlib::deserialize(shape_predictor_training_options& item, std::istream& in) {
	try
	{
		check_serialized_version("shape_predictor_training_options_v2", in);
		deserialize(item.be_verbose, in);
		deserialize(item.cascade_depth, in);
		deserialize(item.tree_depth, in);
		deserialize(item.num_trees_per_cascade_level, in);
		deserialize(item.nu, in);
		deserialize(item.oversampling_amount, in);
		deserialize(item.oversampling_translation_jitter, in);
		deserialize(item.feature_pool_size, in);
		deserialize(item.lambda_param, in);
		deserialize(item.num_test_splits, in);
		deserialize(item.feature_pool_region_padding, in);
		deserialize(item.random_seed, in);
		deserialize(item.landmark_relative_padding_mode, in);
	}
	catch (serialization_error& e)
	{
		throw serialization_error(e.info + "\n   while deserializing an object of type shape_predictor_training_options");
	}
}

const std::vector<point> CDlib_Full_object_detection_Object::parts(HRESULT& hr) {
	hr = S_OK;
	auto& detection = *this->__self->get();

	const unsigned long num_parts = detection.num_parts();
	std::vector<point> parts(num_parts);
	for (unsigned long j = 0; j < num_parts; ++j)
		parts[j] = detection.part(j);
	return parts;
}
