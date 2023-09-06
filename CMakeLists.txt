cmake_minimum_required(VERSION 3.26)
project(ukladanka)

set(CMAKE_CXX_STANDARD 20)

add_executable(ukladanka)

target_sources(ukladanka
    PUBLIC
        src/main.cpp
        src/AppMain.cpp
        src/AppMain.h
        src/Reactor.cpp
        src/Reactor.h

        src/bl/files-operations/FileHandler.cpp
        src/bl/files-operations/FileHandler.h
        src/logger/Logger.cpp
        src/logger/Logger.h
        src/logger/LogLine.cpp
        src/logger/LogLine.h
)
