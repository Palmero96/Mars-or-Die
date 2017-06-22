#pragma once
#include <string>
#include "glut.h"
#include "ETSIDI.h"

class Window
{
	char* text;
	int x, y;

public:
	Window();
	void Draw(float, float, int);
	~Window();
};

