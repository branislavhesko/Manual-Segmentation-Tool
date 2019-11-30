#pragma once
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

enum ImageQuadrant
{
	FIRST,
	SECOND,
	THIRD,
	FORTH,
	NONE
};


class ImageProcessing
{
public:
	ImageProcessing()= default;
	~ImageProcessing()= default;
	void setImage(const cv::Mat &frame);
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
	cv::Size get_original_image_size() {
	    return cv::Size(originalFrame.cols, originalFrame.rows);
	}

	std::vector<std::vector<unsigned>> COLORS = {{255, 255, 255}, {0, 255, 255},
                                                  {0, 0, 255}, {255, 0, 0}, {0, 255, 0}, {255, 255, 0}, {255, 0, 255}};


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

