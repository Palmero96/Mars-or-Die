#pragma once
#include <math.h>

class Vector2
{
public:
	float x, y;
	
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator+(Vector2);
	Vector2 operator+(float f);
	Vector2 operator-(Vector2);
	Vector2 operator=(Vector2);
	Vector2 operator*(float a);
	float operator*(Vector2 u);
};

