//#include "PlayerTank.h"
//#include "Projectile.h"
//#include <iostream>
//
//PlayerTank::PlayerTank()
//{
//}
//
//PlayerTank::PlayerTank(float posX, float posY)
//{
//	this->posX = posX;
//	this->posY = posY;
//	this->moveDirection = FRKey::UP;
//}
//
//void PlayerTank::setTankPosition(float x, float y)
//{
//	this->posX = x;
//	this->posY = y;
//}
//
//void PlayerTank::getTankPosition(float& x, float& y)
//{
//	x = posX;
//	y = posY;
//}
//
//void PlayerTank::setSprite()
//{
//	this->tankSprite = createSprite(spriteFilePath);
//}
//
//Sprite* PlayerTank::getSprite()
//{
//	return this->tankSprite;
//}
//
//void PlayerTank::drawPlayer()
//{
//	if (tankSprite != nullptr)
//		drawSprite(tankSprite, posX, posY);
//}
//
//void PlayerTank::moveTank(float time)
//{
//	switch (moveDirection)
//	{
//	case FRKey::RIGHT: 
//		if (this->posX + this->tankCurrentSpeed * time <= 800)
//			this->posX += this->tankCurrentSpeed * time;
//		break;
//	case FRKey::LEFT: 
//		if (this->posX - this->tankCurrentSpeed * time >= 0)
//			this->posX -= this->tankCurrentSpeed * time;
//		break;
//	case FRKey::DOWN:
//		if (this->posY + this->tankCurrentSpeed * time <= 600)
//			this->posY += this->tankCurrentSpeed * time;
//		break;
//	case FRKey::UP:
//		if (this->posY - this->tankCurrentSpeed * time >= 0)
//			this->posY -= this->tankCurrentSpeed * time;
//		break;
//	default:
//		break;
//	}
//}
//
//float PlayerTank::getTankSpeed()
//{
//	return tankSpeed;
//}
//
//void PlayerTank::setMoveDirection(FRKey direction)
//{
//	this->moveDirection = direction;
//}
//
//void PlayerTank::spawnProjectile()
//{
//	if (spawnedProjectile == nullptr)
//		spawnedProjectile = new Projectile(posX, posY, moveDirection);
//}
//
//FRKey PlayerTank::getMoveDirection()
//{
//	return this->moveDirection;
//}
//
//Projectile* PlayerTank::getSpawnedProjectile()
//{
//	return spawnedProjectile;
//}
//
//void PlayerTank::setTankCurrentSpeed(float currentSpeed)
//{
//	this->tankCurrentSpeed = currentSpeed;
//}
//
//float PlayerTank::getTankCurrentSpeed()
//{
//	return this->tankCurrentSpeed;
//}
//
//void PlayerTank::destroyProjectile()
//{
//	delete spawnedProjectile;
//	spawnedProjectile = nullptr;
//}











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
	//this->posX = posX * 32;
	//this->posY = posY * 32;
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

//void PlayerTank::move(float time)
//{
//	//ParentClass::move(time);
//
//	//if (posX <= 0 || posX >= 800 || posY <= 0 || posY >= 600)
//	//	this->currentSpeed = 0;
//}