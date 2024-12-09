#ifndef KARESZ_H
#define KARESZ_H
#include <string>
#include "raylib.h"

typedef struct kareszprop{
    int x;
    int y;
    int headto;
    bool pen;
    bool didteleport;
    Texture2D texture;
}kareszprop;

extern kareszprop karesz;

void KareszInit();
void MoveKaresz(int x, int y);

#endif