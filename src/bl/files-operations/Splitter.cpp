//
// Created by pc on 06.09.2023.
//

#include "Splitter.h"

using namespace bl;

std::vector<std::string> Splitter::split(const std::string& line, const char splitter) {
    std::vector<std::string> result;

    std::size_t begin = 0;
    std::size_t found = line.find_first_of(splitter);

    while (found != std::string::npos) {
        result.emplace_back(line.substr(begin, found));
        begin = found + 1;
        found = line.find_first_of(splitter, begin);
    }

    return result;
}
