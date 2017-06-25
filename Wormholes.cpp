#include "Wormholes.h"
#define MAX_X 300
#define MAX_Y 400
#define MAX_R 20
#define MAX_A 0

Wormholes::Wormholes(const char *name)
{
	Hole1 = new Holes(name);
	Hole2 = new Holes(name);

}


Wormholes::~Wormholes(void)
{
	delete Hole1;
	delete Hole2;
}

void Wormholes::Draw(Vector2 p){}
