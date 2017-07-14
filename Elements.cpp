#include "Elements.h"
#define MAX_X 3000
#define MAX_Y 200
#define MAX_H 7
#define MAX_W 7
#include <time.h>


Elements::Elements(TYPE itype, const char *name) :Sprite(name, rand() % MAX_X, rand() % (2 * MAX_Y) - MAX_Y, MAX_W, MAX_H), type(itype)
{
	if (type == ASTEROID1) setSize(12, 12);
	if (type == ASTEROID2) setSize(12, 12);
	if (type == ASTEROID3) setSize(12, 12);
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
