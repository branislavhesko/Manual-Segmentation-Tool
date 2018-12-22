#include "pch.h"
#include "ImageProcessing.h"


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
	//this->segmentationMask = cv::Mat(resizedFrame.size(), CV_8UC3);
	cv::threshold(resizedFrame, segmentationMask, 100, 255, CV_THRESH_BINARY);
	composedFrame = cv::Mat(SEGMENTATIONWINDOWSIZE, CV_8UC3);
	resizedFrame.copyTo(composedFrame(cv::Rect(0, 0, resizedFrame.cols, resizedFrame.rows)));
	composeImage();
	cv::imshow("SKUSKA", composedFrame);
	cv::waitKey(10000);
}

void ImageProcessing::composeImage()
{
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
