#include "Dlib_Fhog_object_detector_Object.h"
#include "object_detection.h"

using namespace cv;
using namespace dlib;
using namespace std;

namespace dlib {
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

	template<typename image_type, typename image_view_type>
	struct detector_evaluator {
		typedef function <void(image_view_type&, std::vector<rect_detection>&, const double)> detector_function_1;
		typedef function <void(array2d<image_type>&, std::vector<rect_detection>&, const double)> detector_function_2;

		detector_evaluator(
			const detector_function_1& _detector1,
			const detector_function_2& _detector2
		) :
			detector1(_detector1),
			detector2(_detector2)
		{}

		void operator() (image_view_type& img, std::vector<rect_detection>& rect_detections, const double adjust_threshold) {
			detector1(img, rect_detections, adjust_threshold);
		}

		void operator() (array2d<image_type>& img, std::vector<rect_detection>& rect_detections, const double adjust_threshold) {
			detector2(img, rect_detections, adjust_threshold);
		}

		detector_function_1 detector1;
		detector_function_2 detector2;
	};

	template<typename image_type, typename image_view_type>
	inline std::vector<rectangle> run_detector_with_upscale(
		detector_evaluator<image_type, image_view_type> detector,
		image_view_type& img_view,
		const unsigned int upsampling_amount,
		const double adjust_threshold,
		std::vector<double>& detection_confidences,
		std::vector<unsigned long>& weight_indices
	) {
		pyramid_down<2> pyr;

		std::vector<rectangle> rectangles;
		std::vector<rect_detection> rect_detections;

		if (upsampling_amount == 0) {
			detector(img_view, rect_detections, adjust_threshold);
			split_rect_detections(rect_detections, rectangles, detection_confidences, weight_indices);
			return rectangles;
		}

		array2d<image_type> temp;

		pyramid_up(img_view, temp, pyr);
		unsigned int levels = upsampling_amount - 1;
		while (levels > 0)
		{
			levels--;
			pyramid_up(temp);
		}

		detector(temp, rect_detections, adjust_threshold);
		for (unsigned long i = 0; i < rect_detections.size(); ++i)
			rect_detections[i].rect = pyr.rect_down(rect_detections[i].rect,
				upsampling_amount);
		split_rect_detections(rect_detections, rectangles,
			detection_confidences, weight_indices);

		return rectangles;
	}

	template<typename image_type>
	inline std::vector<rectangle> run_detector_with_upscale_impl(
		simple_object_detector& detector,
		Mat& image,
		const unsigned int upsampling_amount,
		const double adjust_threshold,
		std::vector<double>& detection_confidences,
		std::vector<unsigned long>& weight_indices

	)
	{
		typedef image_view<cv_image<image_type>> image_view_type;

		auto lambda = [&]<typename T>(
			T & img,
			std::vector<rect_detection>&rect_detections,
			const double adjust_threshold) {
			detector(img, rect_detections, adjust_threshold);
		};

		detector_evaluator<image_type, image_view_type> _detector(lambda, lambda);

		auto img = cv_image<image_type>(image);
		auto img_view = make_image_view(img);

		return run_detector_with_upscale(
			_detector,
			img_view,
			upsampling_amount,
			adjust_threshold,
			detection_confidences,
			weight_indices
		);
	}

	template<typename image_type>
	inline std::vector<rectangle> run_detector_with_upscale_impl(
		std::vector<simple_object_detector>& detectors,
		Mat& image,
		const unsigned int upsampling_amount,
		const double adjust_threshold,
		std::vector<double>& detection_confidences,
		std::vector<unsigned long>& weight_indices

	)
	{
		typedef cv_image<image_type> image_view_type;

		auto lambda = [&]<typename T>(
			T & img,
			std::vector<rect_detection>&rect_detections,
			const double adjust_threshold) {
			evaluate_detectors(detectors, img, rect_detections, adjust_threshold);
		};

		detector_evaluator<image_type, image_view_type> _detector(lambda, lambda);

		auto img = cv_image<image_type>(image);
		auto& img_view = img;

		return run_detector_with_upscale(
			_detector,
			img_view,
			upsampling_amount,
			adjust_threshold,
			detection_confidences,
			weight_indices
		);
	}

