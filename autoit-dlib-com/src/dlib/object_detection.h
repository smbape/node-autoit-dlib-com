#pragma once

#include "serialize_object.h"

namespace dlib {
	CV_EXPORTS_W void find_candidate_object_locations(
		cv::Mat& image,
		CV_OUT std::vector<rectangle>& rects,
		std::tuple<double, double, long> kvals = std::tuple<double, double, long>(50, 200, 3),
		ULONG min_size = 20,
		ULONG max_merging_iterations = 50
	);
}
