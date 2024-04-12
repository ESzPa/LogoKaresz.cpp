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

void WinDraw();

int main(){
    InitWindow(window.width, window.height, window.name.c_str());
    SetTargetFPS(30);
    KareszInit();

    WinDraw();

    CloseWindow();
}


