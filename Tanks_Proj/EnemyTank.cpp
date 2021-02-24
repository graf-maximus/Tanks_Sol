#include "EnemyTank.h"
#include "ProjectileController.h"

EnemyTank::EnemyTank(float posX, float posY, bool isFlashing)
	: Tanks(posX, posY, 1, isFlashing)
{
	this->tankRIGHTFilePath = ".\\data\\EnemyTank\\EnemyTankRIGHT.png";
	this->tankLEFTFilePath = ".\\data\\EnemyTank\\EnemyTankLEFT.png";
	this->tankDOWNFilePath = ".\\data\\EnemyTank\\EnemyTankDOWN.png";
	this->tankUPFilePath = ".\\data\\EnemyTank\\EnemyTankUP.png";

	//this->setPosition(posX, posY);
	switch (this->getMoveDirection())
	{
	case FRKey::RIGHT :
		this->setSprite(tankRIGHTFilePath);
		break;
	case FRKey::LEFT:
		this->setSprite(tankLEFTFilePath);
		break;
	case FRKey::DOWN:
		this->setSprite(tankDOWNFilePath);
		break;
	case FRKey::UP:
		this->setSprite(tankUPFilePath);
		break;
	}

	this->currentSpeed = 0.07;
	this->projectileController = new ProjectileController(this);
}

EnemyTank::~EnemyTank()
{
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