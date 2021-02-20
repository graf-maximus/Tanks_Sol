#pragma once
#include <vector>
#include "Projectile.h"

class Tanks;

class ProjectileController
{
	Projectile* spawnedProjectile;
	Tanks* owner;

public:

	ProjectileController();
	ProjectileController(Tanks* owner);
	~ProjectileController();
	void spawnProjectile(float posX, float posY, FRKey direction);
	void checkIntersections();
	void destroyProjectile();
	Projectile* getSpawnedProjectile();
};

