#pragma once
class Vector2D
{
public:
	float x, y;
	
	Vector2D();
	~Vector2D();

	Vector2D operator+(Vector2D u);
	Vector2D operator-(Vector2D u);
};

