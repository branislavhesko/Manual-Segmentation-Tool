#pragma once

#include <vector>
#include "ImageProcessing.h"
#include "mouseControlFunctions.h"

class SegmentByPolygonFit
{
public:
	SegmentByPolygonFit();
	~SegmentByPolygonFit();
	void run(ImageProcessing & im);

private:
	std::vector<cv::Point> segmentedPoints;
	void deleteLastPoint();
	ImageProcessing im;
	void drawPolygon();
};

