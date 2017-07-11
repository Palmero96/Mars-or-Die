#pragma once
#include "Planet.h"
#include "Ship.h"
#include "Capsule.h"
#include "Obstacle.h"
#include "Ship2.h"
#include "Elements.h"
#include "ETSIDI.h"

class Interaction
{
	
public:

	Interaction();
	~Interaction();

	static bool ProximityOrbit(Vector2, Vector2);
	static bool Contact(Capsule &, Obstacle &);
	static bool Colision(class Ship2 sh, class Elements *el);
	static bool AlienBurn(SpriteSequence, Obstacle&);
	static bool Contact(Capsule &c, SpriteSequence);
	static bool Contact(Capsule &c, Sprite);
};

