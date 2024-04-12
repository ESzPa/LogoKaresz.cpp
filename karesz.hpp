#ifndef KARESZ_HPP
#define KARESZ_HPP
#include <string>
#include "raylib.h"

typedef struct kareszprop{
    int x;
    int y;
    int headto;
    Texture2D texture;
}kareszprop;

extern kareszprop karesz;

void KareszInit();
void MoveKaresz(int x, int y);

#endif