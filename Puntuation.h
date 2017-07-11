#pragma once
#include "ETSIDI.h"
#include <ctime>
class Puntuation
{
	float height, weight;
	int numlifes;
	int points;
	long time_points;
	long time_fuel;
	unsigned char red, green;
public:
	Puntuation();
	void Draw(int fase);
	~Puntuation();
	void move();
	void addFuel();
	void addPoints();
	bool Die();
	void substractlife();
	void addLife();
};

