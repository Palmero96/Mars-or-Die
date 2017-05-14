#pragma once
#include <iostream>
#include "glut.h"
#include "Vector2D.h"
#include <math.h>

using namespace std;

class Shot
{
	float angle;
	float or_radius;
	Vector2D position1, position0;

public:

	Shot();
	~Shot();

	void Draw();
	void Move(Vector2D, float, float);
};

