//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_FILEHANDLER_H
#define UKLADANKA_FILEHANDLER_H

#include <fstream>
#include <vector>

namespace bl {
    using Lines = std::vector<std::string>;

    class FileHandler {
    public:
        bool open(const std::string&, std::ios_base::openmode);

        void write(const std::string&);

        Lines readLines();

        void close();

    private:
        std::fstream file;
    };
} // bl

#endif //UKLADANKA_FILEHANDLER_H
