#pragma once

class HealthController
{
	int healthPoint;

public:

	HealthController(int health);
	int getHealth();
	void changeLife(int health);
	bool isAlive();
};