//
// Created by Bella on 12/4/2024.
//

#include "Rock.h"

Rook::Rook(Position startPos, bool isPlayerPiece)
    : Chess(startPos, PieceType::ROOK, isPlayerPiece) {}

std::vector<Position> Rook::GetValidMoves() {
    std::vector<Position> moves;
    const int moveLimit = _isPlayer ? 7 : 5;
    const int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    for (auto& dir : dirs) {
        for (int i = 1; i <= moveLimit; i++) {
            Position newPos = {_pos.row + dir[0] * i, _pos.col + dir[1] * i};
            if (CanMove(newPos)) moves.push_back(newPos);
        }
    }
    return moves;
}

bool Rook::CanMove(Position newPos) {
    return newPos.row >= 0 && newPos.col >= 0 &&
           newPos.row < 20 && newPos.col < 20;
}