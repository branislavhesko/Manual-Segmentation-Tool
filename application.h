//
// Created by brani on 20.3.19.
//

#ifndef MANUAL_SEGMENTATION_TOOL_APPLICATION_H
#define MANUAL_SEGMENTATION_TOOL_APPLICATION_H

#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

#include "opencv2/opencv.hpp"
#include "imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <GL/glew.h>    // Initialize with glewInit()
#include <GLFW/glfw3.h>

#include "categories.h"
#include "image_processing.h"
#include "save_final_mask.h"
#include "segment_by_polygon_fit.h"


class Application {

public:
    Application();
    void run(const std::string &path);

private:
    virtual void initialize() {
        throw std::logic_error("Not implemented, please override!");
    };
    ImageProcessing img_proc;
    static std::vector<std::string> getImagesInFolder(const std::string &path);
    std::vector<bool> a_sel;

protected:
    const cv::Size WINDOWSIZE = cv::Size(320, 1080);
    Category categories;
    std::vector<bool> methodPicker;
    virtual void pickMethodGui(){};
    bool createWindow();
    SegmentByPolygonFit seg;

private:
    std::string help = "Manual segmentation tool. Currenctly implemented methods: \n"
                       "\n"
                       "- by pressing the left mouse button you might depict a polygon around the object. \n"
                       "- by pressing the right mouse button you are able to continously depict object border \n"
                       "\n"
                       "For more informations, please read README.md \n"
                       "branislav.hesko@gmail.com \n"
                       "2019";
    const std::string PATH_CATEGORY_FILE = "./categories.txt";
};


#endif //MANUAL_SEGMENTATION_TOOL_APPLICATION_H
