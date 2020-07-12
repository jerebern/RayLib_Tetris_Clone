#include "DrawGame.h"

DrawGame::DrawGame()
{


}

void DrawGame::DrawUI()
{	
	DrawRectangle(0, 0, PlayField_Min_X, 768,PURPLE);
	DrawRectangle(PlayField_Max_X, 0, 1024,768, PURPLE);



}

void DrawGame::DrawCurrentParts(Piece * piece)
{
	for(int i =0 ; i < 4; i++)
	DrawRectangleRec(piece->GetPart(i), piece->GetColor());
}

void DrawGame::DrawGameField(Rectangle Rect)
{
	DrawRectangleRec(Rect, BROWN);
	

}

