#include "GameInstance.h"
#include <iostream>
#include <fstream>

GameInstance::GameInstance()
{
	this->enemyController = new EnemyController();
	this->bonusSpawner = new BonusSpawner();
}

void GameInstance::spawnPlayer(int posX, int posY)
{
	this->player = new PlayerTank(posX, posY);
	this->player->setMoveDirection(FRKey::UP);
	this->tanks.push_back(player);
}

void GameInstance::addEnemyController(int posX, int posY)
{
	if (this->enemyController == nullptr)
		this->enemyController = new EnemyController();

	enemyController->addEnemySpawner(posX, posY);
}

void GameInstance::addBonusSpawn(int posX, int posY)
{
	if (this->bonusSpawner == nullptr)
		this->bonusSpawner = new BonusSpawner();

	bonusSpawner->addBonusSpawner(posX, posY);
}

void GameInstance::spawnWall(char wallSymbol, int posX, int posY)
{
	if (wallSymbol == 'W')
	{
		BrickWall* wall = new BrickWall(posX, posY);
		walls.push_back(wall);
	}
	else if (wallSymbol == 'S')
	{
		SteelWall* wall = new SteelWall(posX, posY);
		walls.push_back(wall);
	}
}

void GameInstance::spawnPhoenix(int posX, int posY)
{
	if (this->phoenix == nullptr)
		this->phoenix = new Phoenix(posX, posY);
}

void GameInstance::gameOver()
{
	std::cout << "Game over";
}

bool GameInstance::createMap()
{
	std::ifstream file(".\\data\\17x15.txt");
	char fileValue;
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
					case 'W':
						this->spawnWall(fileValue, j, i);
						break;
					case 'T':
						this->spawnPlayer(j, i);
						break;
					case 'S':
						this->spawnWall(fileValue, j, i);
						break;
					case 'R':
						this->addEnemyController(j, i);
						break;
					case 'P':
						this->spawnPhoenix(j, i);
						break;
					case 'B':
						this->addBonusSpawn(j, i);
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