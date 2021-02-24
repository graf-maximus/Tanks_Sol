
#include "BonusThirdStar.h"
#include "ProjectileController.h"

BonusThirdStar::BonusThirdStar(int posX, int posY)
	: Bonus(posX, posY)
{
	this->setSprite(".\\data\\Flash_3.png");
}

void BonusThirdStar::addBonus(Tanks* owner)
{
	owner->getProjectileController()->setPower(2);
}