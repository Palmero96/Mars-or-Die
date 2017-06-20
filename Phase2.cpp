#include "Phase2.h"

Phase2::Phase2()	
{
	x_eye = 0;
	y_eye = 20;
	z_eye = 60;
}

Phase2::~Phase2()	{}

void Phase2::Initialize()
{

}

void Phase2::Draw()
{

	Phase::Draw();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/m.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);  glVertex3f(-18, 18, 0);
	glTexCoord2d(1, 0);  glVertex3f(18, 18, 0);
	glTexCoord2d(1, 1);  glVertex3f(18, -2, 0);
	glTexCoord2d(0, 1);  glVertex3f(-18, -2, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	
}

void Phase2::Timer()
{

}

void Phase2::Key(unsigned char key, int x_t, int y_t)
{

}
