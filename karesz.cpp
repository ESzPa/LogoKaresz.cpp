#include "karesz.hpp"
#include "draw.hpp"
#include <string>
#include <cmath>

//util
int MathSign(int n){
    if(n > 0){ return 1; }
    if(n < 0){ return -1; }
    return 0;
}

kareszprop karesz;

// X: 1175
// Y: 925
void KareszInit(){
    Image texture = LoadImage("resources/karesz.png");
    ImageResize(&texture, 35, 35);
    karesz = {580, 480, 0, true, false};
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

void Teleport(int x, int y, int dir){
    if(karesz.didteleport){
        return;
    }
    karesz.x = x;
    karesz.y = y;
    karesz.headto = dir;
    WinDraw();
}

void Előre(int n){
    int oldx = karesz.x;
    int oldy = karesz.y;
    float angleRad = (90 - karesz.headto) * PI / 180.0;
    float dx = std::cos(angleRad) * n;
    float dy = std::sin(angleRad) * n; 
    karesz.x += static_cast<int>(dx); 
    karesz.y -= static_cast<int>(dy);
    if(karesz.pen){
        std::vector<int> _;
        _.push_back(oldx);
        _.push_back(oldy);
        _.push_back(karesz.x);
        _.push_back(karesz.y);
        linescoords.push_back(_);
    }
    WinDraw();
}

void Hátra(int n){
    Előre(-n);
}

void Fordulj(int n){
    if(karesz.headto + n > 360){
        karesz.headto += n - 360;
    }
    else if(karesz.headto + n < 0){
        karesz.headto += n + 360;
    }
    else{
        karesz.headto += n;
    }
    WinDraw();
}

void Jobbra(int n){
    Fordulj(n);
}

void Balra(int n){
    Fordulj(-n);
}

//from the original logokaresz
void Ív(double degree, double r){
    int unit = MathSign(degree);
    double a = 2 * r * std::tan(PI / 360);
    Előre(a / 2);
    for (int i = 0; i < std::abs(degree) - 1; i++)
    {
        Jobbra(unit);
        Előre(a);
    }
    Jobbra(unit);
    Előre(a / 2);
}

void Tollatfel(){
    karesz.pen = false;
}

void Tollatle(){
    karesz.pen = true;
}