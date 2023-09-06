//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_SQUAREBOARD_H
#define UKLADANKA_SQUAREBOARD_H

#include <memory>

#include "../includes/structures/Position.h"

namespace bl {
    template<class T>
    class SquareBoard {
    public:
        explicit SquareBoard(const std::size_t sideSize)
                : SIDE_SIZE(sideSize), board(std::make_unique<std::unique_ptr<T[]>[]>(sideSize)) {
            for (auto i = 0; i < SIDE_SIZE; ++i) {
                board[i] = std::make_unique<T[]>(SIDE_SIZE);
            }
        }

        void set(const Position &position, const T &value) {
            checkIndexes(position);

            board[position.row][position.col] = value;
        }

        const T &get(const Position &position) {
            checkIndexes(position);

            return board[position.row][position.col];
        }

        void swap(const Position& position1, const Position& position2) {
            checkIndexes(position1);
            checkIndexes(position2);

            std::swap(board[position1.row][position1.col], board[position2.row][position2.col]);
        }

        [[nodiscard]] std::size_t sideSize() const {
            return SIDE_SIZE;
        }

    private:
        void checkIndexes(const Position &position) {
            if (position.row < 0 || position.row >= SIDE_SIZE ||
                position.col < 0 || position.col >= SIDE_SIZE)
                throw std::out_of_range("");
        }

        std::unique_ptr<std::unique_ptr<T[]>[]> board;
        const std::size_t SIDE_SIZE;
    };
} // bl

#endif //UKLADANKA_SQUAREBOARD_H
