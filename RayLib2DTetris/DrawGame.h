#pragma once
#include "raylib.h"
#include "Piece.h"

#define PlayField_Max_X 736
#define PlayField_Min_X 320

class DrawGame
{
private :


public:

	DrawGame();
	void DrawUI();
	void DrawCurrentParts(Piece*);
};

