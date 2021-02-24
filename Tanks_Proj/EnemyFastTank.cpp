#include "EnemyFastTank.h"

EnemyFastTank::EnemyFastTank(float posX, float posY, bool isFlashing)
	: EnemyTank(posX, posY, 1, 3, 2, isFlashing)
{
	this->tankRIGHTFilePath = ".\\data\\EnemyTank\\FastTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\EnemyTank\\FastTankLEFT.png";
	this->tankDOWNFilePath = ".\\data\\EnemyTank\\FastTankDOWN.png";
	this->tankUPFilePath = ".\\data\\EnemyTank\\FastTankUP.png";

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
