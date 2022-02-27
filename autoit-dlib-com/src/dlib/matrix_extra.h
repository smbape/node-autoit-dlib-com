#pragma once

#include "./basic.h"

namespace dlib {
#define mat_row _row
	struct CV_EXPORTS_W _row {
		mat_row() : data(0), size(0) {}
		mat_row(double* data_, long size_) : data(data_), size(size_) {}

		CV_WRAP std::string ToString();
		CV_WRAP double get(long r);
		CV_WRAP void set(long r, double val);

		double* data;
		long size;
	};
}
