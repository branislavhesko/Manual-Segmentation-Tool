//
// Created by brani on 27.3.19.
//
#include "save_final_mask.h"


bool SaveFinalMask::save_mask_into_file(const std::string &original_image_path, const std::string &destination_path,
                                        cv::Mat &mask) {
    std::string image_name = getBasename(original_image_path);
    fs::create_directories(fs::path(destination_path));
    return cv::imwrite(composeOutputPath(destination_path, image_name), mask);;
}

std::string SaveFinalMask::getBasename(const std::string path) {
    return fs::path(path).filename();
}

fs::path SaveFinalMask::composeOutputPath(const std::string folder_structure, const std::string image_name) {
    return fs::path(folder_structure) / image_name;
}
