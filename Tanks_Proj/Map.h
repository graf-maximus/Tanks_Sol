#pragma once

class GameInstance;

class Map
{
public:

	Map();
	bool createMap(GameInstance* game);
	void moveProjectile();
	void moveTank();
};

