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
	ImageQuadrant calculateQuadrant(unsigned int x, unsigned int y);
private:
	cv::Mat composedFrame;
	cv::Mat originalFrame;
	cv::Mat segmentationMask;
	cv::Mat resizedFrame;
	const cv::Size SEGMENTATIONWINDOWSIZE = cv::Size(1200, 800);
	void composeImage();
	cv::Mat mergeImageAndMask();
	cv::Mat maskImageByMask();
};

