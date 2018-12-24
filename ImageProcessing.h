#pragma once
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

enum ImageQuadrant
{
	First,
	Second,
	Third,
	Forth,
	None
};

class ImageProcessing
{
public:
	ImageProcessing();
	~ImageProcessing();
	void setImage(const cv::Mat &originalFrame);
	cv::Mat &getComposedFrame() {
		return composedFrame;
	}
	cv::Mat &getSegmentationMask() {
		return segmentationMask;
	}
	ImageQuadrant calculateQuadrant(unsigned int x, unsigned int y);
private:
	cv::Mat composedFrame;
	cv::Mat originalFrame;
	cv::Mat segmentationMask;
	cv::Mat resizedFrame;
	cv::Size SEGMENTATIONWINDOWSIZE = cv::Size(1600, 900);
	void composeImage();
	cv::Mat mergeImageAndMask();
	cv::Mat maskImageByMask();
};

