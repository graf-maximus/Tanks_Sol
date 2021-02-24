#include "GameInstance.h"
#include <iostream>

GameInstance::GameInstance()
{
	this->enemyController = new EnemyController();
}

void GameInstance::spawnPlayer(int posX, int posY)
{
	this->player = new PlayerTank(posX, posY);
	this->player->setMoveDirection(FRKey::UP);
	this->tanks.push_back(player);
}

void GameInstance::addEnemyController(int posX, int posY)
{
	if (enemyController == nullptr)
		this->enemyController = new EnemyController();

	enemyController->addEnemySpawner(posX, posY);
}

void GameInstance::spawnWall(int number, int posX, int posY)
{
	if (number == 11)
	{
		BrickWall* wall = new BrickWall(posX, posY);
		walls.push_back(wall);
	}
	else if (number == 15)
	{
		SteelWall* wall = new SteelWall(posX, posY);
		walls.push_back(wall);
	}
}

void GameInstance::spawnPhoenix(int posX, int posY)
{

}

void GameInstance::gameOver()
{
	std::cout << "Game over";
}
