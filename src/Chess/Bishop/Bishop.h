//
// Created by Bella on 12/4/2024.
//

#ifndef BISHOP_H
#define BISHOP_H

#include "../Chess.h"

class Bishop : public Chess {
    Bishop(Position startPos, bool isPlayerPiece);
    std::vector<Position> GetValidMoves() override;
    bool CanMove(Position newPos) override;
};



#endif //BISHOP_H
