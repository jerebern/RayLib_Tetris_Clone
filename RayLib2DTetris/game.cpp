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
    float LastTimeUpdateGravity = GetTime();
    float LastTimeUpdatePlayerMovement = GetTime();
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
        //Apply Gravity on the piece every 1 Sec
        if (GetTime() > LastTimeUpdateGravity) {
          piece->Gravity();
          LastTimeUpdateGravity = GetTime() +1;
                    
        }
        //Prevents the player from moving too fast
        if (GetTime() > LastTimeUpdatePlayerMovement) {
            player.Move_Piece(piece);  
             piece->Print_Pos();

             LastTimeUpdatePlayerMovement = GetTime() + 0.2;
        }
      
        drawGame.DrawUI();
        drawGame.DrawCurrentParts(piece);
                  
       

         EndDrawing();
   
    }


    CloseWindow();     

    return 0;
}