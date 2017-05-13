#include "Planet.h"

Planet::Planet() {}

Planet::~Planet() {}


	//Returns the radius os the orbit of each planet
float Planet::GetD() {

	return sqrtf(pow(position_init.x, 2) + pow(position_init.y, 2));
}


void Planet::SetVel(float v) {ang_vel = v;} //Sets the angular velocity of each planet


float Planet::GetVel() {return ang_vel;}	//Returns the angular velocity set in the initializer


void Planet::Move(float vel) {

	float radius = GetD();
	position.x = cos(alpha) * radius;
	position.y = sin(alpha) * radius;

	alpha = alpha + vel * 0.025; // Multipliying by 0.025 reduces the velocity and makes it easier to see
								   // the velocity applyed in the world.Draw function to each planet.
								   // Eventually we'll use another factor that will primarly reflect the actual velocity of mars
								   // and the earth in the Draw function in the World class
	
}


	
