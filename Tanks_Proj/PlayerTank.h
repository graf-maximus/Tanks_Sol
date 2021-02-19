#pragma once
#include "Framework.h"

class Projectile;

class PlayerTank
{
	float posX, posY;
	float tankSpeed = 0.07;
	float tankCurrentSpeed;
	Sprite* tankSprite;
	FRKey moveDirection;
	const char* spriteFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\Tank.png";
	Projectile* spawnedProjectile;

public:

	PlayerTank();
	PlayerTank(float posX, float posY);

	void setTankPosition(float x, float y);
	void getTankPosition(float& x, float& y);
	void setSprite();
	Sprite* getSprite();
	void drawPlayer();
	void moveTank(float time);
	float getTankSpeed();
	void setTankCurrentSpeed(float currentSpeed);
	float getTankCurrentSpeed();
	void setMoveDirection(FRKey direction);
	FRKey getMoveDirection();
	void spawnProjectile();
	void destroyProjectile();
	Projectile* getSpawnedProjectile();
};