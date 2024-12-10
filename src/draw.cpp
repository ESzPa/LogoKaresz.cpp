#include "draw.h"
#include "karesz.h"

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
    int textsize = MeasureText("Start", 50);
    DrawText("Start", 1412-textsize/2, 62, 50, WHITE);
    DrawText(std::to_string((int)karesz.Position().x).c_str(), 1250, 200, fontsize, BLACK);
    DrawText(std::to_string((int)karesz.Position().y).c_str(), 1250, 250, fontsize, BLACK);
    DrawText(std::to_string(karesz.Heading()).c_str(), 1250, 300, fontsize, BLACK);

    for(std::vector<int> line : linescoords){
        DrawLine(line[0], line[1], line[2], line[3], BLACK);
    }

    // Draw karesz with rotation
    Rectangle sourceRec = { 0.0f, 0.0f, (float)karesz.getTexture().width, (float)karesz.getTexture().height };
    Rectangle destRec = { static_cast<float>(karesz.Position().x - (karesz.getTexture().width / 2) + 25), 
        static_cast<float>(karesz.Position().y - (karesz.getTexture().height / 2) + 25), (float)karesz.getTexture().width, (float)karesz.getTexture().height };
    Vector2 origin = { static_cast<float>(karesz.getTexture().width / 2), static_cast<float>(karesz.getTexture().height / 2) };
    DrawTexturePro(karesz.getTexture(), sourceRec, destRec, origin, karesz.Heading(), WHITE);

    EndDrawing();
}
