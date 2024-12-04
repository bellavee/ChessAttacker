//
// Created by Bella on 12/4/2024.
//

#ifndef KING_H
#define KING_H

#include "../Chess.h"

class King : public Chess {

public:
    King(Position startPos, bool isPlayerPiece);
    std::vector<Position> GetValidMoves() override;
    bool CanMove(Position newPos) override;


};



#endif //KING_H
