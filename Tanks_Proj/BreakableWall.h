#pragma once
#include "Wall.h"

class BreakableWall : public Wall
{
	const char* wallFilePath = ".\\data\\CeglaWall.png";

public:
	BreakableWall();
	BreakableWall(int posX, int posY);
};