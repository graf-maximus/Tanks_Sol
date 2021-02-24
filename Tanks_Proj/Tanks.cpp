#include "Tanks.h"
#include "ProjectileController.h"
#include "HealthController.h"
#include "GameInstance.h"

Tanks::Tanks(float posX, float posY, int health, bool isFlashing)
{
	this->setPosition(posX, posY);
	this->projectileController = new ProjectileController(this);
	this->healthController = new HealthController(health);
	this->isFlashing = isFlashing;
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

bool Tanks::checkIntersection(float time, GameInstance*& game)
{
	if (GameRules::checkIntersection(time, game))
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

	for (int i = 0; i < game->tanks.size(); i++)
	{
		if (this != game->tanks.at(i))
		{
			game->tanks.at(i)->getPosition(tank2PosX, tank2PosY);
			getSpriteSize(game->tanks.at(i)->getSprite(), tank2Width, tank2Height);

			if (tank1PosX + tank1Width >= tank2PosX + 1 &&
				tank1PosY + tank1Height >= tank2PosY + 1 &&
				tank2PosX + tank2Width >= tank1PosX + 1 &&
				tank2PosY + tank2Height >= tank1PosY + 1)
			{
				return true;
			}
		}
	}


	if (this == game->player && game->bonus != nullptr)
	{
		float bonusPosX, bonusPosY;
		int bonusW, bonusH;
		game->bonus->getPosition(bonusPosX, bonusPosY);
		getSpriteSize(game->bonus->getSprite(), bonusW, bonusH);

		if (tank1PosX + tank1Width >= bonusPosX + 1 &&
			tank1PosY + tank1Height >= bonusPosY + 1 &&
			bonusPosX + bonusW >= tank1PosX + 1 &&
			bonusPosY + bonusH >= tank1PosY + 1)
		{
			game->bonus->addBonus(this);
			delete game->bonus;
			game->bonus = nullptr;

			return false;
		}
	}

	return false;
}

bool Tanks::IsFlashing()
{
	return this->isFlashing;
}

bool Tanks::IsTierSecond()
{
	return this->isTierSecond;
}

void Tanks::setTier(int tier)
{
	if (tier == 2)
		this->isTierSecond = true;
	else
		this->isTierSecond = false;
}

void Tanks::move(float time)
{
	int screenW, screenH;
	getScreenSize(screenW, screenH);

	switch (this->moveDirection)
	{
	case FRKey::RIGHT:
		if (this->posX + this->currentSpeed * time <= screenW - 32)
			this->posX += this->currentSpeed * time;
		break;
	case FRKey::LEFT:
		if (this->posX - this->currentSpeed * time >= 0)
			this->posX -= this->currentSpeed * time;
		break;
	case FRKey::DOWN:
		if (this->posY + this->currentSpeed * time <= screenH - 32)
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

HealthController* Tanks::getHealthController()
{
	return this->healthController;
}
