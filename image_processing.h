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
	ImageQuadrant calculateQuadrant(cv::Point &point);
	void addPolygonToSegmentationMask(std::vector<cv::Point> &points);

private:
	cv::Mat composedFrame;
	cv::Mat originalFrame;
	cv::Mat segmentationMask;
	cv::Mat resizedFrame;
	cv::Size SEGMENTATION_WINDOW_SIZE = cv::Size(1600, 900);
public:
	const cv::Size &getSEGMENTATION_WINDOW_SIZE() const;

private:
	cv::Mat mergeImageAndMask();
	cv::Mat maskImageByMask();
};

