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
}

void SegmentByPolygonFit::deleteLastPoint()
{
	segmentedPoints.pop_back();
}
