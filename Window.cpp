#include "Window.h"



void Window::Draw(float x, float y, int n) // X position, Y position, kind of window
{
	glPushMatrix();
	glTranslatef(0, 0, -1);

	glEnable(GL_TEXTURE_2D);

	switch (n)
	{
	case 0:		// HOUSTON INCOMING MESSAGE - Y VALUE BETWEEN 0 & 0.5
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/houston_inc.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-1.1, y - 0.3, 0);	// bottom left
		glTexCoord2d(1, 0);  glVertex3f(1.1, y - 0.3, 0); // bottom right
		glTexCoord2d(1, 1);  glVertex3f(1.1, y - 0.55, 0);	// top right
		glTexCoord2d(0, 1);  glVertex3f(-1.1, y - 0.55, 0);// top left
		break;

	case 1:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/houston0.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-1.1, -0.3, 0);	// bottom left
		glTexCoord2d(1, 0);  glVertex3f(1.1, -0.3, 0); // bottom right
		glTexCoord2d(1, 1);  glVertex3f(1.1, -0.55, 0);	// top right
		glTexCoord2d(0, 1);  glVertex3f(-1.1, -0.55, 0);// top left
		break;

	case 2:		// HOUSTON INCOMING MESSAGE - Y VALUE BETWEEN 0 & 0.5
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/houston1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-1.1, y - 0.3, 0);	// bottom left
		glTexCoord2d(1, 0);  glVertex3f(1.1, y - 0.3, 0); // bottom right
		glTexCoord2d(1, 1);  glVertex3f(1.1, y - 0.55, 0);	// top right
		glTexCoord2d(0, 1);  glVertex3f(-1.1, y - 0.55, 0);// top left
		break;

	case 3:		// HOUSTON INCOMING MESSAGE - Y VALUE BETWEEN 0 & 0.5
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/houston3.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-1.1, y - 0.3, 0);	// bottom left
		glTexCoord2d(1, 0);  glVertex3f(1.1, y - 0.3, 0); // bottom right
		glTexCoord2d(1, 1);  glVertex3f(1.1, y - 0.55, 0);	// top right
		glTexCoord2d(0, 1);  glVertex3f(-1.1, y - 0.55, 0);// top left
		break;

	case 4:		// HOUSTON INCOMING MESSAGE - Y VALUE BETWEEN 0 & 0.5
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/houston4.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-1.1, y - 0.3, 0);	// bottom left
		glTexCoord2d(1, 0);  glVertex3f(1.1, y - 0.3, 0); // bottom right
		glTexCoord2d(1, 1);  glVertex3f(1.1, y - 0.55, 0);	// top right
		glTexCoord2d(0, 1);  glVertex3f(-1.1, y - 0.55, 0);// top left
		break;

	case 5:		// HOUSTON INCOMING MESSAGE - Y VALUE BETWEEN 0 & 0.5
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/houston5.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-1.1, y - 0.3, 0);	// bottom left
		glTexCoord2d(1, 0);  glVertex3f(1.1, y - 0.3, 0); // bottom right
		glTexCoord2d(1, 1);  glVertex3f(1.1, y - 0.55, 0);	// top right
		glTexCoord2d(0, 1);  glVertex3f(-1.1, y - 0.55, 0);// top left
		break;

	default:
		break;

	}

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glEnd();
}



Window::~Window()
{
}

Window::Window()
{

}
