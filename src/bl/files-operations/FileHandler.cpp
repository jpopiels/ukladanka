//
// Created by pc on 06.09.2023.
//

#include "FileHandler.h"

using namespace bl;

bool FileHandler::open(const std::string &fileName, std::ios_base::openmode mode) {
    file.open(fileName, mode);

    return file.is_open();
}

void FileHandler::write(const std::string &buffer) {
    file.write(buffer.c_str(), static_cast<std::streamsize>(buffer.size()));
}

std::vector<std::string> FileHandler::readLines() {
    auto result = std::vector<std::string>();

    while(!file.eof()) {
        auto str = std::string();
        getline(file, str);
        result.emplace_back(str);
    }

    return result;
}

void FileHandler::close() {
    if (file.is_open())
        file.close();
}
