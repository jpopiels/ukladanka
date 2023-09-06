//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_CONFIGURATION_H
#define UKLADANKA_CONFIGURATION_H

#include <cstdlib>

class Configuration {
public:
    std::size_t sideSize;

    static constexpr const char* SIDE_SIZE_PARAM_NAME = "SideSize";
    static const char KEY_VALUE_SPLITTER = '=';
};

#endif //UKLADANKA_CONFIGURATION_H
