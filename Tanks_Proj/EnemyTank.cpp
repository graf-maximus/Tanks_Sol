#include "EnemyTank.h"
#include <iostream>

EnemyTank::EnemyTank()
{

}

EnemyTank::EnemyTank(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
	this->moveDirection = FRKey::DOWN;
	this->currentSpeed = 0.07;
}

void EnemyTank::setSprite()
{
	this->sprite = createSprite(this->tankFilePath);
}

void EnemyTank::changeDirection()
{
	FRKey newDirection = this->getMoveDirection();
	int newDir = static_cast<int>(newDirection);
	newDirection = static_cast<FRKey>(++newDir % 4);
	this->setMoveDirection(newDirection);
	this->intersectionWall = false;
}

void EnemyTank::move(float time)
{
	switch (this->moveDirection)
	{
	case FRKey::RIGHT:
		if (this->posX + this->currentSpeed * time <= 800)
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
		if (this->posY + this->currentSpeed * time <= 600)
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
		this->changeDirection();
}