#pragma once

#include <dlib/svm_threaded.h>
#include "base.h"

using namespace std;

namespace dlib {
	// ----------------------------------------------------------------------------------------

	template <typename samp_type, bool BIO, bool high_order, bool nonnegative>
	class segmenter_feature_extractor
	{

	public:
		typedef std::vector<samp_type> sequence_type;
		const static bool use_BIO_model = BIO;
		const static bool use_high_order_features = high_order;
		const static bool allow_negative_weights = nonnegative;


		unsigned long _num_features;
		unsigned long _window_size;

		segmenter_feature_extractor(
		) : _num_features(1), _window_size(1) {}

		segmenter_feature_extractor(
			unsigned long _num_features_,
			unsigned long _window_size_
		) : _num_features(_num_features_), _window_size(_window_size_) {}

		unsigned long num_features(
		) const {
			return _num_features;
		}

		unsigned long window_size(
		) const {
			return _window_size;
		}

		template <typename feature_setter>
		void get_features(
			feature_setter& set_feature,
			const std::vector<dense_vect>& x,
			unsigned long position
		) const
		{
			for (long i = 0; i < x[position].size(); ++i)
			{
				set_feature(i, x[position](i));
			}
		}

		template <typename feature_setter>
		void get_features(
			feature_setter& set_feature,
			const std::vector<sparse_vect>& x,
			unsigned long position
		) const
		{
			for (unsigned long i = 0; i < x[position].size(); ++i)
			{
				set_feature(x[position][i].first, x[position][i].second);
			}
		}

		friend void serialize(const segmenter_feature_extractor& item, std::ostream& out)
		{
			dlib::serialize(item._num_features, out);
			dlib::serialize(item._window_size, out);
		}
		friend void deserialize(segmenter_feature_extractor& item, std::istream& in)
		{
			dlib::deserialize(item._num_features, in);
			dlib::deserialize(item._window_size, in);
		}
	};

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE segmenter_type
	{
		/*!
			WHAT THIS OBJECT REPRESENTS
				This the object that python will use directly to represent a
				sequence_segmenter.  All it does is contain all the possible template
				instantiations of a sequence_segmenter and invoke the right one depending on
				the mode variable.
		!*/

		CV_WRAP segmenter_type() : mode(-1)
		{ }

		CV_WRAP_AS(call) ranges segment_sequence_dense(
			const std::vector<dense_vect>& x
		) const
		{
			switch (mode)
			{
			case 0: return segmenter0(x);
			case 1: return segmenter1(x);
			case 2: return segmenter2(x);
			case 3: return segmenter3(x);
			case 4: return segmenter4(x);
			case 5: return segmenter5(x);
			case 6: return segmenter6(x);
			case 7: return segmenter7(x);
			default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
			}
		}

		CV_WRAP_AS(call) ranges segment_sequence_sparse(
			const std::vector<sparse_vect>& x
		) const
		{
			switch (mode)
			{
			case 8: return segmenter8(x);
			case 9: return segmenter9(x);
			case 10: return segmenter10(x);
			case 11: return segmenter11(x);
			case 12: return segmenter12(x);
			case 13: return segmenter13(x);
			case 14: return segmenter14(x);
			case 15: return segmenter15(x);
			default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
			}
		}

		const matrix<double, 0, 1> get_weights()
		{
			switch (mode)
			{
			case 0: return segmenter0.get_weights();
			case 1: return segmenter1.get_weights();
			case 2: return segmenter2.get_weights();
			case 3: return segmenter3.get_weights();
			case 4: return segmenter4.get_weights();
			case 5: return segmenter5.get_weights();
			case 6: return segmenter6.get_weights();
			case 7: return segmenter7.get_weights();

			case 8: return segmenter8.get_weights();
			case 9: return segmenter9.get_weights();
			case 10: return segmenter10.get_weights();
			case 11: return segmenter11.get_weights();
			case 12: return segmenter12.get_weights();
			case 13: return segmenter13.get_weights();
			case 14: return segmenter14.get_weights();
			case 15: return segmenter15.get_weights();

			default: AUTOIT_ASSERT_THROW(false, "Invalid mode");
			}
		}

		friend void serialize(const segmenter_type& item, std::ostream& out);
		friend void deserialize(segmenter_type& item, std::istream& in);

		int mode;

		typedef segmenter_feature_extractor<dense_vect, false, false, false> fe0;
		typedef segmenter_feature_extractor<dense_vect, false, false, true>  fe1;
		typedef segmenter_feature_extractor<dense_vect, false, true, false> fe2;
		typedef segmenter_feature_extractor<dense_vect, false, true, true>  fe3;
		typedef segmenter_feature_extractor<dense_vect, true, false, false> fe4;
		typedef segmenter_feature_extractor<dense_vect, true, false, true>  fe5;
		typedef segmenter_feature_extractor<dense_vect, true, true, false> fe6;
		typedef segmenter_feature_extractor<dense_vect, true, true, true>  fe7;
		sequence_segmenter<fe0> segmenter0;
		sequence_segmenter<fe1> segmenter1;
		sequence_segmenter<fe2> segmenter2;
		sequence_segmenter<fe3> segmenter3;
		sequence_segmenter<fe4> segmenter4;
		sequence_segmenter<fe5> segmenter5;
		sequence_segmenter<fe6> segmenter6;
		sequence_segmenter<fe7> segmenter7;

		typedef segmenter_feature_extractor<sparse_vect, false, false, false> fe8;
		typedef segmenter_feature_extractor<sparse_vect, false, false, true>  fe9;
		typedef segmenter_feature_extractor<sparse_vect, false, true, false> fe10;
		typedef segmenter_feature_extractor<sparse_vect, false, true, true>  fe11;
		typedef segmenter_feature_extractor<sparse_vect, true, false, false> fe12;
		typedef segmenter_feature_extractor<sparse_vect, true, false, true>  fe13;
		typedef segmenter_feature_extractor<sparse_vect, true, true, false> fe14;
		typedef segmenter_feature_extractor<sparse_vect, true, true, true>  fe15;
		sequence_segmenter<fe8> segmenter8;
		sequence_segmenter<fe9> segmenter9;
		sequence_segmenter<fe10> segmenter10;
		sequence_segmenter<fe11> segmenter11;
		sequence_segmenter<fe12> segmenter12;
		sequence_segmenter<fe13> segmenter13;
		sequence_segmenter<fe14> segmenter14;
		sequence_segmenter<fe15> segmenter15;
	};

