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

Wall::~Wall()
{
	if (this->sprite != nullptr)
		destroySprite(this->sprite);
	delete healthController;
	healthController = nullptr;
}

const char* Wall::getSpriteFilePath()
{
	return wallFilePath;
}

HealthController* Wall::getHealthController()
{
	return this->healthController;
}
