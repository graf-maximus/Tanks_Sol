#pragma once
#include "GameRules.h"
#include "Tanks.h"

class Bonus : public GameRules
{
public:

	Bonus(int posX, int posY);
	~Bonus();
	virtual void addBonus(Tanks* owner) = 0;
};