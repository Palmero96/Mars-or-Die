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