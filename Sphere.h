#pragma	once
#include <iostream>
#include "Vector2D.h"
#include "glut.h"
#include <math.h>
#include "Object.h"
using namespace std;

class Sphere : virtual public Object
{
protected:
	float radius;
public:
	Sphere();
	~Sphere();
	virtual void Draw(const char *c);
	void SetColor(float r, float g, float b);
	void SetRadius(float);
	float GetRadius();
};


