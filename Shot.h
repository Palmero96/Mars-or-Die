#pragma once
#include <iostream>
#include "glut.h"
#include "Vector2D.h"
#include <math.h>

using namespace std;

class Shot
{
	float alpha = atan(position0.x/position0.y);
	float orbit_radius;
	Vector2D position1, position0;

public:

	Shot();
	~Shot();

	void Draw();
	void Move();
	void SetPos(Vector2D, float);
};

