#include "Obstacle.h"



Obstacle::Obstacle()
{
	acc.x = 0;
	acc.y = 5;

	vel.x = 0;
	vel.y = 30;
}


Obstacle::~Obstacle()
{
	//delete image;
}

void Obstacle::SetSize(float w, float h)
{
	image->setSize(w, h);
}

Obstacle::Obstacle(const char *name)
{
	acc.x = 0;
	acc.y = 0;

	vel.x = 0;
	vel.y = 30;
	image = new ETSIDI::Sprite(name, position.x, position.y, 20, 20);
}


void Obstacle::Draw(Vector2 pos)
{

}

void Obstacle::Draw()	{ image->draw(); }

void Obstacle::SetPos(float x, float y)
{
	position.x = x;
	position.y = y;
	image->setPos(x, y);
}

void Obstacle::Move()
{
	float t = 0.025;

	if (vel.y > 30)
	{
		vel.y = 30;
		acc.y = 5;
	}

	if (vel.y < -60)
	{
		vel.y = -60;
		acc.y = -5;
	}

	MovingObject::Move();
	image->setPos(position.x, position.y);
}

bool Obstacle::Collision(Sprite s)
{
	return image->collides(s);
}
