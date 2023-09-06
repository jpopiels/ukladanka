//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_GAMESTATE_H
#define UKLADANKA_GAMESTATE_H

#include "../Defines.h"

#include <vector>

class GameState {
public:
    //todo timer
    std::size_t numOfMoves;
    std::size_t sideSize;
    std::vector<BoardType> values;
};

#endif //UKLADANKA_GAMESTATE_H
