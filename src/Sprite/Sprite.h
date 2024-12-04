//
// Created by Bella on 12/4/2024.
//

#ifndef SPRITE_H
#define SPRITE_H



class Sprite {
public:
    Sprite();
    ~Sprite();

    void LoadImage(char* filePath);
    void Draw();
    void SetPathFile();

private:
    int _width;
    int _height;

};



#endif //SPRITE_H
