#pragma once
#include "Tanks.h"

class EnemyTank : public Tanks
{
protected:

	bool intersectionWall = false;

public:

	EnemyTank(float posX, float posY, int health, float moveSpeed, float projectileSpeed, bool isFlashing);
	~EnemyTank();
	void move(float time);
	void setMoveDirection(FRKey direction);
	void spawnProjectile(float time);   // needs to rename
};