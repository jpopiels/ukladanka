cmake_minimum_required(VERSION 3.26)
project(ukladanka)

set(CMAKE_CXX_STANDARD 20)

add_executable(ukladanka)

target_sources(ukladanka
    PUBLIC
        src/main.cpp

        src/bl/files-operations/FileHandler.cpp
        src/bl/files-operations/FileHandler.h
        src/bl/files-operations/OpenDoClose.cpp
        src/bl/files-operations/OpenDoClose.h
        src/bl/files-operations/Reader.cpp
        src/bl/files-operations/Reader.h
        src/bl/files-operations/Writer.cpp
        src/bl/files-operations/Writer.h
        src/logger/Logger.cpp
        src/logger/Logger.h
        src/logger/LogLine.cpp
        src/logger/LogLine.h
)
