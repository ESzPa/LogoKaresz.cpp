#ifndef DRAW_H
#define DRAW_H
#include <raylib.h>
#include <string>
#include <vector>

#include "karesz.h"
#include "constants.h"

//extern Rectangle startbtn;

class Map_t{
private:
    int width;
    int height;
    Image image;
    Texture2D texture;
public:
    void InitMap(int width, int height);
    ~Map_t();

    bool isInBounds(int x, int y) const;
    void set(int x, int y, Color color);
    Texture2D getTexture();
    void updateTexture();
};

extern Map_t map;

void WinDraw();

#endif