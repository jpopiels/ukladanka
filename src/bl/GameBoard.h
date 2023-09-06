//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_GAMEBOARD_H
#define UKLADANKA_GAMEBOARD_H

#include <map>

#include "SquareBoard.h"
#include "../includes/enumerations/EmptyNeighbourPosition.h"
#include "../includes/structures/Move.h"
#include "../includes/Defines.h"

namespace bl {
    using Board = SquareBoard<BoardType>;

    class GameBoard {
    public:
        explicit GameBoard(std::size_t boardSideSize);

        explicit GameBoard(std::unique_ptr<Board> loadedBoard);

        [[nodiscard]] const Position& getNeighbour(EmptyNeighbourPosition) const;

        [[nodiscard]] Move move(const Position&);

        [[nodiscard]] bool isGameEnd() const;

        [[nodiscard]] const Board& getBoard() const;

    private:
        void findEmpty();

        void findEmptyNeighbours();

        void checkGameEndCondition();

        bool gameEnd = false;
        Position emptyPosition{};
        std::map<EmptyNeighbourPosition, Position> emptyNeighbours;
        std::unique_ptr<Board> board;

        static const BoardType EMPTY = 0;
    };
} // bl

#endif //UKLADANKA_GAMEBOARD_H
