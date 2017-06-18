#include "MovingObject.h"
#include <math.h>


MovingObject::MovingObject()	
{
}


MovingObject::~MovingObject()	{}


void MovingObject::Move()
{
	float t = 0.025;
	position = position + vel * t + acc * pow(t, 2);
	vel = vel + acc * t;
}

float MovingObject::GetAngle()
{
	return alpha;
}

void MovingObject::SetAngle(float a)
{
	alpha = a;
}

float MovingObject::GetOrbitRadius()
{
	return orbit_radius;
}

void MovingObject::SetOrbitRadius(float or )
{
	orbit_radius = or ;
}

float MovingObject::GetOmega()
{
	return omega;
}

void MovingObject::SetOmega(float o)
{
	omega = o;
}

void MovingObject::SetAcc(Vector2 a)
{
	acc = a;
}