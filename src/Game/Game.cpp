//
// Created by Bella on 24/11/2024.
//

#include "Game.h"

Game::Game() {
}

Game::~Game() {
    CloseWindow();
}

void Game::Init() {
    InitWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::WINDOW_TITLE);
    SetTargetFPS(60);

    _board = new Board();
}

void Game::Update() {
    _board->Update();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleLinesEx(gameView, 2, BLACK);
    _board->Draw();
    DrawRectangleLinesEx(previewArea, 2, BLACK);
    DrawRectangleLinesEx(minimapArea, 2, BLACK);
    EndDrawing();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}
