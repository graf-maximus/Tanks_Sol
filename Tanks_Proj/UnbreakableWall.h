#pragma once
#include "Wall.h"

class UnbreakableWall : public Wall
{
	const char* wallFilePath = ".\\data\\SteelWall.png";

public:
	UnbreakableWall();
	UnbreakableWall(int posX, int posY);
};