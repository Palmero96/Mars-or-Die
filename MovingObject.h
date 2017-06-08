#pragma once
#include "Object.h"
#include "Vector2D.h"

class MovingObject : virtual public Object
{
protected:

	float alpha, omega, orbit_radius;

public:

	MovingObject();
	virtual ~MovingObject();

	float GetAngle();
	void SetAngle(float);

	float GetOrbitRadius();
	void SetOrbitRadius(float);

	float GetOmega();
	void SetOmega(float);

	void Move();
};

