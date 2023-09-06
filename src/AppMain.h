//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_APPMAIN_H
#define UKLADANKA_APPMAIN_H

#include "Reactor.h"

#include <memory>

class AppMain {
public:
    void configure();

    void create(int argc, char** argv);

    void initialize();

    void start();

private:
    std::unique_ptr<Reactor> reactor;
};

#endif //UKLADANKA_APPMAIN_H
