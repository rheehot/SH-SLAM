#ifndef RELATIVE_CAMERA_POSE_HPP
#define RELATIVE_CAMERA_POSE_HPP

#include "opencv2/opencv.hpp"

namespace shslam
{
// Compute relative camera pose based on E or H
class RelativeCameraPose
{
public:
    RelativeCameraPose();
    ~RelativeCameraPose();
private:
    cv::Mat compute_homography();
    cv::Mat compute_essential_matrix();
    uint32_t symmetric_transfer_error();
};
} // namespace shslam

#endif