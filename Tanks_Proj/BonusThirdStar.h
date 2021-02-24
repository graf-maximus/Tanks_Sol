#pragma once
#include "Bonus.h"

class BonusThirdStar : public Bonus
{
public:
	BonusThirdStar(int posX, int posY);
	void addBonus(Tanks* owner);
};