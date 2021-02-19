#pragma once
#include "ParentClass.h"

class Projectile : public ParentClass
{
	float projectileSpeed = 0.4;
	int spriteSizeW, spriteSizeH;
	const char* projectileFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\bullet.png";

public:

	Projectile(float posX, float posY, FRKey moveDirection);
	~Projectile();
	void setSprite();
	bool isProjectileOverWall();
	bool projectileIntersection();
};