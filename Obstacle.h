#pragma once
#include "ETSIDI.h"
#include "Interaction.h"
#include "Vector2.h"

class Obstacle : public MovingObject
{
protected:

	ETSIDI::Sprite *image;

public:

	Obstacle();
	Obstacle(const char*);
	~Obstacle();

	virtual void Draw(Vector2 pos);
	void Move();
	void Draw();
	void SetPos(float, float);
	void SetSize(float, float);
	ETSIDI::Sprite getImage() { return *image; }
	friend class Interaction;
};

