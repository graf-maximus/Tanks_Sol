#pragma once
#include <vector>
#include "EnemyTank.h"

class Tanks;

class EnemyController
{
	std::vector<std::pair<int, int>> enemySpawners;
	unsigned int spawnTimer = 0;
	int spawnTime = 3000;  // 3 second

public:

	EnemyController();
	void addEnemySpawner(int posX, int posY);
	EnemyTank* spawnNewEnemy(std::vector<Tanks*> tanks);
	bool IsFreeSpawn(std::vector<Tanks*> tanks, int posX, int posY);
	bool needToSpawn();
};