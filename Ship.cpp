#include "Ship.h"

Ship::Ship()	
{
	radius = 1;
	acc.y = 0;
	acc.x = 0;
	t = 0.05;
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
	position = position + vel * t + acc * pow(t, 2);
	vel = vel + acc * t;
}

void Ship::SetPos(Vector2D pos)
{
	position = pos;
	
	vel.y =  (95000/ (pos.x * pos.x + pos.y * pos.y));
	vel.x =  (-(pos.y / pos.x) * (95000/ (pos.x * pos.x + pos.y * pos.y)));
	
//	vel = vel + pos;

}