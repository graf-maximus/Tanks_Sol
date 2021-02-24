#include "EnemyController.h"
#include "BonusSpawner.h"
#include "GameInstance.h"
#include "EnemyArmorTank.h"
#include "EnemyDefaultTank.h"
#include "EnemyFastTank.h"
#include "EnemyPowerTank.h"

EnemyController::EnemyController()
{
}

void EnemyController::addEnemySpawner(int posX, int posY)
{
	enemySpawners.push_back(std::make_pair(posX, posY));
}

EnemyTank* EnemyController::spawnNewEnemy(std::vector<Tanks*> tanks, Bonus*& bonus, BonusSpawner* bonusSpawner)
{
	if (tanks.size() <= 1)
	{
		int shiftX = std::rand() % enemySpawners.size();
		int tank = std::rand() % 4;
		
		EnemyTank* newEnemy = nullptr;

		switch (tank)
		{
		case 0:
			newEnemy = new EnemyDefaultTank(enemySpawners.at(shiftX).first, enemySpawners.at(shiftX).second, false);
			break;
		case 1:
			newEnemy = new EnemyFastTank(enemySpawners.at(shiftX).first, enemySpawners.at(shiftX).second, false);
			break;
		case 2:
			newEnemy = new EnemyPowerTank(enemySpawners.at(shiftX).first, enemySpawners.at(shiftX).second, false);
			break;
		case 3:
			newEnemy = new EnemyArmorTank(enemySpawners.at(shiftX).first, enemySpawners.at(shiftX).second, false);
			break;
		default:
			break;
		}

		newEnemy->setMoveDirection(static_cast<FRKey>(std::rand() % 4));

		this->enemyCount++;

		spawnTimer = getTickCount();
		return newEnemy;
	}

	std::vector<std::pair<int, int>> availableSpawners;

	for (int i = 0; i < this->enemySpawners.size(); i++)
	{
		if (this->IsFreeSpawn(tanks, this->enemySpawners.at(i).first, this->enemySpawners.at(i).second))
			availableSpawners.push_back(std::make_pair(this->enemySpawners.at(i).first, this->enemySpawners.at(i).second));
	}

	if (!availableSpawners.empty())
	{
		this->enemyCount++;

		int shiftX = std::rand() % (availableSpawners.size());
		int tank = std::rand() % 4;
		
		EnemyTank* newEnemy = nullptr;
		bool isFlashing = false;
		
		if (this->enemyCount == 4 || this->enemyCount == 11 || this->enemyCount == 18)
		{
			if (bonus != nullptr)
			{
				delete bonus;
				bonus = nullptr;
			}
			isFlashing = true;
		}
		switch (tank)
		{
		case 0:
			newEnemy = new EnemyDefaultTank(availableSpawners.at(shiftX).first, availableSpawners.at(shiftX).second, isFlashing);
			break;
		case 1:
			newEnemy = new EnemyFastTank(availableSpawners.at(shiftX).first, availableSpawners.at(shiftX).second, isFlashing);
			break;
		case 2:
			newEnemy = new EnemyPowerTank(availableSpawners.at(shiftX).first, availableSpawners.at(shiftX).second, isFlashing);
			break;
		case 3:
			newEnemy = new EnemyArmorTank(availableSpawners.at(shiftX).first, availableSpawners.at(shiftX).second, isFlashing);
			break;
		default:
			break;
		}

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
	if (getTickCount() - spawnTimer >= spawnTime && this->enemyCount <= 20)
		return true;

	return false;
}