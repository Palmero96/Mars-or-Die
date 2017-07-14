#include "Alien.h"
#define vel 3



Alien::Alien(const char *name, TYPE itype) :Elements(itype, name)
{
	pos.x = getPos().x;
	pos.y = getPos().y;
	setSize(15, 5);
	velo = rand() % (2 * vel) - vel;
}


Alien::~Alien()
{
}


void Alien::draw() {
	setPos(pos.x, pos.y);
	Sprite::draw();
}

void Alien::move() {
	pos.y += velo* 0.25;
	if (pos.y > 300)pos.y = -300;
	if (getPos().y < -300)pos.y = 300;
}
