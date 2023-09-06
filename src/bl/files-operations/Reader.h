//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_READER_H
#define UKLADANKA_READER_H

#include "OpenDoClose.h"

namespace bl {
    class Reader : public OpenDoClose {
    public:
        Reader(const std::string &_fileName, std::ios_base::openmode _mode, Lines &_lines);

    private:
        void act() final;

        Lines &lines;
    };
} // bl

#endif //UKLADANKA_READER_H
