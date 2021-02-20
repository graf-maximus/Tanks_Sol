#include "ProjectileController.h"
#include "Projectile.h"
#include "Tanks.h"
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
	delete owner;
}

void ProjectileController::spawnProjectile(float posX, float posY, FRKey direction)
{
	if (spawnedProjectile == nullptr)
	{
		std::cout << "Spawn from controller" << '\n';
		spawnedProjectile = new Projectile(posX, posY, direction);
		spawnedProjectile->setSprite();
	}
}

void ProjectileController::checkIntersections()
{
	if (spawnedProjectile != nullptr)
	{
		float posX, posY;
		spawnedProjectile->getPosition(posX, posY);

		if (posX <= 0 || posX >= 800)
			this->destroyProjectile();
		else if (posY <= 0 || posY >= 600)
			this->destroyProjectile();
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
