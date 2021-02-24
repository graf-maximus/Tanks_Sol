#include "Projectile.h"
#include "Tanks.h"
#include "Wall.h"
#include "GameInstance.h"
#include <iostream>

Projectile::Projectile(float posX, float posY, FRKey moveDirection, Tanks* owner)
{
	this->moveDirection = moveDirection;
	this->posX = posX;
	this->posY = posY;
	this->setSpeed(0.4);
	this->owner = owner;
	this->setSprite(projectileFilePath);

	int tankSpriteSizeWidth, tankSpriteSizeHeight;
	getSpriteSize(this->owner->getSprite(), tankSpriteSizeWidth, tankSpriteSizeHeight);

	switch (moveDirection)
	{
	case FRKey::RIGHT:
		owner->getPosition(this->posX, this->posY);
		this->posX += tankSpriteSizeWidth;
		this->posY += tankSpriteSizeHeight / 2;
		break;
	case FRKey::LEFT:
		owner->getPosition(this->posX, this->posY);
		this->posY += tankSpriteSizeHeight / 2;
		break;
	case FRKey::DOWN:
		owner->getPosition(this->posX, this->posY);
		this->posX += tankSpriteSizeWidth / 2;
		this->posY += tankSpriteSizeHeight;
		break;
	case FRKey::UP:
		owner->getPosition(this->posX, this->posY);
		this->posX += tankSpriteSizeWidth / 2;
		break;
	default:
		break;
	}
}

Projectile::~Projectile()
{
	if (this->sprite != nullptr)
		destroySprite(this->sprite);
}

bool Projectile::checkIntersection(float time, GameInstance*& game)
{




	float objPosX, objPosY, wallPosX, wallPosY;
	int objWidth, objHeight, wallWidth, wallHeight;
	this->getPosition(objPosX, objPosY);

	getSpriteSize(this->getSprite(), objWidth, objHeight);

	switch (this->getMoveDirection())
	{
	case FRKey::RIGHT:
		objPosX += this->getSpeed() * time;
		break;
	case FRKey::LEFT:
		objPosX -= this->getSpeed() * time;
		break;
	case FRKey::DOWN:
		objPosY += this->getSpeed() * time;
		break;
	case FRKey::UP:
		objPosY -= this->getSpeed() * time;
		break;
	default:
		break;
	}

	getSpriteSize(game->phoenix->getSprite(), wallWidth, wallHeight);
	game->phoenix->getPosition(wallPosX, wallPosY);

	if (objPosX + objWidth >= wallPosX + 1 &&
		objPosY + objHeight >= wallPosY + 1 &&
		wallPosX + wallWidth >= objPosX + 1 &&
		wallPosY + wallHeight >= objPosY + 1)
	{
		game->gameOver();

		return true;
	}

	for (int i = 0; i < game->walls.size(); i++)
	{
		getSpriteSize(game->walls.at(i)->getSprite(), wallWidth, wallHeight);
		game->walls.at(i)->getPosition(wallPosX, wallPosY);

		if (objPosX + objWidth >= wallPosX + 1 &&
			objPosY + objHeight >= wallPosY + 1 &&
			wallPosX + wallWidth >= objPosX + 1 &&
			wallPosY + wallHeight >= objPosY + 1)
		{
			game->walls.at(i)->getHealthController()->changeLife(-1);
			if (!game->walls.at(i)->getHealthController()->isAlive())
				game->walls.erase(game->walls.begin() + i);

			return true;
		}
	}







	if (this != nullptr)
	{
		float posX, posY;
		this->getPosition(posX, posY);

		if (posX <= 0 || posX >= 544 || posY <= 0 || posY >= 480)
			return true;
	}

	float tankPosX, tankPosY, projectilePosX, projectilePosY;
	int tankWidth, tankHeight, projectileWidth, projectileHeight;
	getSpriteSize(this->getSprite(), projectileWidth, projectileHeight);
	this->getPosition(projectilePosX, projectilePosY);

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

	if (this->owner != game->player)
	{
		game->player->getPosition(tankPosX, tankPosY);
		getSpriteSize(game->player->getSprite(), tankWidth, tankHeight);

		if (tankPosX + tankWidth >= projectilePosX + 1 &&
			tankPosY + tankHeight >= projectilePosY + 1 &&
			projectilePosX + projectileWidth >= tankPosX + 1 &&
			projectilePosY + projectileHeight >= tankPosY + 1)
		{
			game->player->getHealthController()->changeLife(-1);
			return true;
		}
	}
	else
	{
		for (int i = 0; i < game->tanks.size(); i++)
		{
			if (game->tanks.at(i) != game->player)
			{
				game->tanks.at(i)->getPosition(tankPosX, tankPosY);
				getSpriteSize(game->tanks.at(i)->getSprite(), tankWidth, tankHeight);

				if (tankPosX + tankWidth >= projectilePosX + 1 &&
					tankPosY + tankHeight >= projectilePosY + 1 &&
					projectilePosX + projectileWidth >= tankPosX + 1 &&
					projectilePosY + projectileHeight >= tankPosY + 1)
				{
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