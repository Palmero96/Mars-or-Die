#include "Sphere.h"
#include "ETSIDI.h"

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


void Sphere::Draw(const char *c)
{
	/*glPushMatrix();
	glTranslatef(position.x, 0, position.y);
	glColor4f(red, green, blue, 1.0);
	glutSolidSphere(radius, 40, 40);
	glPopMatrix();*/

	glColor4f(red, green, blue, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(c).id);

	GLUquadric  *quadObj;
	quadObj = gluNewQuadric();
	gluQuadricTexture(quadObj, GL_TRUE);

	glDisable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(position.x, 0, position.y);
	gluSphere(quadObj, radius, 40, 40);
	glPopMatrix();

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord3d(0, 1, -1024);  glVertex3f(position.x - radius, -10, position.y + radius);
	glTexCoord3d(1, 1, 1024);  glVertex3f(position.x + radius, -10, position.y + radius);
	glTexCoord3d(1, 0, -1024);  glVertex3f(position.x + radius, -10, position.y - radius);
	glTexCoord3d(0, 0, 1024);  glVertex3f(position.x - radius, -10, position.y - radius);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/
}




void Sphere::SetRadius(float r)
{
	radius = r;
}

float  Sphere::GetRadius()
{
	return radius;
}