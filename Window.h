#pragma once
#include <string>
class Window
{
	char *text;
	int x, y;

public:
	Window(int x, int y, char*);
	Window();
	~Window();
};

