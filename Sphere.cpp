#include "Sphere.h"

Sphere::Sphere() {
	SetPos(.0, 0.0);
}

Sphere::~Sphere() {}

void Sphere::SetPos(float x, float z) {	
	position.x = x;
	position.y = z;
}

void Sphere::SetColor(float r, float g, float b) {
	red = r;
	green = g;
	blue = b;
}

void Sphere::RiseRadius(float r) {
	radius += r;
}

void Sphere::SetRadius(float r) {
	radius = r;
}

void Sphere::Draw() {

	glPushMatrix();
	glTranslatef(position.x, 0, position.y);
	glColor3f(red, green, blue);
	glutSolidSphere(radius, 40, 40);
	glPopMatrix();

}