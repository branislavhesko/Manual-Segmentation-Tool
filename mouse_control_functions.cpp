#include "mouse_control_functions.h"
#include <vector>
#include "opencv2/opencv.hpp"

void polygonSegmentationMouseControl(int event, int x, int y, int flag, void * points)
{
	auto *polyPoints = static_cast<std::vector<cv::Point> *> (points);
    static bool mousePressed = false;
	if (event == cv::EVENT_LBUTTONUP) {
		polyPoints->push_back(cv::Point(x, y));
	}
	if (event == cv::EVENT_RBUTTONUP) {
        mousePressed = false;
	}

	if (event == cv::EVENT_RBUTTONDOWN) {
	    mousePressed = true;
	}

	if (event == cv::EVENT_MOUSEMOVE & mousePressed) {
        polyPoints->push_back(cv::Point(x, y));
    }

}
