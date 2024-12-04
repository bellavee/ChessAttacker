//
// Created by Bella on 24/11/2024.
//

#ifndef CHESS_H
#define CHESS_H

#include "raylib.h"
#include <vector>
#include "../../include/Config.h"
#include "../../include/Struct.h"

enum class PieceType {
    KING, ROOK, KNIGHT, BISHOP, QUEEN, PAWN,
    ROYAL_KNIGHT, HUNTING_DOG, CANNON,
    HAULIDA, SAKARZ, MINI_TUFF,
    WITCH, ROYAL_WIZARD,
    SHIELD_GUARD, CARPENTER
};

class Chess {

public:
    Chess(Position startPos, PieceType pieceType, bool isPlayerPiece);
    virtual ~Chess();

    virtual std::vector<Position> GetValidMoves() = 0;
    virtual bool CanMove(Position newPos) = 0;
    virtual void Move(Position newPos);
    virtual void Draw(Vector2 boardPos);

    Position GetPosition() const { return _pos; }
    PieceType GetType() const { return _type; }
    bool IsPlayerPiece() const { return _isPlayer; }

protected:
    Position _pos;
    PieceType _type;
    bool _isPlayer;
    Texture2D _sprite;
    Color _color;
};



#endif //CHESS_H
