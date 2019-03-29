//
// Created by brani on 20.3.19.
//

#ifndef MANUAL_SEGMENTATION_TOOL_APPLICATION_H
#define MANUAL_SEGMENTATION_TOOL_APPLICATION_H

#include <stdexcept>
#include <vector>

#include "opencv2/opencv.hpp"
#include "imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <GL/glew.h>    // Initialize with glewInit()
#include <GLFW/glfw3.h>

class Application {

public:
    Application();
    void run();

private:
    virtual void initialize() {
        throw std::logic_error("Not implemented, please override!");
    };

protected:
    const cv::Size WINDOWSIZE = cv::Size(800, 600);
    std::vector<bool> methodPicker;
    virtual void pickMethodGui(){};
    bool createWindow();

private:
    std::string help = "Manual segmentation tool. Currenctly implemented methods: \n"
                       "\n"
                       "- by pressing the left mouse button you might depict a polygon around the object. \n"
                       "- by pressing the right mouse button you are able to continously depict object border \n"
                       "\n"
                       "For more informations, please read README.md \n"
                       "branislav.hesko@gmail.com \n"
                       "2019";
};


#endif //MANUAL_SEGMENTATION_TOOL_APPLICATION_H
