#pragma once
#include "ETSIDI.h"
#include "MovingObject.h"
#include "Vector2.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Obstacle : public MovingObject, public Sprite
{
protected:

	bool damage;		//aliens have damage true and fuel has damage false

public:

	Obstacle(const char*);
	~Obstacle();

	void Move();
	void SetPos(float, float);

	void SetAlive(bool);
	bool GetAlive();

	void SetNature(bool);
	bool GetNature();

	Vector2 GetSize();

	bool alive;
};

