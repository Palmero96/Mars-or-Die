#include "FuelUnit.h"

FuelUnit::FuelUnit(int n)
{
	index = n;
	x = -1.1155;		// let's call these, 'empiric' values ...
	y = -0.535;
}

FuelUnit::~FuelUnit()
{
}

void FuelUnit::Draw()
{
	switch (index)
	{
	case 0:
		break;
	case 1:
		y = -0.535 + 0.125;
		break;
	case 2:
		y = -0.535 + 0.25;
		break;
	case 3:
		y = -0.535 + 0.375;
		break;
	case 4:
		y = -0.535 + 0.5;
		break;
	default:
		break;
	}

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/fuel_unit.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 1);
	glTexCoord2d(0, 0);  glVertex3f(x, y + 0.115, 0);	// top left
	glTexCoord2d(1, 0);  glVertex3f(x + 0.1705, y + 0.115, 0); // top right
	glTexCoord2d(1, 1);  glVertex3f(x + 0.1705, y, 0);	// bottom right
	glTexCoord2d(0, 1);  glVertex3f(x, y, 0);// bottom left
	glEnd();
}