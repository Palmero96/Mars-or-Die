#pragma once
#include "ETSIDI.h"
#include <ctime>
class Puntuation
{
	float height, weight;
	int numlifes;
	int points;
	unsigned char red, green;
public:

	Puntuation();
	void Draw(int fase);
	~Puntuation();
	void move(bool stop);
	void addFuel();
	void addPoints();
	void addPoints(int);
	void SubPoints(int);
	bool Die();
	void substractlife();
	void addLife();
	Puntuation operator=(Puntuation n);
	int getPoints();

	Puntuation operator+(Puntuation);
};

