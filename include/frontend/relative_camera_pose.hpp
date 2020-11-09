#ifndef RELATIVE_CAMERA_POSE_HPP
#define RELATIVE_CAMERA_POSE_HPP

#include "opencv2/opencv.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/features2d.hpp"

#include "frontend/feature_matcher.hpp"

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
    cv::Mat compute_homography(
        std::vector<cv::KeyPoint> keypoints_src,
        std::vector<cv::KeyPoint> keypoints_dst,
        std::vector<DMatch> good_matches);
    cv::Mat compute_essential_matrix(
        std::vector<cv::KeyPoint> keypoints_src,
        std::vector<cv::KeyPoint> keypoints_dst,
        std::vector<DMatch> good_matches);
    uint32_t symmetric_transfer_error((
        cv::Mat homography_mat, 
        cv::Mat essential_mat);

    shslam::FeatureMatcher matcher_;

    cv::Mat relative_pose_;
};
} // namespace shslam

#endif