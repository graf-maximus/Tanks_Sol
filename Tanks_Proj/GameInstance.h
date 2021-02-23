#pragma once
#include "Framework.h"
#include "PlayerTank.h"
#include "EnemyController.h"
#include "ProjectileController.h"
#include "BreakableWall.h"
#include "UnbreakableWall.h"
#include "GameRules.h"
#include <vector>

class GameInstance
{
public:

	PlayerTank* player;
	EnemyController* enemyController;
	std::vector<Tanks*> tanks;
	std::vector<Wall*> walls;

	GameInstance();
	void spawnPlayer(int posX, int posY);
	void spawnEnemyController(int posX, int posY);
	void spawnWall(int number, int posX, int posY);
	void spawnPhoenix(int posX, int posY);
	void changeLevel();
};