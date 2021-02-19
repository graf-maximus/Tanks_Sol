#include "Projectile.h"
#include <iostream>

Projectile::Projectile(float posX, float posY, FRKey moveDirection)
{
	this->moveDirection = moveDirection;
	this->posX = posX;
	this->posY = posY;

	/*int tankSpriteSizeWidth, tankSpriteSizeHeight;
	getSpriteSize(ownerTank->getSprite(), tankSpriteSizeWidth, tankSpriteSizeHeight);

	switch (moveDirection)
	{
	case FRKey::RIGHT:
		ownerTank->getTankPosition(this->posX, this->posY);
		this->posX += tankSpriteSizeWidth;
		this->posY += tankSpriteSizeHeight / 2;
		break;
	case FRKey::LEFT:
		ownerTank->getTankPosition(this->posX, this->posY);
		this->posY += tankSpriteSizeHeight / 2;
		break;
	case FRKey::DOWN:
		ownerTank->getTankPosition(this->posX, this->posY);
		this->posX += tankSpriteSizeWidth / 2;
		this->posY += tankSpriteSizeHeight;
		break;
	case FRKey::UP:
		ownerTank->getTankPosition(this->posX, this->posY);
		this->posX += tankSpriteSizeWidth / 2;
		break;
	default:
		break;
	}*/

	this->setSprite();
}

Projectile::~Projectile()
{
	destroySprite(projectileSprite);
}

void Projectile::getProjectilePosition(float& x, float& y)
{
	x = this->posX;
	y = this->posY;
}

void Projectile::setSprite()
{
	this->projectileSprite = createSprite(projectileFilePath);
	getSpriteSize(this->projectileSprite, this->spriteSizeW, this->spriteSizeH);
}

Sprite* Projectile::getSprite()
{
	if (this->projectileSprite != nullptr)
		return this->projectileSprite;
	return nullptr;
}

void Projectile::moveProjectile(float time)
{
	switch (moveDirection)
	{
	case FRKey::RIGHT:
		this->posX += this->projectileSpeed * time;
		break;
	case FRKey::LEFT:
		this->posX -= this->projectileSpeed * time;
		break;
	case FRKey::DOWN:
		this->posY += this->projectileSpeed * time;
		break;
	case FRKey::UP:
		this->posY -= this->projectileSpeed * time;
		break;
	default:
		break;
	}
}

float Projectile::getProjectileSpeed()
{
	return this->projectileSpeed;
}

void Projectile::drawProjectile()
{
	if (this->projectileSprite != nullptr)
		drawSprite(this->projectileSprite, this->posX, this->posY);
}

bool Projectile::isProjectileOverWall()
{
	if (this->posX + spriteSizeW <= 0 || this->posX >= 800)
		return true;
	else if (this->posY + spriteSizeH <= 0 || this->posY >= 600)
		return true;

	return false;
}

bool Projectile::projectileIntersection()
{
	return false;
}
