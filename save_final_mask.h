//
// Created by brani on 27.3.19.
//

#ifndef MANUAL_SEGMENTATION_TOOL_SAVE_FINAL_MASK_H
#define MANUAL_SEGMENTATION_TOOL_SAVE_FINAL_MASK_H

#include <iostream>
#include <string>
#include <experimental/filesystem>
#include "opencv2/opencv.hpp"

namespace fs = std::experimental::filesystem;

class SaveFinalMask {
public:
    bool save_mask_into_file(const std::string &original_image_path,
            const std::string &destination_path, cv::Mat &mask);
    SaveFinalMask() = default;

private:
    std::string getBasename(const std::string &path);
    fs::path composeOutputPath(const std::string &folder_structure, const std::string &image_name);
};


#endif //MANUAL_SEGMENTATION_TOOL_SAVE_FINAL_MASK_H
