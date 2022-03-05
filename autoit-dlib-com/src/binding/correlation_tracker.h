#pragma once

// make the generator include this file
// CV_EXPORTS

#include <dlib/geometry.h>
#include <dlib/image_processing.h>
#include "base.h"

using namespace std;

namespace dlib {
	// ----------------------------------------------------------------------------------------

	void start_track(
		correlation_tracker& tracker,
		cv::Mat& img,
		const drectangle& bounding_box
	);

	double update(
		correlation_tracker& tracker,
		cv::Mat& img
	);

	double update(
		correlation_tracker& tracker,
		cv::Mat& img,
		const drectangle& bounding_box
	);

}
