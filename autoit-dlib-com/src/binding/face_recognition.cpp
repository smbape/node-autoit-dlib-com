#pragma once

#include "face_recognition.h"

using namespace dlib;
using namespace std;

face_recognition_model_v1::face_recognition_model_v1(const std::string& model_filename) {
	deserialize(model_filename) >> net;
}

dense_vect face_recognition_model_v1::compute_face_descriptor(
	const cv::Mat& image,
	const full_object_detection& face,
	const int num_jitters,
	float padding
)
{
	std::vector<full_object_detection> faces(1, face);
	return compute_face_descriptor(image, faces, num_jitters, padding)[0];
}

dense_vect face_recognition_model_v1::compute_face_descriptor(
	const cv::Mat& image,
	const int num_jitters
)
{
	std::vector<cv::Mat> images{ image };
	return compute_face_descriptor(images, num_jitters)[0];
}
std::vector<dense_vect> face_recognition_model_v1::compute_face_descriptor(
	const cv::Mat& image,
	const std::vector<full_object_detection>& faces,
	const int num_jitters,
	float padding
)
{
	std::vector<cv::Mat> images(1, image);
	std::vector<std::vector<full_object_detection>> batch_faces(1, faces);
	return compute_face_descriptor(images, batch_faces, num_jitters, padding)[0];
}

std::vector<std::vector<dense_vect>> face_recognition_model_v1::compute_face_descriptor(
	const std::vector<cv::Mat>& images,
	const std::vector<std::vector<full_object_detection>>& batch_faces,
	const int num_jitters,
	float padding
)
{
	const auto& batch_imgs = vector_Mat_to_dlib<rgb_pixel>(images);

	AUTOIT_ASSERT_THROW(
		batch_imgs.size() == batch_faces.size(),
		"The array of images and the array of array of locations must be of the same size"
	);

	int total_chips = 0;
	for (const auto& faces : batch_faces)
	{
		total_chips += faces.size();
		for (const auto& f : faces)
		{
			AUTOIT_ASSERT_THROW(
				f.num_parts() == 68 || f.num_parts() == 5,
				"The full_object_detection must use the iBUG 300W 68 point face landmark style or dlib's 5 point style."
			);
		}
	}

	dlib::array<matrix<rgb_pixel>> face_chips;
	for (int i = 0; i < batch_imgs.size(); ++i)
	{
		auto& faces = batch_faces[i];
		auto& image = batch_imgs[i];

		std::vector<chip_details> dets;
		for (const auto& f : faces)
			dets.push_back(get_face_chip_details(f, 150, padding));
		dlib::array<matrix<rgb_pixel>> this_img_face_chips;
		extract_image_chips(image, dets, this_img_face_chips);

		for (auto& chip : this_img_face_chips)
			face_chips.push_back(chip);
	}

	std::vector<std::vector<dense_vect>> face_descriptors(batch_imgs.size());
	if (num_jitters <= 1)
	{
		// extract descriptors and convert from float vectors to double vectors
		auto descriptors = net(face_chips, 16);
		auto next = std::begin(descriptors);
		for (int i = 0; i < batch_faces.size(); ++i)
		{
			for (int j = 0; j < batch_faces[i].size(); ++j)
			{
				face_descriptors[i].push_back(matrix_cast<double>(*next++));
			}
		}
		DLIB_ASSERT(next == std::end(descriptors));
	}
	else
	{
		// extract descriptors and convert from float vectors to double vectors
		auto fimg = std::begin(face_chips);
		for (int i = 0; i < batch_faces.size(); ++i)
		{
			for (int j = 0; j < batch_faces[i].size(); ++j)
			{
				auto& r = mean(mat(net(jitter_image(*fimg++, num_jitters), 16)));
				face_descriptors[i].push_back(matrix_cast<double>(r));
			}
		}
		DLIB_ASSERT(fimg == std::end(face_chips));
	}

	return face_descriptors;
}

std::vector<dense_vect> face_recognition_model_v1::compute_face_descriptor(
	const std::vector<cv::Mat>& images,
	const int num_jitters
)
{
	dlib::array<matrix<rgb_pixel>> face_chips;

	for (const auto& img : images) {
		AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
		AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

		matrix<rgb_pixel> image;

		if (img.channels() == 1) {
			assign_image(image, cv_image<unsigned char>(img));
		}
		else {
			assign_image(image, cv_image<rgb_pixel>(img));
		}

		// Check for the size of the image
		if ((image.nr() != 150) || (image.nc() != 150)) {
			throw dlib::error("Unsupported image size, it should be of size 150x150. Also cropping must be done as `dlib.get_face_chip` would do it. \
                    That is, centered and scaled essentially the same way.");
		}

		face_chips.push_back(image);
	}

	std::vector<dense_vect> face_descriptors;
	if (num_jitters <= 1)
	{
		// extract descriptors and convert from float vectors to double vectors
		auto descriptors = net(face_chips, 16);

		for (auto& des : descriptors) {
			face_descriptors.push_back(matrix_cast<double>(des));
		}
	}
	else
	{
		// extract descriptors and convert from float vectors to double vectors
		for (auto& fimg : face_chips) {
			auto& r = mean(mat(net(jitter_image(fimg, num_jitters), 16)));
			face_descriptors.push_back(matrix_cast<double>(r));
		}
	}
	return face_descriptors;
}

std::vector<matrix<rgb_pixel>> face_recognition_model_v1::jitter_image(
	const matrix<rgb_pixel>& image,
	const int num_jitters
)
{
	std::vector<matrix<rgb_pixel>> crops;
	for (int i = 0; i < num_jitters; ++i)
		crops.push_back(dlib::jitter_image(image, rnd));
	return crops;
}


void dlib::save_face_chip(
	const cv::Mat& img,
	const full_object_detection& face,
	const std::string& chip_filename,
	size_t size,
	float padding
)
{
	std::vector<full_object_detection> faces(1, face);
	save_face_chips(img, faces, chip_filename, size, padding);
}

void dlib::save_face_chips(
	const cv::Mat& _img,
	const std::vector<full_object_detection>& faces,
	const std::string& chip_filename,
	size_t size,
	float padding
)
{
	cv_image<rgb_pixel> img(_img);

	int num_faces = faces.size();
	std::vector<chip_details> dets;
	for (const auto& f : faces)
		dets.push_back(get_face_chip_details(f, size, padding));
	dlib::array<matrix<rgb_pixel>> face_chips;
	extract_image_chips(img, dets, face_chips);
	int i = 0;
	for (const auto& chip : face_chips)
	{
		i++;
		if (num_faces > 1)
		{
			const std::string& file_name = chip_filename + "_" + std::to_string(i) + ".jpg";
			save_jpeg(chip, file_name);
		}
		else
		{
			const std::string& file_name = chip_filename + ".jpg";
			save_jpeg(chip, file_name);
		}
	}
}