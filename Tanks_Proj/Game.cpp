

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
		
		player->move(time);

		player->draw();

		if (player->getSpawnedProjectile() != nullptr)
		{
			player->getSpawnedProjectile()->move(time);
			player->getSpawnedProjectile()->draw();
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
		default:
			break;
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
