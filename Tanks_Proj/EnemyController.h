#pragma once
#include <vector>
#include "EnemyTank.h"

class EnemyController
{
	std::vector<std::pair<int, int>> enemySpawners;
	std::vector<EnemyTank*> enemyTanks;
	unsigned int spawnTimer = 0;
	int spawnTime = 3000;  // 3 second

public:

	EnemyController();
	void addEnemySpawner(int posX, int posY);
	void spawnNewEnemy();
	std::vector<EnemyTank*> getEnemyTanks();
	bool needToSpawn();
};