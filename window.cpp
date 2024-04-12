#include "feladat.hpp"
#include "karesz.hpp"
#include "raylib.h"
#include <string>

typedef struct window{
    const std::string name = "LogoKaresz C++";
    const int width = 1600;
    const int height = 1000;
} windowprop;

windowprop window;

void WinUpdate();
void WinDraw();

int main(){
    InitWindow(window.width, window.height, window.name.c_str());
    SetTargetFPS(30);
    KareszInit();

    while(!WindowShouldClose()){
        WinUpdate();
        WinDraw();
    }

    CloseWindow();
}

void WinUpdate(){
    if(IsKeyDown(KEY_W)){
        MoveKaresz(karesz.x, karesz.y-5);
    }
}

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
