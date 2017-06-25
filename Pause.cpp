#include "Pause.h"



Pause::Pause()
{
}


Pause::~Pause()
{
}

void Pause::Draw()
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


	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 50);
	ETSIDI::printxy("Pause Menu", -10, 8);




}

void Pause::Initialize()
{

}

void Pause::Key(unsigned char key, int x_t, int y_t)
{
}

void Pause::Timer()
{

}