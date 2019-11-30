//
// Created by brani on 30.11.19.
//

#ifndef MANUAL_SEGMENTATION_TOOL_CATEGORIES_H
#define MANUAL_SEGMENTATION_TOOL_CATEGORIES_H

#include <fstream>
#include <vector>
#include <string>


class Category{
    void load(const std::string& file_name);
    std::vector<std::string> categories;
};


#endif //MANUAL_SEGMENTATION_TOOL_CATEGORIES_H
