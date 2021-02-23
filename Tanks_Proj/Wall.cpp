#include "Wall.h"
#include <iostream>

Wall::Wall()
{
}

Wall::Wall(int posX, int posY)
{
	this->posX = posX * 32;
	this->posY = posY * 32;
	this->currentSpeed = 0;
	this->setSprite(this->wallFilePath);
}

const char* Wall::getSpriteFilePath()
{
	return this->wallFilePath;
}
