#pragma once
#include "glut.h"
#include "MovingObject.h"
class Capsule :	public MovingObject
{
	Vector2 g;
	int life;
	int fuel;

public:
	Capsule();
	~Capsule();

	void Move();
	void Draw();

	void SetVel(Vector2);
	Vector2 GetVel();

	void Hurt();
	void Cure();

	void BurnFuel();
	void FuelUp();
};

