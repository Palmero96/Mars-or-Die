#include "Planet.h"
#include "ETSIDI.h"

Planet::Planet() {}

Planet::~Planet() {}

void Planet::Draw(const char *c)
{
	Sphere::Draw(c);

	//	ORBIT	
	glColor4f(red, green, blue, 1.0);
	for (float i = 0; i < 2 * 3.1416; i += 0.01)
	{
		glVertex3f(orbit_radius*cos(i), 0, orbit_radius*sin(i));
		glVertex3f(orbit_radius*cos(i + 0.01), 0, orbit_radius*sin(i + 0.01));
	}
	glEnd();
}

void Planet::Move()
{
	alpha += omega * 0.025;
	position.x = orbit_radius * cosf(alpha);
	position.y = orbit_radius * sinf(alpha);
}
void Planet::SetIni(float ir, float ig, float ib, float irad, float iror, float plan) {

	SetColor(ir, ig, ib);
	SetRadius(irad);
	SetOrbitRadius(iror);
	SetOmega(plan);
	SetAngle(rand() % 360);
}
