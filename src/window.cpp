#include "feladat.h"
#include "karesz.h"
#include "draw.h"
#include "constants.h"
#include <raylib.h>
#include <memory>

Rectangle startbtn = {1250, 25, 325, 125};

int main(){
    InitWindow(windowWidth, windowHeight, windowName);
    SetTargetFPS(120);
    // X: 1175
    // Y: 925
    karesz.Init({600, 475}, 0, true, false, "../assets/karesz.png");

    while(!CheckCollisionPointRec(GetMousePosition(), startbtn) && !IsMouseButtonPressed(KEY_LEFT)){
        WinDraw();
    }
    Feladat();

    while (!WindowShouldClose()){
        WinDraw();
    }
    
    CloseWindow();
}


