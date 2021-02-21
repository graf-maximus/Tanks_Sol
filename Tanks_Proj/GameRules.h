#pragma once
#include "Framework.h"

class GameRules
{
protected:
	float posX, posY;
	float currentSpeed;
	Sprite* sprite;
	FRKey moveDirection;
	const char* spriteFilePath;

public:

	virtual void setPosition(float x, float y);
	virtual void getPosition(float& x, float& y);
	virtual void setSprite() = 0;
	virtual Sprite* getSprite();
	virtual void draw();
	virtual void move(float time);
	virtual void setSpeed(float speed);
	virtual float getSpeed();
	virtual void setMoveDirection(FRKey direction);
	virtual FRKey getMoveDirection();
};