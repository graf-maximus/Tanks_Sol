

#include "Framework.h"
#include "PlayerTank.h"
#include "Projectile.h"
#include <iostream>

/* Test Framework realization */
class MyFramework : public Framework {

	PlayerTank* player = new PlayerTank{400, 300};
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

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		
		time = getTickCount() - time;
		
		player->moveTank(time);

		player->drawPlayer();

		if (player->getSpawnedProjectile() != nullptr)
		{
			player->getSpawnedProjectile()->moveProjectile(time);
			player->getSpawnedProjectile()->drawProjectile();
			if (player->getSpawnedProjectile()->isProjectileOverWall())
				player->destroyProjectile();
		}
		time = getTickCount();


		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		switch (button)
		{
		case FRMouseButton::LEFT:
			player->spawnProjectile();
			break;	
		case FRMouseButton::MIDDLE:
			break;
		case FRMouseButton::RIGHT:
			break;
		case FRMouseButton::COUNT:
			break;
		default:
			break;
		}
	}

	virtual void onKeyPressed(FRKey k) {
		player->setMoveDirection(k);
		player->setTankCurrentSpeed(player->getTankSpeed());
	}

	virtual void onKeyReleased(FRKey k) {
		player->setTankCurrentSpeed(0);
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
