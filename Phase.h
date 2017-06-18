#pragma once
#include "glut.h"
#include "ETSIDI.h"

class Phase
{
public:

	Phase();
	virtual ~Phase();

	virtual void Draw();
	virtual void Initialize() = 0;
	virtual void Key(unsigned char key, int x_t, int y_t) = 0;
	virtual void Timer() = 0;

};

