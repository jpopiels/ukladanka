//
// Created by pc on 06.09.2023.
//

#include "GameBoard.h"

#include <random>
#include <ranges>
#include <algorithm>

using namespace bl;

GameBoard::GameBoard(const size_t boardSideSize)
        : board(std::make_unique<Board>(boardSideSize)) {
    auto generateRandomValues = [](const auto _boardSize) {
        const auto in = std::ranges::views::iota(0, static_cast<int>(_boardSize));
        auto out = std::vector<BoardType>(in.begin(), in.end());
        auto rd = std::mt19937{std::random_device{}()};
        std::ranges::shuffle(out, rd);
        return out;
    };

    auto initializeBoardValues = [this](const auto _randoms) {
        for (auto row = 0; row < board->sideSize(); ++row) {
            for (auto col = 0; col < board->sideSize(); ++col) {
                const auto random = _randoms[board->sideSize() * row + col];
                board->set({row, col}, random);
            }
        }
    };

    const auto boardSize = board->sideSize() * board->sideSize();
    const auto randoms = generateRandomValues(boardSize);
    initializeBoardValues(randoms);
    findEmpty();
    findEmptyNeighbours();
}

GameBoard::GameBoard(std::unique_ptr<Board> loadedBoard)
        : board(std::move(loadedBoard)) {
    findEmpty();
    findEmptyNeighbours();
}

const Position &GameBoard::getNeighbour(EmptyNeighbourPosition emptyNeighbourPosition) const {
    return emptyNeighbours.at(emptyNeighbourPosition);
}

Move GameBoard::move(const Position &position) {
    if (std::ranges::none_of(emptyNeighbours, [position](const auto p) {
        return position == p.second;
    }))
        return {};

    board->swap(position, emptyPosition);
    emptyPosition = position;
    findEmptyNeighbours();

    checkGameEndCondition();

    return {position, emptyPosition};
}

bool GameBoard::isGameEnd() const {
    return gameEnd;
}

const Board& GameBoard::getBoard() const {
    return *board;
}

void GameBoard::findEmpty() {
    for (auto row = 0; row < board->sideSize(); ++row) {
        for (auto col = 0; col < board->sideSize(); ++col) {
            const auto value = board->get({row, col});

            if (value == EMPTY) {
                emptyPosition = {row, col};
                break;
            }
        }
    }
}

void GameBoard::findEmptyNeighbours() {
    static const auto neighboursOffsets = std::vector<std::pair<EmptyNeighbourPosition, Position>>{
            {EmptyNeighbourPosition::UP,    {-1, 0}},
            {EmptyNeighbourPosition::RIGHT, {0,  1}},
            {EmptyNeighbourPosition::DOWN,  {1,  0}},
            {EmptyNeighbourPosition::LEFT,  {0,  -1}}
    };

    for (const auto &offset: neighboursOffsets) {
        try {
            const auto newPosition = Position{emptyPosition.row + offset.second.row,
                                              emptyPosition.col + offset.second.col};
            board->get(newPosition);
            emptyNeighbours.emplace(offset.first, newPosition);
        }
        catch (const std::out_of_range &) {
            continue;
        }
    }
}

void GameBoard::checkGameEndCondition() {
    const auto lastIndex = board->sideSize() - 1;
    const auto isEmptyFirst = (emptyPosition.row == 0 && emptyPosition.col == 0);
    if (!isEmptyFirst && (emptyPosition.row != lastIndex || emptyPosition.col != lastIndex))
        return;


    for (int row = 0; row < board->sideSize(); ++row) {
        for (int col = 0; col < board->sideSize(); ++col) {
            auto value = BoardType{};

            if (isEmptyFirst)
                value = row * board->sideSize() + col;
            else
                value = (((row == lastIndex && col == lastIndex) ? EMPTY : row * board->sideSize() + col + 1));

            if (board->get({row, col}) != value)
                return;
        }
    }

    gameEnd = true;
}
