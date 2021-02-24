#pragma once
#include "Bonus.h"

class BonusTank : public Bonus
{
public:

	BonusTank(int posX, int posY);
	void addBonus(Tanks* owner);
};