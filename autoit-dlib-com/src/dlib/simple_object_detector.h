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


		CV_WRAP std::string ToString()
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
		CV_PROP_RW fhog_object_detector detector;
		CV_PROP_RW uint upsampling_amount;

		CV_WRAP simple_object_detector_com() {}

		CV_WRAP simple_object_detector_com(fhog_object_detector& _detector, uint _upsampling_amount) :
			detector(_detector), upsampling_amount(_upsampling_amount) {}

		CV_WRAP simple_object_detector_com(std::vector<simple_object_detector_com>& detectors);

		CV_WRAP static std::shared_ptr<simple_object_detector_com> create(const std::string& filename);

		CV_WRAP std::vector<rectangle> call(cv::Mat & img, const uint upsampling_amount_);
		CV_WRAP std::vector<rectangle> call(cv::Mat & img);
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
		simple_object_detector_com& detector,
		const int upsampling_amount = -1
	);

	CV_EXPORTS_W simple_test_results test_simple_object_detector (
		const std::vector<cv::Mat>& images,
		std::vector<std::vector<rectangle>>& boxes,
		fhog_object_detector& detector,
		const uint upsampling_amount = 0
	);

	CV_EXPORTS_W simple_test_results test_simple_object_detector (
		const std::vector<cv::Mat>& images,
		std::vector<std::vector<rectangle>>& boxes,
		simple_object_detector_com& detector,
		const int upsampling_amount = -1
	);

	// ----------------------------------------------------------------------------------------

	inline void split_rect_detections(
		std::vector<rect_detection>& rect_detections,
		std::vector<rectangle>& rectangles,
		std::vector<double>& detection_confidences,
		std::vector<unsigned long>& weight_indices
	)
	{
		rectangles.clear();
		detection_confidences.clear();
		weight_indices.clear();

		for (unsigned long i = 0; i < rect_detections.size(); ++i)
		{
			rectangles.push_back(rect_detections[i].rect);
			detection_confidences.push_back(rect_detections[i].detection_confidence);
			weight_indices.push_back(rect_detections[i].weight_index);
		}
	}

	// ----------------------------------------------------------------------------------------

	namespace impl
	{
		inline void pick_best_window_size(
			const std::vector<std::vector<rectangle>>& boxes,
			unsigned long& width,
			unsigned long& height,
			const unsigned long target_size
		)
		{
			// find the average width and height
			running_stats<double> avg_width, avg_height;
			for (unsigned long i = 0; i < boxes.size(); ++i)
			{
				for (unsigned long j = 0; j < boxes[i].size(); ++j)
				{
					avg_width.add(boxes[i][j].width());
					avg_height.add(boxes[i][j].height());
				}
			}

			// now adjust the box size so that it is about target_pixels pixels in size
			double size = avg_width.mean() * avg_height.mean();
			double scale = std::sqrt(target_size / size);

			width = (unsigned long)(avg_width.mean() * scale + 0.5);
			height = (unsigned long)(avg_height.mean() * scale + 0.5);
			// make sure the width and height never round to zero.
			if (width == 0)
				width = 1;
			if (height == 0)
				height = 1;
		}

		inline bool contains_any_boxes(
			const std::vector<std::vector<rectangle>>& boxes
		)
		{
			for (unsigned long i = 0; i < boxes.size(); ++i)
			{
				if (boxes[i].size() != 0)
					return true;
			}
			return false;
		}

		inline void throw_invalid_box_error_message(
			const std::string& dataset_filename,
			const std::vector<std::vector<rectangle>>& removed,
			const simple_object_detector_training_options& options
		)
		{

			std::ostringstream sout;
			// Note that the 1/16 factor is here because we will try to upsample the image
			// 2 times to accommodate small boxes.  We also take the max because we want to
			// lower bound the size of the smallest recommended box.  This is because the
			// 8x8 HOG cells can't really deal with really small object boxes.
			sout << "Error!  An impossible set of object boxes was given for training. ";
			sout << "All the boxes need to have a similar aspect ratio and also not be ";
			sout << "smaller than about " << std::max<long>(20 * 20, options.detection_window_size / 16) << " pixels in area. ";

			std::ostringstream sout2;
			if (dataset_filename.size() != 0)
			{
				sout << "The following images contain invalid boxes:\n";
				image_dataset_metadata::dataset data;
				load_image_dataset_metadata(data, dataset_filename);
				for (unsigned long i = 0; i < removed.size(); ++i)
				{
					if (removed[i].size() != 0)
					{
						const std::string imgname = data.images[i].filename;
						sout2 << "  " << imgname << "\n";
					}
				}
			}

			auto msg = wrap_string(sout.str()) + "\n" + sout2.str();
			AUTOIT_ASSERT_THROW(false, msg.c_str());
		}
	}

	// ----------------------------------------------------------------------------------------

	template <typename image_array>
	inline simple_object_detector_com train_simple_object_detector_on_images(
		const std::string& dataset_filename, // can be "" if it's not applicable
		image_array& images,
		std::vector<std::vector<rectangle>>& boxes,
		std::vector<std::vector<rectangle>>& ignore,
		const simple_object_detector_training_options& options
	)
	{
		AUTOIT_ASSERT_THROW(options.C > 0, "Invalid C value given to train_simple_object_detector(), C must be > 0.");
		AUTOIT_ASSERT_THROW(options.epsilon > 0, "Invalid epsilon value given to train_simple_object_detector(), epsilon must be > 0.");
		AUTOIT_ASSERT_THROW(options.max_runtime_seconds > 0, "Invalid max_runtime_seconds value given to train_simple_object_detector(), max_runtime_seconds must be > 0.");

		AUTOIT_ASSERT_THROW(options.nuclear_norm_regularization_strength >= 0, "Invalid nuclear_norm_regularization_strength value given to train_simple_object_detector(), it must be must be >= 0.");

		AUTOIT_ASSERT_THROW(images.size() == boxes.size(), "The list of images must have the same length as the list of boxes.");
		AUTOIT_ASSERT_THROW(images.size() == ignore.size(), "The list of images must have the same length as the list of ignore boxes.");

		AUTOIT_ASSERT_THROW(impl::contains_any_boxes(boxes), "Error, the training dataset does not have any labeled object boxes in it.");

		typedef scan_fhog_pyramid<pyramid_down<6>> image_scanner_type;
		image_scanner_type scanner;
		unsigned long width, height;
		impl::pick_best_window_size(boxes, width, height, options.detection_window_size);
		scanner.set_detection_window_size(width, height);
		scanner.set_nuclear_norm_regularization_strength(options.nuclear_norm_regularization_strength);
		structural_object_detection_trainer<image_scanner_type> trainer(scanner);
		trainer.set_num_threads(options.num_threads);
		trainer.set_c(options.C);
		trainer.set_epsilon(options.epsilon);
		trainer.set_max_runtime(std::chrono::milliseconds((int64_t)std::round(options.max_runtime_seconds * 1000)));
		if (options.be_verbose)
		{
			std::cout << "Training with C: " << options.C << std::endl;
			std::cout << "Training with epsilon: " << options.epsilon << std::endl;
			std::cout << "Training using " << options.num_threads << " threads." << std::endl;
			std::cout << "Training with sliding window " << width << " pixels wide by " << height << " pixels tall." << std::endl;
			if (options.add_left_right_image_flips)
				std::cout << "Training on both left and right flipped versions of images." << std::endl;
			trainer.be_verbose();
		}

		unsigned long upsampling_amount = 0;

		// now make sure all the boxes are obtainable by the scanner.  We will try and
		// upsample the images at most two times to help make the boxes obtainable.
		std::vector<std::vector<rectangle>> temp(boxes), removed;
		removed = remove_unobtainable_rectangles(trainer, images, temp);
		while (impl::contains_any_boxes(removed) && upsampling_amount < options.upsample_limit)
		{
			++upsampling_amount;
			if (options.be_verbose)
				std::cout << "Upsample images..." << std::endl;
			upsample_image_dataset<pyramid_down<2>>(images, boxes, ignore);
			temp = boxes;
			removed = remove_unobtainable_rectangles(trainer, images, temp);
		}
		// if we weren't able to get all the boxes to match then throw an error 
		if (impl::contains_any_boxes(removed))
			impl::throw_invalid_box_error_message(dataset_filename, removed, options);

		if (options.add_left_right_image_flips)
			add_image_left_right_flips(images, boxes, ignore);

		simple_object_detector detector = trainer.train(images, boxes, ignore);

		if (options.be_verbose)
		{
			std::cout << "Training complete." << std::endl;
			std::cout << "Trained with C: " << options.C << std::endl;
			std::cout << "Training with epsilon: " << options.epsilon << std::endl;
			std::cout << "Trained using " << options.num_threads << " threads." << std::endl;
			std::cout << "Trained with sliding window " << width << " pixels wide by " << height << " pixels tall." << std::endl;
			if (upsampling_amount != 0)
			{
				// Unsampled images # time(s) to allow detection of small boxes
				std::cout << "Upsampled images " << upsampling_amount;
				std::cout << ((upsampling_amount > 1) ? " times" : " time");
				std::cout << " to allow detection of small boxes." << std::endl;
			}
			if (options.add_left_right_image_flips)
				std::cout << "Trained on both left and right flipped versions of images." << std::endl;
		}

		return simple_object_detector_com(detector, upsampling_amount);
	}

	template <typename image_array>
	inline const simple_test_results test_simple_object_detector_with_images(
		image_array& images,
		const unsigned int upsample_amount,
		std::vector<std::vector<rectangle>>& boxes,
		std::vector<std::vector<rectangle>>& ignore,
		simple_object_detector& detector
	)
	{
		for (unsigned int i = 0; i < upsample_amount; ++i)
			upsample_image_dataset<pyramid_down<2>>(images, boxes);

		matrix<double, 1, 3> res = test_object_detection_function(detector, images, boxes, ignore);
		simple_test_results ret;
		ret.precision = res(0);
		ret.recall = res(1);
		ret.average_precision = res(2);
		return ret;
	}
}
