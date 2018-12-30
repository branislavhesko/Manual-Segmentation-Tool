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
	void composeImage();
	ImageQuadrant calculateQuadrant(unsigned int x, unsigned int y);
	void addPolygonToSegmentationMask(std::vector<cv::Point> &points);

private:
	cv::Mat composedFrame;
	cv::Mat originalFrame;
	cv::Mat segmentationMask;
	cv::Mat resizedFrame;
	cv::Size SEGMENTATIONWINDOWSIZE = cv::Size(1600, 900);
	cv::Mat mergeImageAndMask();
	cv::Mat maskImageByMask();
};