	// ----------------------------------------------------------------------------------------

	struct CV_EXPORTS_W_SIMPLE segmenter_params
	{
		CV_WRAP segmenter_params()
		{
			use_BIO_model = true;
			use_high_order_features = true;
			allow_negative_weights = true;
			window_size = 5;
			num_threads = 4;
			epsilon = 0.1;
			max_cache_size = 40;
			be_verbose = false;
			C = 100;
		}

		CV_WRAP const std::string ToString() const;

		friend void serialize(const segmenter_params& item, std::ostream& out);
		friend void deserialize(segmenter_params& item, std::istream& in);

		CV_PROP_RW bool use_BIO_model;
		CV_PROP_RW bool use_high_order_features;
		CV_PROP_RW bool allow_negative_weights;
		CV_PROP_RW ULONG window_size;
		CV_PROP_RW ULONG num_threads;
		CV_PROP_RW double epsilon;
		CV_PROP_RW ULONG max_cache_size;
		CV_PROP_RW bool be_verbose;
		CV_PROP_RW double C;
	};

	// ----------------------------------------------------------------------------------------


	struct CV_EXPORTS_W_SIMPLE segmenter_test
	{
		CV_WRAP const std::string ToString() const;

		friend void serialize(const segmenter_test& item, std::ostream& out);
		friend void deserialize(segmenter_test& item, std::istream& in);

		CV_PROP_RW double precision;
		CV_PROP_RW double recall;
		CV_PROP_RW double f1;
	};

	CV_EXPORTS_AS(train_sequence_segmenter) segmenter_type train_dense(
		const std::vector<std::vector<dense_vect>>& samples,
		const std::vector<ranges>& segments,
		segmenter_params params = segmenter_params()
	);

	CV_EXPORTS_AS(train_sequence_segmenter) segmenter_type train_sparse(
		const std::vector<std::vector<sparse_vect>>& samples,
		const std::vector<ranges>& segments,
		segmenter_params params = segmenter_params()
	);

	CV_EXPORTS_AS(test_sequence_segmenter) const segmenter_test test_sequence_segmenter1(
		const segmenter_type& segmenter,
		const std::vector<std::vector<dense_vect> >& samples,
		const std::vector<ranges>& segments
	);

	CV_EXPORTS_AS(test_sequence_segmenter) const segmenter_test test_sequence_segmenter2(
		const segmenter_type& segmenter,
		const std::vector<std::vector<sparse_vect> >& samples,
		const std::vector<ranges>& segments
	);

	CV_EXPORTS_AS(cross_validate_sequence_segmenter) const segmenter_test cross_validate_sequence_segmenter1(
		const std::vector<std::vector<dense_vect> >& samples,
		const std::vector<ranges>& segments,
		long folds,
		segmenter_params params = segmenter_params()
	);

	CV_EXPORTS_AS(cross_validate_sequence_segmenter) const segmenter_test cross_validate_sequence_segmenter2(
		const std::vector<std::vector<sparse_vect> >& samples,
		const std::vector<ranges>& segments,
		long folds,
		segmenter_params params = segmenter_params()
	);
}
