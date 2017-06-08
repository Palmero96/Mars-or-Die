#pragma once
#include "Vector2D.h"
#include "glut.h"

class Ship
{
	float d = sqrt(pow(position.x, 2) + pow(position.y, 2));
	//float g = 1 - (2 * d / sun_r) + (3 * pow(d, 2) / pow(sun_r, 3)); // gravitational force depending on the distance to the spheres surface 'd'
	float radius, min_r, max_r,t;
	Vector2D position, vel, acc;

public:
	Ship();
	~Ship();
	void Draw();
	void Move();
	void SetPos(Vector2D);
};

