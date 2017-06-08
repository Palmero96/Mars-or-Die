#pragma once
#include "Sphere.h"
#include "MovingObject.h"
#include <math.h>

class Planet : public Sphere, public MovingObject
{
public:

	Planet();
	~Planet();

	void Draw();
};

