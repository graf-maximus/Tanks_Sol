#include "Map.h"
#include "GameInstance.h"
#include <fstream>
#include <iostream>

Map::Map()
{
}

bool Map::createMap(GameInstance* game)
{
	std::ifstream file("D:\\doc\\Tanks_Sol\\Tanks_Proj\\17x15.txt");
	int fileValue;
	if (!file)
	{
		std::cout << "Could not open file" << '\n';
		return false;
	}
	else
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (!file.eof())
				{
					file >> fileValue;
					switch (fileValue)
					{
					case 11:
						game->spawnWall(fileValue, j, i);
					break;
					case 12:
						game->spawnPlayer(j, i);
					break;
					case 15:
						game->spawnWall(fileValue, j, i);
					break;
					case 18:
						game->addEnemyController(j, i);
					break;
					default:
						break;
					}
				}
			}
		}
		return true;
	}
}

void Map::moveProjectile()
{

}

void Map::moveTank()
{

}
