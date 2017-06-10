#pragma once
#include "Vector2D.h"
#include "MovingObject.h"
#include "glut.h"

class Ship : public MovingObject
{
	float d = sqrt(pow(position.x, 2) + pow(position.y, 2));
	float radius, min_r, max_r,t;

public:

	Ship();
	~Ship();

	void Draw();
	void Move();
};

