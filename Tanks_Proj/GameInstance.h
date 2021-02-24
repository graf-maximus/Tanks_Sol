#pragma once
#include "Framework.h"
#include "PlayerTank.h"
#include "EnemyController.h"
#include "ProjectileController.h"
#include "BrickWall.h"
#include "SteelWall.h"
#include "GameRules.h"
#include "Phoenix.h"
#include <vector>

class GameInstance
{
public:

	PlayerTank* player;
	EnemyController* enemyController;
	Phoenix* phoenix;
	std::vector<Tanks*> tanks;
	std::vector<Wall*> walls;

	GameInstance();
	bool createMap();
	void spawnPlayer(int posX, int posY);
	void addEnemyController(int posX, int posY);
	void spawnWall(char wallSymbol, int posX, int posY);
	void spawnPhoenix(int posX, int posY);
	void gameOver();
};