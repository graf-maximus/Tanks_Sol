#include "GameInstance.h"
#include <iostream>

GameInstance::GameInstance()
{
}

void GameInstance::spawnPlayer(int posX, int posY)
{
	this->player = new PlayerTank(posX, posY);
	this->player->setMoveDirection(FRKey::UP);
	this->tanks.push_back(player);
}

void GameInstance::spawnEnemyController(int posX, int posY)
{
	if (enemyController == nullptr)
		enemyController = new EnemyController();

	enemyController->addEnemySpawner(posX, posY);
}

void GameInstance::spawnWall(int number, int posX, int posY)
{
	if (number == 11)
	{
		BreakableWall* wall = new BreakableWall(posX, posY);
		walls.push_back(wall);
	}
	else if (number == 15)
	{
		UnbreakableWall* wall = new UnbreakableWall(posX, posY);
		walls.push_back(wall);
	}
}

void GameInstance::spawnPhoenix(int posX, int posY)
{

}

void GameInstance::changeLevel()
{

}