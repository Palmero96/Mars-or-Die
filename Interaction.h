#pragma once
#include "Planet.h"
#include "Ship.h"
#include "Capsule.h"
#include "FuelBonus.h"

class Interaction
{
public:

	Interaction();
	~Interaction();

	static bool ProximityOrbit(Vector2, Vector2);
//	static bool Catch()
};

