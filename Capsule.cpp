#include "Capsule.h"



Capsule::Capsule()
{
	life = 100;

	acc.x = 0;
	acc.y = 0;

	position.x = 0;
	position.y = 0;

	vel.x = 0;
	vel.y = -3;

	g.x = 0;
	g.y = 0;
}


Capsule::~Capsule()
{
}

void Capsule::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(2, 20, 5);
	glPopMatrix();
	glEnd();
}

void Capsule::Move()
{
	if (vel.y > 3)	vel.y = 3;

	if (vel.y <-5)	vel.y = -5;

	if (vel.x > 3)	vel.x = 3;

	if (vel.x <-3)	vel.x = -3;

	float t = 0.025;
	position = position + vel * t + (acc) * t * t;
	vel = vel + acc * t;
}

void Capsule::SetVel(Vector2 v)
{
	vel = v;
}

Vector2 Capsule::GetVel()
{
	return vel;
}

void Capsule::Hurt() { life -= 5; }

void Capsule::Cure() { life += 10; }

void Capsule::BurnFuel() { fuel--; }

void Capsule::FuelUp() { fuel += 100; }

