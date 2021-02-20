#pragma once
#include "GameRules.h"

class Projectile;

class Tanks : public GameRules
{
	float staticSpeed = 0.07;
	const char* tankFilePath;
	Projectile* spawnedProjectile;

public:

	Tanks();
	Tanks(float posX, float posY);

	virtual void setSprite();
	virtual void move(float time);
	virtual float getTankStaticSpeed();
	virtual void spawnProjectile();
	virtual void destroyProjectile();
	virtual Projectile* getSpawnedProjectile();
};