#pragma once
#include "Vector2.h"
#include "glut.h"
class Shot
{
	float radio;
	Vector2 pos, vel;
public:
	Shot();
	virtual ~Shot();
	void Draw(Vector2 pos);
	void Move(unsigned char key, Vector2 pos, Vector2 vel);
	Vector2 getPos();
	friend class Interaction;
};

