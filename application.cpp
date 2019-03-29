//
// Created by brani on 20.3.19.
//

#include "application.h"


void Application::run() {
    initialize();
    pickMethodGui();
}

Application::Application() {
    methodPicker = std::vector<bool>(3, false);
}

bool Application::createWindow() {
    ImGui::Begin("Main window");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("Please pick your manual segmentation method");               // Display some text (you can use a format strings too)

    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

    if (ImGui::Button("Method 1"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        methodPicker[0] = true;
    ImGui::SameLine();
    ImGui::Text("This method depicts object by a polygon by clicking on \n"
                "edge points or continuously depicting object by mouse movement.");


    if (ImGui::Button("Method 3"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        methodPicker[2] = true;
    ImGui::SameLine();
    ImGui::Text("This method depicts object by painting pixels");

    if (ImGui::Button("DONE")) {
        return false;
    }
    ImGui::End();

    ImGui::Begin("HELP");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text(help.c_str());
    ImGui::End();

    // ImGui::Text("application_win32 average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    return true;
}

