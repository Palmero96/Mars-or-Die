#include "Window.h"



void Window::Draw(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y , z);
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/m.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);  glVertex3f(-25, 20, 0);
	glTexCoord2d(1,0);  glVertex3f(25, 20, 0);
	glTexCoord2d(1,1);  glVertex3f(25, -10, 0);
	glTexCoord2d(0,1);  glVertex3f(-25, -10, 0);*/
	glColor4f(1.0,1.0,1.0, 1.0);
	glutSolidSphere(5, 40, 40);
	glPopMatrix();
	glEnd(); 
}



Window::~Window()
{
}

Window::Window()
{

}
