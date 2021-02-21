

#include "Framework.h"
//#include "PlayerTank.h"
//#include "EnemyTank.h"
//#include "EnemyController.h"
//#include "Projectile.h"
#include "GameInstance.h"
#include "Map.h"
//#include "PlayerTank.h"
#include <iostream>

/* Test Framework realization */
class MyFramework : public Framework {

	/*PlayerTank* player = new PlayerTank{400, 300};
	EnemyController* enemySpawner = new EnemyController();*/
	GameInstance* game;
	Map* map;
	float time = 0;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 544;
		height = 480;
		fullscreen = false;
	}

	virtual bool Init() {

		//player->setSprite();
		//player->setMoveDirection(FRKey::DOWN);
		//enemySpawner->spawnNewEnemy();

		game = new GameInstance();
		map = new Map();
		if (!map->createMap(game))
			return false;

		game->enemyController->spawnNewEnemy();

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		
		time = getTickCount() - time;
		game->player->move(time);
		game->player->draw();

		if (game->player->getProjectileController()->getSpawnedProjectile() != nullptr)
		{
			game->player->getProjectileController()->getSpawnedProjectile()->move(time);
			game->player->getProjectileController()->getSpawnedProjectile()->draw();
			game->player->getProjectileController()->checkIntersections();
		}

		for (int i = 0; i < game->walls.size(); i++)
		{
			game->walls.at(i)->draw();
		}

		if (game->enemyController->needToSpawn())
			game->enemyController->spawnNewEnemy();

		for (int i = 0; i < game->enemyController->getEnemyTanks().size(); i++)
		{
			game->enemyController->getEnemyTanks().at(i)->move(time);
			game->enemyController->getEnemyTanks().at(i)->draw();
			game->enemyController->getEnemyTanks().at(i)->spawnProjectile(time);
			if (game->enemyController->getEnemyTanks().at(i)->getProjectileController()->needToSpawn())
			{
				game->enemyController->getEnemyTanks().at(i)->spawnProjectile(time);
			}
			if (game->enemyController->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile() != nullptr)
			{
				game->enemyController->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile()->move(time);
				game->enemyController->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile()->draw();
			}
		}

		game->player->getProjectileController()->checkIntersections();

		for (int i = 0; i < game->enemyController->getEnemyTanks().size(); i++)
		{
			game->enemyController->getEnemyTanks().at(i)->getProjectileController()->checkIntersections();
		}



		
		//player->move(time);

		//player->draw();

		//if (player->getProjectileController()->getSpawnedProjectile() != nullptr)
		//{
		//	player->getProjectileController()->getSpawnedProjectile()->move(time);
		//	player->getProjectileController()->getSpawnedProjectile()->draw();
		//}

		//if (enemySpawner->needToSpawn(getTickCount()))
		//{
		//	enemySpawner->spawnNewEnemy();
		//}

		//for (int i = 0; i < enemySpawner->getEnemyTanks().size(); i++)
		//{
		//	enemySpawner->getEnemyTanks().at(i)->move(time);
		//	enemySpawner->getEnemyTanks().at(i)->draw();
		//	//enemySpawner->getEnemyTanks().at(i)->spawnProjectile(time);
		//	if (enemySpawner->getEnemyTanks().at(i)->getProjectileController()->needToSpawn())
		//	{
		//		enemySpawner->getEnemyTanks().at(i)->spawnProjectile(time);
		//	}

		//	if (enemySpawner->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile() != nullptr)
		//	{
		//		enemySpawner->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile()->move(time);
		//		enemySpawner->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile()->draw();
		//	}
		//}

		//player->getProjectileController()->checkIntersections();

		//for (int i = 0; i < enemySpawner->getEnemyTanks().size(); i++)
		//{
		//	enemySpawner->getEnemyTanks().at(i)->getProjectileController()->checkIntersections();
		//}

		//if (player->getSpawnedProjectile() != nullptr)
		//{
		//	player->getSpawnedProjectile()->move(time);
		//	player->getSpawnedProjectile()->draw();
		//	if (player->getSpawnedProjectile()->isProjectileOverWall())
		//		player->destroyProjectile();
		//}

		time = getTickCount();


		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if (!isReleased)
		{
			switch (button)
			{
			case FRMouseButton::LEFT:
				float posX, posY;
				game->player->getPosition(posX, posY);
				game->player->getProjectileController()->spawnProjectile(posX, posY, game->player->getMoveDirection());
				break;
			default:
				break;
			}
		}
	}

	virtual void onKeyPressed(FRKey k) {
		game->player->setMoveDirection(k);
		game->player->setSpeed(game->player->getTankStaticSpeed());
	}

	virtual void onKeyReleased(FRKey k) {
		game->player->setSpeed(0);
	}

	virtual const char* GetTitle() override
	{
		return "Tanks-Maksym_Sokorenko";
	}
};

int main(int argc, char* argv[])
{
	return run(new MyFramework);
}
