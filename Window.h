#pragma once
#include <string>
#include "glut.h"
#include "ETSIDI.h"

class Window
{
	int x, y;

public:
	Window();
	void Draw(float, float, int);
	~Window();
};