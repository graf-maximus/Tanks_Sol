#include "EnemyController.h"

EnemyController::EnemyController()
{
}

void EnemyController::spawnNewEnemy()
{
	EnemyTank* newEnemy = new EnemyTank(100, 100);
	newEnemy->setSprite();
	this->enemyTanks.push_back(newEnemy);
}

std::vector<EnemyTank*> EnemyController::getEnemyTanks()
{
	return std::vector<EnemyTank*>(this->enemyTanks);
}

bool EnemyController::needToSpawn(unsigned int time)
{
	if (time - spawnTimer >= spawnTime)
	{
		spawnTimer = time;
		return true;
	}

	return false;
}
