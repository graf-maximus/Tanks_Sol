#pragma once
#include "GameRules.h"

class ProjectileController;

class Tanks : public GameRules
{
protected:
	float staticSpeed = 0.07;
	const char* tankRIGHTFilePath;
	const char* tankLEFTFilePath;
	const char* tankDOWNFilePath;
	const char* tankUPFilePath;
	ProjectileController* projectileController;

public:

	Tanks();
	Tanks(float posX, float posY);
	~Tanks();

	virtual void move(float time);
	virtual void setMoveDirection(FRKey direction);
	virtual float getTankStaticSpeed();
	virtual ProjectileController* getProjectileController();
	virtual bool checkIntersection(float time, std::vector<Wall*> walls, std::vector<Tanks*> tanks, Tanks* player);
};