#pragma once
#include "Obstacle.h"
class Alien :public Obstacle
{
	float x, y;
public:
	Alien(const char *name);
	~Alien();
	void Draw(Vector2 pos);
	friend class Interaction;
};

