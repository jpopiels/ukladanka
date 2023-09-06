//
// Created by pc on 06.09.2023.
//

#include "LogLine.h"

#include <iomanip>
#include <ctime>
#include <sstream>

void LogLine::operator<<(const std::string &str) const {
    const auto fullMessage = getCurrentDateAndTime() + ' ' + str;
    Logger::log(fullMessage);
}

std::string LogLine::getCurrentDateAndTime() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "[%d-%m-%Y %H-%M-%S]");

    return oss.str();
}
