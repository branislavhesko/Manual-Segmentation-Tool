#pragma once

#include <vector>
#include "image_processing.h"
#include "mouse_control_functions.h"
#include "segmentation_method.h"

class SegmentByPolygonFit : public SegmentationMethod
{
public:
	SegmentByPolygonFit();
	~SegmentByPolygonFit();
	void run(ImageProcessing & im);

private:
	std::vector<cv::Point> segmented_points;
	void deleteLastPoint();
	ImageProcessing im;
	void drawPolygon();
};

