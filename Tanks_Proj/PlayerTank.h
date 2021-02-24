#pragma once
#include "Tanks.h"

class PlayerTank : public Tanks
{
	int defaultPosX, defaultPosY;

public:

	PlayerTank(float posX, float posY);
	int getDefaultPosX();
	int getDefaultPosY();
	~PlayerTank();
};