#include "Flame.h"



Flame::Flame(const char *name)
{
	image = new ETSIDI::Sprite(name, position.x, position.y, 20, 20);
}


Flame::~Flame()
{
}

void Flame::Draw()
{
	image->setPos(position.x, position.y);
	image->draw();
}