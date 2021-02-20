#include "Projectile.h"
#include "GameRules.h"
#include <iostream>

Projectile::Projectile(float posX, float posY, FRKey moveDirection)
{
	this->moveDirection = moveDirection;
	this->posX = posX;
	this->posY = posY;
	this->setSpeed(0.4);

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
	destroySprite(sprite);
}

void Projectile::setSprite()
{
	this->sprite = createSprite(projectileFilePath);
	getSpriteSize(this->sprite, this->spriteSizeW, this->spriteSizeH);
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
