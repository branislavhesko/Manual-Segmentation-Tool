#include "pch.h"
#include "image_processing.h"


ImageProcessing::ImageProcessing()
{
}


ImageProcessing::~ImageProcessing()
{
}

void ImageProcessing::setImage(const cv::Mat & originalFrame)
{
	this->originalFrame = originalFrame;
	cv::resize(originalFrame, this->resizedFrame, 
		cv::Size(SEGMENTATIONWINDOWSIZE.width / 2, SEGMENTATIONWINDOWSIZE.height / 2));
	cv::threshold(resizedFrame, segmentationMask, 100, 255, cv::THRESH_BINARY);
	composedFrame = cv::Mat(SEGMENTATIONWINDOWSIZE, CV_8UC3);
	composeImage();

}

ImageQuadrant ImageProcessing::calculateQuadrant(unsigned int x, unsigned int y)
{
	if (x < SEGMENTATIONWINDOWSIZE.width & x > SEGMENTATIONWINDOWSIZE.width / 2) {
		if (y < SEGMENTATIONWINDOWSIZE.height & y > SEGMENTATIONWINDOWSIZE.height / 2) {
			return ImageQuadrant::Forth;
		}
		else {
			return ImageQuadrant::First;
		}
	}
	else {
		if (y < SEGMENTATIONWINDOWSIZE.height & y > SEGMENTATIONWINDOWSIZE.height / 2) {
			return ImageQuadrant::Third;
		}
		else {
			return ImageQuadrant::Second;
		}
	}
	return ImageQuadrant::None;
}

void ImageProcessing::addPolygonToSegmentationMask(std::vector<cv::Point>& points)
{
	cv::fillConvexPoly(segmentationMask, points, cv::Scalar(255, 255, 255));
}

void ImageProcessing::composeImage()
{
	resizedFrame.copyTo(composedFrame(cv::Rect(0, 0, resizedFrame.cols, resizedFrame.rows)));
	segmentationMask.copyTo(composedFrame(cv::Rect(resizedFrame.cols, 0, resizedFrame.cols, resizedFrame.rows)));
	mergeImageAndMask().copyTo(composedFrame(cv::Rect(0, resizedFrame.rows, resizedFrame.cols, resizedFrame.rows)));
	maskImageByMask().copyTo(composedFrame(cv::Rect(resizedFrame.cols, resizedFrame.rows, resizedFrame.cols, resizedFrame.rows)));
}

cv::Mat ImageProcessing::mergeImageAndMask()
{
	std::vector<cv::Mat> channels(3);
	std::vector<cv::Mat> maskChannels(3);
	cv::split(resizedFrame, channels);
	cv::split(segmentationMask, maskChannels);
	cv::bitwise_not(maskChannels[0], maskChannels[0]);
	cv::bitwise_and(channels[0], maskChannels[0], channels[0]);
	cv::bitwise_and(channels[2], maskChannels[0], channels[2]);
	cv::Mat image;
	cv::merge(channels, image);
	return image;
}

cv::Mat ImageProcessing::maskImageByMask()
{
	std::vector<cv::Mat> channels(3);
	std::vector<cv::Mat> maskChannels(3);
	cv::split(resizedFrame, channels);
	cv::split(segmentationMask, maskChannels);
	cv::bitwise_not(maskChannels[0], maskChannels[0]);
	cv::bitwise_and(channels[0], maskChannels[0], channels[0]);
	cv::bitwise_and(channels[1], maskChannels[0], channels[1]);
	cv::bitwise_and(channels[2], maskChannels[0], channels[2]);
	cv::Mat image;
	cv::merge(channels, image);
	return image;
}
