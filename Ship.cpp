#include "Ship.h"

Ship::Ship()	
{
	radius = 1;
	vel.x = 0;
	vel.y = 0;
	acc.x = 0;
	acc.y = 0;
}

Ship::~Ship()	{}


void Ship::Draw()
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(position.x, 0, position.y);
	glutSolidSphere(radius, 15, 15);
	glPopMatrix();
}

void Ship::Move()
{
	acc = m - position;
	vel.x = position.x * 0.5;
	vel.y = position.y * 0.5;
	MovingObject::Move();
}

void Ship::GetAV(Vector2 marsP)
{
	m = marsP;
}

void Ship::OrbitAround(Vector2 planet_pos)
{

	Vector2 r = planet_pos - position;
	float d = sqrtf(pow(r.x, 2) + pow(r.y, 2));

	glTranslatef(planet_pos.x, 0, planet_pos.y);
	alpha += omega * 0.025;
	position.x = d * cosf(alpha);
	position.y = d * sinf(alpha);
}