#include "correlation_tracker.h"

using namespace std;

namespace dlib {
    // ----------------------------------------------------------------------------------------

    void start_track(
        correlation_tracker& tracker,
        cv::Mat& img,
        const drectangle& bounding_box
    )
    {
        AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
        AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

        if (img.channels() == 1)
        {
            tracker.start_track(cv_image<unsigned char>(img), bounding_box);
        }
        else
        {
            tracker.start_track(cv_image<bgr_pixel>(img), bounding_box);
        }
    }

    double update(
        correlation_tracker& tracker,
        cv::Mat& img
    )
    {
        AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
        AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

        if (img.channels() == 1)
        {
            return tracker.update(cv_image<unsigned char>(img));
        }

        return tracker.update(cv_image<bgr_pixel>(img));
    }

    double update(
        correlation_tracker& tracker,
        cv::Mat& img,
        const drectangle& bounding_box
    )
    {
        AUTOIT_ASSERT_THROW(img.depth() == CV_8U, "Unsupported image type, must be 8bit gray or RGB image.");
        AUTOIT_ASSERT_THROW(img.channels() == 1 || img.channels() == 3, "Unsupported image type, must be 8bit gray or RGB image.");

        if (img.channels() == 1)
        {
            return tracker.update(cv_image<unsigned char>(img), bounding_box);
        }

        return tracker.update(cv_image<bgr_pixel>(img), bounding_box);
    }

}
