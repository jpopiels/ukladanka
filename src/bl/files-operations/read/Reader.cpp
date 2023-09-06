//
// Created by pc on 06.09.2023.
//

#include "Reader.h"

using namespace bl;

Reader::Reader(const std::string &_fileName, std::ios_base::openmode _mode, Lines &_lines)
        : lines(_lines), OpenDoClose(_fileName, _mode) {}

void Reader::act() {
    lines = mutableFileHandler().readLines();
}
