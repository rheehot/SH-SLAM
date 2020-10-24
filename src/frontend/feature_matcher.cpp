#include "frontend/feature_matcher.hpp"

namespace shslam
{
FeatureMatcher::FeatureMatcher()
{
    detector_ = ORB::create();

    // Load detection parameters from config
    detector_.setMatFeatures(2000);

    matcher_ = DescriptorMatcher::create("BruteForce-Hamming");
}

cv::Mat FeatureMatcher::process(const cv::Mat frame_src, const cv::Mat frame_dst)
{
    cv::Mat descriptor_src = extract_features(frame_src);
    cv::Mat descriptor_dst = extract_features(frame_dst);

    match_features(descriptor_src, descriptor_dst);
}

cv::Mat FeatureMatcher::extract_features(const cv::Mat frame)
{
    std::vector<cv::KeyPoint> keypoint;
    cv::Mat descriptor;

    detector->detectAndCompute(frame, cv::noArray(), keypoint, descriptor);

    return descrptor;
}

void FeatureMatcher::match_features(const cv::Mat descriptor_src, const cv::Mat descriptor_dst)
{
}
} // namespace shslam