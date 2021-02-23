#include "HealthController.h"

void HealthController::changeLife(int health)
{
	this->healthPoint += health;
}

HealthController::HealthController(int health)
{
	this->healthPoint = health;
}

int HealthController::getHealth()
{
	return this->healthPoint;
}

bool HealthController::isAlive()
{
	if (healthPoint <= 0)
		return false;

	return true;
}
