#include "frontend/feature_matcher.hpp"

namespace shslam
{
FeatureMatcher::FeatureMatcher(cv::Ptr<cv::Features2D> _detector) : detector(_detector)
{
    // Load detection parameters from config
}

cv::Mat FeatureMatcher::extract(const cv::Mat frame)
{
    std::vector<cv::KeyPoint> keypoint;
    cv::Mat descriptor;

    detector->detectAndCompute(frame, cv::noArray(), keypoint, descriptor);
}

cv::Mat FeatureMatcher::extract_features(const cv::Mat frame)
{
    return frame;
}

cv::Mat FeatureMatcher::match_features(const cv::Mat frame_src, const cv::Mat frame_dst)
{
    (void)frame_src;
    return frame_dst;
}
} // namespace shslam