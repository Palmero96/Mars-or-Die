#include "Capsule.h"

Capsule::~Capsule() {}

Capsule::Capsule(const char *name) : Sprite(name, position.x, position.y, 0, 0)
{
	position.x = 0;
	position.y = 0;

	MovingObject::vel.x = 0;
	MovingObject::vel.y = -3;

	acc.x = 0;
	acc.y = 0;

	alive = true;

	life = 3;
	fuel = 7;

	burnTime = 0;
	explosion = 0;
	flame = flame2 = flame3 = 0;
	explosionStarted = burn = burning = false; 

	setSize(8, 9);
}

void Capsule::Draw()
{

	switch (alive)	// this way, if it's not alive it won't be drawn. Genius, right?
	{
	case true:		

		draw();
		
		if (flame)
		{
			flame->setAngle(180);
			flame->setPos(position.x + 3.9, position.y - 2.6);
			flame->draw();

			flame2->setAngle(180);
			flame2->setPos(position.x + 6, position.y);
			flame2->draw();

			flame3->setAngle(180);
			flame3->setPos(position.x + 2, position.y);
			flame3->draw();
		}
		break;

	case false:

		if (!explosionStarted)
		{
			explosion = new SpriteSequence("textures/phase3/explosion.png", 5, 4, 50, false, position.x + 5, position.y + 6 , 10, 10);
			explosionStarted = true;
			break;
		}
	}

	if (explosion)
	{
		explosion->draw();

	}

	if (burn)
	{
		flame = new SpriteSequence("textures/phase3/flame.png", 5, 4, 50, false, position.x, position.y, 7, 9);
		flame2 = new SpriteSequence("textures/phase3/blueflame.png", 5, 4, 50, false, position.x, position.y, 3, 6);
		flame3 = new SpriteSequence("textures/phase3/blueflame.png", 5, 4, 50, false, position.x, position.y, 3, 6);


		fuel--;
		burn = false;
		burning = true;
		acc = Vector2(0, 3.5);

		ETSIDI::play("music/burn.wav");
	}

	if (burning)
	{
		burnTime++;

		if (burnTime >= 35)
		{
			acc = Vector2(0, -3);
			burnTime = 0;
			burning = false;
		}
	}

}

void Capsule::Move()
{
	if (alive)
	{
		if (MovingObject::vel.y < -3)	MovingObject::vel.y = -3;

		if (MovingObject::vel.x > 30)	MovingObject::vel.x = 30;

		if (MovingObject::vel.x < -30)	MovingObject::vel.x = -30;


		if (position.x <= -50)
			position.x = 50;
		if (position.x > 50)
			position.x = -50;

		float t = 0.025;

		position = position + MovingObject::vel * t + (acc)* t * t;
		MovingObject::vel = MovingObject::vel + acc * t;

		setPos(position.x, position.y);

		if (flame)
		{
			flame->loop();
			flame2->loop();
			flame3->loop();
		}
	}
	if (explosion)
		explosion->loop();
}

void Capsule::Land()
{
	MovingObject::vel = Vector2(0, 0);
	fuel--;
	if (flame)
	{
		flame->loop();
		flame2->loop();
		flame3->loop();
	}
}

void Capsule::SetVel(Vector2 v)		{ MovingObject::vel = v; }

Vector2 Capsule::GetVel()			{ return MovingObject::vel; }

void Capsule::SetAlive (bool b)		{ alive = b; }

bool Capsule::Alive()				{ return alive; }

void Capsule::SetLife(int x)		{ life = x;	}

int Capsule::GetLife()				{ return life; }

void Capsule::SetBurn(bool b)		{ burn = b; }

bool Capsule::GetBurn()				{ return burn; }

int Capsule::GetFuel()				{ return fuel; }

Vector2 Capsule::GetSize()			{ return Vector2(_width, _height); }

void Capsule::SetFuel(int f)		{ fuel = f; }

bool Capsule::GetBurning()			{ return burning; }

SpriteSequence Capsule::GetFlame()  { if(flame) return *flame; }