#include "End.h"

End::End()
{
}


End::~End()
{
}


void End::Draw()
{
	Phase::Draw();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/home/mars_home.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-25, 20, 0);
	glTexCoord2d(1, 1); glVertex3f(25, 20, 0);
	glTexCoord2d(1, 0); glVertex3f(25, -10, 0);
	glTexCoord2d(0, 0); glVertex3f(-25, -10, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 40);
	ETSIDI::printxy("Total points: ", -15, 5);

	int size = sizeof(punt.getPoints()) * 4;
	char *pidStr = new char[size + 1];
	_itoa_s(punt.getPoints(), pidStr, size + 1, 10);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 30);
	ETSIDI::printxy(pidStr, 0, 5);
}

void End::Initialize()
{

}


void End::Timer()
{

}


void End::Key(unsigned char key, int x_t, int y_t)
{
}

void End::SetPoints(Puntuation n)
{
	punt = n;
}