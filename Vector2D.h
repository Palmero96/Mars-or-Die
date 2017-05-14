#pragma once
#include <math.h>

class Vector2D
{
public:
	float x, y;
	
	Vector2D();
	~Vector2D();

	Vector2D operator+(Vector2D u);
	Vector2D operator-(Vector2D u);
	float operator*(Vector2D u);

	float mod();
	float angle(Vector2D);
};

