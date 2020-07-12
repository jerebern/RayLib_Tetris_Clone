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
    int x, y;
    bool Place_Block = false;
    int Upper_Line = 0;
    int Gravity_Index;
    srand(time(0));
    InitWindow(screenWidth, screenHeight, "2D Tetris with Raylib");

    //Init Camera
    Camera2D camera = { 0 };
    camera.offset =  { screenWidth / 2, screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 5.0f;

    DrawGame drawGame;
    Player player;
    Rectangle Play_Area[13][28] = { NULL };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Piece* piece = new Piece(GetRandomValue(0,6));
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
       // printf("%f \n", GetTime());
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //Apply Gravity on the piece every 1 Sec
        if (GetTime() > LastTimeUpdateGravity) {
          
            for (int i = 0; i < 4; i++) {
                x = piece->GetPart(i).x / 32;
                y = piece->GetPart(i).y / 32;
                
                printf("X: %i ,  Y : %i \n", x, y);

                if (CheckCollisionRecs(Play_Area[x + 1][y + 1],piece->GetPart(i)) || piece->GetPart(i).y >= 730) {

                    printf("collision\n");
                    Place_Block = true;

                }
                if (Place_Block) {
                    
                    Play_Area[x/2][y/2] = piece->GetPart(i);
                    piece = new Piece(GetRandomValue(0, 6));
                    Place_Block = false;
                  }
            }


            piece->Gravity();
          LastTimeUpdateGravity = GetTime() +1;
                    
        }
        //Prevents the player from moving too fast
        if (GetTime() > LastTimeUpdatePlayerMovement) {
            player.Move_Piece(piece);  
             piece->Print_Pos();

             LastTimeUpdatePlayerMovement = GetTime() + 0.2;
        }
        //Planifier pour verifier si ligne pleine

/*        for (int i = 0; i < 0; i++) {

            for (int j = 0; j < 0; j++) {
                if(Play_Area[i][j] != NULL)

            }

        }*/
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 28; j++) {
                
                if(Play_Area != NULL)
                    drawGame.DrawGameField(Play_Area[i][j]);

            }

        }
 
        drawGame.DrawUI();
        drawGame.DrawCurrentParts(piece);
  
         EndDrawing();
   
    }


    CloseWindow();     

    return 0;
}