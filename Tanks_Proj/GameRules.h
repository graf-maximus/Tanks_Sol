#pragma once
#include "Framework.h"
#include <vector>

class GameInstance;

class GameRules
{
protected:
	float posX, posY;
	float currentSpeed;
	Sprite* sprite;
	FRKey moveDirection;

public:

	virtual void setPosition(float x, float y);
	virtual void getPosition(float& x, float& y);
	virtual void setSprite(const char* filePath);
	virtual Sprite* getSprite();
	virtual void draw();
	virtual void move(float time);
	virtual void setSpeed(float speed);
	virtual float getSpeed();
	virtual void setMoveDirection(FRKey direction);
	virtual FRKey getMoveDirection();
	virtual bool checkIntersection(float time, GameInstance*& game);
};