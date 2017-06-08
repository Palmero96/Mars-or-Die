#pragma once
#include "Vector2D.h"

class Object
{
protected:

	float red, green, blue;
	Vector2D position;

public:

	Object();
	virtual ~Object();

	Vector2D GetPos();
};

