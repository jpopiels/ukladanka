//
// Created by pc on 06.09.2023.
//

#include "OpenDoClose.h"

using namespace bl;

OpenDoClose::OpenDoClose(const std::string &_fileName, std::ios_base::openmode _mode)
        : fileName(_fileName), mode(_mode) {}

FileHandler& OpenDoClose::mutableFileHandler() {
    return fileHandler;
}

bool OpenDoClose::action() {
    if (!fileHandler.open(fileName, mode))
        return false;

    act();
    fileHandler.close();
    return true;
}
