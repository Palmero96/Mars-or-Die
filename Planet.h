#pragma once
#include "Sphere.h"
#include <math.h>

class Planet : public Sphere{

	float vel;
	float alpha = atanf(position.y / position.x);
	float omega = vel / orbit_radius;
	float a_n = pow(vel, 2) / orbit_radius;
	float a_t;

public:

	void Move();
	void SetVel(float);
	void SetOrbitRadius(float);
	void SetAngle(float);
	float GetModVel();
	Vector2D GetVel();
	float GetOrbitRadius();
	float GetAngle();

	Planet();
	~Planet();

};

