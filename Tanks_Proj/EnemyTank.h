#pragma once
#include "Tanks.h"
#include "ProjectileController.h"

class EnemyTank : public Tanks
{
	const char* tankFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\Tank.png";
	bool intersectionWall = false;
	ProjectileController* projectileController;

public:

	EnemyTank();
	EnemyTank(float posX, float posY);
	~EnemyTank();
	void setSprite();
	void move(float time);
	void setMoveDirection(FRKey direction);
	ProjectileController* getProjectileController();
	void spawnProjectile(float time);   // needs to rename
};