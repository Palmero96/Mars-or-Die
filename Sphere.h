#pragma	once
#include <iostream>
#include "Vector2D.h"
#include "glut.h"
#include <math.h>

using namespace std;

class Sphere
{

protected:

	Vector2D position;
	float radius, orbit_radius;
	float red, green, blue;

public:
		
	Sphere();
	~Sphere();

	void Draw();
	void SetColor(float r, float g, float b);
	void SetRadius(float r);
	Vector2D GetPos();
};

