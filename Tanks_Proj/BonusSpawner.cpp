#include "BonusSpawner.h"
#include "BonusTank.h"
#include "BonusFirstStar.h"
#include "BonusSecondStar.h"
#include "BonusThirdStar.h"
#include <iostream>

BonusSpawner::BonusSpawner()
{
}

Bonus* BonusSpawner::spawnBonus(std::vector<Tanks*> tanks)
{
	std::vector<std::pair<int, int>> availableSpawners;

	for (int i = 0; i < bonusSpawners.size(); i++)
	{
		if (this->IsFreeSpawn(tanks, bonusSpawners.at(i).first, bonusSpawners.at(i).second))
			availableSpawners.push_back(std::make_pair(bonusSpawners.at(i).first, bonusSpawners.at(i).second));
	}

	if (!availableSpawners.empty())
	{
		Bonus* bonus = nullptr;
		int shift = std::rand() % (availableSpawners.size());
		int randBonus = std::rand() % 4;
		switch (randBonus)
		{
		case 0:
			bonus = new BonusTank(availableSpawners.at(shift).first, availableSpawners.at(shift).second);
			break;
		case 1:
			bonus = new BonusFirstStar(availableSpawners.at(shift).first, availableSpawners.at(shift).second);
			break;
		case 2:
			bonus = new BonusSecondStar(availableSpawners.at(shift).first, availableSpawners.at(shift).second);
			break;
		case 3:
			bonus = new BonusThirdStar(availableSpawners.at(shift).first, availableSpawners.at(shift).second);
			break;
		default:
			break;
		}

		std::cout << "Spawn bonus" << '\n';

		return bonus;
	}


	return nullptr;
}

bool BonusSpawner::IsFreeSpawn(std::vector<Tanks*> tanks, int posX, int posY)
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

void BonusSpawner::addBonusSpawner(int posX, int posY)
{
	this->bonusSpawners.push_back(std::make_pair(posX, posY));
}
