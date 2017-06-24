#pragma once
#include "glut.h"
#include "ETSIDI.h"

class FuelUnit
{
	int index;
	float x,y;

public:

	FuelUnit(int n);
	virtual ~FuelUnit();
	void Draw();
};

