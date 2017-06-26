#include "Capsule.h"

Capsule::Capsule() {}

Capsule::~Capsule() {}

Capsule::Capsule(const char *name)
{
	acc.x = 0;
	acc.y = 0;
	alive = true;
	life = 3;

	position.x = 0;
	position.y = 0;

	vel.x = 0;
	vel.y = -3;

	explosion = 0;
	explosionStarted = false;
	image = new ETSIDI::Sprite(name, position.x, position.y, 20, 20);
}

void Capsule::Draw()
{
	switch (alive)
	{
	case true:

		image->setSize(10, 12);
		image->setPos(position.x, position.y);
		image->draw();
		break;

	case false:

		if (!explosionStarted)
		{
			image->~Sprite();
			explosion = new SpriteSequence("textures/phase3/explosion.png", 5, 4, 50, false, position.x - 5, position.y - 5, 10, 10);
			explosionStarted = true;
			break;
		}
	}
	if (explosion)
		explosion->draw();
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

	if (explosion)
		explosion->loop();
}

void Capsule::SetVel(Vector2 v)		{ vel = v; }

Vector2 Capsule::GetVel()			{ return vel; }

void Capsule::SetAlive(bool b)		{ alive = b; }

bool Capsule::Alive()				{ return alive; }

void Capsule::SetLife(int x)		{ life = x;	}

int Capsule::GetLife()				{ return life; }

Sprite Capsule::GetImage()			{ return *image; }

