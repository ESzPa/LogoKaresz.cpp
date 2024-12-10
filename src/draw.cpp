#include "draw.h"
#include "karesz.h"

void Map_t::InitMap(int width, int height){
    this->width = width;
    this->height = height;
    this->image = GenImageColor(this->width, this->height, RAYWHITE);
    this->texture = LoadTextureFromImage(this->image);
}

Map_t::~Map_t(){
    UnloadImage(this->image);
    UnloadTexture(this->texture);
}

bool Map_t::isInBounds(int x, int y) const {
    return x >= 0 && x < this->width && y >= 0 && y < this->height;
}

void Map_t::set(int x, int y, Color color){
    if(isInBounds(x, y)){
        ImageDrawPixel(&this->image, x, y, color);
    }
    else{
        throw std::runtime_error("Pixel drawn out of bounds.");
    }
}

Texture2D Map_t::getTexture() { return this->texture; }
void Map_t::updateTexture() { UpdateTexture(this->texture, this->image.data); }

Map_t map;
bool shouldReDraw = true;

void WinDraw(){
    if(!shouldReDraw) return;
    BeginDrawing();

    ClearBackground({ 230, 230, 230, 255 });

    // Draw the map
    DrawRectangle(mapX-2, mapY-2, mapWidth+4, mapHeight+4, LIGHTGRAY);
    DrawRectangle(mapX, mapY, mapWidth, mapHeight, RAYWHITE);

    // Draw the sidebar
    DrawRectangle(1250, 25, 325, 125, GREEN);
    int fontsize = 30;
    int textsize = MeasureText("Start", 50);
    DrawText("Start", 1412-textsize/2, 62, 50, WHITE);
    DrawText(std::to_string((int)karesz.Position().x).c_str(), 1250, 200, fontsize, BLACK);
    DrawText(std::to_string((int)karesz.Position().y).c_str(), 1250, 250, fontsize, BLACK);
    DrawText(std::to_string(karesz.Heading()).c_str(), 1250, 300, fontsize, BLACK);

    map.updateTexture();
    DrawTexture(map.getTexture(), mapX, mapY, WHITE);

    // Draw karesz with rotation
    Rectangle sourceRec = { 0.0f, 0.0f, (float)karesz.getTexture().width, (float)karesz.getTexture().height };
    Rectangle destRec = { static_cast<float>(karesz.Position().x - (karesz.getTexture().width / 2) + 25), 
        static_cast<float>(karesz.Position().y - (karesz.getTexture().height / 2) + 25), (float)karesz.getTexture().width, (float)karesz.getTexture().height };
    Vector2 origin = { static_cast<float>(karesz.getTexture().width / 2), static_cast<float>(karesz.getTexture().height / 2) };
    DrawTexturePro(karesz.getTexture(), sourceRec, destRec, origin, karesz.Heading(), WHITE);

    EndDrawing();
}
