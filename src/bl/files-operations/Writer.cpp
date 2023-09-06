//
// Created by pc on 06.09.2023.
//

#include "Writer.h"

using namespace bl;

Writer::Writer(const std::string &_fileName, std::ios_base::openmode _mode, const std::string &_buffer)
        : buffer(_buffer), OpenDoClose(_fileName, _mode) {}

void Writer::act() {
    mutableFileHandler().write(buffer);
}
