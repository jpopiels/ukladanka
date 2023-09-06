cmake_minimum_required(VERSION 3.26)
project(ukladanka)

set(CMAKE_CXX_STANDARD 20)

add_executable(ukladanka)

target_sources(ukladanka
    PUBLIC
        src/main.cpp
)
