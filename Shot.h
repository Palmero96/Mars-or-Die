#pragma once
#include <iostream>
#include "glut.h"
#include "Vector2D.h"
#include <math.h>

using namespace std;

class Shot
{

	float base, height, angle;
	float or_radius;
	Vector2D position;

public:

	Shot();
	~Shot();

	void Draw();
	float GetOrRad(float r_elip);
	float GetAngle(float, float);
	void Move(Vector2D, float);
	

};

