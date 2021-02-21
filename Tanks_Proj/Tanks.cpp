#include "Tanks.h"
#include "Projectile.h"
#include <iostream>

Tanks::Tanks()
{
}

Tanks::Tanks(float posX, float posY)
{
}

void Tanks::setSprite()
{
	this->sprite = createSprite(this->tankFilePath);
}

void Tanks::setMoveDirection(FRKey direction)
{
	this->moveDirection = direction;
	if (sprite != nullptr)
		destroySprite(sprite);
	switch (direction)
	{
	case FRKey::RIGHT:
		sprite = createSprite("D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\TankRight.png");
		break;
	case FRKey::LEFT:
		sprite = createSprite("D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\TankLeft.png");
		break;
	case FRKey::DOWN:
		sprite = createSprite("D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\TankDown.png");
		break;
	case FRKey::UP:
		this->sprite = createSprite("D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\TankUp.png");
		break;
	case FRKey::COUNT:
		break;
	default:
		break;
	}
}

void Tanks::move(float time)
{
	switch (this->moveDirection)
	{
	case FRKey::RIGHT:
		if (this->posX + this->currentSpeed * time <= 800)
			this->posX += this->currentSpeed * time;
		break;
	case FRKey::LEFT:
		if (this->posX - this->currentSpeed * time >= 0)
			this->posX -= this->currentSpeed * time;
		break;
	case FRKey::DOWN:
		if (this->posY + this->currentSpeed * time <= 600)
			this->posY += this->currentSpeed * time;
		break;
	case FRKey::UP:
		if (this->posY - this->currentSpeed * time >= 0)
			this->posY -= this->currentSpeed * time;
		break;
	default:
		break;
	}
}

float Tanks::getTankStaticSpeed()
{
	return this->staticSpeed;
}

//void Tanks::spawnProjectile()
//{
//	if (this->spawnedProjectile == nullptr)
//		this->spawnedProjectile = new Projectile(this->posX, this->posY, this->moveDirection);
//}
//
//void Tanks::destroyProjectile()
//{
//	delete this->spawnedProjectile;
//	this->spawnedProjectile = nullptr;
//}
//
//Projectile* Tanks::getSpawnedProjectile()
//{
//	return this->spawnedProjectile;
//}
