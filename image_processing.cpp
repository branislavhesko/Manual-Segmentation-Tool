#include "image_processing.h"


void ImageProcessing::setImage(const cv::Mat & frame)
{
	this->originalFrame = frame;
	cv::resize(frame, this->resizedFrame,
               cv::Size(SEGMENTATION_WINDOW_SIZE.width / 2, SEGMENTATION_WINDOW_SIZE.height / 2));
	// cv::threshold(resizedFrame, segmentation_mask_, 100, 255, cv::THRESH_BINARY);
	segmentation_mask_ = cv::Mat(cv::Size(SEGMENTATION_WINDOW_SIZE.width / 2,
			SEGMENTATION_WINDOW_SIZE.height / 2), CV_8UC3, cv::Scalar(0.));
	composedFrame = cv::Mat(SEGMENTATION_WINDOW_SIZE, CV_8UC3);
	composeImage();

}

ImageQuadrant ImageProcessing::calculateQuadrant(unsigned int x, unsigned int y)
{
	if (x < SEGMENTATION_WINDOW_SIZE.width & x > SEGMENTATION_WINDOW_SIZE.width / 2) {
		if (y < SEGMENTATION_WINDOW_SIZE.height & y > SEGMENTATION_WINDOW_SIZE.height / 2) {
			return ImageQuadrant::FORTH;
		}
		else {
			return ImageQuadrant::FIRST;
		}
	}
	else {
		if (y < SEGMENTATION_WINDOW_SIZE.height & y > SEGMENTATION_WINDOW_SIZE.height / 2) {
			return ImageQuadrant::THIRD;
		}
		else {
			return ImageQuadrant::SECOND;
		}
	}
	return ImageQuadrant::NONE;
}

void ImageProcessing::addPolygonToSegmentationMask(std::vector<cv::Point>& points)
{
	if (points.size() <= 1) {
		return;
	}
    std::cout << "Actual category " << actual_category << std::endl;
    cv::fillConvexPoly(segmentation_mask_, points, COLORS[actual_category]);
}

void ImageProcessing::composeImage()
{
	resizedFrame.copyTo(composedFrame(cv::Rect(0, 0, resizedFrame.cols, resizedFrame.rows)));
	segmentation_mask_.copyTo(composedFrame(cv::Rect(resizedFrame.cols, 0, resizedFrame.cols, resizedFrame.rows)));
	mergeImageAndMask().copyTo(composedFrame(cv::Rect(0, resizedFrame.rows, resizedFrame.cols, resizedFrame.rows)));
	maskImageByMask().copyTo(composedFrame(cv::Rect(resizedFrame.cols, resizedFrame.rows, resizedFrame.cols, resizedFrame.rows)));
}

cv::Mat ImageProcessing::mergeImageAndMask()
{
	std::vector<cv::Mat> channels(3);
	std::vector<cv::Mat> maskChannels(3);
	cv::split(resizedFrame, channels);
	cv::split(segmentation_mask_, maskChannels);
	cv::Mat segmentation_mask_gray;
    cv::cvtColor(segmentation_mask_, segmentation_mask_gray, cv::COLOR_RGB2GRAY);
    cv::threshold(segmentation_mask_gray, segmentation_mask_gray, 1, 255, cv::THRESH_BINARY_INV);
	cv::bitwise_and(channels[0], maskChannels[0], channels[0]);
	cv::bitwise_and(channels[1], maskChannels[1], channels[1]);
	cv::bitwise_and(channels[2], maskChannels[2], channels[2]);
	cv::Mat image;
	cv::merge(channels, image);
	cv::merge(std::vector<cv::Mat>{segmentation_mask_gray,
                                segmentation_mask_gray, segmentation_mask_gray}, segmentation_mask_gray);
	cv::Mat output;
	resizedFrame.copyTo(output);
	cv::bitwise_and(segmentation_mask_gray, output, output);
	cv::bitwise_or(output, image, output);
	return output;
}

cv::Mat ImageProcessing::maskImageByMask()
{
	std::vector<cv::Mat> channels(3);
	cv::Mat mask;
	cv::cvtColor(segmentation_mask_, mask, cv::COLOR_RGB2GRAY);
	cv::threshold(mask, mask, 1, 255, cv::THRESH_BINARY_INV);
	cv::split(resizedFrame, channels);
	cv::bitwise_and(channels[0], mask, channels[0]);
	cv::bitwise_and(channels[1], mask, channels[1]);
	cv::bitwise_and(channels[2], mask, channels[2]);
	cv::Mat image;
	cv::merge(channels, image);
	return image;
}

const cv::Size &ImageProcessing::getSEGMENTATION_WINDOW_SIZE() const {
	return SEGMENTATION_WINDOW_SIZE;
}

ImageQuadrant ImageProcessing::calculateQuadrant(cv::Point &point) {
	return calculateQuadrant((unsigned int) point.x, (unsigned int) point.y);
}

void ImageProcessing::setActualCategory(unsigned int actualCategory) {
    actual_category = actualCategory;
}
