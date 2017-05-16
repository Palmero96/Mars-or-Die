#include "Ship.h"

Ship::Ship()	
{

	radius = 1;
	vel = 2;
}

Ship::~Ship()	{}

void Ship::SetLaunchVel(Vector2D vel) 
{
	launch_vel = vel;
}

void Ship::SetInitPos(Vector2D pos0)
{
	position = pos0;
}
void Ship::getTotVel(Vector2D earth_vel) 
{	
	v_tot = launch_vel + earth_vel;
	v_tot.x = launch_vel.x + earth_vel.x;
	v_tot.y = launch_vel.y + earth_vel.y;
}

void Ship::Draw()
{
	glPopMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(position.x, 0, position.y);
	glutSolidSphere(1.0, 15, 15);
	glPushMatrix();
}

void Ship::Move()
{
	position.x = position.x + v_tot.x * 0.025;
	position.y = position.y + v_tot.y * 0.025;
}

