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
	std::string windowName = "SEGMENTATION METHOD";
	cv::namedWindow(windowName);
	while (true) {
		pointQuadrantCorrecion();
		drawPolygon();
		cv::imshow(windowName, im.getComposedFrame());
		int key = cv::waitKey(10);
		if (key == 27) {
			break;
		}
		if (key == 97) {
			im.addPolygonToSegmentationMask(segmented_points);
			segmented_points.clear();
		}
		if (key == 101) {
		    if (!segmented_points.empty()) {
                segmented_points.pop_back();
            }
		}
		if (key == 100) {
			if (segmented_points.size() > 5) {
				segmented_points.erase(segmented_points.end() - 5, segmented_points.end());
			}
		}
        im.composeImage();
        cv::setMouseCallback(windowName, polygonSegmentationMouseControl, &segmented_points);
	}
	im.addPolygonToSegmentationMask(segmented_points);
	im.composeImage();
	cv::imshow(windowName, im.getComposedFrame());
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
		cv::line(im.getComposedFrame(), segmented_points[i], segmented_points[i - 1], cv::Scalar(0, 0, 255), 1);
		cv::line(im.getComposedFrame(), segmented_points[i] + cv::Point(width, 0), 
			segmented_points[i - 1] + cv::Point(width, 0), cv::Scalar(0, 0, 255), 1);
		cv::line(im.getComposedFrame(), segmented_points[i] + cv::Point(width, height), 
			segmented_points[i - 1] + cv::Point(width, height), cv::Scalar(0, 0, 255), 1);
		cv::line(im.getComposedFrame(), segmented_points[i] + cv::Point(0, height), 
			segmented_points[i - 1] + cv::Point(0, height), cv::Scalar(0, 0, 255), 1);
	}
}

void SegmentByPolygonFit::pointQuadrantCorrecion() {
	for (auto &point : segmented_points) {
		ImageQuadrant quadrant = im.calculateQuadrant(point);
		if (quadrant == ImageQuadrant::FIRST) {
			point += cv::Point(-im.getSEGMENTATION_WINDOW_SIZE().width / 2, 0);
		} else if (quadrant == ImageQuadrant::THIRD) {
			point += cv::Point(0, -im.getSEGMENTATION_WINDOW_SIZE().height / 2);
		} else if (quadrant == ImageQuadrant::FORTH) {
			point += cv::Point(-im.getSEGMENTATION_WINDOW_SIZE().width / 2, -im.getSEGMENTATION_WINDOW_SIZE().height / 2);
		}
	}
}


