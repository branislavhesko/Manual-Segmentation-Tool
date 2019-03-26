//
// Created by brani on 20.3.19.
//

#include "application_glfw_opengl3.h"

void ApplicationGlfwOpengl3::initialize() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return;

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(WINDOWSIZE.width, WINDOWSIZE.height,
            "PickerMethodGui", NULL, NULL);


    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
}
