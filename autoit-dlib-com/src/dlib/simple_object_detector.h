#pragma once

#include <dlib/image_processing/object_detector.h>
#include <dlib/image_processing/scan_fhog_pyramid.h>
#include <dlib/svm/structural_object_detection_trainer.h>
#include <dlib/geometry.h>
#include <dlib/data_io/load_image_dataset.h>
#include <dlib/image_processing/remove_unobtainable_rectangles.h>
#include <sstream>
#include "basic.h"

namespace dlib {

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE simple_object_detector_training_options
	{
		CV_WRAP simple_object_detector_training_options()
		{
			be_verbose = false;
			add_left_right_image_flips = false;
			num_threads = 4;
			detection_window_size = 80 * 80;
			C = 1;
			epsilon = 0.01;
			upsample_limit = 2;
			nuclear_norm_regularization_strength = 0;
			max_runtime_seconds = 86400.0 * 365.0 * 100.0; // 100 years
		}

		CV_PROP_RW bool be_verbose;
		CV_PROP_RW bool add_left_right_image_flips;
		CV_PROP_RW ULONG num_threads;
		CV_PROP_RW ULONG detection_window_size;
		CV_PROP_RW double C;
		CV_PROP_RW double epsilon;
		CV_PROP_RW ULONG upsample_limit;
		CV_PROP_RW double nuclear_norm_regularization_strength;
		CV_PROP_RW double max_runtime_seconds;


		CV_WRAP const std::string ToString()
		{
			const auto& o = *this;

			std::ostringstream sout;
			sout << "simple_object_detector_training_options("
				<< "be_verbose=" << o.be_verbose << ", "
				<< "add_left_right_image_flips=" << o.add_left_right_image_flips << ", "
				<< "num_threads=" << o.num_threads << ", "
				<< "detection_window_size=" << o.detection_window_size << ", "
				<< "C=" << o.C << ", "
				<< "epsilon=" << o.epsilon << ", "
				<< "max_runtime_seconds=" << o.max_runtime_seconds << ", "
				<< "upsample_limit=" << o.upsample_limit << ", "
				<< "nuclear_norm_regularization_strength=" << o.nuclear_norm_regularization_strength
				<< ")";
			return sout.str();
		}
	};

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE simple_test_results
	{
		CV_PROP_RW double precision;
		CV_PROP_RW double recall;
		CV_PROP_RW double average_precision;
	};

	struct CV_EXPORTS_AS(simple_object_detector) simple_object_detector_com
	{
		CV_WRAP simple_object_detector_com() = default;

		CV_WRAP simple_object_detector_com(fhog_object_detector & _detector, uint _upsampling_amount = 0) :
			detector(_detector), upsampling_amount(_upsampling_amount) {}

		simple_object_detector_com(const fhog_object_detector & _detector, uint _upsampling_amount = 0) :
			detector(_detector), upsampling_amount(_upsampling_amount) {}

		CV_WRAP simple_object_detector_com(std::vector<simple_object_detector_com>&detectors);

		CV_WRAP static std::shared_ptr<simple_object_detector_com> create(const std::string & filename);

		CV_WRAP std::vector<rectangle> call(cv::Mat & img, const uint upsampling_amount_);
		CV_WRAP std::vector<rectangle> call(cv::Mat & img);

		CV_PROP_RW fhog_object_detector detector;
		CV_PROP_RW uint upsampling_amount = 0;
	};

	// ----------------------------------------------------------------------------------------

	CV_EXPORTS_W void train_simple_object_detector(
		const std::string& dataset_filename,
		const std::string& detector_output_filename,
		const simple_object_detector_training_options& options
	);

	CV_EXPORTS_W simple_object_detector_com train_simple_object_detector(
		const std::vector<cv::Mat>& images,
		std::vector<std::vector<rectangle>>& boxes,
		const simple_object_detector_training_options& options
	);

	CV_EXPORTS_W const simple_test_results test_simple_object_detector(
		const std::string& dataset_filename,
		const std::string& detector_filename,
		const int upsampling_amount = -1
	);

	CV_EXPORTS_W const simple_test_results test_simple_object_detector(
		const std::string& dataset_filename,
		fhog_object_detector& detector,
		const int upsampling_amount = 0
	);

	CV_EXPORTS_W const simple_test_results test_simple_object_detector(
		const std::string& dataset_filename,
		simple_object_detector_com& detector,
		const int upsampling_amount = -1
	);

	CV_EXPORTS_W simple_test_results test_simple_object_detector(
		const std::vector<cv::Mat>& images,
		std::vector<std::vector<rectangle>>& boxes,
		fhog_object_detector& detector,
		const uint upsampling_amount = 0
	);

	CV_EXPORTS_W simple_test_results test_simple_object_detector(
		const std::vector<cv::Mat>& images,
		std::vector<std::vector<rectangle>>& boxes,
		simple_object_detector_com& detector,
		const int upsampling_amount = -1
	);
}
