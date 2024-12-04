//
// Created by Bella on 12/4/2024.
//

#include "Bishop.h"

Bishop::Bishop(Position startPos, bool isPlayerPiece)
    : Chess(startPos, PieceType::BISHOP, isPlayerPiece) {}

std::vector<Position> Bishop::GetValidMoves() {
    std::vector<Position> moves;
    const int moveLimit = _isPlayer ? 7 : 5;
    const int dirs[4][2] = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};

    for (auto& dir : dirs) {
        for (int i = 1; i <= moveLimit; i++) {
            Position newPos = {_pos.row + dir[0] * i, _pos.col + dir[1] * i};
            if (CanMove(newPos)) moves.push_back(newPos);
        }
    }
    return moves;
}

bool Bishop::CanMove(Position newPos) {
    return newPos.row >= 0 && newPos.col >= 0 &&
           newPos.row < 20 && newPos.col < 20;
}