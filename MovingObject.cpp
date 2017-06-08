#include "MovingObject.h"
#include <math.h>


MovingObject::MovingObject()	
{
}


MovingObject::~MovingObject()	{}


void MovingObject::Move()
{
	alpha += omega * 0.025;
	position.x = orbit_radius * cosf(alpha);
	position.y = orbit_radius * sinf(alpha);

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