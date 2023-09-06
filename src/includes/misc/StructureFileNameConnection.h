//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_STRUCTUREFILENAMECONNECTION_H
#define UKLADANKA_STRUCTUREFILENAMECONNECTION_H

#include "../structures/Configuration.h"
#include "../structures/GameState.h"
#include "../structures/RankTable.h"

class StructureFileNameConnection {
protected:
    template<class T>
    std::string getFileName();

private:
    static constexpr const char* CONFIGURATION_FILE_NAME = "config.cfg";
    static constexpr const char* GAME_STATE_FILE_NAME = "game_state.txt";
    static constexpr const char* RANK_TABLE_FILE_NAME = "rank_table.txt";
};


#endif //UKLADANKA_STRUCTUREFILENAMECONNECTION_H
