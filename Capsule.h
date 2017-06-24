#pragma once
#include "glut.h"
#include "MovingObject.h"
#include "ETSIDI.h"

class Capsule :	public MovingObject
{
	ETSIDI::Sprite *image;
	Vector2 g;
	int life;
	int fuel;

public:
	Capsule(const char *name);
	Capsule();
	~Capsule();

	void Move();
	void Draw();

	void SetVel(Vector2);
	Vector2 GetVel();
};

