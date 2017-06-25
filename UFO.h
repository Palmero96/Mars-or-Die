#pragma once
#include "Obstacle.h"
#include "ETSIDI.h"
class UFO :public Obstacle
{
	ETSIDI::Sprite *P;
public:
	UFO(const char *name);
	virtual ~UFO(void);
	void Draw(Vector2);
};

