#pragma once
#include "glut.h"
class Phase2
{
	float x_eye, y_eye, z_eye;

public:


	Phase2();
	virtual ~Phase2();

	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
};

