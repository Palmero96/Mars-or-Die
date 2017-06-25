#include "Fuel.h"
#define MAX_X 1000
#define MAX_Y -300
#define MAX_H 5
#define MAX_W 5



Fuel::Fuel(const char *name)
{
	image = new ETSIDI::Sprite(name, rand() % MAX_X, rand() % 600 + MAX_Y, MAX_W, MAX_H);
}



Fuel::~Fuel()
{
}

void Fuel::Draw(Vector2 pos) {
	image->draw();
}
