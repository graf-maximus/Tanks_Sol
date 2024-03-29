#include "GameRules.h"
#include "GameInstance.h"
#include <iostream>

GameRules::~GameRules()
{
	if (this->sprite != nullptr)
	{
		destroySprite(this->sprite);
		this->sprite = nullptr;
	}
}

void GameRules::setPosition(float x, float y)
{
	this->posX = x * 32;
	this->posY = y * 32;
}

void GameRules::getPosition(float& x, float& y)
{
	x = this->posX;
	y = this->posY;
}

void GameRules::setSprite(const char* filePath)
{
	if (this->sprite != nullptr)
	{
		destroySprite(this->sprite);
		this->sprite = nullptr;
	}
	this->sprite = createSprite(filePath);
}

Sprite* GameRules::getSprite()
{
	if (this->sprite != nullptr)
		return this->sprite;
}

void GameRules::draw()
{
	if (this->sprite != nullptr)
		drawSprite(this->sprite, this->posX, this->posY);
}

void GameRules::move(float time)
{
	switch (moveDirection)
	{
	case FRKey::RIGHT:
		this->posX += this->currentSpeed * time;
		break;
	case FRKey::LEFT:
		this->posX -= this->currentSpeed * time;
		break;
	case FRKey::DOWN:
		this->posY += this->currentSpeed * time;
		break;
	case FRKey::UP:
		this->posY -= this->currentSpeed * time;
		break;
	default:
		break;
	}
}

void GameRules::setSpeed(float speed)
{
	this->currentSpeed = speed;
}

float GameRules::getSpeed()
{
	return this->currentSpeed;
}

void GameRules::setMoveDirection(FRKey direction)
{
	this->moveDirection = direction;
}

FRKey GameRules::getMoveDirection()
{
	return this->moveDirection;
}

bool GameRules::checkIntersection(float time, GameInstance*& game)
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

	for (int i = 0; i < game->walls.size(); i++)
	{
		getSpriteSize(game->walls.at(i)->getSprite(), wallWidth, wallHeight);
		game->walls.at(i)->getPosition(wallPosX, wallPosY);

		if (objPosX + objWidth >= wallPosX + 1 &&
			objPosY + objHeight >= wallPosY + 1 &&
			wallPosX + wallWidth >= objPosX + 1 &&
			wallPosY + wallHeight >= objPosY + 1)
		{
			return true;
		}
	}

	return false;
}