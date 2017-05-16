#include "Vector2D.h"

Vector2D::Vector2D()	{}

Vector2D::~Vector2D()	{}

Vector2D Vector2D::operator+(Vector2D u){

	Vector2D v;
	v.x = x + u.x;
	v.y = y + u.y;
	return v;
}

Vector2D Vector2D::operator+(float f) {

	x += f;
	y += f;
	return *this;
}

Vector2D Vector2D::operator=(Vector2D u) {

	x = u.x;
	y = u.y;
	return *this;
}
Vector2D Vector2D::operator-(Vector2D u){

	Vector2D v;
	v.x = x - u.x;
	v.y = y - u.y;
	return v;
}

float Vector2D::operator*(Vector2D u) {

	return  (x * u.x + y * u.x);

}

float Vector2D::mod() {
	return sqrtf(pow(x, 2) + pow(y, 2));
}

float Vector2D::angle(Vector2D u) {

	float w = x * u.x + y * u.x;
	float a = mod();
	float b = u.mod();
	float c = cosf(w / (a*b));

	return acosf(c);
}