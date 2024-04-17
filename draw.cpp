#include "karesz.hpp"
#include "raylib.h"
#include <string>
#include <vector>

std::vector<std::vector<int>> linescoords;

void WinDraw(){
    BeginDrawing();

    ClearBackground({ 230, 230, 230, 255 });

    // Draw the map
    DrawRectangle(23, 23, 1204, 954, LIGHTGRAY);
    DrawRectangle(25, 25, 1200, 950, RAYWHITE);

    // Draw the sidebar
    DrawRectangle(1250, 25, 325, 125, GREEN);
    int fontsize = 30;
    DrawText(std::to_string(karesz.x).c_str(), 1250, 200, fontsize, BLACK);
    DrawText(std::to_string(karesz.y).c_str(), 1250, 250, fontsize, BLACK);
    DrawText(std::to_string(karesz.headto).c_str(), 1250, 300, fontsize, BLACK);

    for(std::vector<int> line : linescoords){
        DrawLine(line[0], line[1], line[2], line[3], BLACK);
    }

    // Draw karesz with rotation
    Rectangle sourceRec = { 0.0f, 0.0f, (float)karesz.texture.width, (float)karesz.texture.height };
    Rectangle destRec = { karesz.x - (karesz.texture.width / 2) + 25, karesz.y - (karesz.texture.height / 2) + 25,
                          (float)karesz.texture.width, (float)karesz.texture.height };
    Vector2 origin = { karesz.texture.width / 2, karesz.texture.height / 2 };
    DrawTexturePro(karesz.texture, sourceRec, destRec, origin, karesz.headto, WHITE);

    EndDrawing();
}
