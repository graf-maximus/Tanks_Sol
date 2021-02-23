#include "PlayerTank.h"
#include "ProjectileController.h"

PlayerTank::PlayerTank(float posX, float posY)
	: Tanks(posX, posY, 1)
{
	this->tankRIGHTFilePath = ".\\data\\PlayerTank\\PlayerTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\PlayerTank\\PlayerTankLEFT.png";
	this->tankUPFilePath = ".\\data\\PlayerTank\\PlayerTankUP.png";
	this->tankDOWNFilePath = ".\\data\\PlayerTank\\PlayerTankDOWN.png";
	//	this->setMoveDirection(FRKey::UP);
}

PlayerTank::~PlayerTank()
{
	delete projectileController;
}