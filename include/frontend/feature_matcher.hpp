#ifndef FEATURE_MATCHER_HPP
#define FEATURE_MATCHER_HPP

// I'll add other feature methods to here, if possible...

#include "opencv2/opencv.hpp"
#include "opencv2/features2d.hpp"

namespace shslam
{
class FeatureMatcher
{
public:
    FeatureMatcher();
    ~FeatureMatcher();

    cv::Mat process(const cv::Mat frame_src, const cv::Mat frame_dst);

private:
    cv::Mat extract_features(const cv::Mat frame);
    void match_features(const cv::Mat descriptor_src, const cv::Mat descriptor_dst);

    cv::Ptr<ORB> detector_;
    cv::Ptr<DescriptorMatcher> matcher_;
};
} // namespace shslam

#endif