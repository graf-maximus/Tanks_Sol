#pragma once
#include "Tanks.h"
#include "ProjectileController.h"

class PlayerTank : public Tanks
{
	const char* tankFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\Tank.png";
	ProjectileController* projectileController;

public:

	PlayerTank();
	~PlayerTank();
	PlayerTank(float posX, float posY);
	void setSprite();
	ProjectileController* getProjectileController();
};