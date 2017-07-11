#pragma once
#include "Elements.h"
class Alien :public Elements
{
	Vector2 pos;
	float velo;
public:
	Alien(const char *name = "textures/phase2/Alien.png", TYPE itype = ALIEN);
	~Alien();
	void draw();
	void move();
	friend class Interaction;
};

