#pragma once
#include "GameRules.h"
#include "HealthController.h"

class Wall : public GameRules
{
protected:

	const char* wallFilePath;
	HealthController* healthController;

public:

	Wall(int posX, int posY, const char* wallFilePath, int beginHealth);
	const char* getSpriteFilePath();
};