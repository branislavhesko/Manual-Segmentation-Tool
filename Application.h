#pragma once

#include "opencv2/opencv.hpp"

#include "ImageProcessing.h"

class Application
{
public:
	Application();
	~Application();
	cv::Mat run(const cv::Mat processedImage);

private:
	const cv::Size WINDOWSIZE = cv::Size(200, 800);

};

