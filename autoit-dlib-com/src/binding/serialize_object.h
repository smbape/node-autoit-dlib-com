// Copyright (C) 2014  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.
#ifndef DLIB_SERIALIZE_OBJECT_DETECTOR_H__
#define DLIB_SERIALIZE_OBJECT_DETECTOR_H__

#include "simple_object_detector.h"

namespace dlib
{
	inline void serialize(const simple_object_detector_com& item, std::ostream& out)
	{
		int version = 1;
		serialize(item.detector, out);
		serialize(version, out);
		serialize(item.upsampling_amount, out);
	}

	inline void deserialize(simple_object_detector_com& item, std::istream& in)
	{
		int version = 0;
		deserialize(item.detector, in);
		deserialize(version, in);
		AUTOIT_ASSERT_THROW(version == 1, "Unexpected version found while deserializing a simple_object_detector.");
		deserialize(item.upsampling_amount, in);
	}

	inline void save_simple_object_detector_com(const simple_object_detector_com& detector, const std::string& detector_output_filename)
	{
		std::ofstream fout(detector_output_filename.c_str(), std::ios::binary);
		int version = 1;
		serialize(detector.detector, fout);
		serialize(version, fout);
		serialize(detector.upsampling_amount, fout);
	}
}

#endif // DLIB_SERIALIZE_OBJECT_DETECTOR_H__
