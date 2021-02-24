#include "ProjectileController.h"

ProjectileController::ProjectileController(Tanks* owner)
{
	this->owner = owner;
}

ProjectileController::~ProjectileController()
{
	spawnedProjectile.clear();
}

void ProjectileController::spawnProjectile(float posX, float posY, FRKey direction)
{
	if (spawnedProjectile.empty())
	{
		int spriteW, spriteH, tankW, tankH;
		getSpriteSize(this->owner->getSprite(), tankW, tankH);
		
		if (this->owner->IsTierSecond())
		{
			switch (direction)
			{
			case FRKey::RIGHT:
				spawnedProjectile.push_back(new Projectile(posX + tankW, posY, direction, this->owner, this->projectileSpeed, this->bulletPower));
				spawnedProjectile.push_back(new Projectile(posX + tankW, posY + tankH - 12, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			case FRKey::LEFT:
				spawnedProjectile.push_back(new Projectile(posX - 13, posY, direction, this->owner, this->projectileSpeed, this->bulletPower));
				spawnedProjectile.push_back(new Projectile(posX - 13, posY + tankH - 12, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			case FRKey::DOWN:
				spawnedProjectile.push_back(new Projectile(posX, posY + tankH, direction, this->owner, this->projectileSpeed, this->bulletPower));
				spawnedProjectile.push_back(new Projectile(posX + tankW - 13, posY + tankH, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			case FRKey::UP:
				spawnedProjectile.push_back(new Projectile(posX, posY - 12, direction, this->owner, this->projectileSpeed, this->bulletPower));
				spawnedProjectile.push_back(new Projectile(posX + tankW - 13, posY - 12, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			default:
				break;
			}
		}
		else
		{
			switch (direction)
			{
			case FRKey::RIGHT:
				spawnedProjectile.push_back(new Projectile(posX + tankW, posY + tankH/2 - 6, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			case FRKey::LEFT:
				spawnedProjectile.push_back(new Projectile(posX, posY + tankH/2 - 6, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			case FRKey::DOWN:
				spawnedProjectile.push_back(new Projectile(posX + tankW/2 - 6, posY + tankH, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			case FRKey::UP:
				spawnedProjectile.push_back(new Projectile(posX + tankW/2 - 6, posY, direction, this->owner, this->projectileSpeed, this->bulletPower));
				break;
			default:
				break;
			}
		}
	}
}

void ProjectileController::destroyProjectile(Projectile* projectile)
{
	for (int i = 0; i < spawnedProjectile.size(); i++)
		if (spawnedProjectile.at(i) == projectile)
			spawnedProjectile.erase(spawnedProjectile.begin() + i);
}

std::vector<Projectile*> ProjectileController::getSpawnedProjectile()
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

void ProjectileController::setSpeed(float speed)
{
	this->projectileSpeed = this->defaultSpeed * speed;
}

void ProjectileController::setPower(int power)
{
	this->bulletPower = power;
}

void ProjectileController::setProjectileDefaultSpeed()
{
	this->projectileSpeed = this->defaultSpeed;
}

void ProjectileController::setProjectileDefaultPower()
{
	this->bulletPower = 1;
}
