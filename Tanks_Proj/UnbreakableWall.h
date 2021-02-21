#pragma once
#include "Wall.h"

class UnbreakableWall : public Wall
{
	const char* wallFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\Wall.png";

public:
	UnbreakableWall(int posX, int posY);
	void setSprite();
};