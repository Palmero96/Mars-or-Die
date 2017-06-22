#include "LifeBar.h"



LifeBar::LifeBar()
{
}


LifeBar::~LifeBar()
{
}

void LifeBar::Draw()
{
	glPushMatrix();
	glTranslatef(0, 0, -1);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/fuel_unit.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 1);
	glTexCoord2d(0, 0);  glVertex3f(-1.085, -0.4, 0);	// top left
	glTexCoord2d(1, 0);  glVertex3f(-0.88, -0.4, 0); // top right
	glTexCoord2d(1, 1);  glVertex3f(-0.88, -0.485, 0);	// bottom right
	glTexCoord2d(0, 1);  glVertex3f(-1.085, -0.485, 0);// bottom left
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/fuel.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);  glVertex3f(-1.1, 0.5, 0);	// bottom left
	glTexCoord2d(1, 0);  glVertex3f(-0.5, 0.5, 0); // bottom right
	glTexCoord2d(1, 1);  glVertex3f(-0.5, -0.5, 0);	// top right
	glTexCoord2d(0, 1);  glVertex3f(-1.1, -0.5, 0);// top left

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glEnd();

	glDisable(GL_BLEND);				// VERY IMPORTANT! DON'T CHANGE THE ORTHER OF THESE FUNCTIONS BELOW (or the Vogons will come to read us their poetry...)
	glDepthMask(GL_TRUE);

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}
