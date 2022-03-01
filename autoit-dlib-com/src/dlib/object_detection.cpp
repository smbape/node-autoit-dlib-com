#include "object_detection.h"

using namespace cv;
using namespace dlib;
using namespace std;

template<typename image_type, typename image_view_type>
struct detector_evaluator {
	// typedef void (*detector_function_1)(image_view_type& img, std::vector<rect_detection>& rect_detections, const double adjust_threshold);
	// typedef void (*detector_function_2)(array2d<image_type>& img, std::vector<rect_detection>& rect_detections, const double adjust_threshold);
	typedef std::function <void(image_view_type&, std::vector<rect_detection>&, const double)> detector_function_1;
	typedef std::function <void(array2d<image_type>&, std::vector<rect_detection>&, const double)> detector_function_2;

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
inline std::vector<dlib::rectangle> run_detector_with_upscale(
	detector_evaluator<image_type, image_view_type> detector,
	image_view_type& img_view,
	const unsigned int upsampling_amount,
	const double adjust_threshold,
	std::vector<double>& detection_confidences,
	std::vector<unsigned long>& weight_indices
) {
	pyramid_down<2> pyr;

	std::vector<dlib::rectangle> rectangles;
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
inline std::vector<dlib::rectangle> run_detector_with_upscale_impl(
	dlib::simple_object_detector& detector,
	cv::Mat& image,
	const unsigned int upsampling_amount

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

	const double adjust_threshold = 0.0;
	std::vector<double> detection_confidences;
	std::vector<unsigned long> weight_indices;

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

void dlib::find_candidate_object_locations(
	Mat& image,
	std::vector<rectangle>& boxes,
	std::tuple<double, double, long> _kvals,
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
	std::vector<rectangle> rects = boxes;

	if (image.channels() == 1) {
		find_candidate_object_locations(cv_image<unsigned char>(image), rects, kvals, min_size, max_merging_iterations);
	}
	else {
		find_candidate_object_locations(cv_image<rgb_pixel>(image), rects, kvals, min_size, max_merging_iterations);
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
	dlib::array<array2d<rgb_pixel> > images;
	std::vector<std::vector<rectangle> > boxes, ignore;
	ignore = load_image_dataset(images, boxes, dataset_filename);

	simple_object_detector_com detector = train_simple_object_detector_on_images(dataset_filename, images, boxes, ignore, options);

	save_simple_object_detector_com(detector, detector_output_filename);

	if (options.be_verbose)
		std::cout << "Saved detector to file " << detector_output_filename << std::endl;
}

simple_object_detector_com dlib::train_simple_object_detector(
	const std::vector<cv::Mat>& cvimages,
	std::vector<std::vector<rectangle>>& boxes,
	const simple_object_detector_training_options& options
)
{
	const auto num_images = cvimages.size();

	AUTOIT_ASSERT_THROW(num_images == boxes.size(), "The length of the boxes list must match the length of the images list.");

	// We never have any ignore boxes for this version of the API.
	std::vector<std::vector<rectangle>> ignore(num_images);
	dlib::array<cv_image<rgb_pixel>> images(num_images);
	cvimages_to_dlib(cvimages, images);

	return train_simple_object_detector_on_images("", images, boxes, ignore, options);
}

const simple_test_results dlib::test_simple_object_detector(
	const std::string& dataset_filename,
	const std::string& detector_filename,
	const int upsample_amount
)
{

	// Load all the testing images
	dlib::array<array2d<rgb_pixel> > images;
	std::vector<std::vector<rectangle> > boxes, ignore;
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
		if (version != 1)
			throw error("Unknown simple_object_detector format.");
		deserialize(final_upsampling_amount, fin);
	}
	if (upsample_amount >= 0)
		final_upsampling_amount = upsample_amount;

	return test_simple_object_detector_with_images(images, final_upsampling_amount, boxes, ignore, detector);
}

inline std::vector<dlib::rectangle> run_detector_with_upscale(
	dlib::simple_object_detector& detector,
	cv::Mat& image,
	const unsigned int upsampling_amount
)
{
	AUTOIT_ASSERT_THROW(image.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
	AUTOIT_ASSERT_THROW(image.channels() == 1 || image.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

	if (image.channels() == 1) {
		typedef unsigned char image_type;
		return run_detector_with_upscale_impl<image_type>(detector, image, upsampling_amount);
	}

	typedef rgb_pixel image_type;
	return run_detector_with_upscale_impl<image_type>(detector, image, upsampling_amount);
}

std::vector<dlib::rectangle> dlib::simple_object_detector_com::run_detector1(cv::Mat& img, const uint upsampling_amount_) {
	return run_detector_with_upscale(detector, img, upsampling_amount_);
}

std::vector<dlib::rectangle> dlib::simple_object_detector_com::run_detector2(cv::Mat& img) {
	return run_detector_with_upscale(detector, img, upsampling_amount);
}
