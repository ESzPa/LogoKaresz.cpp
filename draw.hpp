#ifndef DRAW_HPP
#define DRAW_HPP
#include "karesz.hpp"
#include "raylib.h"
#include <string>

void WinDraw(){
    BeginDrawing();

    ClearBackground({ 230, 230, 230, 255 });

    // Draw the map
    DrawRectangle(23, 23, 1204, 954, LIGHTGRAY);
    DrawRectangle(25, 25, 1200, 950, RAYWHITE);

    // Draw the sidebar
    DrawRectangle(1250, 25, 325, 125, GREEN);
    int fontsize = 30;
    DrawText(std::to_string(karesz.x).c_str(), 1250, 200, fontsize, BLACK);
    DrawText(std::to_string(karesz.y).c_str(), 1250, 250, fontsize, BLACK);
    DrawText(std::to_string(karesz.headto).c_str(), 1250, 300, fontsize, BLACK);

    // Draw karesz
    DrawTexture(karesz.texture, karesz.x-(karesz.texture.width/2)+25, karesz.y-(karesz.texture.height/2)+25, WHITE);

    EndDrawing();
}

#endif