#include "Ship.h"

Ship::Ship()	
{
	radius = 1;
	vel.x = 0;
	vel.y = 0;
	acc.x = 0;
	acc.y = 0;
}

Ship::~Ship()	{}


void Ship::Draw()
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(position.x, 0, position.y);
	glutSolidSphere(radius, 15, 15);
	glPopMatrix();
}

void Ship::Move()
{
	vel.x = position.x * 0.5;
	vel.y = position.y * 0.5;
	MovingObject::Move();
}
