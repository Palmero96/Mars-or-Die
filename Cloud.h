#pragma once
#include "glut.h"
#include <ctime>
#include <cstdlib>
#include "ETSIDI.h"
#include "MovingObject.h"

class Cloud :public MovingObject
{
	int rand_cloud;

public:

	Cloud(float, float, int);
	~Cloud();

	void Draw();
	void Move();
	void Decelerate();
	void Accelerate();
};

