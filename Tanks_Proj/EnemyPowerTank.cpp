#include "EnemyPowerTank.h"

EnemyPowerTank::EnemyPowerTank(float posX, float posY, bool isFlashing)
	: EnemyTank(posX, posY, 1, 2, 3, isFlashing)
{
	this->tankRIGHTFilePath = ".\\data\\EnemyTank\\PowerTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\EnemyTank\\PowerTankLEFT.png";
	this->tankDOWNFilePath = ".\\data\\EnemyTank\\PowerTankDOWN.png";
	this->tankUPFilePath = ".\\data\\EnemyTank\\PowerTankUP.png";

	switch (this->getMoveDirection())
	{
	case FRKey::RIGHT:
		this->setSprite(tankRIGHTFilePath);
		break;
	case FRKey::LEFT:
		this->setSprite(tankLEFTFilePath);
		break;
	case FRKey::DOWN:
		this->setSprite(tankDOWNFilePath);
		break;
	case FRKey::UP:
		this->setSprite(tankUPFilePath);
		break;
	}
}
