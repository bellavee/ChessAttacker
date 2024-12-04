//
// Created by Bella on 24/11/2024.
//

#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "../../include/Config.h"
#include "../Board/Board.h"

class Game {
public:
    Game();
    ~Game();

    void Init();
    void Update();
    void Draw();
    void Run();

private:
    Rectangle gameView{0, 0, Config::WINDOW_WIDTH * 0.7f, Config::WINDOW_HEIGHT};     // Left side - game view
    Rectangle previewArea{Config::WINDOW_WIDTH * 0.7f, 0, Config::WINDOW_WIDTH * 0.3f, Config::WINDOW_HEIGHT * 0.4f};  // Right top - piece preview
    Rectangle minimapArea{Config::WINDOW_WIDTH * 0.7f, Config::WINDOW_HEIGHT * 0.4f, Config::WINDOW_WIDTH * 0.3f, Config::WINDOW_HEIGHT * 0.6f};  // Right bottom - minimap

    Board* _board;
};



#endif //GAME_H
