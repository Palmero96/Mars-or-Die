#pragma once
#include "glut.h"
#include "Planet.h"
#include "Sphere.h"
#include <math.h>

class World
{

	Sphere sun;
	Planet earth, mars, moon;
	float x_eye, y_eye, z_eye;
	float theta, d;

public:

	World();
	~World();

	void Initialize();
	void Draw();
	void Timer();
};

