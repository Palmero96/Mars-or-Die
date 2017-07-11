#include "Puntuation.h"
#include "glut.h"
#include <stdio.h>


Puntuation::Puntuation()
{
	numlifes = 3;
	height = 255;
	weight = 30;
	time_fuel = 0;
	time_points = 0;
	points = 0;
}


Puntuation::~Puntuation()
{
}

void Puntuation::Draw(int fase) {
	
		glDisable(GL_LIGHTING);

		glMatrixMode(GL_TEXTURE);
		glPushMatrix();
		glLoadIdentity();

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		if (fase == 1) {
			char phrase1[500];
			char phrase2[500];
			char phrase3[500];
			sprintf_s(phrase1, "We are going to commence the tutorial,with the up and down arrow buttons, you can rotate de spacecraft");
			sprintf_s(phrase2," The other button we are going to use are the left and right arrow buttons to accelerate o deccelerate");
			sprintf_s(phrase3, "When you understand how does it work, press 's' to continue");
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 10);
			ETSIDI::printxy(phrase1, 50, 550);
			ETSIDI::printxy(phrase2, 50, 525);
			ETSIDI::printxy(phrase3, 100, 500);	
			
		}
		if (fase == 2) {
			int size = sizeof(points) * 4;
			char *pidStr = new char[size + 1];
			_itoa_s(points, pidStr, size + 1, 10);

			int size2 = sizeof(numlifes) * 4;
			char *pidStr2 = new char[size2 + 1];
			_itoa_s(numlifes, pidStr2, size2 + 1, 10);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 30);
			ETSIDI::printxy(pidStr2, 30, 550);
			ETSIDI::printxy(pidStr, 30, 33);

			red = 255 - height;
			green = height;
			glBegin(GL_POLYGON);
			glColor3ub(red, green, 0);
			glVertex3f(645, -weight + 40, 0.0f);
			glVertex3f(645, weight + 40, 0.0f);
			glVertex3f(height + 645, weight + 40, 0.0);
			glVertex3f(height + 645, -weight + 40, 0.0f);
			glEnd();
		}
		if (fase == 3) {
			char phrase[500];
			sprintf_s(phrase, "GAME OVER");
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 60);
			ETSIDI::printxy(phrase, 300, 300);
		}
		if (fase == 4) {
			char phrase[500];
			sprintf_s(phrase, "Press 'c' to continue to the next level");
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 60);
			ETSIDI::printxy(phrase, 300, 300);
		}
		glMatrixMode(GL_TEXTURE);
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		glEnable(GL_DEPTH_TEST);

		
}


void Puntuation::move() {
	height -= 0.25 * 0.25;
	time_points = ETSIDI::getMillis();
	time_fuel = ETSIDI::getMillis();
	if (time_points > 12000) {
		points++;
		time_points = 0;
	}
}

void Puntuation::addFuel()
{
	height += 40;
	if (height > 255) height = 255;
}

void Puntuation::addPoints()
{
	points += 100;
}

bool Puntuation::Die()
{
	if (numlifes == 0 || height == 0) return true;
	return false;
}

void Puntuation::substractlife()
{
	numlifes--;
}

void Puntuation::addLife()
{
	numlifes++;
}



