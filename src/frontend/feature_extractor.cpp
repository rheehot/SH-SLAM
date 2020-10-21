#include "frontend/feature_extractor.hpp"

namespace shslam
{
FeatureExtractor::FeatureExtractor(cv::Ptr<cv::Features2D> _detector) : detector(_detector)
{
    // Load detection parameters from config
}

cv::Mat FeatureExtractor::extract(const cv::Mat frame)
{
    std::vector<cv::KeyPoint> keypoint;
    cv::Mat descriptor;

    detector->detectAndCompute(frame, cv::noArray(), keypoint, descriptor);
}
} // namespace shslam