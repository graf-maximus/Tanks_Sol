#include "BonusFirstStar.h"
#include "ProjectileController.h"

BonusFirstStar::BonusFirstStar(int posX, int posY)
	: Bonus(posX, posY)
{
	this->setSprite(".\\data\\Flash_1.png");
}

void BonusFirstStar::addBonus(Tanks* owner)
{
	owner->getProjectileController()->setSpeed(3);
}