#include "Wall.h"
#include <iostream>

Wall::Wall()
{
}

Wall::Wall(int posX, int posY)
{
}

void Wall::setSprite()
{
	this->sprite = createSprite(this->spriteFilePath);
}
