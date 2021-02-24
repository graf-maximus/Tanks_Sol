#include "EnemyArmorTank.h"

EnemyArmorTank::EnemyArmorTank(float posX, float posY, bool isFlashing)
	: EnemyTank(posX, posY, 4, 2, 2, isFlashing)
{
	this->tankRIGHTFilePath = ".\\data\\EnemyTank\\ArmorTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\EnemyTank\\ArmorTankLEFT.png";
	this->tankDOWNFilePath = ".\\data\\EnemyTank\\ArmorTankDOWN.png";
	this->tankUPFilePath = ".\\data\\EnemyTank\\ArmorTankUP.png";

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
