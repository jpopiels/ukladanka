//
// Created by pc on 06.09.2023.
//

#include "AppMain.h"

int main(int argc, char** argv) {
    AppMain appMain;
    appMain.configure();
    appMain.create(argc, argv);
    appMain.initialize();
    appMain.start();
    return 0;
}
