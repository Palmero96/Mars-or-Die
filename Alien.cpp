#include "Alien.h"
#define MAX_X 1000
#define MAX_Y -300
//#define MAX_H 10
//#define MAX_W 10


Alien::Alien(const char *name)
{
	image = new ETSIDI::Sprite(name, rand() % MAX_X, rand() % 600 + MAX_Y, 5, 5);
	x = rand() % MAX_X;
	y = rand() % MAX_Y;
}


Alien::~Alien()
{
}

void Alien::Draw(Vector2 pos) {
	/*while (-300 < y < 300)y = y + rand() % 10 - 10;
	if (y <=-300)y = y + 100;
	if (y >= 300)y = y - 100;
	image->setPos(x, y);*/
	image->draw();
}
