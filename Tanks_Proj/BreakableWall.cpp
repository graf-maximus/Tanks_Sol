#include "BreakableWall.h"

BreakableWall::BreakableWall(int posX, int posY)
{
	this->posX = posX * 32;
	this->posY = posY * 32;
	this->currentSpeed = 0;
	this->posXFile = posX;
	this->posYFile = posY;
	this->breakableWall = true;
}

void BreakableWall::setSprite()
{
	this->sprite = createSprite(this->wallFilePath);
}
