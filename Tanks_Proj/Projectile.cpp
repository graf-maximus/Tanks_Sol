#include "Projectile.h"
#include "Tanks.h"
#include "Wall.h"
#include "GameInstance.h"
#include <iostream>

Projectile::Projectile(float posX, float posY, FRKey direction, Tanks* owner, float projectileSpeed, int bulletPower)
{
	this->posX = posX;
	this->posY = posY;
	this->setSpeed(projectileSpeed);
	this->setMoveDirection(direction);
	this->owner = owner;
	this->setSprite(projectileFilePath);
	this->bulletPower = bulletPower;

	int tankSpriteSizeWidth, tankSpriteSizeHeight;
	getSpriteSize(this->owner->getSprite(), tankSpriteSizeWidth, tankSpriteSizeHeight);
}

Projectile::~Projectile()
{
	if (this->sprite != nullptr)
		destroySprite(this->sprite);
}

bool Projectile::checkIntersection(float time, GameInstance*& game)
{
	float projectilePosX, projectilePosY, objPosX, objPosY;
	int projectileWidth, projectileHeight, objWidth, objHeight;
	this->getPosition(projectilePosX, projectilePosY);

	getSpriteSize(this->getSprite(), projectileWidth, projectileHeight);

	if (this != nullptr)
	{
		int screenW, screenH;
		getScreenSize(screenW, screenH);

		if (projectilePosX <= 0 || projectilePosX >= screenW || projectilePosY <= 0 || projectilePosY >= screenH)
			return true;
	}

	switch (this->getMoveDirection())
	{
	case FRKey::RIGHT:
		projectilePosX += this->getSpeed() * time;
		break;
	case FRKey::LEFT:
		projectilePosX -= this->getSpeed() * time;
		break;
	case FRKey::DOWN:
		projectilePosY += this->getSpeed() * time;
		break;
	case FRKey::UP:
		projectilePosY -= this->getSpeed() * time;
		break;
	default:
		break;
	}

	getSpriteSize(game->phoenix->getSprite(), objWidth, objHeight);
	game->phoenix->getPosition(objPosX, objPosY);

	if (projectilePosX + projectileWidth >= objPosX + 1 &&
		projectilePosY + projectileHeight >= objPosY + 1 &&
		objPosX + objWidth >= projectilePosX + 1 &&
		objPosY + objHeight >= projectilePosY + 1)
	{
		game->gameOver();
		return true;
	}

	for (int i = 0; i < game->walls.size(); i++)
	{
		getSpriteSize(game->walls.at(i)->getSprite(), objWidth, objHeight);
		game->walls.at(i)->getPosition(objPosX, objPosY);

		if (projectilePosX + projectileWidth >= objPosX + 1 &&
			projectilePosY + projectileHeight >= objPosY + 1 &&
			objPosX + objWidth >= projectilePosX + 1 &&
			objPosY + objHeight >= projectilePosY + 1)
		{
			if (game->walls.at(i)->IsWallBrick())
				game->walls.at(i)->getHealthController(static_cast<int>(this->getMoveDirection()))->changeLife(-this->bulletPower);
			else if (this->bulletPower > 1)
				game->walls.at(i)->getHealthController(static_cast<int>(this->getMoveDirection()))->changeLife(-2);

			if (!game->walls.at(i)->getHealthController(static_cast<int>(this->getMoveDirection()))->isAlive())
				game->walls.erase(game->walls.begin() + i);
			return true;
		}
	}

	if (this->owner != game->player)
	{
		game->player->getPosition(objPosX, objPosY);
		getSpriteSize(game->player->getSprite(), objWidth, objHeight);

		if (objPosX + objWidth >= projectilePosX + 1 &&
			objPosY + objHeight >= projectilePosY + 1 &&
			projectilePosX + projectileWidth >= objPosX + 1 &&
			projectilePosY + projectileHeight >= objPosY + 1)
		{
			game->player->getHealthController()->changeLife(-1);
			game->player->setPosition(game->player->getDefaultPosX(), game->player->getDefaultPosY());
			game->player->getProjectileController()->setProjectileDefaultSpeed();
			game->player->setTier(1);
			game->player->getProjectileController()->setProjectileDefaultPower();
			return true;
		}
	}
	else
	{
		for (int i = 0; i < game->tanks.size(); i++)
		{
			if (game->tanks.at(i) != game->player)
			{
				game->tanks.at(i)->getPosition(objPosX, objPosY);
				getSpriteSize(game->tanks.at(i)->getSprite(), objWidth, objHeight);

				if (objPosX + objWidth >= projectilePosX + 1 &&
					objPosY + objHeight >= projectilePosY + 1 &&
					projectilePosX + projectileWidth >= objPosX + 1 &&
					projectilePosY + projectileHeight >= objPosY + 1)
				{
					if (game->tanks.at(i)->IsFlashing())
						game->bonus = game->bonusSpawner->spawnBonus(game->tanks);

					game->tanks.at(i)->getHealthController()->changeLife(-1);
					if (!game->tanks.at(i)->getHealthController()->isAlive())
						game->tanks.erase(game->tanks.begin() + i);

					return true;
				}
			}
		}
	}

	return false;
}

int Projectile::getProjectilePower()
{
	return this->bulletPower;
}
