#include "Interaction.h"



Interaction::Interaction()
{
}

Interaction::~Interaction()
{

}

bool Interaction::ProximityOrbit(Vector2 planet_pos, Vector2 ship_pos)
{
	Vector2 r = planet_pos - ship_pos;
	float d = sqrtf(pow(r.x, 2) + pow(r.y, 2));

	if (d < 30)
	{
		return true;
	}
	else
		return false;
}

bool Interaction::Contact(Capsule &c, Obstacle &o)
{
	bool collisionX = c.GetPos().x + c.GetSize().x >= o.GetPos().x &&		//AABB COLLISION (https://learnopengl.com/#!In-Practice/2D-Game/Collisions/Collision-detection)
		o.GetPos().x + o.GetSize().x >= c.GetPos().x;

	bool collisionY = c.GetPos().y + c.GetSize().y - 1 >= o.GetPos().y &&
		o.GetPos().y + o.GetSize().y - 1 >= c.GetPos().y;

	if (collisionX && collisionY)
		return true;
	else
		return false;
}

bool Interaction::Colision(Ship2 sh, Elements *el)
{
	if (sh.ship->collides(*el)) {
		return true;
	}
	return false;
}

bool Interaction::AlienBurn(SpriteSequence flame, Obstacle &alien)
{
	bool collisionX = flame.getPos().x + 7 >= alien.GetPos().x &&
		alien.GetPos().x + alien.GetSize().x >= flame.getPos().x;

	bool collisionY = flame.getPos().y + 9 >= alien.GetPos().y &&
		alien.GetPos().y + alien.GetSize().y - 1 >= flame.getPos().y;

	if (collisionX && collisionY)
	{

		return true;

	}
	else return false;
}

bool Interaction::Contact(Capsule &c, SpriteSequence landPad)
{
	bool collisionX = c.GetPos().x + 4 >= landPad.getPos().x - 10 &&
		c.GetPos().x - 4 <= landPad.getPos().x + 10;

	bool collisionY = c.GetPos().y <= landPad.getPos().y + 1.5;

	if (collisionX && collisionY)	return true;

	else return false;
}

bool Interaction::Contact(Capsule &c, Sprite land)
{
	bool collisionY = c.GetPos().y <= -154;

	bool collision_X = c.GetPos().x + 4 >= -10 &&
		c.GetPos().x - 4 <= 10;

	bool collision_Y = c.GetPos().y <= -153.8;

	if (collisionY || (collision_X && collision_Y))
		return true;

	else return false;
}