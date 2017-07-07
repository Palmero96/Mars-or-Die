#include "Obstacle.h"

Obstacle::~Obstacle()	{}

Obstacle::Obstacle(const char *name) : Sprite (name, position.x, position.y, 0, 0)
{
	acc.x = 0;
	acc.y = 0;

	MovingObject::vel.x = 0;
	MovingObject::vel.y = 30;

	alive = true;
}

void Obstacle::SetPos(float x, float y)
{
	position.x = x;
	position.y = y;
	setPos(x, y);
}

void Obstacle::Move()
{
	float t = 0.025;

	if (MovingObject::vel.y > 30)
	{
		MovingObject::vel.y = 30;
		acc.y = 5;
	}

	if (MovingObject::vel.y < -60)
	{
		MovingObject::vel.y = -60;
		acc.y = -5;
	}

	MovingObject::Move();
	setPos(position.x, position.y);
}


void Obstacle::SetAlive(bool b) { alive = b; }

bool Obstacle::GetAlive() { return alive; }

Vector2 Obstacle::GetSize() { return Vector2(_width, _height); }