#include "frontend/relative_camera_pose.hpp"

namespace shslam
{
RelativeCameraPose::RelativeCameraPose()
{
    //
}

RelativeCameraPose::~RelativeCameraPose()
{
    //
}

void RelativeCameraPose::compute()
{
    // Get keypoints and matches from the feature_matcher
    // 

    cv::Mat transform_model;

    cv::Mat homography_mat = compute_homography(keypoints_src, keypoints_dst, good_matches);
    cv::Mat essential_mat = compute_essential_matrix(keypoints_src, keypoints_dst, good_matches);

    int32_t error_score = symmetric_transfer_error(homography_mat, essential_mat);

    if(error_score > 0.45)
        transform_model = homography_mat;
    else
        transform_model = essential_mat;

    // Decompose matrix and compute R|t
}

cv::Mat RelativeCameraPose::compute_homography(
    std::vector<cv::KeyPoint> keypoints_src,
    std::vector<cv::KeyPoint> keypoints_dst,
    std::vector<DMatch> good_matches)
{
    std::vector<Point2f> point_src;
    std::vector<Point2f> point_dst;

    for (size_t i = 0; i < good_matches.size(); i++)
    {
        point_src.push_back(keypoints_src[good_matches[i].queryIdx].pt);
        point_dst.push_back(keypoints_dst[good_matches[i].trainIdx].pt);
    }

    return cv::findHomography(point_src, point_dst, cv::RANSAC);
}

cv::Mat RelativeCameraPose::compute_essential_matrix(
    std::vector<cv::KeyPoint> keypoints_src,
    std::vector<cv::KeyPoint> keypoints_dst,
    std::vector<DMatch> good_matches)
{
    std::vector<Point2f> point_src;
    std::vector<Point2f> point_dst;

    for (size_t i = 0; i < good_matches.size(); i++)
    {
        point_src.push_back(keypoints_src[good_matches[i].queryIdx].pt);
        point_dst.push_back(keypoints_dst[good_matches[i].trainIdx].pt);
    }

    return cv::findEssentialMat(point_src, point_dst);
}

uint32_t RelativeCameraPose::symmetric_transfer_error(
    cv::Mat homography_mat, 
    cv::Mat essential_mat)
{
    //
}
} // namespace shslam