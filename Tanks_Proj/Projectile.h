#pragma once
#include "GameRules.h"
#include <vector>

class Tanks;
class Wall;
class GameInstance;

class Projectile : public GameRules
{
	float projectileSpeed = 0.4;
	Tanks* owner;
	const char* projectileFilePath = ".\\data\\bullet.png";

public:

	Projectile(float posX, float posY, FRKey moveDirection, Tanks* owner);
	~Projectile();
	bool checkIntersection(float time, GameInstance*& game);
};