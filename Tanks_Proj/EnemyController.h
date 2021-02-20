#pragma once
#include <vector>
#include "EnemyTank.h"

class EnemyController
{
	std::vector<EnemyTank*> enemyTanks;

public:

	EnemyController();
	void spawnNewEnemy();
	std::vector<EnemyTank*> getEnemyTanks();
};