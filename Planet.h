#pragma once
#include "Sphere.h"

class Planet : public Sphere{

	float spin;
	float alpha;
	float ang_vel;
	float radius;
	
public:

	void Move(float, float);
	void SetVel(float);
	float GetVel();
	float GetD();
	float GetAngle();

	Planet();
	~Planet();

};

