//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_SPLITTER_H
#define UKLADANKA_SPLITTER_H

#include <vector>
#include <string>

namespace bl {
    class Splitter {
    public:
        static std::vector<std::string> split(const std::string&, char splitter = SPLITTER);

        static const char SPLITTER = ';';
    };
} // bl

#endif //UKLADANKA_SPLITTER_H
