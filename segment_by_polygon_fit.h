#pragma once

#include <vector>
#include "image_processing.h"
#include "mouse_control_functions.h"
#include "segmentation_method.h"

class SegmentByPolygonFit : public SegmentationMethod
{
public:
	SegmentByPolygonFit(ImageProcessing & img_proc): im(img_proc) {};
	~SegmentByPolygonFit() override;
	void run();

private:
	std::vector<cv::Point> segmented_points;
	void deleteLastPoint();
	void pointQuadrantCorrecion();
	ImageProcessing& im;
	void drawPolygon();
};

