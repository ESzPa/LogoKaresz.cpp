#ifndef KARESZ_HPP
#define KARESZ_HPP
#include <string>

typedef struct kareszprop{
    int x;
    int y;
    int headto;
}kareszprop;

extern kareszprop karesz;

void KareszInit();

#endif