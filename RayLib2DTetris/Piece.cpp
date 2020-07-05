#include "Piece.h"
#include <stdio.h>

Piece::Piece()
{
}

Piece::Piece(int rnd)
{

	// REF https://qph.fs.quoracdn.net/main-qimg-bf707b034d64c955a8f5c1f89d7000aa
	switch (rnd)
	{
	case 0:
		//O - Block
		color = YELLOW;

		part[0].x = 512;
		part[0].y = 24;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 544;
		part[1].y = 24;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 512;
		part[2].y = 56;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 544;
		part[3].y = 56;
		part[3].width = 32;
		part[3].height = 32;

		break;
	case 1:
		//L - Block
		color = SKYBLUE;

		part[0].x = 512;
		part[0].y = 56;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 544;
		part[1].y = 56;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 576;
		part[2].y = 56;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 608;
		part[3].y = 56;
		part[3].width = 32;
		part[3].height = 32;


		break;
	case 2:
		// J - Block

		color = BLUE;

		part[0].x = 512;
		part[0].y = 24;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 512;
		part[1].y = 56;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 544;
		part[2].y = 56;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 576;
		part[3].y = 56;
		part[3].width = 32;
		part[3].height = 32;


		break;

	case 3:

		// L - Block
		color = ORANGE;

		part[0].x = 576;
		part[0].y = 24;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 576;
		part[1].y = 56;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 544;
		part[2].y = 56;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 512;
		part[3].y = 56;
		part[3].width = 32;
		part[3].height = 32;


		break;

	case 4:
		// S - Block
		color = GREEN;

		part[0].x = 512;
		part[0].y = 56;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 544;
		part[1].y = 56;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 544;
		part[2].y = 24;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 576;
		part[3].y = 24;
		part[3].width = 32;
		part[3].height = 32;

		break;

	case 5 :
		// Z  - Block
		color = RED;

		part[0].x = 512;
		part[0].y = 24;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 544;
		part[1].y = 24;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 544;
		part[2].y = 56;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 576;
		part[3].y = 56;
		part[3].width = 32;
		part[3].height = 32;

		break;
	case 6 : 
		//T - Block
		color = DARKPURPLE;

		part[0].x = 512;
		part[0].y = 56;
		part[0].width = 32;
		part[0].height = 32;

		part[1].x = 544;
		part[1].y = 56;
		part[1].width = 32;
		part[1].height = 32;

		part[2].x = 544;
		part[2].y = 24;
		part[2].width = 32;
		part[2].height = 32;

		part[3].x = 576;
		part[3].y = 56;
		part[3].width = 32;
		part[3].height = 32;
		break;
	default:
		break;
	}

}

Rectangle Piece::GetPart(int partnb)
{
	return part[partnb];
}

Color Piece::GetColor()
{
	return color;
}

void Piece::Print_Pos()
{
	for (int i = 0; i < 4; i++) {

		printf("Part %i X : %f Y: %f \n", i , part[i].x , part[i].y);

	}

}

void Piece::MoveLeftAndRight(int Direction)
{
	
	for (int i = 0; i < 4; i++) {
		part[i].x = part[i].x + Direction;
	}

}

void Piece::Gravity()
{
	for (int i = 0; i < 4; i++) {
		part[i].y = part[i].y + 32;
	}


}
