//
// Created by Bella on 12/4/2024.
//

#ifndef STRUCT_H
#define STRUCT_H

struct Position {
    int row, col;
    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
};

#endif //STRUCT_H
