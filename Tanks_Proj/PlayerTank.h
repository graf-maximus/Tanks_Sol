
#include "Framework.h"

class PlayerTank
{
	float posX, posY;
	float tankSpeed;
	Sprite* tankSprite;
	FRKey moveDirection;
	const char* spriteFilePath = "D:\\doc\\Tanks_Sol\\Tanks_Proj\\data\\Tank.png";

public:
	PlayerTank();
	PlayerTank(int posX, int posY);

	void setTankPosition(int x, int y);
	void getTankPosition(int& x, int& y);
	void setSprite();
	Sprite* getSprite();
	void drawPlayer();
	void moveTank(float time);
	int getTankSpeed();
	void setMoveDirection(FRKey direction);
};
