#include "Planet.h"

Planet::Planet() {
	alpha = 0;
	position.x = orbit_radius * cos(alpha);
	position.y = orbit_radius * sin(alpha);
}

Planet::~Planet() {}

	//Returns the radius os the orbit of each planet
float Planet::GetOrbitRadius() 
{
	return orbit_radius;
}

float Planet::GetAngle() { return alpha; }

float Planet::GetModVel() { return vel; }	

Vector2D Planet::GetVel() 
{
	Vector2D v;
	v.x = vel * cos(alpha);
	v.y = vel * sin(alpha);
	return v;
}

void Planet::SetVel(float v) {vel = v;} //Sets the linear velocity of each planet

void Planet::SetOrbitRadius(float r)	{orbit_radius = r;}

void Planet::SetAngle(float a) { alpha = a;}

void Planet::Move()
{
	position.x = cos(alpha) * orbit_radius;
	position.y = sin(alpha) * orbit_radius;

	alpha += 0.025 * vel;
}


	
