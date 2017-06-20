#include "Vector2D.h"

Vector2::Vector2()	{}

Vector2::Vector2(float u_x, float u_y)
{
	x = u_x;
	y = u_y;
}

Vector2::~Vector2()	{}

Vector2 Vector2::operator+(Vector2 u){

	return Vector2(x + u.x, y + u.y);
}

Vector2 Vector2::operator+(float f) {

	x += f;
	y += f;
	return *this;
}

Vector2 Vector2::operator*(float a)
{
	Vector2 v;
	v.x = x * a;
	v.y = y * a;
	return v;
}

Vector2 Vector2::operator=(Vector2 u) 
{	
	x = u.x;
	y = u.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 u)
{
	return Vector2(x - u.x, y - u.y);
}

float Vector2::operator*(Vector2 u) {

	return  (x * u.x + y * u.x);

}

float Vector2::angle(Vector2 v)
{
	float num = x * v.x + y * v.y;
	float den = sqrtf(x * x + y * y) * sqrtf(v.x * v.x + v.y + v.y);
	return (num / den);
}