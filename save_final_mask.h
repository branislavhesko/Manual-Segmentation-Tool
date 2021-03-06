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
    static bool save_mask_into_file(const std::string &original_image_path,
            const std::string &destination_path, cv::Mat &mask, const cv::Size& frame_size);
    SaveFinalMask() = default;

private:
    static std::string getBasename(const std::string &path);
    static fs::path composeOutputPath(const std::string &folder_structure, const std::string &image_name);
};


#endif //MANUAL_SEGMENTATION_TOOL_SAVE_FINAL_MASK_H
