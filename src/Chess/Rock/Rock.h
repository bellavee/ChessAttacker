//
// Created by Bella on 12/4/2024.
//

#ifndef ROCK_H
#define ROCK_H

#include "../Chess.h"

class Rook : public Chess {
public:
    Rook(Position startPos, bool isPlayerPiece);
    std::vector<Position> GetValidMoves() override;
    bool CanMove(Position newPos) override;
};


#endif //ROCK_H
