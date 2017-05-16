#include "Shot.h"

Shot::Shot()	{}

Shot::~Shot()	{}

void Shot::SetPos(Vector2D earth_pos, float r) 
{
	position0 = earth_pos;
	orbit_radius = r;
}


void Shot::Move() 
{
	position1.x = position0.x + 40 * cos(alpha);
	position1.y = position0.y + 40 * sin(alpha);
}

void Shot::Draw()
{
	glPopMatrix();
	glLineWidth(8);
	glColor4f(0.0, 1.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(position0.x, 0, position0.y);
	glVertex3f(position1.x, 0, position1.y);
	glPushMatrix();
	glEnd();
}
