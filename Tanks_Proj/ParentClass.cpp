#include "ParentClass.h"

void ParentClass::setPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;
}

void ParentClass::getPosition(float& x, float& y)
{
	x = this->posX;
	y = this->posY;
}

Sprite* ParentClass::getSprite()
{
	return this->sprite;
}

void ParentClass::draw()
{
	if (this->sprite != nullptr)
		drawSprite(this->sprite, this->posX, this->posY);
}

void ParentClass::move(float time)
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

void ParentClass::setSpeed(float speed)
{
	this->currentSpeed = speed;
}

float ParentClass::getSpeed()
{
	return this->currentSpeed;
}

void ParentClass::setMoveDirection(FRKey direction)
{
	this->moveDirection = direction;
}

FRKey ParentClass::getMoveDirection()
{
	return this->moveDirection;
}