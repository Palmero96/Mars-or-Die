#include "Sphere.h"

Sphere::Sphere() {

	position.x = 0;
	position.y = 0;

}

Sphere::~Sphere() {}
 
void Sphere::SetColor(float r, float g, float b) 
{
	red = r;
	green = g;
	blue = b;
}

void Sphere::SetRadius(float r) {
	radius = r;
}

Vector2D Sphere::GetPos() {
	return position;
}

void Sphere::Draw() {

	glPushMatrix();
	glTranslatef(position.x, 0, position.y);
	glColor4f(red, green, blue, 1.0);
	glutSolidSphere(radius, 40, 40);
	glPopMatrix();

	glLineWidth(2);
	glBegin(GL_LINE_LOOP);					//	ORBIT	
	glColor4f(red, green, blue, 1.0);
	for (float i = 0; i < 2 * 3.1416; i+=0.01) {	
		glVertex3f(orbit_radius*cos(i), 0, orbit_radius*sin(i));
		glVertex3f(orbit_radius*cos(i + 0.01), 0, orbit_radius*sin(i + 0.01));
		
	}
	glEnd();
}
