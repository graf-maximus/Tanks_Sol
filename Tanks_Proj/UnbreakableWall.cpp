#include "UnbreakableWall.h"
#include <iostream>

UnbreakableWall::UnbreakableWall(int posX, int posY)
{
	this->posX = posX * 32;
	this->posY = posY * 32;
	this->currentSpeed = 0;
	this->breakableWall = false;
}

void UnbreakableWall::setSprite()
{
	this->sprite = createSprite(this->wallFilePath);
}