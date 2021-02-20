#pragma once
#include <vector>
#include "EnemyTank.h"

class EnemySpawner
{
	std::vector<EnemyTank*> enemyTanks;

public:

	EnemySpawner();
	void spawnNewEnemy();
	std::vector<EnemyTank*> getEnemyTanks();
};