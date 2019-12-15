//
// Created by brani on 20.3.19.
//

#include "application.h"


void Application::run(const std::string &path) {
    auto image_files = getImagesInFolder(path);

    for (auto& image_file: image_files) {
        initialize();
        std::cout << "Processing file: " << image_file << std::endl;
        img_proc.setImage(cv::imread(image_file));
        seg.setIsRunning(true);
        std::thread th1(&SegmentByPolygonFit::run, &seg, std::ref(img_proc));
        std::thread th2(&Application::pickMethodGui, this);
        th1.join();
        th2.join();
        SaveFinalMask::save_mask_into_file(image_file, "./result/mask", img_proc.getSegmentationMask());
    }
}

Application::Application() {
    methodPicker = std::vector<bool>(3, false);
    categories.load(PATH_CATEGORY_FILE);
    a_sel = std::vector<bool>(categories.getCategories().size(), false);
}

bool Application::createWindow() {
    ImGui::Begin("Main window");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("Please pick your manual segmentation method");               // Display some text (you can use a format strings too)

    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

    if (ImGui::Button("Method 1"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        methodPicker[0] = true;
    ImGui::SameLine();
    ImGui::Text("This method depicts object by \na polygon by clicking on \n"
                "edge points or continuously \ndepicting object by mouse movement.");


    if (ImGui::Button("Method 3"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        methodPicker[2] = true;
    ImGui::SameLine();
    ImGui::Text("This method depicts object by \npainting pixels");

    if (ImGui::Button("DONE")) {
        return false;
    }
    ImGui::End();

    ImGui::Begin("HELP");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text(help.c_str());
    ImGui::End();

    ImGui::Begin("CLASS PICKER");
    static bool sel;
    ImGui::ListBoxHeader("CLASS");
    for (unsigned  int i=0; i < categories.getCategories().size(); i++) {
        if (ImGui::Selectable(categories.getCategories()[i].c_str(), &sel)) {
            std::cout << "Setting category " << categories.getCategories()[i] << std::endl;
            img_proc.setActualCategory(i);
        }
    }
    ImGui::ListBoxFooter();
    ImGui::End();

    // ImGui::Text("application_win32 average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    return true;
}




std::vector<std::string> Application::getImagesInFolder(const std::string &path) {
    std::vector<std::string> imageFiles;
    for (auto &file : fs::directory_iterator(path))
    {
        imageFiles.push_back(file.path().string());
    }
    return imageFiles;
}