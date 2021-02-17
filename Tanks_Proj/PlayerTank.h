
#include "Framework.h"

class PlayerTank
{
	int posX, posY;
	Sprite* tankSprite;

public:
	PlayerTank();

	void setTankPosition(int x, int y);
	void getTankPosition(int& x, int& y);
};
