#pragma once
#include "GameRules.h"

class Wall : public GameRules
{
protected:
	bool breakableWall;
	//Sprite* sprite;
	//const char* wallFilePath;
	//int posX, posY;

public:
	Wall();
	Wall(int posX, int posY);
	void setSprite();
};

