//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_WRITER_H
#define UKLADANKA_WRITER_H

#include "../OpenDoClose.h"

namespace bl {
    class Writer : public OpenDoClose {
    public:
        Writer(const std::string &_fileName, std::ios_base::openmode _mode, const std::string &_buffer);

    private:
        void act() final;

        const std::string& buffer;
    };
} // bl

#endif //UKLADANKA_WRITER_H
