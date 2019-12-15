#include "segmentation_method.h"


SegmentationMethod::SegmentationMethod()
{
}


SegmentationMethod::~SegmentationMethod()
{
}

bool SegmentationMethod::isRunning() const {
    return is_running;
}

void SegmentationMethod::setIsRunning(bool isRunning) {
    is_running = isRunning;
}
