//
// Created by Bella on 12/4/2024.
//

#include "King.h"

#include <stdlib.h>

King::King(Position startPos, bool isPlayerPiece)
    : Chess(startPos, PieceType::KING, isPlayerPiece) {}

std::vector<Position> King::GetValidMoves() {
    std::vector<Position> moves;
    const int directions[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},           {0,1},
        {1,-1},  {1,0},  {1,1}
    };

    for (auto& dir : directions) {
        Position newPos = {_pos.row + dir[0], _pos.col + dir[1]};
        if (CanMove(newPos)) {
            moves.push_back(newPos);
        }
    }
    return moves;
}

bool King::CanMove(Position newPos) {
    int rowDiff = abs(newPos.row - _pos.row);
    int colDiff = abs(newPos.col - _pos.col);
    return rowDiff <= 1 && colDiff <= 1;
}