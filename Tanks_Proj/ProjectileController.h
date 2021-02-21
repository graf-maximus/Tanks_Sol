#pragma once
#include <vector>
#include "Projectile.h"

class Tanks;

class ProjectileController
{
	Projectile* spawnedProjectile;
	Tanks* owner;
	unsigned int spawnTimer = getTickCount();
	int spawnTime = 5000;  // 5 second

public:

	ProjectileController();
	ProjectileController(Tanks* owner);
	~ProjectileController();
	void spawnProjectile(float posX, float posY, FRKey direction);
	void checkIntersections();
	void destroyProjectile();
	Projectile* getSpawnedProjectile();
	bool needToSpawn();
};

