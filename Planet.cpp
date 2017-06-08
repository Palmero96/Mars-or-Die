#include "Planet.h"

Planet::Planet()	{}

Planet::~Planet()   {}

void Planet::Draw() 
{
	Sphere::Draw();

	glLineWidth(2);
	glBegin(GL_LINE_LOOP);					//	ORBIT	
	glColor4f(red, green, blue, 1.0);
	for (float i = 0; i < 2 * 3.1416; i += 0.01)
	{
		glVertex3f(orbit_radius*cos(i), 0, orbit_radius*sin(i));
		glVertex3f(orbit_radius*cos(i + 0.01), 0, orbit_radius*sin(i + 0.01));
	}

	glEnd();

}

