#pragma once
#include "GameRules.h"
#include "HealthController.h"
#include <vector>

class Wall : public GameRules
{
protected:

	const char* wallFilePath;
	std::vector<HealthController*> healthController;
	bool isBrick = false;

public:

	Wall(int posX, int posY, const char* wallFilePath, int beginHealth, bool isBrick);
	~Wall();
	const char* getSpriteFilePath();
	HealthController* getHealthController(int wallNumber);
	bool IsWallBrick();
};