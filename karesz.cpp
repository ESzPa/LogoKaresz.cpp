#include "karesz.hpp"
#include <string>

kareszprop karesz;

// X: 1175
// Y: 925
void KareszInit(){
    Image texture = LoadImage("resources/karesz.png");
    ImageResize(&texture, 35, 35);
    karesz = {580, 480, 0};
    karesz.texture = LoadTextureFromImage(texture);
    UnloadImage(texture);
}

void MoveKaresz(int x, int y){
    int newx = x;
    int newy = y;
    if(newx > 1200 || newy > 950 || newx < 25 || newy < 25){
        return;
    }
    karesz.x = newx;
    karesz.y = newy;
}