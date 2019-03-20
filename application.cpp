//
// Created by brani on 20.3.19.
//

#include "application.h"


void Application::run() {
    initialize();
    //pickMethodGui();
}

Application::Application() {
    methodPicker = std::vector<bool>(3, false);
}

