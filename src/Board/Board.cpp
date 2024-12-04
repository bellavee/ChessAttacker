//
// Created by Bella on 12/4/2024.
//

#include "Board.h"

#include <memory>
#include <algorithm>

#include "../Chess/King/King.h"

Board::Board() : _grid(Config::BOARD_SIZE, std::vector<std::shared_ptr<Chess>>(Config::BOARD_SIZE)) {
    _position = {
        (Config::WINDOW_WIDTH * 0.7f - Config::BOARD_SIZE * Config::CELL_SIZE) / 2,
        (Config::WINDOW_HEIGHT - Config::BOARD_SIZE * Config::CELL_SIZE) / 2
    };

    Position centerPos = {Config::BOARD_SIZE/2, Config::BOARD_SIZE/2};
    _grid[centerPos.row][centerPos.col] = std::make_shared<King>(centerPos, true);
    _isDragging = false;
    InitializePieces();
}

void Board::InitializePieces() {
    // Clear existing pieces
    _grid = std::vector<std::vector<std::shared_ptr<Chess>>>(Config::BOARD_SIZE,
            std::vector<std::shared_ptr<Chess>>(Config::BOARD_SIZE));

    // Center positions
    const int centerPositions[4][2] = {
        {Config::BOARD_SIZE/2 - 1, Config::BOARD_SIZE/2 - 1},
        {Config::BOARD_SIZE/2 - 1, Config::BOARD_SIZE/2},
        {Config::BOARD_SIZE/2, Config::BOARD_SIZE/2 - 1},
        {Config::BOARD_SIZE/2, Config::BOARD_SIZE/2}
    };

    // Place king in one of center positions randomly
    int randPos = rand() % 4;
    _grid[centerPositions[randPos][0]][centerPositions[randPos][1]] =
        std::make_shared<King>(Position{centerPositions[randPos][0],
                                      centerPositions[randPos][1]}, true);
}

void Board::Update() {
    Vector2 mousePos = GetMousePosition();
    int row = (mousePos.y - _position.y) / Config::CELL_SIZE;
    int col = (mousePos.x - _position.x) / Config::CELL_SIZE;
    Position currentPos = {row, col};

    DrawText(TextFormat("Mouse: %.2f, %.2f", mousePos.x, mousePos.y), 10, 10, 20, BLACK);
    DrawText(TextFormat("Grid: %d, %d", row, col), 10, 30, 20, BLACK);
    DrawText(TextFormat("Board Pos: %.2f, %.2f", _position.x, _position.y), 10, 50, 20, BLACK);

    // Show valid moves on click
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (IsValidPosition(row, col) && _grid[row][col]) {
            _selectedPiece = _grid[row][col];
            _selectedPos = currentPos;
            _validMoves = _selectedPiece->GetValidMoves();
        }
        // Click on valid move to move piece
        else if (_selectedPiece && IsPositionInValidMoves(currentPos)) {
            _grid[_selectedPos.row][_selectedPos.col] = nullptr;
            _grid[row][col] = _selectedPiece;
            _selectedPiece->Move(currentPos);
            _selectedPiece = nullptr;
            _validMoves.clear();
        }
        // Click elsewhere to deselect
        else {
            _selectedPiece = nullptr;
            _validMoves.clear();
        }
    }

    // Just update hover state
    if (_selectedPiece && IsValidPosition(row, col)) {
        _hoveredMove = IsPositionInValidMoves(currentPos) ? currentPos : Position{-1, -1};
    }
}

void Board::Draw() {
    for (int row = 0; row < Config::BOARD_SIZE; row++) {
        for (int col = 0; col < Config::BOARD_SIZE; col++) {
            Rectangle cell = {
                _position.x + col * Config::CELL_SIZE,
                _position.y + row * Config::CELL_SIZE,
                Config::CELL_SIZE,
                Config::CELL_SIZE
            };

            Color cellColor = ((row + col) % 2 == 0) ? LIGHTGRAY : WHITE;
            Position currentPos = {row, col};

            if (IsPositionInValidMoves(currentPos)) {
                cellColor = currentPos == _hoveredMove ? GREEN : DARKGREEN;
            }

            DrawRectangleRec(cell, cellColor);
            DrawRectangleLinesEx(cell, 1, BLACK);

            if (_grid[row][col]) {
                _grid[row][col]->Draw(GetBoardPosition());
            }
        }
    }
}

Vector2 Board::GetScreenPosition(int row, int col) {
    return {_position.x + col * Config::CELL_SIZE, _position.y + row * Config::CELL_SIZE};
}

bool Board::IsValidPosition(int row, int col) {
    return row >= 0 && row < Config::BOARD_SIZE && col >= 0 && col < Config::BOARD_SIZE;
}

bool Board::IsPositionInValidMoves(Position pos) {
    return std::find(_validMoves.begin(), _validMoves.end(), pos) != _validMoves.end();
}
