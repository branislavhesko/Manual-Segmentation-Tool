//
// Created by brani on 30.11.19.
//

#include "categories.h"

void Category::load(const std::string &file_name) {
    std::ifstream file;
    file.open(file_name);
    std::string line;
    while(getline(file, line)) {
        categories.push_back(line);
    }
}
