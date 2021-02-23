#include "BreakableWall.h"

BreakableWall::BreakableWall()
{
}

BreakableWall::BreakableWall(int posX, int posY)
{
	this->posX = posX * 32;
	this->posY = posY * 32;
	this->currentSpeed = 0;
	this->setSprite(this->wallFilePath);
}