#pragma once
#include "Tanks.h"
#include "Bonus.h"
#include <vector>

class BonusSpawner
{
	std::vector<std::pair<int, int>> bonusSpawners;

public:

	BonusSpawner();
	Bonus* spawnBonus(std::vector<Tanks*> tanks);
	bool IsFreeSpawn(std::vector<Tanks*> tanks, int posX, int posY);
	void addBonusSpawner(int posX, int posY);
};