#ifndef FEATURE_EXTRACTOR_HPP
#define FEATURE_EXTRACTOR_HPP

#include "opencv2/opencv.hpp"
#include "opencv2/features2d.hpp"

namespace shslam
{
class FeatureExtractor
{
public:
    FeatureExtractor(cv::Ptr<cv::Features2D> _detector);
    ~FeatureExtractor();

    cv::Mat extract(const cv::Mat frame);
private:
    cv::Ptr<cv::Features2D> detector;
    cv::Mat first_frame;
    cv::Mat first_descriptor;
    std::vector<cv::KeyPoint> first_keypoint;
};
} // namespace shslam

#endif