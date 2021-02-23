#pragma once
#include "Tanks.h"

class EnemyTank : public Tanks
{
	bool intersectionWall = false;

public:

	EnemyTank();
	EnemyTank(float posX, float posY);
	~EnemyTank();
	void move(float time);
	void setMoveDirection(FRKey direction);
	void spawnProjectile(float time);   // needs to rename
};