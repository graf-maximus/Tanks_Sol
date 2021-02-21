#include "EnemyController.h"
#include <iostream>

EnemyController::EnemyController()
{
}

void EnemyController::addEnemySpawner(int posX, int posY)
{
	enemySpawners.push_back(std::make_pair(posX, posY));
}

void EnemyController::spawnNewEnemy()
{
	int shiftX = std::rand() % (this->enemySpawners.size());
	EnemyTank* newEnemy = new EnemyTank(this->enemySpawners.at(shiftX).first, this->enemySpawners.at(shiftX).second);
	newEnemy->setMoveDirection(FRKey::DOWN);
	this->enemyTanks.push_back(newEnemy);
}

std::vector<EnemyTank*> EnemyController::getEnemyTanks()
{
	return std::vector<EnemyTank*>(this->enemyTanks);
}

bool EnemyController::needToSpawn()
{
	if (getTickCount() - spawnTimer >= spawnTime)
	{
		spawnTimer = getTickCount();
		return true;
	}

	return false;
}
