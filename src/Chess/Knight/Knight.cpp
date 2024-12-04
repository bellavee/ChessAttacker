//
// Created by Bella on 12/4/2024.
//

#include "Knight.h"

Knight::Knight(Position startPos, bool isPlayerPiece)
    : Chess(startPos, PieceType::KNIGHT, isPlayerPiece) {}

std::vector<Position> Knight::GetValidMoves() {
    std::vector<Position> moves;
    const int dirs[8][2] = {
        {-2,-1}, {-2,1}, {-1,-2}, {-1,2},
        {1,-2}, {1,2}, {2,-1}, {2,1}
    };

    for (auto& dir : dirs) {
        Position newPos = {_pos.row + dir[0], _pos.col + dir[1]};
        if (CanMove(newPos)) moves.push_back(newPos);
    }
    return moves;
}

bool Knight::CanMove(Position newPos) {
    return newPos.row >= 0 && newPos.col >= 0 &&
           newPos.row < 20 && newPos.col < 20;
}