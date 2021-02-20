#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
{
}

void EnemySpawner::spawnNewEnemy()
{
	EnemyTank* newEnemy = new EnemyTank(100, 100);
	newEnemy->setSprite();
	this->enemyTanks.push_back(newEnemy);
}

std::vector<EnemyTank*> EnemySpawner::getEnemyTanks()
{
	return std::vector<EnemyTank*>(this->enemyTanks);
}