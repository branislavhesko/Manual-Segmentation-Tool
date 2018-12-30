#include "pch.h"
#include "SegmentByPolygonFit.h"


SegmentByPolygonFit::SegmentByPolygonFit()
{
}


SegmentByPolygonFit::~SegmentByPolygonFit()
{
}

void SegmentByPolygonFit::run(ImageProcessing & im)
{
	this->im = im;
	cv::namedWindow("SKUSKA");
	while (true) {
		drawPolygon();
		cv::imshow("SKUSKA", im.getComposedFrame());
		if (cv::waitKey(27) == 27) {
			break;
		}
		cv::setMouseCallback("SKUSKA", polygonSegmentationMouseControl, &segmentedPoints);
	}
	im.addPolygonToSegmentationMask(segmentedPoints);
	im.composeImage();
	cv::imshow("SKUSKA", im.getComposedFrame());
	cv::waitKey(10000);
}

void SegmentByPolygonFit::deleteLastPoint()
{
	segmentedPoints.pop_back();
}

void SegmentByPolygonFit::drawPolygon()
{
	if (segmentedPoints.size() < 2) {
		return;
	}
	int height = im.getSegmentationMask().rows;
	int width = im.getSegmentationMask().cols;
	for (int i = 1; i < segmentedPoints.size(); i++) {
		cv::line(im.getComposedFrame(), segmentedPoints[i], segmentedPoints[i - 1], cv::Scalar(0, 0, 255), 3);
		cv::line(im.getComposedFrame(), segmentedPoints[i] + cv::Point(width, 0), 
			segmentedPoints[i - 1] + cv::Point(width, 0), cv::Scalar(0, 0, 255), 3);
		cv::line(im.getComposedFrame(), segmentedPoints[i] + cv::Point(width, height), 
			segmentedPoints[i - 1] + cv::Point(width, height), cv::Scalar(0, 0, 255), 3);
		cv::line(im.getComposedFrame(), segmentedPoints[i] + cv::Point(0, height), 
			segmentedPoints[i - 1] + cv::Point(0, height), cv::Scalar(0, 0, 255), 3);
	}
}


