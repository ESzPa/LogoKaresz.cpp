#include "karesz.h"
#include "moves.h"

//util
int MathSign(int n){
    if(n > 0){ return 1; }
    if(n < 0){ return -1; }
    return 0;
}

void Karesz_t::Init(Vector2 pos, int startHeading, bool startPen, bool hasTeleported, const char* texture){
    this->x = pos.x;
    this->y = pos.y;
    this->heading = startHeading;
    this->pendown = startPen;
    this->teleported = hasTeleported;

    // Loading the texture
    Image tmpImg = LoadImage(texture);
    ImageResize(&tmpImg, 30, 30);
    this->texture = LoadTextureFromImage(tmpImg);
    UnloadImage(tmpImg);
}

bool Karesz_t::HasTeleported() const { return this->teleported; }

Vector2 Karesz_t::Position() const { return (Vector2){(float)this->x, (float)this->y}; }

int Karesz_t::Heading() const { return this->heading; }

Texture2D Karesz_t::getTexture() const { return this->texture; }

void Karesz_t::Move(int x, int y){
    if(x > 1200 || y > 950 || x < 25 || y < 25){
        throw std::runtime_error("Karesz has exceeded the boundaries of its allowed area.");
    }
    this->x = x;
    this->y = y;
}

void Karesz_t::Teleport(int x, int y, int heading){
    if(this->teleported){
        throw std::runtime_error("Karesz has already teleported once.");
    }
    this->Move(x, y);
    this->heading = heading;
    WinDraw();
}

void Karesz_t::Forward(int n){
    int oldX = this->x;
    int oldY = this->y;
    float rad = (90 - this->heading) * PI / 180.0;
    float dx = std::cos(rad) * n;
    float dy = std::sin(rad) * n;
    this->Move(this->x+(int)dx, this->y-(int)dy);
    if(this->pendown){
        // Bresenham's line algorithm 
        int x0 = oldX;
        int y0 = oldY;
        int x1 = this->x;
        int y1 = this->y;

        int dx = std::abs(x1 - x0);
        int dy = std::abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1; 
        int err = dx - dy;

        while (true) {
            map.set(x0, y0, BLACK); 
            if (x0 == x1 && y0 == y1) break; 

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x0 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y0 += sy;
            }
        }
    }
    WinDraw();
}

void Karesz_t::Backward(int n){
    this->Forward(-n);
}

void Karesz_t::Turn(int n){
    if(this->heading + n > 360){
        this->heading += n - 360;
    }
    else if(this->heading + n < 0){
        this->heading += n + 360;
    }
    else{
        this->heading += n;
    }
    WinDraw();
}

void Karesz_t::PenUp(){
    this->pendown = false;
}

void Karesz_t::PenDown(){
    this->pendown = true;
}

void Karesz_t::Fill(){
    Color fillColor = BLACK;
    int startX = this->x-25;
    int startY = this->y-25;
    Image tmpImg = map.getImage();
    Color targetColor = GetImageColor(tmpImg, startX, startY);

    if(fillColor.r == targetColor.r && fillColor.g == targetColor.g && fillColor.b == targetColor.b && fillColor.a == fillColor.a){
        UnloadImage(tmpImg);
        return;
    }

    std::queue<Vector2> pixels;
    pixels.push((Vector2){startX, startY});

    while (!pixels.empty()){
        Vector2 current = pixels.front();
        pixels.pop();

        int x = current.x;
        int y = current.y;
        
        if(x >= 0 && x < tmpImg.width && y >= 0 && y < tmpImg.height){
            Color currentColor = GetImageColor(tmpImg, x, y);
            if (currentColor.r == targetColor.r && currentColor.g == targetColor.g &&
                currentColor.b == targetColor.b && currentColor.a == targetColor.a) {
                ImageDrawPixel(&tmpImg, x, y, fillColor);
                pixels.push((Vector2){(float)x + 1, (float)y});
                pixels.push((Vector2){(float)x - 1, (float)y});
                pixels.push((Vector2){(float)x, (float)y + 1});
                pixels.push((Vector2){(float)x, (float)y - 1});
            }
        }
    }
    map.setImage(tmpImg);
    UnloadImage(tmpImg);
    WinDraw();
}

Karesz_t karesz;

void Teleport(int x, int y, int heading) { karesz.Teleport(x, y, heading); }
void Előre(int n) { karesz.Forward(n); }
void Hátra(int n) { karesz.Backward(n); }
void Fordulj(int n) { karesz.Turn(n); }
void Jobbra(int n) { karesz.Turn(n); }
void Balra(int n) { karesz.Turn(-n); }
void Tollatfel() { karesz.PenUp(); }
void Tollatle() { karesz.PenDown(); }
void Ív(double degree, double r){
    int unit = MathSign(degree);
    double a = 2 * r * std::tan(PI / 360);
    karesz.Forward(a / 2);
    for (int i = 0; i < std::abs(degree) - 1; i++){
        karesz.Turn(unit);
        karesz.Forward(a);
    }
    karesz.Turn(unit);
    karesz.Forward(a / 2);
}
void Frissíts(bool should){
    shouldReDraw = should;
}
Pozicíó_t Pozicíó(){
    return (Pozicíó_t){ (int)karesz.Position().x, (int)karesz.Position().y };
}
void Kitölt() { karesz.Fill(); }