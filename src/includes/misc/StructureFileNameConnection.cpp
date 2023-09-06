//
// Created by pc on 06.09.2023.
//

#include "StructureFileNameConnection.h"

template<>
std::string StructureFileNameConnection::getFileName<Configuration>() {
    return CONFIGURATION_FILE_NAME;
}

template<>
std::string StructureFileNameConnection::getFileName<GameState>() {
    return GAME_STATE_FILE_NAME;
}

template<>
std::string StructureFileNameConnection::getFileName<RankTable>() {
    return RANK_TABLE_FILE_NAME;
}
