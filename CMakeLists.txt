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

        src/bl/SquareBoard.h
        src/bl/GameBoard.cpp
        src/bl/GameBoard.h
        src/bl/files-operations/FileHandler.cpp
        src/bl/files-operations/FileHandler.h
        src/bl/files-operations/OpenDoClose.cpp
        src/bl/files-operations/OpenDoClose.h
        src/bl/files-operations/Splitter.cpp
        src/bl/files-operations/Splitter.h
        src/bl/files-operations/read/Reader.cpp
        src/bl/files-operations/read/Reader.h
        src/bl/files-operations/read/StructureReader.h
        src/bl/files-operations/write/StructureWriter.h
        src/bl/files-operations/write/Writer.cpp
        src/bl/files-operations/write/Writer.h

        src/includes/Defines.h
        src/includes/enumerations/EmptyNeighbourPosition.h
        src/includes/misc/StructureFileNameConnection.cpp
        src/includes/misc/StructureFileNameConnection.h
        src/includes/structures/Configuration.h
        src/includes/structures/GameState.h
        src/includes/structures/Move.h
        src/includes/structures/Position.h
        src/includes/structures/RankTable.h
        src/includes/structures/SingleRankTableRecord.h

        src/logger/Logger.cpp
        src/logger/Logger.h
        src/logger/LogLine.cpp
        src/logger/LogLine.h
)
