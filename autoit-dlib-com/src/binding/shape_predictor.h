#pragma once

#include <dlib/data_io/load_image_dataset.h>
#include <dlib/geometry.h>
#include <dlib/image_processing.h>
#include "base.h"

using namespace std;

namespace dlib
{

	// ----------------------------------------------------------------------------------------

	full_object_detection run_predictor(
		shape_predictor& predictor,
		const cv::Mat& img,
		const rectangle& box
	);

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE shape_predictor_training_options
	{
		CV_WRAP shape_predictor_training_options() = default;

		CV_WRAP const std::string ToString() const {
			const auto& o = *this;

			std::ostringstream sout;
			sout << "shape_predictor_training_options("
				<< "be_verbose=" << o.be_verbose << ", "
				<< "cascade_depth=" << o.cascade_depth << ", "
				<< "tree_depth=" << o.tree_depth << ", "
				<< "num_trees_per_cascade_level=" << o.num_trees_per_cascade_level << ", "
				<< "nu=" << o.nu << ", "
				<< "oversampling_amount=" << o.oversampling_amount << ", "
				<< "oversampling_translation_jitter=" << o.oversampling_translation_jitter << ", "
				<< "feature_pool_size=" << o.feature_pool_size << ", "
				<< "lambda_param=" << o.lambda_param << ", "
				<< "num_test_splits=" << o.num_test_splits << ", "
				<< "feature_pool_region_padding=" << o.feature_pool_region_padding << ", "
				<< "random_seed=" << o.random_seed << ", "
				<< "num_threads=" << o.num_threads << ", "
				<< "landmark_relative_padding_mode=" << o.landmark_relative_padding_mode
				<< ")";
			return sout.str();
		}

		friend void serialize(const shape_predictor_training_options& item, std::ostream& out);
		friend void deserialize(shape_predictor_training_options& item, std::istream& in);

		CV_PROP_RW bool be_verbose = false;
		CV_PROP_RW ULONG cascade_depth = 10;
		CV_PROP_RW ULONG tree_depth = 4;
		CV_PROP_RW ULONG num_trees_per_cascade_level = 500;
		CV_PROP_RW double nu = 0.1;
		CV_PROP_RW ULONG oversampling_amount = 20;
		CV_PROP_RW double oversampling_translation_jitter = 0;
		CV_PROP_RW ULONG feature_pool_size = 400;
		CV_PROP_RW double lambda_param = 0.1;
		CV_PROP_RW ULONG num_test_splits = 20;
		CV_PROP_RW double feature_pool_region_padding = 0;
		CV_PROP_RW std::string random_seed = "";
		CV_PROP_RW bool landmark_relative_padding_mode = true;

		// not serialized
		CV_PROP_RW ULONG num_threads = 0;
	};

	CV_EXPORTS_W void train_shape_predictor (
		const std::string& dataset_filename,
		const std::string& predictor_output_filename,
		const shape_predictor_training_options& options
	);

	// ----------------------------------------------------------------------------------------

	namespace impl
	{
		inline bool contains_any_detections(
			const std::vector<std::vector<full_object_detection> >& detections
		)
		{
			for (unsigned long i = 0; i < detections.size(); ++i)
			{
				if (detections[i].size() != 0)
					return true;
			}
			return false;
		}
	}

	// ----------------------------------------------------------------------------------------

