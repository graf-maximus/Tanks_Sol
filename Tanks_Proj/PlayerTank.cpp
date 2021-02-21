#include "PlayerTank.h"
#include <iostream>

PlayerTank::PlayerTank()
{
}

PlayerTank::~PlayerTank()
{
	delete projectileController;
}

PlayerTank::PlayerTank(float posX, float posY)
{
	this->setPosition(posX, posY);
	this->setMoveDirection(FRKey::UP);
	this->projectileController = new ProjectileController(this);
}

void PlayerTank::setSprite()
{
	this->sprite = createSprite(this->tankFilePath);
}

ProjectileController* PlayerTank::getProjectileController()
{
	return this->projectileController;
}