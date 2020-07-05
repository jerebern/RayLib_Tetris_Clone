#include "Player.h"

void Player::Move_Piece(Piece* current_piece)
{
	if (IsKeyDown(KEY_A)) current_piece->MoveLeftAndRight(-32);
	if (IsKeyDown(KEY_D)) current_piece->MoveLeftAndRight(32);

}
