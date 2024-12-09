#include "feladat.h"
#include "karesz.h"
#include "draw.h"
#include <raylib.h>
#include <string>

typedef struct window{
    const std::string name = "LogoKaresz C++";
    const int width = 1600;
    const int height = 1000;
} windowprop;

windowprop window;

Rectangle startbtn = {1250, 25, 325, 125};

int main(){
    InitWindow(window.width, window.height, window.name.c_str());
    SetTargetFPS(120);
    KareszInit();

    while(!CheckCollisionPointRec(GetMousePosition(), startbtn) && !IsMouseButtonPressed(KEY_LEFT)){
        WinDraw();
    }
    Feladat();

    while (!WindowShouldClose())
    {
        WinDraw();
    }
    
    CloseWindow();
}

