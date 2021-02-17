
#include "PlayerTank.h"

PlayerTank::PlayerTank()
{
}

void PlayerTank::setTankPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void PlayerTank::getTankPosition(int& x, int& y)
{
	x = posX;
	y = posY;
}
