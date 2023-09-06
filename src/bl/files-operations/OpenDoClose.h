//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_OPENDOCLOSE_H
#define UKLADANKA_OPENDOCLOSE_H

#include "FileHandler.h"

namespace bl {
    class OpenDoClose {
    public:
        OpenDoClose(const std::string&, std::ios_base::openmode);

        bool action();

    protected:
        FileHandler& mutableFileHandler();

    private:
        virtual void act() = 0;

        std::string fileName;
        std::ios_base::openmode mode;

        FileHandler fileHandler;
    };
} // bl

#endif //UKLADANKA_OPENDOCLOSE_H
