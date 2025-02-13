#pragma once

#include "base.h"

namespace dlib {
	struct CV_EXPORTS_W_SIMPLE _row {
		CV_WRAP _row() : data(0), size(0) {}
		CV_WRAP _row(double* data_, long size_) : data(data_), size(size_) {}

		CV_WRAP const std::string ToString();
		CV_WRAP double get(long r);
		CV_WRAP void set(long r, double val);

		double* data;
		long size;
	};

	typedef _row mat_row;
}
