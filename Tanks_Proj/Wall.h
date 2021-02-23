#pragma once
#include "GameRules.h"

class Wall : public GameRules
{
protected:

	const char* wallFilePath = ".\\data\\CeglaWall.png";

public:

	Wall();
	Wall(int posX, int posY);
	const char* getSpriteFilePath();
};