#include "PlayerTank.h"
#include "ProjectileController.h"

PlayerTank::PlayerTank(float posX, float posY)
	: Tanks(posX, posY, 1, false)
{
	this->defaultPosX = posX;
	this->defaultPosY = posY;
	this->tankRIGHTFilePath = ".\\data\\PlayerTank\\PlayerTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\PlayerTank\\PlayerTankLEFT.png";
	this->tankUPFilePath = ".\\data\\PlayerTank\\PlayerTankUP.png";
	this->tankDOWNFilePath = ".\\data\\PlayerTank\\PlayerTankDOWN.png";
}

int PlayerTank::getDefaultPosX()
{
	return this->defaultPosX;
}

int PlayerTank::getDefaultPosY()
{
	return this->defaultPosY;
}

PlayerTank::~PlayerTank()
{
	delete this->projectileController;
}
