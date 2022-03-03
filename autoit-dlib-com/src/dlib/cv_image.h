// Copyright (C) 2009  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.
#ifndef DLIB_CvIMAGE_H_
#define DLIB_CvIMAGE_H_

#include <opencv2/core/core.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/imgproc.hpp>
#include <dlib/algs.h>
#include <dlib/pixel.h>
#include <dlib/matrix/matrix_mat.h>
#include <dlib/image_processing/generic_image.h>

namespace dlib
{

	template <typename pixel_type>
	struct cv_image
	{
		typedef pixel_type type;
		typedef default_memory_manager mem_manager_type;

		cv_image() = default;

		cv_image (const cv::Mat& img) 
		{
			AUTOIT_ASSERT_THROW(img.depth() == cv::DataType<typename pixel_traits<pixel_type>::basic_pixel_type>::depth &&
						 img.channels() == pixel_traits<pixel_type>::num, 
						 "The pixel type you gave doesn't match pixel used by the open cv Mat object."
						 << "\n\t img.depth():    " << img.depth() 
						 << "\n\t img.cv::DataType<typename pixel_traits<pixel_type>::basic_pixel_type>::depth: " 
							<< cv::DataType<typename pixel_traits<pixel_type>::basic_pixel_type>::depth 
						 << "\n\t img.channels(): " << img.channels() 
						 << "\n\t img.pixel_traits<pixel_type>::num: " << pixel_traits<pixel_type>::num 
						 );

			image = img;
		}

		size_t size () const { return static_cast<size_t>(image.rows * image.cols); }

		inline pixel_type* operator[](const long row ) 
		{ 
			// make sure requires clause is not broken
			AUTOIT_ASSERT_THROW(0 <= row && row < nr(),
				"\tpixel_type* cv_image::operator[](row)"
				<< "\n\t you have asked for an out of bounds row " 
				<< "\n\t row:  " << row
				<< "\n\t nr(): " << nr() 
				<< "\n\t this:  " << this
				);

			return reinterpret_cast<pixel_type*>(image.ptr(row));
		}

		inline const pixel_type* operator[](const long row ) const
		{ 
			// make sure requires clause is not broken
			AUTOIT_ASSERT_THROW(0 <= row && row < nr(),
				"\tconst pixel_type* cv_image::operator[](row)"
				<< "\n\t you have asked for an out of bounds row " 
				<< "\n\t row:  " << row
				<< "\n\t nr(): " << nr() 
				<< "\n\t this:  " << this
				);

			return reinterpret_cast<const pixel_type*>(image.ptr(row));
		}

		inline const pixel_type& operator()(const long row, const long column) const
		{
		  AUTOIT_ASSERT_THROW(0<= column && column < nc(),
			  "\tcont pixel_type& cv_image::operator()(const long rown const long column)"
			  << "\n\t you have asked for an out of bounds column "
			  << "\n\t column: " << column
			  << "\n\t nc(): " << nc()
			  << "\n\t this:  " << this
			  );

		  return (*this)[row][column];
		}

		inline pixel_type& operator()(const long row, const long column)
		{
		  AUTOIT_ASSERT_THROW(0<= column && column < nc(),
			  "\tcont pixel_type& cv_image::operator()(const long rown const long column)"
			  << "\n\t you have asked for an out of bounds column "
			  << "\n\t column: " << column
			  << "\n\t nc(): " << nc()
			  << "\n\t this:  " << this
			  );

		  return (*this)[row][column];
		}

		long nr() const { return image.rows; }
		long nc() const { return image.cols; }
		void set_image_size(long rows, long cols) {
			cv::Mat dst;
			cv::Size dsize(cols, rows);
			cv::resize(image, dst, dsize);
			image = dst;
		}
		long width_step() const { return (size_t) image.step; }

		cv::Mat image = cv::Mat();
	};

// ----------------------------------------------------------------------------------------

	template <
		typename T
		>
	const matrix_op<op_array2d_to_mat<cv_image<T>>> mat (
		const cv_image<T>& m 
	)
	{
		typedef op_array2d_to_mat<cv_image<T>> op;
		return matrix_op<op>(op(m));
	}

// ----------------------------------------------------------------------------------------

// Define the global functions that make cv_image a proper "generic image" according to
// ../image_processing/generic_image.h
	template <typename T>
	struct image_traits<cv_image<T>>
	{
		typedef T pixel_type;
	};

	template <typename T>
	inline long num_rows( const cv_image<T>& img) { return img.nr(); }
	template <typename T>
	inline long num_columns( const cv_image<T>& img) { return img.nc(); }

	template <typename T>
	inline void set_image_size(
		cv_image<T>& img,
		long rows,
		long cols 
	) {
		img.set_image_size(rows, cols);
	}

	template <typename T>
	inline void* image_data(
		cv_image<T>& img
	)
	{
		return img.image.ptr();
	}

	template <typename T>
	inline const void* image_data(
		const cv_image<T>& img
	)
	{
		return img.image.ptr();
	}

	template <typename T>
	inline long width_step(
		const cv_image<T>& img
	) 
	{ 
		return img.width_step(); 
	}

	template <typename T>
	inline void swap(
		cv_image<T>& a,
		cv_image<T>& b
	) {
		cv::swap(a.image, b.image);
	}

// ----------------------------------------------------------------------------------------

}

#endif // DLIB_CvIMAGE_H_

