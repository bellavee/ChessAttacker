//
// Created by Bella on 12/4/2024.
//

#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Chess.h"

class Knight : public Chess{
    Knight(Position startPos, bool isPlayerPiece);
    std::vector<Position> GetValidMoves() override;
    bool CanMove(Position newPos) override;
};



#endif //KNIGHT_H
