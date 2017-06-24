#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"

class FuelBonus
{
	ETSIDI::Sprite *image;
	Vector2 position;
public:
	FuelBonus();
	~FuelBonus();
	void Draw();

};

