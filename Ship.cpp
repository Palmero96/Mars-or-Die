#include "Ship.h"

Ship::Ship()	
{
	alpha = 0;
	radius = 1;
	vel.x = 0;
	vel.y = 0;
	acc.x = 0;
	acc.y = 0;
	t = 0.5;
	orbit = false;
}

Ship::~Ship()	{}

void Ship::Move()
{

	acc = m - position;
	vel.x = position.x * t;
	vel.y = position.y * t;
	MovingObject::Move();
}

void Ship::GetAV(Vector2 marsP)
{
	m = marsP;
}

void Ship::SetOrbit(bool s)
{
	orbit = s;
}

bool Ship::GetOrbit()
{
	return orbit;
}

void Ship::OrbitAround(Vector2 planet_pos)
{
	planetO = planet_pos;
	alpha += omega * 0.05;
	position.x = 9 * cosf(alpha);
	position.y = 9 * sinf(alpha);
}

void Ship::Draw()
{
	if (orbit)
	{
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(planetO.x, 0, planetO.y);
		glTranslatef(position.x, 0, position.y);
		glutSolidSphere(radius, 15, 15);
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(position.x, 0, position.y);
		glutSolidSphere(radius, 15, 15);
		glPopMatrix();
	}
}

void Ship::SetT(float a)
{
	t = a;
}

float Ship::GetT()
{
	return t;
}