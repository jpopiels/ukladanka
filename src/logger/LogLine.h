//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_LOGLINE_H
#define UKLADANKA_LOGLINE_H

#include "Logger.h"

#define LOG LogLine()

class LogLine {
public:
    void operator<<(const std::string& str) const;

private:
    static std::string getCurrentDateAndTime();
};


#endif //UKLADANKA_LOGLINE_H
