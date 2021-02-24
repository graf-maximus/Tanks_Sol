#pragma once
#include <vector>
#include "Projectile.h"
#include "Tanks.h"

class ProjectileController
{
	std::vector<Projectile*> spawnedProjectile;
	Tanks* owner;
	unsigned int spawnTimer = getTickCount();
	float projectileSpeed = 0.4;
	float defaultSpeed = 0.4;
	int spawnTime = 2000;  // 2 second
	int bulletPower = 1;

public:

	ProjectileController(Tanks* owner);
	~ProjectileController();
	void spawnProjectile(float posX, float posY, FRKey direction);
	void destroyProjectile(Projectile* projectile);
	std::vector<Projectile*> getSpawnedProjectile();
	bool needToSpawn();
	void setSpeed(float speed);
	void setPower(int power);
	void setProjectileDefaultSpeed();
	void setProjectileDefaultPower();
};