#include "Framework.h"
#include "GameInstance.h"
#include "Map.h"
#include <iostream>

/* Test Framework realization */
class MyFramework : public Framework {

	GameInstance* game;
	Map* map;
	float clock = 0;
	float time;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 544;
		height = 480;
		fullscreen = false;
	}

	virtual bool Init() {

		game = new GameInstance();
		map = new Map();
		if (!map->createMap(game))
			return false;

		game->tanks.push_back(game->enemyController->spawnNewEnemy(game->tanks));

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		
		clock = getTickCount() - clock;
		time = clock;
		clock = getTickCount();

		for (int i = 0; i < game->tanks.size(); i++)
		{
			if (game->tanks.at(i)->checkIntersection(time, game->walls, game->tanks, game->player))
			{
				if (game->tanks.at(i) == game->player)
					game->tanks.at(i)->setSpeed(0.f);
				else
					game->tanks.at(i)->setMoveDirection(static_cast<FRKey>(std::rand() % 4));
			}
			else
				game->tanks.at(i)->move(time);

			if (game->tanks.at(i)->getProjectileController()->getSpawnedProjectile() != nullptr)
			{
				if (game->tanks.at(i)->getProjectileController()->getSpawnedProjectile()->checkIntersection(time, game->walls, game->tanks, game->player))
				{
					game->tanks.at(i)->getProjectileController()->destroyProjectile();
	/*				if (game->tanks.at(i) != game->player)
					{
						game->tanks.erase(game->tanks.begin() + i);
						i--;
					}*/
				}
				else // потім треба буде прибрати (треба буде віднімати життя у танків)
					game->tanks.at(i)->getProjectileController()->getSpawnedProjectile()->move(time);
			}
			else if (game->tanks.at(i) != game->player && game->tanks.at(i)->getProjectileController()->needToSpawn())
			{
				float posX, posY;
				game->tanks.at(i)->getPosition(posX, posY);
				game->tanks.at(i)->getProjectileController()->spawnProjectile(posX, posY, game->tanks.at(i)->getMoveDirection());
			}
		}

		for (int i = 0; i < game->tanks.size(); i++)
		{
			game->tanks.at(i)->draw();
			if (game->tanks.at(i)->getProjectileController()->getSpawnedProjectile() != nullptr)
				game->tanks.at(i)->getProjectileController()->getSpawnedProjectile()->draw();
		}

		for (int i = 0; i < game->walls.size(); i++)
			game->walls.at(i)->draw();

		if (game->enemyController->needToSpawn())
		{
			EnemyTank* tank = game->enemyController->spawnNewEnemy(game->tanks);
			if (tank != nullptr)
				game->tanks.push_back(tank);
		}
		

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
		if (k == game->player->getMoveDirection())
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
