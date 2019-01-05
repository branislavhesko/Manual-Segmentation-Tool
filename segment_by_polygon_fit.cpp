#include "pch.h"
#include "segment_by_polygon_fit.h"


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
		cv::setMouseCallback("SKUSKA", polygonSegmentationMouseControl, &segmented_points);
	}
	im.addPolygonToSegmentationMask(segmented_points);
	im.composeImage();
	cv::imshow("SKUSKA", im.getComposedFrame());
	cv::waitKey(10000);
}

void SegmentByPolygonFit::deleteLastPoint()
{
	segmented_points.pop_back();
}

void SegmentByPolygonFit::drawPolygon()
{
	if (segmented_points.size() < 2) {
		return;
	}
	int height = im.getSegmentationMask().rows;
	int width = im.getSegmentationMask().cols;
	for (int i = 1; i < segmented_points.size(); i++) {
		cv::line(im.getComposedFrame(), segmented_points[i], segmented_points[i - 1], cv::Scalar(0, 0, 255), 3);
		cv::line(im.getComposedFrame(), segmented_points[i] + cv::Point(width, 0), 
			segmented_points[i - 1] + cv::Point(width, 0), cv::Scalar(0, 0, 255), 3);
		cv::line(im.getComposedFrame(), segmented_points[i] + cv::Point(width, height), 
			segmented_points[i - 1] + cv::Point(width, height), cv::Scalar(0, 0, 255), 3);
		cv::line(im.getComposedFrame(), segmented_points[i] + cv::Point(0, height), 
			segmented_points[i - 1] + cv::Point(0, height), cv::Scalar(0, 0, 255), 3);
	}
}


