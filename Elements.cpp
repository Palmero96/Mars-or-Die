#include "Elements.h"
#define MAX_X 2000
#define MAX_Y 300
#define MAX_H 7
#define MAX_W 7
#include <time.h>


Elements::Elements(TYPE itype, const char *name):Sprite(name, rand() % MAX_X, rand() % (2*MAX_Y) - MAX_Y, MAX_W, MAX_H), type(itype)
{
	//srand(time(NULL));
}

Elements::~Elements()
{
}

void Elements::draw() { Sprite::draw(); }

void Elements::move()
{

}

TYPE Elements::getType()
{
	return type;
}
