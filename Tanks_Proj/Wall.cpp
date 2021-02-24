#include "Wall.h"
#include "HealthController.h"

Wall::Wall(int posX, int posY, const char* wallFilePath, int beginHealth, bool isBrick)
{
	this->posX = posX * 32;
	this->posY = posY * 32;
	this->wallFilePath = wallFilePath;
	this->setSprite(wallFilePath);
	this->isBrick = isBrick;
	for (int i = 0; i < 4; i++)
		this->healthController.push_back(new HealthController(beginHealth));
}

Wall::~Wall()
{
	if (this->sprite != nullptr)
		destroySprite(this->sprite);
	healthController.clear();
}

const char* Wall::getSpriteFilePath()
{
	return wallFilePath;
}

HealthController* Wall::getHealthController(int wallNumber)
{
	if (wallNumber >= 0 && wallNumber <= 3)
		return this->healthController.at(wallNumber);
}

bool Wall::IsWallBrick()
{
	return this->isBrick;
}
