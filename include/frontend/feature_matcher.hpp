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
    FeatureMatcher(cv::Ptr<cv::Features2D> _detector);
    ~FeatureMatcher();

    cv::Mat process(const cv::Mat frame);
private:
    cv::Mat extract_features(const cv::Mat frame);
    cv::Mat match_features(const cv::Mat frame_src, const cv::Mat frame_dst);

    cv::Ptr<cv::Features2D> detector;
    cv::Mat first_frame;
    cv::Mat first_descriptor;
    std::vector<cv::KeyPoint> first_keypoint;
};
} // namespace shslam

#endif