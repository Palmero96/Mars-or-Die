#include "Vector2D.h"

Vector2D::Vector2D()	{}

Vector2D::~Vector2D()	{}

Vector2D Vector2D::operator+(Vector2D u){

	Vector2D v;
	v.x = x + u.x;
	v.y = y + u.y;
	return v;
}

Vector2D Vector2D::operator-(Vector2D u){

	Vector2D v;
	v.x = x - u.x;
	v.y = y - u.y;
	return v;
}