#include "Bonus.h"

Bonus::Bonus(int posX, int posY)
{
	this->setPosition(posX, posY);
}

Bonus::~Bonus()
{
	if (this->sprite != nullptr)
		destroySprite(this->sprite);
	this->sprite = nullptr;
}