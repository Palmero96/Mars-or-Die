#pragma once
#include "glut.h"
#include <ctime>
#include <cstdlib>
#include "ETSIDI.h"
#include "MovingObject.h"

class SmallCloud:public MovingObject 
{

	int rand_cloud;

public:

	SmallCloud(float, float, int);
	~SmallCloud();

	void Draw();
	void Move();
	void Decelerate();
	void Accelerate();
};

