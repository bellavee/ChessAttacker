//
// Created by Bella on 12/4/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>
#include "../../include/Struct.h"
#include "../../include/Config.h"

#include "raylib.h"


class Chess;

class Board {
public:
    Board();
    void InitializePieces();
    void Update();
    void Draw();
    Vector2 GetScreenPosition(int row, int col);
    bool IsValidPosition(int row, int col);
    bool IsPositionInValidMoves(Position pos);
    Vector2 GetBoardPosition() const { return _position; }

private:
    std::vector<std::vector<std::shared_ptr<Chess>>> _grid;
    Vector2 _position;
    std::shared_ptr<Chess> _selectedPiece;
    Position _selectedPos;
    bool _isDragging;

    std::vector<Position> _validMoves;
    Position _hoveredMove{-1, -1};
};



#endif //BOARD_H
