#pragma once
#include "Tanks.h"

class EnemyTank : public Tanks
{
	const char* tankFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\Tank.png";
	bool intersectionWall = false;

public:

	EnemyTank();
	EnemyTank(float posX, float posY);
	void setSprite();
	void move(float time);
	void changeDirection();
	void shootProjectile(float time);
};