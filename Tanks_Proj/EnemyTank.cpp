#include "EnemyTank.h"
#include <iostream>

EnemyTank::EnemyTank()
{

}

EnemyTank::EnemyTank(float posX, float posY)
{
	this->setPosition(posX, posY);
	this->currentSpeed = 0.07;
	this->projectileController = new ProjectileController(this);
}

EnemyTank::~EnemyTank()
{
	delete projectileController;
}

void EnemyTank::setSprite()
{
	this->sprite = createSprite(this->tankFilePath);
}

void EnemyTank::setMoveDirection(FRKey direction)
{
	Tanks::setMoveDirection(direction);
	this->intersectionWall = false;
}

ProjectileController* EnemyTank::getProjectileController()
{
	return this->projectileController;
}

void EnemyTank::spawnProjectile(float time)
{
	if (this->getProjectileController()->getSpawnedProjectile() == nullptr)
		this->getProjectileController()->spawnProjectile(this->posX, this->posY, this->moveDirection);
}

void EnemyTank::move(float time)
{
	switch (this->moveDirection)
	{
	case FRKey::RIGHT:
		if (this->posX + this->currentSpeed * time <= 544)
			this->posX += this->currentSpeed * time;
		else
			this->intersectionWall = true;
		break;
	case FRKey::LEFT:
		if (this->posX - this->currentSpeed * time >= 0)
			this->posX -= this->currentSpeed * time;
		else
			this->intersectionWall = true;
		break;
	case FRKey::DOWN:
		if (this->posY + this->currentSpeed * time <= 480)
			this->posY += this->currentSpeed * time;
		else
			this->intersectionWall = true;
		break;
	case FRKey::UP:
		if (this->posY - this->currentSpeed * time >= 0)
			this->posY -= this->currentSpeed * time;
		else
			this->intersectionWall = true;
		break;
	default:
		break;
	}

	if (this->intersectionWall)
		this->setMoveDirection(static_cast<FRKey>(std::rand() % 4));
}