#pragma once
class Map
{
	char PlayerTank = 'P';
	char EnemyTank = 'E';
	char Projectile = 'J';
	char Wall = 'W';
	char SteelWall = 'S';
	char Addons = 'A';
	char Map[800][600];

public:

	void createMap();
	void moveProjectile();
	void moveTank();
};

