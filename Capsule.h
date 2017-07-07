#pragma once
#include "glut.h"
#include "MovingObject.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Capsule : public MovingObject, public Sprite
{
	SpriteSequence *explosion, *flame, *flame2, *flame3;
	int life, fuel;
	float burnTime;
	bool  alive, explosionStarted, burn, burning;

public:

	Capsule(const char *name);
	~Capsule();

	void Move();
	void Draw();

	void SetVel(Vector2);
	Vector2 GetVel();

	Vector2 GetSize();
	
	int GetLife();
	void SetLife(int);

	int GetFuel();
	void SetFuel(int);

	bool Alive();
	void SetAlive(bool);

	void SetBurn(bool);
	bool GetBurn();

	SpriteSequence GetFlame();

	bool GetBurning();
};

