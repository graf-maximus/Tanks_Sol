

#include "Framework.h"
#include "PlayerTank.h"

/* Test Framework realization */
class MyFramework : public Framework {
	PlayerTank player;
	Sprite* playerSprite;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 800;
		height = 600;
		fullscreen = false;
	}

	virtual bool Init() {

		player.setTankPosition(400, 300);
		playerSprite = createSprite("D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\tank.png");

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		drawTestBackground();

		int tankX, tankY;
		player.getTankPosition(tankX, tankY);

		drawSprite(playerSprite, tankX, tankY);

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
	}

	virtual void onKeyReleased(FRKey k) {
	}

	virtual const char* GetTitle() override
	{
		return "Tanks";
	}
};

int main(int argc, char* argv[])
{
	return run(new MyFramework);
}
