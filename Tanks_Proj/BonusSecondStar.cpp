#include "BonusSecondStar.h"
#include "ProjectileController.h"

BonusSecondStar::BonusSecondStar(int posX, int posY)
	: Bonus(posX, posY)
{
	this->setSprite(".\\data\\Flash_2.png");
}

void BonusSecondStar::addBonus(Tanks* owner)
{
	owner->setTier(2);
}