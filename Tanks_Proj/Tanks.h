#pragma once
#include "GameRules.h"

class ProjectileController;
class HealthController;
class GameInstance;

class Tanks : public GameRules
{
protected:
	float staticSpeed = 0.07;
	const char* tankRIGHTFilePath;
	const char* tankLEFTFilePath;
	const char* tankDOWNFilePath;
	const char* tankUPFilePath;
	bool isFlashing;
	bool isTierSecond = false;
	ProjectileController* projectileController;
	HealthController* healthController;

public:

	Tanks(float posX, float posY, int health, bool isFlashing);
	~Tanks();

	virtual void move(float time);
	virtual void setMoveDirection(FRKey direction);
	virtual float getTankStaticSpeed();
	virtual ProjectileController* getProjectileController();
	virtual HealthController* getHealthController();
	virtual bool checkIntersection(float time, GameInstance*& game);
	virtual bool IsFlashing();
	virtual bool IsTierSecond();
	virtual void setTier(int tier);
};