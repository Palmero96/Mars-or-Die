#include "Planet.h"

Planet::Planet() {}

Planet::~Planet() {}


	//Returns the radius os the orbit of each planet
float Planet::GetD() {

	return sqrtf(pow(position_init.x, 2) + pow(position_init.y, 2));
}


void Planet::SetVel(float v) {ang_vel = v;} //Sets the angular velocity of each planet

float Planet::GetAngle() {
	return alpha;
}

float Planet::GetVel() {	
	return ang_vel;}	//Returns the angular velocity set in the initializer


void Planet::Move(float vel, float radius) {

	position.x = cos(alpha) * radius;
	position.y = sin(alpha) * radius;
	
	alpha += vel; 
}


	
