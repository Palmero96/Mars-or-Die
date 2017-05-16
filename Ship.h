#pragma once
#include "Vector2D.h"
#include "glut.h"

class Ship
{
	float d = sqrt(pow(position.x, 2) + pow(position.y, 2));
	float g = 1 - (2 * d / radius) + (3 * pow(d, 2) / pow(radius, 3)); // gravitational force depending on the distance to the spheres surface 'd'
	float radius, vel;
	Vector2D position, launch_vel, v_tot;

public:
	Ship();
	~Ship();
	void Draw();
	void Move();
	void SetInitPos(Vector2D);
	void getTotVel(Vector2D);
	void SetLaunchVel(Vector2D);
};

