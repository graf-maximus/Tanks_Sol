#include "EnemyController.h"
#include "GameInstance.h"

EnemyController::EnemyController()
{
}

void EnemyController::addEnemySpawner(int posX, int posY)
{
	enemySpawners.push_back(std::make_pair(posX, posY));
}

EnemyTank* EnemyController::spawnNewEnemy(std::vector<Tanks*> tanks)
{
	if (tanks.size() <= 1)
	{
		int shiftX = std::rand() % enemySpawners.size();
		EnemyTank* newEnemy = new EnemyTank(enemySpawners.at(shiftX).first, enemySpawners.at(shiftX).second);
		newEnemy->setMoveDirection(static_cast<FRKey>(std::rand() % 4));

		spawnTimer = getTickCount();
		return newEnemy;
	}

	std::vector<std::pair<int, int>> availableSpawners;

	for (int i = 0; i < this->enemySpawners.size(); i++)
	{
		if (this->IsFreeSpawn(tanks, enemySpawners.at(i).first, enemySpawners.at(i).second))
			availableSpawners.push_back(std::make_pair(enemySpawners.at(i).first, enemySpawners.at(i).second));
	}

	if (!availableSpawners.empty())
	{
		int shiftX = std::rand() % (availableSpawners.size());
		EnemyTank* newEnemy = new EnemyTank(availableSpawners.at(shiftX).first, availableSpawners.at(shiftX).second);
		newEnemy->setMoveDirection(static_cast<FRKey>(std::rand() % 4));

		spawnTimer = getTickCount();
		return newEnemy;
	}

	return nullptr;
}

bool EnemyController::IsFreeSpawn(std::vector<Tanks*> tanks, int posX, int posY)
{
	for (int i = 0; i < tanks.size(); i++)
	{
		float tankPosX, tankPosY;
		int tankW, tankH;
		getSpriteSize(tanks.at(i)->getSprite(), tankW, tankH);

		tanks.at(i)->getPosition(tankPosX, tankPosY);

		if (posX * tankW + tankW >= tankPosX &&
			posY * tankH + tankH >= tankPosY &&
			tankPosX + tankW >= posX * tankW &&
			tankPosY + tankH >= posY * tankH)
			{
				return false;
			}
	}

	return true;
}

bool EnemyController::needToSpawn()
{
	if (getTickCount() - spawnTimer >= spawnTime)
		return true;

	return false;
}