#pragma once
#include "Obstacle.h"
class Holes :public Obstacle
{
	ETSIDI::Sprite *P;
public:

	void Draw(Vector2);
	Holes(const char *name);
	virtual ~Holes();
};

