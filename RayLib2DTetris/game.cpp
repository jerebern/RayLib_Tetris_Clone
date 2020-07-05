#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <raylib.h>

#include "DrawGame.h"
#include "Piece.h"
#include "Player.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    float LastTime = GetTime();
    const int screenWidth = 1024;
    const int screenHeight = 768;

    int x = 0, y = 0;
    srand(time(0));
    InitWindow(screenWidth, screenHeight, "2D Tetris with Raylib");

    //Init Camera
    Camera2D camera = { 0 };
    camera.offset =  { screenWidth / 2, screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 5.0f;

    DrawGame drawGame;
    Player player;
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Piece* piece = new Piece(5);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
       // printf("%f \n", GetTime());
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (GetTime() > LastTime) {
          piece->Gravity();
          LastTime = GetTime() +1;

        player.Move_Piece(piece);  
        piece->Print_Pos();
        }
      
        drawGame.DrawUI();
        drawGame.DrawCurrentParts(piece);
                  
       

         EndDrawing();
   
    }


    CloseWindow();     

    return 0;
}