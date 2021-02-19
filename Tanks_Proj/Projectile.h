#pragma once
#include "Framework.h"

class Projectile
{
	FRKey moveDirection;
	float projectileSpeed = 0.4;
	float posX, posY;
	Sprite* projectileSprite;
	int spriteSizeW, spriteSizeH;
	const char* projectileFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\bullet.png";

public:

	Projectile(float posX, float posY, FRKey moveDirection);
	~Projectile();
	void getProjectilePosition(float& x, float& y);
	void setSprite();
	Sprite* getSprite();
	void moveProjectile(float time);
	float getProjectileSpeed();
	void drawProjectile();
	bool isProjectileOverWall();
	bool projectileIntersection();
};