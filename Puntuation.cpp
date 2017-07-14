#include "Puntuation.h"
#include "glut.h"
#include <stdio.h>


Puntuation::Puntuation()
{
	numlifes = 3;
	height = 383;
	weight = 30;
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
		sprintf_s(phrase1, "Vamos a comenzar el tutorial, con las teclas de las flechas arriba y abajo se puede rotar la nave");
		sprintf_s(phrase2, "Con las teclas de izquierda y derecha se puede acelerar o decelerar");
		sprintf_s(phrase3, "Cuando comprenda como funcionan los controles pulse 's' para continuar");
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

		char phrase1[200];
		char phrase2[200];
		char phrase3[200];
		sprintf_s(phrase1, "Puntuation: ");
		sprintf_s(phrase2, "Life:");
		sprintf_s(phrase3, "Fuel: ");

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 30);
		ETSIDI::printxy(pidStr2, 175, 550);
		ETSIDI::printxy(pidStr, 300, 33);
		ETSIDI::printxy(phrase1,15,33 );
		ETSIDI::printxy(phrase2, 15, 550);
		ETSIDI::printxy(phrase3, 525, 30);

		red = 255 - 2 * height / 3;
		green = 2 * height / 3;
		glDisable(GL_LIGHTING);
		glBegin(GL_QUADS);
			glColor3ub(red, green, 0);
			/*glVertex3f(50, 150, 0.0f);
			glVertex3f(weight + 50, 150, 0.0f);
			glVertex3f(50, 150 + height, 0.0f);
			glVertex3f(weight + 50, 150 + height, 0.0f);*/
			glVertex3f(645, -weight + 40, 0.0f);
			glVertex3f(645, weight + 40, 0.0f);
			glVertex3f(height + 645, weight + 40, 0.0);
			glVertex3f(height + 645, -weight + 40, 0.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		}

		if (fase == 3)
		{
			char phrase[500];
			sprintf_s(phrase, "GAME OVER");
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 60);
			ETSIDI::printxy(phrase, 300, 300);
		}

		if (fase == 4)
		{
			char phrase[500];
			sprintf_s(phrase, "Pulse 'c' para continuar en el siguiente nivel");
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 20);
			ETSIDI::printxy(phrase, 300, 320);
		}

		if (fase == 5) {
			int size = sizeof(points) * 4;
			char *pidStr = new char[size + 1];
			_itoa_s(points, pidStr, size + 1, 10);

			char phrase1[200];
		
			sprintf_s(phrase1, "Puntuation: ");

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 30);
			ETSIDI::printxy(pidStr, 300, 33);
			ETSIDI::printxy(phrase1, 35, 33);
		}


		if (fase == 6) {
			int size = sizeof(points) * 4;
			char *pidStr = new char[size + 1];
			_itoa_s(points, pidStr, size + 1, 10);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fonts/nasalization-rg.ttf", 30);
			ETSIDI::printxy(pidStr, 600, 250);
		}

		glMatrixMode(GL_TEXTURE);
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		glEnable(GL_DEPTH_TEST);

}



void Puntuation::move(bool stop) {
	if(height>0)
	height -= 0.5 * 0.25;
	if (!Die()) {
		if(!stop)
			points++;
	}
}

void Puntuation::addFuel()
{
	height += 40;
	if (height > 383) height = 383;
	ETSIDI::play("music/fuel_phase2.wav");
}

void Puntuation::addPoints()
{
	points += 100;
}

void Puntuation::addPoints(int n)
{
	points += n;
}

void Puntuation::SubPoints(int n)
{
	points -= n;
}

bool Puntuation::Die()
{
	if (numlifes == 0 || height <= 0) {
		ETSIDI::play("music/gameoverphase2.wav");
		return true;
	}
	return false;
}

void Puntuation::substractlife()
{
	numlifes--;
}

void Puntuation::addLife()
{
	numlifes++;
	ETSIDI::play("music/life_phase2.wav");
}

Puntuation Puntuation::operator=(Puntuation n)
{
	points = n.points;
	return *this;
}

int Puntuation::getPoints()
{
	return points;
}



Puntuation Puntuation::operator+(Puntuation p)
{
	numlifes += p.numlifes;
	points += p.points;

	return *this;
}