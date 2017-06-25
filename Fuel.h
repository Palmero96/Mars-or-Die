#pragma once
#include "Obstacle.h"
class Fuel :public Obstacle
{
public:
	Fuel(const char *name);
	virtual ~Fuel();
	void Draw(Vector2 pos);
	friend class Interaction;
};

