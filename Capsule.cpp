#include "Capsule.h"



Capsule::Capsule(const char *name)
{
	fuel = 3;
	life = 100;

	acc.x = 0;
	acc.y = 0;

	position.x = 0;
	position.y = 0;

	vel.x = 0;
	vel.y = -3;

	g.x = 0;
	g.y = 0;

	image = new ETSIDI::Sprite(name, position.x, position.y, 20, 20);
}


Capsule::Capsule()
{
}

Capsule::~Capsule()
{
}

void Capsule::Draw()
{
	image->setSize(10, 12);
	image->setPos(position.x, position.y);
	image->draw();
}

void Capsule::Move()
{
	if (vel.y > 3)	vel.y = 3;

	if (vel.y <-5)	vel.y = -5;

	if (vel.x > 20)	vel.x = 20;

	if (vel.x <-20)	vel.x = -20;

	float t = 0.025;

	position = position + vel * t + (acc)* t * t;
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



