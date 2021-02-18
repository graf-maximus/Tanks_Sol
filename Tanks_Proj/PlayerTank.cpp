
#include "PlayerTank.h"
#include <iostream>

PlayerTank::PlayerTank()
{
}

PlayerTank::PlayerTank(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	this->tankSpeed = 0.07;
	this->moveDirection = FRKey::COUNT;
}

void PlayerTank::setTankPosition(int x, int y)
{
	this->posX = x;
	this->posY = y;
}

void PlayerTank::getTankPosition(int& x, int& y)
{
	x = posX;
	y = posY;
}

void PlayerTank::setSprite()
{
	this->tankSprite = createSprite(spriteFilePath);
}

Sprite* PlayerTank::getSprite()
{
	if (tankSprite != nullptr)
		return tankSprite;
	else
		return nullptr;
}

void PlayerTank::drawPlayer()
{
	if (tankSprite != nullptr)
		drawSprite(tankSprite, posX, posY);
}

void PlayerTank::moveTank(float time)
{
	switch (moveDirection)
	{
	case FRKey::RIGHT: 
		if (this->posX + this->tankSpeed * time <= 800)
			this->posX += this->tankSpeed * time; 
		break;
	case FRKey::LEFT: 
		if (this->posX - this->tankSpeed * time >= 0)
			this->posX -= this->tankSpeed * time; 
		break;
	case FRKey::DOWN:
		if (this->posY + this->tankSpeed * time <= 600)
			this->posY += this->tankSpeed * time; 
		break;
	case FRKey::UP:
		if (this->posY - this->tankSpeed * time >= 0)
			this->posY -= this->tankSpeed * time;
		break;
	default:
		break;
	}
}

int PlayerTank::getTankSpeed()
{
	return tankSpeed;
}

void PlayerTank::setMoveDirection(FRKey direction)
{
	this->moveDirection = direction;
}
