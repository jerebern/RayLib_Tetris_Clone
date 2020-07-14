#pragma once
#include "raylib.h"
class Piece
{
private :
    Rectangle part[4]; // il y a 4 partie dans une piece 
    Color color;
public:

        Piece();
        Piece(int);
        Rectangle GetPart(int);
        Color GetColor();
        void Print_Pos();
        void MoveLeftAndRight(int);
        int Gravity(int);
        void Rotate();

};

