#pragma once
#include <vector>
#include "Projectile.h"
#include "Tanks.h"

class ProjectileController
{
	Projectile* spawnedProjectile;
	Tanks* owner;
	unsigned int spawnTimer = getTickCount();
	int spawnTime = 2000;  // 2 second

public:

	ProjectileController();
	ProjectileController(Tanks* owner);
	~ProjectileController();
	void spawnProjectile(float posX, float posY, FRKey direction);
	void destroyProjectile();
	Projectile* getSpawnedProjectile();
	bool needToSpawn();
};