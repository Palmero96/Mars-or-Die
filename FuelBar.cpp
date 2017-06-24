#include "FuelBar.h"

FuelBar::FuelBar()
{
	for (int i = 0; i < 3; i++)
	{
		FuelUnit *gas = new FuelUnit(i);
		fuel.Add(gas);
		int n = fuel.GetNum();
		fuel.SetNum(n++);
	}
}


FuelBar::~FuelBar()
{
	fuel.DestroyContent();
}

void FuelBar::Draw()
{
	glPushMatrix();
	glTranslatef(0, 0, -1);

	glEnable(GL_TEXTURE_2D);

	fuel.Draw();

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/fuel.png").id);
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

void FuelBar::Burn()
{
	fuel.Remove();
}

int FuelBar::GetNum()
{
	return fuel.GetNum();
}