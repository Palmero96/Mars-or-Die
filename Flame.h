#pragma once
#include "ETSIDI.h"
#include "Vector2.h"

class Flame
{
	ETSIDI::Sprite *image;
	Vector2 position;

public:
	Flame(const char *name);
	~Flame();
	void Draw();
};

