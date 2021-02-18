

#include "Framework.h"
#include "PlayerTank.h"
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
		fullscreen = true;
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

		time = getTickCount();

		player->drawPlayer();

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
		player->setMoveDirection(k);
	}

	virtual void onKeyReleased(FRKey k) {
		player->setMoveDirection(FRKey::COUNT);
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
