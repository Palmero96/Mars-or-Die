#include "Interaction.h"



Interaction::Interaction()
{
}


Interaction::~Interaction()
{
}

bool Interaction::ProximityOrbit(Vector2 planet_pos, Vector2 ship_pos)
{
	Vector2 r = planet_pos - ship_pos;
	float d = sqrtf(pow(r.x, 2) + pow(r.y, 2));

	if (d < 30)
	{
		return true;
	}
	else
		return false;
}

bool Interaction::Contact(Capsule c, Obstacle &o)
{
	if (o.Collision(c.GetImage()))
	{
		if (c.GetLife() > 1)
			c.SetLife(c.GetLife() - 1);

		else c.SetAlive(false);

		return true;
	}
	else
		return false;
}