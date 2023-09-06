//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_LOGGER_H
#define UKLADANKA_LOGGER_H

#include "../bl/files-operations/FileHandler.h"

class Logger {
public:
    static bool open();

    static void log(const std::string&);

    static void close();

private:
    static bl::FileHandler fileHandler;

    static constexpr const char* LOG_FILE_NAME = "last.log";
};


#endif //UKLADANKA_LOGGER_H
