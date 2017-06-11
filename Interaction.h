#pragma once
#include "Planet.h"
#include "Ship.h"

class Interaction
{
public:

	Interaction();
	~Interaction();

	static bool ProximityOrbit(Vector2, Vector2);
};