	template <typename image_array>
	inline shape_predictor train_shape_predictor_on_images(
		const image_array& images,
		std::vector<std::vector<full_object_detection>>& detections,
		const shape_predictor_training_options& options
	)
	{
		AUTOIT_ASSERT_THROW(options.lambda_param > 0,
			"Invalid lambda_param value given to train_shape_predictor(), lambda_param must be > 0.");
		AUTOIT_ASSERT_THROW(0 < options.nu && options.nu <= 1,
			"Invalid nu value given to train_shape_predictor(). It is required that 0 < nu <= 1.");
		AUTOIT_ASSERT_THROW(options.feature_pool_region_padding > -0.5,
			"Invalid feature_pool_region_padding value given to train_shape_predictor(), feature_pool_region_padding must be > -0.5.");

		AUTOIT_ASSERT_THROW(images.size() == detections.size(),
			"The list of images must have the same length as the list of detections.");

		AUTOIT_ASSERT_THROW(impl::contains_any_detections(detections),
			"Error, the training dataset does not have any labeled object detections in it.");

		shape_predictor_trainer trainer;

		trainer.set_cascade_depth(options.cascade_depth);
		trainer.set_tree_depth(options.tree_depth);
		trainer.set_num_trees_per_cascade_level(options.num_trees_per_cascade_level);
		trainer.set_nu(options.nu);
		trainer.set_random_seed(options.random_seed);
		trainer.set_oversampling_amount(options.oversampling_amount);
		trainer.set_oversampling_translation_jitter(options.oversampling_translation_jitter);
		trainer.set_feature_pool_size(options.feature_pool_size);
		trainer.set_feature_pool_region_padding(options.feature_pool_region_padding);
		trainer.set_lambda(options.lambda_param);
		trainer.set_num_test_splits(options.num_test_splits);
		trainer.set_num_threads(options.num_threads);
		if (options.landmark_relative_padding_mode)
			trainer.set_padding_mode(shape_predictor_trainer::landmark_relative);
		else
			trainer.set_padding_mode(shape_predictor_trainer::bounding_box_relative);

		if (options.be_verbose)
		{
			std::cout << "Training with cascade depth: " << options.cascade_depth << std::endl;
			std::cout << "Training with tree depth: " << options.tree_depth << std::endl;
			std::cout << "Training with " << options.num_trees_per_cascade_level << " trees per cascade level." << std::endl;
			std::cout << "Training with nu: " << options.nu << std::endl;
			std::cout << "Training with random seed: " << options.random_seed << std::endl;
			std::cout << "Training with oversampling amount: " << options.oversampling_amount << std::endl;
			std::cout << "Training with oversampling translation jitter: " << options.oversampling_translation_jitter << std::endl;
			std::cout << "Training with landmark_relative_padding_mode: " << options.landmark_relative_padding_mode << std::endl;
			std::cout << "Training with feature pool size: " << options.feature_pool_size << std::endl;
			std::cout << "Training with feature pool region padding: " << options.feature_pool_region_padding << std::endl;
			std::cout << "Training with " << options.num_threads << " threads." << std::endl;
			std::cout << "Training with lambda_param: " << options.lambda_param << std::endl;
			std::cout << "Training with " << options.num_test_splits << " split tests." << std::endl;
			trainer.be_verbose();
		}

		return trainer.train(images, detections);
	}

	// ----------------------------------------------------------------------------------------

	template <typename image_array>
	inline double test_shape_predictor_with_images(
		const image_array& images,
		const std::vector<std::vector<full_object_detection> >& detections,
		const std::vector<std::vector<double> >& scales,
		const shape_predictor& predictor
	)
	{
		AUTOIT_ASSERT_THROW(images.size() == detections.size(),
			"The list of images must have the same length as the list of detections."
		);
		AUTOIT_ASSERT_THROW(scales.size() == 0 || scales.size() == images.size(),
			"The list of images must have the same length as the list of detections."
		);

		if (scales.size() > 0) {
			return test_shape_predictor(predictor, images, detections, scales);
		}
		return test_shape_predictor(predictor, images, detections);
	}

	inline double test_shape_predictor_with_images(
		const std::string& dataset_filename,
		const std::string& predictor_filename
	)
	{
		// Load the images, no scales can be provided
		dlib::array<array2d<unsigned char> > images;
		// This interface cannot take the scales parameter.
		std::vector<std::vector<double> > scales;
		std::vector<std::vector<full_object_detection> > objects;
		load_image_dataset(images, objects, dataset_filename);

		// Load the shape predictor
		shape_predictor predictor;
		deserialize(predictor_filename) >> predictor;

		return test_shape_predictor_with_images(images, objects, scales, predictor);
	}

}