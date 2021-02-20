

#include "Framework.h"
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "EnemyController.h"
#include "Projectile.h"
#include <iostream>

/* Test Framework realization */
class MyFramework : public Framework {

	PlayerTank* player = new PlayerTank{400, 300};
	EnemyController* enemySpawner = new EnemyController();
	float time = 0;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 800;
		height = 600;
		fullscreen = false;
	}

	virtual bool Init() {

		player->setSprite();
		enemySpawner->spawnNewEnemy();

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		
		time = getTickCount() - time;
		
		player->move(time);

		player->draw();

		if (player->getProjectileController()->getSpawnedProjectile() != nullptr)
		{
			player->getProjectileController()->getSpawnedProjectile()->move(time);
			player->getProjectileController()->getSpawnedProjectile()->draw();
		}

		for (int i = 0; i < enemySpawner->getEnemyTanks().size(); i++)
		{
			enemySpawner->getEnemyTanks().at(i)->move(time);
			enemySpawner->getEnemyTanks().at(i)->draw();
			enemySpawner->getEnemyTanks().at(i)->spawnProjectile(time);
			if (enemySpawner->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile() != nullptr)
			{
				enemySpawner->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile()->move(time);
				enemySpawner->getEnemyTanks().at(i)->getProjectileController()->getSpawnedProjectile()->draw();
			}
		}

		player->getProjectileController()->checkIntersections();

		for (int i = 0; i < enemySpawner->getEnemyTanks().size(); i++)
		{
			enemySpawner->getEnemyTanks().at(i)->getProjectileController()->checkIntersections();
		}

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
				player->getPosition(posX, posY);
				player->getProjectileController()->spawnProjectile(posX, posY, player->getMoveDirection());
				//player->spawnProjectile();
				break;
			default:
				break;
			}
		}
	}

	virtual void onKeyPressed(FRKey k) {
		player->setMoveDirection(k);
		player->setSpeed(player->getTankStaticSpeed());
	}

	virtual void onKeyReleased(FRKey k) {
		player->setSpeed(0);
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
