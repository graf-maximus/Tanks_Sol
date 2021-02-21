#include "GameRules.h"

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

Sprite* GameRules::getSprite()
{
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