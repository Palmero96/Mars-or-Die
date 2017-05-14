#include "Shot.h"

Shot::Shot()	{}

Shot::~Shot()	{}


void Shot::Draw() {

	glPopMatrix();
	glLineWidth(2);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(position0.x, 0, position0.y);
	glVertex3f(position1.x, 0, position1.y);
	glPushMatrix();
	glEnd();
}

void Shot::Move(Vector2D pos0, float r, float vel) {

	position0 = pos0;
	position1.x = r * sin(angle + 1); // adding 1 to the angle changes the angle of the end of the shot respect the earths position vertex. This allows it to be out of phase
	position1.y = r * cos(angle + 1);

	angle -= vel;
}