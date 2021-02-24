#pragma once
#include "GameRules.h"
#include <vector>

class Tanks;
class Wall;
class GameInstance;

class Projectile : public GameRules
{
	Tanks* owner;
	const char* projectileFilePath = ".\\data\\bullet.png";
	int bulletPower;

public:

	Projectile(float posX, float posY, FRKey moveDirection, Tanks* owner, float projectileSpeed, int bulletPower);
	~Projectile();
	bool checkIntersection(float time, GameInstance*& game);
	int getProjectilePower();
};