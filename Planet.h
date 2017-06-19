#pragma once
#include "Sphere.h"
#include "MovingObject.h"
#include <math.h>

class Planet : public Sphere, public MovingObject
{
public:

	Planet();
	~Planet();

	void Draw(const char *c);
	void Move();
	void SetIni(float ir, float ig, float ib, float irad, float iror, float plan);
};

