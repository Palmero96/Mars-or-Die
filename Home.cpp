#include "Home.h"

Home::Home()
{
	text_x = -10;				//
	text_gone = false;			//		HOME_TEXT_MOVEMENT
	text_leave = false;			//
}


Home::~Home()
{
}

void Home::Draw()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	Phase::Draw();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/mars_home.png").id);
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

	if (text_leave)
		text_x++;
	if (text_x >= 25)
	{
		text_gone = true;
		text_leave = false;
	}

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 50);
	ETSIDI::printxy("MARS or Die",text_x, 7);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
	ETSIDI::printxy("Ignacio Hermes Rodriguez & Elena Rodríguez", 0, 0);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
	ETSIDI::printxy("Press a to start", -4, 5);
}

void Home::Initialize()	{}

void Home::Timer()
{}

void Home::Key(unsigned char key, int x_t, int y_t)
{
	if (key == 'a')
		text_leave = true;				//     HOME_TEXT_MOVEMENT
}

void Home::SetText_x(int a) { text_x = a; }
int Home::GetText_x() { return text_x; }

void Home::SetText_Gone(bool a) { text_gone = a; }
bool Home::GetText_Gone() { return text_gone; }

void Home::SetText_Leave(bool a) { text_leave = a; }
bool Home::GetText_Leave() { return text_leave; }
