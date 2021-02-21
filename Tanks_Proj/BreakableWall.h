#pragma once
#include "Wall.h"

class BreakableWall : public Wall
{
	const char* wallFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\DestructibleWall.png";

public:
	BreakableWall(int posX, int posY);
	void setSprite();
};