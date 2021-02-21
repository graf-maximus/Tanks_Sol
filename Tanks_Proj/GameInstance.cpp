#include "GameInstance.h"

#include <iostream>

GameInstance::GameInstance()
{
}

void GameInstance::spawnPlayer(int posX, int posY)
{
	player = new PlayerTank(posX, posY);
	player->setMoveDirection(FRKey::UP);
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
		wall->setSprite();
		walls.push_back(wall);
	}
	else if (number == 15)
	{
		UnbreakableWall* wall = new UnbreakableWall(posX, posY);
		wall->setSprite();
		walls.push_back(wall);
	}
}

void GameInstance::spawnPhoenix(int posX, int posY)
{

}

void GameInstance::changeLevel()
{

}

bool GameInstance::checkPlayerTankWallIntersections(float time)
{
	
	float posX1, posY1, posX2, posY2;
	int tankW, tankH, wallW, wallH;
	this->player->getPosition(posX1, posY1);
	getSpriteSize(this->player->getSprite(), tankW, tankH);

	switch (this->player->getMoveDirection())
	{
	case FRKey::RIGHT :
		posX1 += this->player->getSpeed() * time;
		break;
	case FRKey::LEFT:
		posX1 -= this->player->getSpeed() * time;
		break;
	case FRKey::DOWN:
		posY1 += this->player->getSpeed() * time;
		break;
	case FRKey::UP:
		posY1 -= this->player->getSpeed() * time;
		break;
	default:
		break;
	}

	for (int i = 0; i < this->walls.size(); i++)
	{
		getSpriteSize(this->walls.at(i)->getSprite(), wallW, wallH);
		this->walls.at(i)->getPosition(posX2, posY2);

		if (posX1 + tankW >= posX2 + 1 &&
			posY1 + tankH >= posY2 + 1 &&
			posX2 + wallW >= posX1 + 1 &&
			posY2 + wallH >= posY1 + 1)
		{
			return true;
		}
		
	}

	return false;
}
