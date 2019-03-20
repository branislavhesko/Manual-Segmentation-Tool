//
// Created by brani on 20.3.19.
//

#ifndef MANUAL_SEGMENTATION_TOOL_APPLICATION_H
#define MANUAL_SEGMENTATION_TOOL_APPLICATION_H

#include <stdexcept>
#include <vector>

#include "imgui/imgui.h"

class Application {

public:
    Application();
    void run();

private:
    virtual void initialize() {
        throw std::logic_error("Not implemented, please override!");
    };

protected:
    std::vector<bool> methodPicker;
    virtual void pickMethodGui(){};
    bool createWindow();
};


#endif //MANUAL_SEGMENTATION_TOOL_APPLICATION_H