	inline std::vector<rectangle> run_detector_with_upscale(
		simple_object_detector& detector,
		Mat& image,
		const unsigned int upsampling_amount,
		const double adjust_threshold,
		std::vector<double>& detection_confidences,
		std::vector<unsigned long>& weight_indices
	)
	{
		AUTOIT_ASSERT_THROW(image.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
		AUTOIT_ASSERT_THROW(image.channels() == 1 || image.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

		if (image.channels() == 1) {
			typedef unsigned char image_type;
			return run_detector_with_upscale_impl<image_type>(
				detector,
				image,
				upsampling_amount,
				adjust_threshold,
				detection_confidences,
				weight_indices
				);
		}

		typedef bgr_pixel image_type;
		return run_detector_with_upscale_impl<image_type>(
			detector,
			image,
			upsampling_amount,
			adjust_threshold,
			detection_confidences,
			weight_indices
			);
	}

	inline std::vector<rectangle> run_detector_with_upscale(
		std::vector<simple_object_detector>& detectors,
		Mat& image,
		const unsigned int upsampling_amount,
		const double adjust_threshold,
		std::vector<double>& detection_confidences,
		std::vector<unsigned long>& weight_indices
	)
	{
		AUTOIT_ASSERT_THROW(image.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
		AUTOIT_ASSERT_THROW(image.channels() == 1 || image.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

		if (image.channels() == 1) {
			typedef unsigned char image_type;
			return run_detector_with_upscale_impl<image_type>(
				detectors,
				image,
				upsampling_amount,
				adjust_threshold,
				detection_confidences,
				weight_indices
				);
		}

		typedef bgr_pixel image_type;
		return run_detector_with_upscale_impl<image_type>(
			detectors,
			image,
			upsampling_amount,
			adjust_threshold,
			detection_confidences,
			weight_indices
			);
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
			const string& dataset_filename,
			const std::vector<std::vector<rectangle>>& removed,
			const simple_object_detector_training_options& options
		)
		{

			ostringstream sout;
			// Note that the 1/16 factor is here because we will try to upsample the image
			// 2 times to accommodate small boxes.  We also take the max because we want to
			// lower bound the size of the smallest recommended box.  This is because the
			// 8x8 HOG cells can't really deal with really small object boxes.
			sout << "Error!  An impossible set of object boxes was given for training. ";
			sout << "All the boxes need to have a similar aspect ratio and also not be ";
			sout << "smaller than about " << std::max<long>(20 * 20, options.detection_window_size / 16) << " pixels in area. ";

			ostringstream sout2;
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

			AUTOIT_ASSERT_THROW(false, wrap_string(sout.str()) << "\n" << sout2.str());
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

void dlib::find_candidate_object_locations(
	Mat& image,
	std::vector<dlib::rectangle>& boxes,
	tuple<double, double, long> _kvals,
	ULONG min_size,
	ULONG max_merging_iterations
) {
	AUTOIT_ASSERT_THROW(image.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
	AUTOIT_ASSERT_THROW(image.channels() == 1 || image.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

	double start = std::get<0>(_kvals);
	double end = std::get<1>(_kvals);
	long num = std::get<2>(_kvals);

	matrix_range_exp<double> kvals = linspace(start, end, num);

	// Copy any rectangles in the input pyboxes into rects so that any rectangles will be
	// properly deduped in the resulting output.
	std::vector<dlib::rectangle> rects = boxes;

	if (image.channels() == 1) {
		find_candidate_object_locations(cv_image<unsigned char>(image), rects, kvals, min_size, max_merging_iterations);
	}
	else {
		find_candidate_object_locations(cv_image<bgr_pixel>(image), rects, kvals, min_size, max_merging_iterations);
	}

	// Collect boxes containing candidate objects
	for (const auto& rect : rects) {
		boxes.push_back(rect);
	}
}

void dlib::train_simple_object_detector(
	const std::string& dataset_filename,
	const std::string& detector_output_filename,
	const simple_object_detector_training_options& options
)
{
	dlib::array<array2d<rgb_pixel>> images;
	std::vector<std::vector<dlib::rectangle>> boxes, ignore;
	ignore = load_image_dataset(images, boxes, dataset_filename);

	simple_object_detector_com detector = train_simple_object_detector_on_images(dataset_filename, images, boxes, ignore, options);

	save_simple_object_detector_com(detector, detector_output_filename);

	if (options.be_verbose)
		std::cout << "Saved detector to file " << detector_output_filename << std::endl;
}

simple_object_detector_com dlib::train_simple_object_detector_on_images(
	const std::vector<Mat>& _images,
	std::vector<std::vector<dlib::rectangle>>& boxes,
	const simple_object_detector_training_options& options
)
{
	const auto num_images = _images.size();
	AUTOIT_ASSERT_THROW(num_images == boxes.size(), "The length of the boxes list must match the length of the images list.");

	// We never have any ignore boxes for this version of the API.
	std::vector<std::vector<dlib::rectangle>> ignore(num_images);
	dlib::array<cv_image<bgr_pixel>> images(num_images);
	vector_Mat_to_dlib(_images, images);

	return train_simple_object_detector_on_images("", images, boxes, ignore, options);
}

const simple_test_results dlib::test_simple_object_detector(
	const std::string& dataset_filename,
	const std::string& detector_filename,
	const int upsampling_amount
)
{

	// Load all the testing images
	dlib::array<array2d<rgb_pixel>> images;
	std::vector<std::vector<dlib::rectangle>> boxes, ignore;
	ignore = load_image_dataset(images, boxes, dataset_filename);

	// Load the detector off disk (We have to use the explicit serialization here
	// so that we have an open file stream)
	simple_object_detector detector;
	std::ifstream fin(detector_filename.c_str(), std::ios::binary);
	if (!fin) {
		auto msg = "Unable to open file " + detector_filename;
		AUTOIT_ASSERT_THROW(fin, msg.c_str());
	}
	deserialize(detector, fin);


	/*  Here we need a little hack to deal with whether we are going to be loading a
	 *  simple_object_detector (possibly trained outside of Python) or a
	 *  simple_object_detector_py (definitely trained from Python). In order to do this
	 *  we peek into the filestream to see if there is more data after the object
	 *  detector. If there is, it will be the version and upsampling amount. Therefore,
	 *  by default we set the upsampling amount to -1 so that we can catch when no
	 *  upsampling amount has been passed (numbers less than 0). If -1 is passed, we
	 *  assume no upsampling and use 0. If a number > 0 is passed, we use that, else we
	 *  use the upsampling amount saved in the detector file (if it exists).
	 */
	unsigned int final_upsampling_amount = 0;
	if (fin.peek() != EOF)
	{
		int version = 0;
		deserialize(version, fin);
		AUTOIT_ASSERT_THROW(version == 1, "Unknown simple_object_detector format.");
		deserialize(final_upsampling_amount, fin);
	}
	if (upsampling_amount >= 0)
		final_upsampling_amount = upsampling_amount;

	return test_simple_object_detector_with_images(images, final_upsampling_amount, boxes, ignore, detector);
}

const simple_test_results dlib::test_simple_object_detector2(
	const std::string& dataset_filename,
	simple_object_detector& detector,
	const int upsampling_amount
)
{
	// Load all the testing images
	dlib::array<array2d<rgb_pixel>> images;
	std::vector<std::vector<dlib::rectangle>> boxes, ignore;
	ignore = load_image_dataset(images, boxes, dataset_filename);

	unsigned int final_upsampling_amount = upsampling_amount < 0 ? 0 : upsampling_amount;
	return test_simple_object_detector_with_images(images, final_upsampling_amount, boxes, ignore, detector);
}

const simple_test_results dlib::test_simple_object_detector3(
	const std::string& dataset_filename,
	simple_object_detector_com& detector,
	const int upsampling_amount
)
{
	// Allow users to pass an upsampling amount ELSE use the one cached on the object
	// Anything less than 0 is ignored and the cached value is used.
	unsigned int final_upsampling_amount = upsampling_amount < 0 ? detector.upsampling_amount : upsampling_amount;

	return test_simple_object_detector2(dataset_filename, detector.detector, final_upsampling_amount);
}

simple_test_results dlib::test_simple_object_detector_with_images(
	const std::vector<Mat>& _images,
	std::vector<std::vector<dlib::rectangle>>& boxes,
	simple_object_detector& detector,
	const int upsampling_amount
)
{
	const auto num_images = _images.size();
	AUTOIT_ASSERT_THROW(num_images == boxes.size(), "The length of the boxes list must match the length of the images list.");

	// We never have any ignore boxes for this version of the API.
	std::vector<std::vector<dlib::rectangle>> ignore(num_images);
	dlib::array<cv_image<bgr_pixel>> images(num_images);
	vector_Mat_to_dlib(_images, images);

	unsigned int final_upsampling_amount = upsampling_amount < 0 ? 0 : upsampling_amount;

	return test_simple_object_detector_with_images(images, final_upsampling_amount, boxes, ignore, detector);
}

simple_test_results dlib::test_simple_object_detector_with_images2(
	const std::vector<Mat>& _images,
	std::vector<std::vector<dlib::rectangle>>& boxes,
	simple_object_detector_com& detector,
	const int upsampling_amount
)
{
	// Allow users to pass an upsampling amount ELSE use the one cached on the object
	// Anything less than 0 is ignored and the cached value is used.
	unsigned int final_upsampling_amount = upsampling_amount < 0 ? detector.upsampling_amount : upsampling_amount;

	return test_simple_object_detector_with_images(_images, boxes, detector.detector, final_upsampling_amount);
}

void CDlib_Fhog_object_detector_Object::run(
	Mat& img,
	std::vector<dlib::rectangle>& rectangles,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices,
	unsigned int upsampling_amount,
	double adjust_threshold,
	HRESULT& hr
) {
	hr = S_OK;
	auto& detector = *__self->get();
	rectangles = run_detector_with_upscale(detector, img, upsampling_amount, adjust_threshold, detection_confidences, weight_indices);
}

void CDlib_Fhog_object_detector_Object::call(
	Mat& img,
	std::vector<dlib::rectangle>& rectangles,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices,
	unsigned int upsampling_amount,
	double adjust_threshold,
	HRESULT& hr
) {
	hr = S_OK;
	auto& detector = *__self->get();
	rectangles = run_detector_with_upscale(detector, img, upsampling_amount, adjust_threshold, detection_confidences, weight_indices);
}

void CDlib_Fhog_object_detector_Object::run_multiple(
	std::vector<fhog_object_detector>& detectors,
	Mat& img,
	std::vector<dlib::rectangle>& rectangles,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices,
	unsigned int upsampling_amount,
	double adjust_threshold,
	HRESULT& hr
) {
	hr = S_OK;

	rectangles = run_detector_with_upscale(detectors, img, upsampling_amount, adjust_threshold, detection_confidences, weight_indices);
}

void CDlib_Fhog_object_detector_Object::run_multiple(
	std::vector<simple_object_detector_com>& _detectors,
	Mat& img,
	std::vector<dlib::rectangle>& rectangles,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices,
	unsigned int upsampling_amount,
	double adjust_threshold,
	HRESULT& hr
) {
	hr = S_OK;

	std::vector<fhog_object_detector> detectors;
	detectors.reserve(_detectors.size());
	for (auto& detector : _detectors) {
		detectors.push_back(detector.detector);
	}

	rectangles = run_detector_with_upscale(detectors, img, upsampling_amount, adjust_threshold, detection_confidences, weight_indices);
}

void CDlib_Simple_object_detector_com_Object::run_multiple(
	std::vector<fhog_object_detector>& detectors,
	Mat& img,
	std::vector<dlib::rectangle>& rectangles,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices,
	unsigned int upsampling_amount,
	double adjust_threshold,
	HRESULT& hr
) {
	hr = S_OK;

	rectangles = run_detector_with_upscale(detectors, img, upsampling_amount, adjust_threshold, detection_confidences, weight_indices);
}

void CDlib_Simple_object_detector_com_Object::run_multiple(
	std::vector<simple_object_detector_com>& _detectors,
	Mat& img,
	std::vector<dlib::rectangle>& rectangles,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices,
	unsigned int upsampling_amount,
	double adjust_threshold,
	HRESULT& hr
) {
	hr = S_OK;

	std::vector<fhog_object_detector> detectors;
	detectors.reserve(_detectors.size());
	for (auto& detector : _detectors) {
		detectors.push_back(detector.detector);
	}

	rectangles = run_detector_with_upscale(detectors, img, upsampling_amount, adjust_threshold, detection_confidences, weight_indices);
}

dlib::simple_object_detector_com::simple_object_detector_com(std::vector<simple_object_detector_com>& detectors) {
	AUTOIT_ASSERT_THROW(detectors.size() > 0, "there should be detectors");

	std::vector<simple_object_detector> temp;
	temp.reserve(detectors.size());

	for (const auto& d : detectors)
		temp.push_back(d.detector);

	detector = fhog_object_detector(temp);
	upsampling_amount = detectors[0].upsampling_amount;
}

shared_ptr<simple_object_detector_com> dlib::simple_object_detector_com::create(const std::string& filename) {
	return load_object_from_file<simple_object_detector_com>(filename);
}

std::vector<dlib::rectangle> dlib::simple_object_detector_com::call(Mat& img, const unsigned int upsampling_amount_) {
	const double adjust_threshold = 0.0;
	std::vector<double> detection_confidences;
	std::vector<unsigned long> weight_indices;

	return run_detector_with_upscale(
		detector,
		img,
		upsampling_amount_,
		adjust_threshold,
		detection_confidences,
		weight_indices
	);
}

std::vector<dlib::rectangle> dlib::simple_object_detector_com::call(Mat& img) {
	const double adjust_threshold = 0.0;
	std::vector<double> detection_confidences;
	std::vector<unsigned long> weight_indices;

	return run_detector_with_upscale(
		detector,
		img,
		upsampling_amount,
		adjust_threshold,
		detection_confidences,
		weight_indices
	);
}
