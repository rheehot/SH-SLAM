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

    void compute();
    cv::Mat get_relative_pose() { return relative_pose_; }

private:
    cv::Mat compute_homography();
    cv::Mat compute_essential_matrix();
    uint32_t symmetric_transfer_error();

    cv::Mat relative_pose_;
};
} // namespace shslam

#endif