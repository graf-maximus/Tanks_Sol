#pragma once

class HealthController
{
	int healthPoint;

public:

	HealthController(int health);
	void changeLife(int health);
	bool isAlive();
};