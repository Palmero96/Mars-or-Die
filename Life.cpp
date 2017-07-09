#include "Life.h"
#include "glut.h"


Life::Life()
{
	for (int i = 0; i < 3; i++)
	{
		Sprite *l = new Sprite("textures/phase3/nave.png", 0.8 + i*0.075, 0.5, 0.05, 0.05);
		life.Add(l);
		int n = life.GetNum();
		life.SetNum(n++);
	}
}

Life::~Life()
{
	//life.DestroyContent();
}

void Life::Draw()
{
	glPushMatrix();
	glTranslatef(0, 0, -1);

	glEnable(GL_TEXTURE_2D);

	life.Spec(&Sprite::draw);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/nave.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);  glVertex3f(-1.15, 0.55, 0);	// top left
	glTexCoord2d(1, 0);  glVertex3f(-0.92, 0.55, 0); // top right
	glTexCoord2d(1, 1);  glVertex3f(-0.92, -0.57, 0);	// bottom right
	glTexCoord2d(0, 1);  glVertex3f(-1.15, -0.57, 0);// bottom left

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

int Life::GetNum() { return life.GetNum(); }

void Life::SetNum(int n) { life.SetNum(n); }

