#pragma once
#include "Bonus.h"

class BonusFirstStar : public Bonus
{
public:
	BonusFirstStar(int posX, int posY);
	void addBonus(Tanks* owner);
};