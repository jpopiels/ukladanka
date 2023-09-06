//
// Created by pc on 06.09.2023.
//

#include "Logger.h"

bl::FileHandler Logger::fileHandler;

bool Logger::open() {
    return fileHandler.open(LOG_FILE_NAME, std::ios_base::out | std::ios_base::trunc);
}

void Logger::log(const std::string &str) {
    fileHandler.write(str);
}

void Logger::close() {
    fileHandler.close();
}
