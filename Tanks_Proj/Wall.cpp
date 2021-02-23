#include "Wall.h"
#include "HealthController.h"

Wall::Wall(int posX, int posY, const char* wallFilePath, int beginHealth)
{
	this->posX = posX * 32;
	this->posY = posY * 32;
	this->wallFilePath = wallFilePath;
	this->setSprite(wallFilePath);
	this->healthController = new HealthController(beginHealth);
}

const char* Wall::getSpriteFilePath()
{
	return wallFilePath;
}