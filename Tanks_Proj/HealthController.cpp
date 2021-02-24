#include "HealthController.h"

void HealthController::changeLife(int health)
{
	this->healthPoint += health;
}

HealthController::HealthController(int health)
{
	this->healthPoint = health;
}

bool HealthController::isAlive()
{
	if (healthPoint <= 0)
		return false;

	return true;
}
