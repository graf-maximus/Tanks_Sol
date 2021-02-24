#include "BonusTank.h"
#include "HealthController.h"

BonusTank::BonusTank(int posX, int posY)
	: Bonus(posX, posY)
{
	this->setSprite(".\\data\\TankBonus.png");
}

void BonusTank::addBonus(Tanks* owner)
{
	owner->getHealthController()->changeLife(1);
}