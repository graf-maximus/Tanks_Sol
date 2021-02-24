#include "Framework.h"
#include "GameInstance.h"
#include <iostream>

/* Test Framework realization */
class MyFramework : public Framework {

	int windowWidth, windowHeight;
	GameInstance* game;
	float clock = 0;
	float time;

public:

	MyFramework(int windowWidth, int windowHeight)
		: windowWidth(windowWidth), windowHeight(windowHeight) {}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = windowWidth;
		height = windowHeight;
		fullscreen = false;
	}

	virtual bool Init() {

		game = new GameInstance();
		
		if (!game->createMap())
			return false;

		game->tanks.push_back(game->enemyController->spawnNewEnemy(game->tanks, game->bonus, game->bonusSpawner));

		return true;
	}

	virtual void Close() {
		delete game;
	}

	virtual bool Tick() {
		
		clock = getTickCount() - clock;
		time = clock;
		clock = getTickCount();

		for (int i = 0; i < game->tanks.size(); i++)
		{
			if (game->tanks.at(i) == nullptr)
				continue;

			if (game->tanks.at(i)->checkIntersection(time, game))
			{
				if (game->tanks.at(i) != game->player)
					game->tanks.at(i)->setMoveDirection(static_cast<FRKey>(std::rand() % 4));
			}
			else
				game->tanks.at(i)->move(time);

			for (int j = 0; j < game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().size(); j++)
			{
				if (game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().at(j) != nullptr)
				{
					if (game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().at(j)->checkIntersection(time, game))
					{
						game->tanks.at(i)->getProjectileController()->destroyProjectile(game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().at(j));
					
						if (!game->player->getHealthController()->isAlive())
						{
							game->gameOver();
							delete game;
							return true;
						}
					}
					else
						game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().at(j)->move(time);
				}
			}
			
			if (game->tanks.at(i) != game->player && game->tanks.at(i)->getProjectileController()->needToSpawn())
			{
				float posX, posY;
				game->tanks.at(i)->getPosition(posX, posY);
				game->tanks.at(i)->getProjectileController()->spawnProjectile(posX, posY, game->tanks.at(i)->getMoveDirection());
			}

		}

		if (game->enemyController->needToSpawn())
		{
			EnemyTank* tank = game->enemyController->spawnNewEnemy(game->tanks, game->bonus, game->bonusSpawner);
			if (tank != nullptr)
				game->tanks.push_back(tank);
		}

		for (int i = 0; i < game->tanks.size(); i++)
		{
			game->tanks.at(i)->draw();
			for (int j = 0; j < game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().size(); j++)
				game->tanks.at(i)->getProjectileController()->getSpawnedProjectile().at(j)->draw();
		}

		for (int i = 0; i < game->walls.size(); i++)
			game->walls.at(i)->draw();

		if (game->phoenix != nullptr)
			game->phoenix->draw();

		if (game->bonus != nullptr && game->bonus->getSprite() != nullptr)
			game->bonus->draw();


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
	int screenWidth = 480, screenHeight = 480;
	if (argc > 1)
	{
		screenWidth = 0; screenHeight = 0;

		for (int i = 1; i < argc; i += 2)
		{
			if (!strcmp(argv[i], "-window"))
			{
				std::string screenSize = argv[i + 1];

				while (isdigit(screenSize.front()))
				{
					screenWidth *= 10;
					screenWidth += (screenSize.front() - '0');
					screenSize.erase(screenSize.begin());
				}
				screenSize.erase(screenSize.begin());
				while (isdigit(screenSize.front()))
				{
					screenWidth *= 10;
					screenHeight += (screenSize.front() - '0');
					screenSize.erase(screenSize.begin());
				}

				break;
			}
		}
	}

	return run(new MyFramework(screenWidth, screenHeight));
}
