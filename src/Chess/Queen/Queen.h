//
// Created by Bella on 12/4/2024.
//

#ifndef QUEEN_H
#define QUEEN_H

#include "../Chess.h"

class Queen : public Chess {
    Queen(Position startPos, bool isPlayerPiece);
    std::vector<Position> GetValidMoves() override;
    bool CanMove(Position newPos) override;
};



#endif //QUEEN_H
