#ifndef MOVES_H
#define MOVES_H

struct Pozicíó_t{
    int x;
    int y;
};

void Teleport(int x, int y, int heading);
void Előre(int n);
void Hátra(int in);
void Fordulj(int n);
void Jobbra(int n);
void Balra(int n);
void Ív(double degree, double r);
void Tollatfel();
void Tollatle();
void Frissíts(bool should);
Pozicíó_t Pozicíó();
void Kitölt();

#endif