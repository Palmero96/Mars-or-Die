#pragma once
#include "ETSIDI.h"
#include "Interaction.h"
#include "Vector2.h"

class Obstacle
{
protected:

	ETSIDI::Sprite *image;

public:

	Obstacle();
	~Obstacle();

	virtual void Draw(Vector2 pos) = 0;
	ETSIDI::Sprite getImage() { return *image; }
	friend class Interaction;
};

