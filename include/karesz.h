#ifndef KARESZ_H
#define KARESZ_H
#include <raylib.h>
#include <stdexcept>
#include <cmath>
#include <memory>

#include "draw.h"

class Karesz_t{
private:
    int x;
    int y;
    int heading;
    bool pendown;
    bool teleported;
    Texture2D texture;

    void Move(int x, int y);
public:
    void Init(Vector2 pos, int startHeading, bool startPen, bool hasTeleported, const char* texture);

    bool HasTeleported() const;
    Vector2 Position() const;
    int Heading() const;
    Texture2D getTexture() const;

    void Teleport(int x, int y, int heading);
    void Forward(int n);
    void Backward(int n);
    void Turn(int n);
    void PenUp();
    void PenDown();
};

extern Karesz_t karesz;

#endif