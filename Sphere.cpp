#include "Sphere.h"

Sphere::Sphere()
{
}

Sphere::~Sphere() {}
 
void Sphere::SetColor(float r, float g, float b) 
{
	red = r;
	green = g;
	blue = b;
}


void Sphere::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, 0, position.y);
	glColor4f(red, green, blue, 1.0);
	glutSolidSphere(radius, 40, 40);
	glPopMatrix();
}

void Sphere::SetRadius(float r)
{
	radius = r;
}

float  Sphere::GetRadius()
{
	return radius;
}