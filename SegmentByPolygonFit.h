#pragma once

#include <vector>
#include "ImageProcessing.h"

struct Point2D
{
	int x;
	int y;
	Point2D(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class SegmentByPolygonFit
{
public:
	SegmentByPolygonFit();
	~SegmentByPolygonFit();
	void run(ImageProcessing &im);

private:
	std::vector<Point2D> segmentedPoints;
	void deleteLastPoint();
};

