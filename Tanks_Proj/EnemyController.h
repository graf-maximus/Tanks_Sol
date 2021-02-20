#pragma once
#include <vector>
#include "EnemyTank.h"

class EnemyController
{
	std::vector<EnemyTank*> enemyTanks;
	unsigned int spawnTimer = 0;
	int spawnTime = 3000;  // 3 second

public:

	EnemyController();
	void spawnNewEnemy();
	std::vector<EnemyTank*> getEnemyTanks();
	bool needToSpawn(unsigned int time);
};