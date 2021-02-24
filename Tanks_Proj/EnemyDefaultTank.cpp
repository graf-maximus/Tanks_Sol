#include "EnemyDefaultTank.h"

EnemyDefaultTank::EnemyDefaultTank(float posX, float posY, bool isFlashing)
	: EnemyTank(posX, posY, 1, 1, 1, isFlashing)
{
	this->tankRIGHTFilePath = ".\\data\\EnemyTank\\DefaultTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\EnemyTank\\DefaultTankLEFT.png";
	this->tankDOWNFilePath = ".\\data\\EnemyTank\\DefaultTankDOWN.png";
	this->tankUPFilePath = ".\\data\\EnemyTank\\DefaultTankUP.png";

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