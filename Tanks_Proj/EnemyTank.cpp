#include "EnemyTank.h"
#include "ProjectileController.h"

EnemyTank::EnemyTank(float posX, float posY, int health, float moveSpeed, float projectileSpeed, bool isFlashing)
	: Tanks(posX, posY, health, isFlashing)
{
	this->currentSpeed = (moveSpeed/1.5) * this->staticSpeed;
	this->projectileController->setSpeed(projectileSpeed/2);
}

EnemyTank::~EnemyTank()
{
	if (this->projectileController != nullptr)
		delete projectileController;
}

void EnemyTank::setMoveDirection(FRKey direction)
{
	Tanks::setMoveDirection(direction);
	this->intersectionWall = false;
}

void EnemyTank::spawnProjectile(float time)
{
	if (this->getProjectileController()->getSpawnedProjectile().empty())
		this->getProjectileController()->spawnProjectile(this->posX, this->posY, this->moveDirection);
}

void EnemyTank::move(float time)
{
	int screenW, screenH, tankW, tankH;
	getScreenSize(screenW, screenH);
	getSpriteSize(this->getSprite(), tankW, tankH);

	switch (this->moveDirection)
	{
	case FRKey::RIGHT:
		if (this->posX + this->currentSpeed * time <= screenW - tankW)
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
		if (this->posY + this->currentSpeed * time <= screenH - tankH)
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