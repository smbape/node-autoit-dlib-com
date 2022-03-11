#pragma once

#include <chrono>
#include "autoit_bridge_common.h"
#include "conversion.h"

using std::string;

namespace dlib {
	// ----------------------------------------------------------------------------------------

	extern std::string version;
	extern std::string time_compiled;
	extern bool DLIB_USE_CUDA;
	extern bool DLIB_USE_BLAS;
	extern bool DLIB_USE_LAPACK;
	extern bool USE_AVX_INSTRUCTIONS;
	extern bool USE_NEON_INSTRUCTIONS;

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE binary_test
	{
		CV_WRAP binary_test() : class1_accuracy(0), class2_accuracy(0) {}
		binary_test(
			const dlib::matrix<double, 1, 2>& m
		) : class1_accuracy(m(0)),
			class2_accuracy(m(1)) {}

		CV_WRAP const std::string ToString() const {
			const auto& item = *this;
			std::ostringstream sout;
			sout << "class1_accuracy: " << item.class1_accuracy << "  class2_accuracy: " << item.class2_accuracy;
			return sout.str();
		}

		CV_PROP_RW double class1_accuracy;
		CV_PROP_RW double class2_accuracy;
	};

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE regression_test
	{
		CV_WRAP regression_test() = default;
		regression_test(
			const dlib::matrix<double, 1, 4>& m
		) : mean_squared_error(m(0)),
			R_squared(m(1)),
			mean_average_error(m(2)),
			mean_error_stddev(m(3))
		{}

		CV_WRAP const std::string ToString() const {
			const auto& item = *this;
			std::ostringstream sout;
			sout << "mean_squared_error: " << item.mean_squared_error << "  R_squared: " << item.R_squared;
			sout << "  mean_average_error: " << item.mean_average_error << "  mean_error_stddev: " << item.mean_error_stddev;
			return sout.str();
		}

		CV_PROP_RW double mean_squared_error = 0;
		CV_PROP_RW double R_squared = 0;
		CV_PROP_RW double mean_average_error = 0;
		CV_PROP_RW double mean_error_stddev = 0;
	};

	struct CV_EXPORTS_W_SIMPLE ranking_test
	{
		CV_WRAP ranking_test() : ranking_accuracy(0), mean_ap(0) {}
		ranking_test(
			const dlib::matrix<double, 1, 2>& m
		) : ranking_accuracy(m(0)),
			mean_ap(m(1)) {}

		CV_WRAP const std::string ToString() const {
			const auto& item = *this;
			std::ostringstream sout;
			sout << "ranking_accuracy: " << item.ranking_accuracy << "  mean_ap: " << item.mean_ap;
			return sout.str();
		}

		CV_PROP_RW double ranking_accuracy;
		CV_PROP_RW double mean_ap;
	};

	// ----------------------------------------------------------------------------------------

	template <typename T>
	inline std::shared_ptr<T> load_object_from_file(
		const std::string& filename
	)
		/*!
			ensures
				- deserializes an object of type T from the given file and returns it.
		!*/
	{
		std::ifstream fin(filename.c_str(), std::ios::binary);
		if (!fin) {
			AUTOIT_ASSERT_THROW(fin, "Unable to open " << filename);
		}
		auto obj = std::make_shared<T>();
		deserialize(*obj, fin);
		return obj;
	}

	template <typename T>
	inline void save_object_to_file(const T& obj, const std::string& filename)
	{
		std::ofstream fout(filename.c_str(), std::ios::binary);
		serialize(obj, fout);
	}
}
