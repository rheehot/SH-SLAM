#include "frontend/feature_matcher.hpp"

namespace shslam
{
FeatureMatcher::FeatureMatcher()
{
    detector_ = ORB::create();

    // Load detection parameters from config
    detector_.setMaxFeatures(2000);

    matcher_ = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
}

bool FeatureMatcher::process(const cv::Mat frame_src, const cv::Mat frame_dst)
{
    cv::Mat descriptor_src = extract_features(frame_src);
    cv::Mat descriptor_dst = extract_features(frame_dst);

    std::vector<DMatch> matches = match_features(descriptor_src, descriptor_dst);

    return true;
}

cv::Mat FeatureMatcher::extract_features(const cv::Mat frame)
{
    std::vector<cv::KeyPoint> keypoint;
    cv::Mat descriptor;

    detector->detectAndCompute(frame, cv::noArray(), keypoint, descriptor);

    // [TODO] I should get keypoints!!!
    return descrptor;
}

std::vector<DMatch> FeatureMatcher::match_features(const cv::Mat descriptor_src, const cv::Mat descriptor_dst)
{
    const float ratio_threshhold = 0.7f;
    std::vector<std::vector<DMatch>> knn_matches;
    std::vector<DMatch> good_matches;

    matcher->knnMatch(descriptor_src, descriptor_dst, knn_matches, 2);

    for (size_t i = 0; i < knn_matches.size(); i++)
    {
        if (knn_matches[i][0].distance < ratio_threshhold * knn_matches[i][1].distance)
        {
            good_matches.push_back(knn_matches[i][0]);
        }
    }

    return good_matches;
}
} // namespace shslam