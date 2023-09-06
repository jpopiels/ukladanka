//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_POSITION_H
#define UKLADANKA_POSITION_H

class Position {
public:
    int row;
    int col;

    bool operator==(const Position& position) const {
        return (this->row == position.row && this->col == position.col);
    }
};

#endif //UKLADANKA_POSITION_H
