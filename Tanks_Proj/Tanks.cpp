#include "Tanks.h"
#include "ProjectileController.h"
#include <iostream>

Tanks::Tanks()
{
}

Tanks::Tanks(float posX, float posY)
{
	this->setPosition(posX, posY);
	this->projectileController = new ProjectileController(this);
}

Tanks::~Tanks()
{
	
}

void Tanks::setMoveDirection(FRKey direction)
{
	this->moveDirection = direction;

	switch (direction)
	{
	case FRKey::RIGHT:
		this->setSprite(this->tankRIGHTFilePath);
		break;
	case FRKey::LEFT:
		this->setSprite(this->tankLEFTFilePath);
		break;
	case FRKey::DOWN:
		this->setSprite(this->tankDOWNFilePath);
		break;
	case FRKey::UP:
		this->setSprite(this->tankUPFilePath);
		break;
	case FRKey::COUNT:
		break;
	default:
		break;
	}
}

bool Tanks::checkIntersection(float time, std::vector<Wall*> walls, std::vector<Tanks*> tanks, Tanks* player)
{
	if (GameRules::checkIntersection(time, walls, tanks, player))
		return true;

	float tank1PosX, tank1PosY, tank2PosX, tank2PosY;
	int tank1Width, tank1Height, tank2Width, tank2Height;
	this->getPosition(tank1PosX, tank1PosY);
	getSpriteSize(this->getSprite(), tank1Width, tank1Height);

	switch (this->getMoveDirection())
	{
	case FRKey::RIGHT:
		tank1PosX += this->getSpeed() * time;
		break;
	case FRKey::LEFT:
		tank1PosX -= this->getSpeed() * time;
		break;
	case FRKey::DOWN:
		tank1PosY += this->getSpeed() * time;
		break;
	case FRKey::UP:
		tank1PosY -= this->getSpeed() * time;
		break;
	default:
		break;
	}

	for (int i = 0; i < tanks.size(); i++)
	{
		if (this != tanks.at(i))
		{
			tanks.at(i)->getPosition(tank2PosX, tank2PosY);
			getSpriteSize(tanks.at(i)->getSprite(), tank2Width, tank2Height);

			if (tank1PosX + tank1Width >= tank2PosX + 1 &&
				tank1PosY + tank1Height >= tank2PosY + 1 &&
				tank2PosX + tank2Width >= tank1PosX + 1 &&
				tank2PosY + tank2Height >= tank1PosY + 1)
			{
				return true;
			}
		}
	}

	return false;
}

void Tanks::move(float time)
{
	switch (this->moveDirection)
	{
	case FRKey::RIGHT:
		if (this->posX + this->currentSpeed * time <= 544)
			this->posX += this->currentSpeed * time;
		break;
	case FRKey::LEFT:
		if (this->posX - this->currentSpeed * time >= 0)
			this->posX -= this->currentSpeed * time;
		break;
	case FRKey::DOWN:
		if (this->posY + this->currentSpeed * time <= 480)
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

ProjectileController* Tanks::getProjectileController()
{
	return this->projectileController;
}