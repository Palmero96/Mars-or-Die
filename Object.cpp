#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}


Vector2 Object::GetPos()
{
	return position;
}

void Object::SetPos(Vector2 pos)
{
	position = pos;
}