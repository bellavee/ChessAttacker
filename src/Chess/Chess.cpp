//
// Created by Bella on 24/11/2024.
//

#include "Chess.h"

Chess::Chess(Position startPos, PieceType pieceType, bool isPlayerPiece)
    : _pos(startPos), _type(pieceType), _isPlayer(isPlayerPiece) {
    _color = _isPlayer ? BLUE : RED;
}

Chess::~Chess() {
    UnloadTexture(_sprite);
}

void Chess::Move(Position newPos) {
    _pos = newPos;
}

void Chess::Draw(Vector2 boardPos) {
    Rectangle dest = {
        boardPos.x + _pos.col * Config::CELL_SIZE,
        boardPos.y + _pos.row * Config::CELL_SIZE,
        Config::CELL_SIZE,
        Config::CELL_SIZE
    };

    if (_sprite.id != 0) {
        DrawTexture(_sprite, dest.x, dest.y, WHITE);
    } else {
        DrawRectangleRec(dest, _color);
    }
}