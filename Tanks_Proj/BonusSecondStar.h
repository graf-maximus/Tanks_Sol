#pragma once
#include "Bonus.h"

class BonusSecondStar : public Bonus
{
public:
	BonusSecondStar(int posX, int posY);
	void addBonus(Tanks* owner);
};

