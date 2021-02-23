#include "PlayerTank.h"
#include "ProjectileController.h"

PlayerTank::PlayerTank()
{
}

PlayerTank::~PlayerTank()
{
	delete projectileController;
}

PlayerTank::PlayerTank(float posX, float posY)
{
	this->tankRIGHTFilePath = ".\\data\\PlayerTank\\PlayerTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\PlayerTank\\PlayerTankLEFT.png";
	this->tankUPFilePath = ".\\data\\PlayerTank\\PlayerTankUP.png";
	this->tankDOWNFilePath = ".\\data\\PlayerTank\\PlayerTankDOWN.png";
	this->setPosition(posX, posY);
//	this->setMoveDirection(FRKey::UP);
	this->projectileController = new ProjectileController(this);
}