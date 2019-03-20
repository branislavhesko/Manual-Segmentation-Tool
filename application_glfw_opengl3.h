//
// Created by brani on 20.3.19.
//

#ifndef MANUAL_SEGMENTATION_TOOL_APPLICATION_GLFW_OPENGL3_H
#define MANUAL_SEGMENTATION_TOOL_APPLICATION_GLFW_OPENGL3_H

#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl2.h"

#include <GL/glew.h>    // Initialize with glewInit()
#include <GLFW/glfw3.h>

#include "application.h"


static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


class ApplicationGlfwOpengl3 : public Application {
    void initialize() override;
};


#endif //MANUAL_SEGMENTATION_TOOL_APPLICATION_GLFW_OPENGL3_H
