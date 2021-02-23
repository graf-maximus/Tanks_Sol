#include "ProjectileController.h"
#include <iostream>

ProjectileController::ProjectileController()
{

}

ProjectileController::ProjectileController(Tanks* owner)
{
	this->owner = owner;
}

ProjectileController::~ProjectileController()
{
	delete spawnedProjectile;
}

void ProjectileController::spawnProjectile(float posX, float posY, FRKey direction)
{
	if (spawnedProjectile == nullptr)
	{
		spawnedProjectile = new Projectile(posX, posY, direction, this->owner);
	}
}

void ProjectileController::destroyProjectile()
{
	delete spawnedProjectile;
	spawnedProjectile = nullptr;
}

Projectile* ProjectileController::getSpawnedProjectile()
{
	return this->spawnedProjectile;
}

bool ProjectileController::needToSpawn()
{
	if (getTickCount() - spawnTimer >= spawnTime)
	{
		spawnTimer = getTickCount();
		return true;
	}
	return false;
}
