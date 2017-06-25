#pragma once
#include "ETSIDI.h"
#include "Vector2.h"
#include "Interaction.h"
#include "Shot.h"
#include "glut.h"

class Ship2
{
	ETSIDI::SpriteSequence *up, *down;
	ETSIDI::Sprite *ship;
	Vector2 position, velocity, acc;
	float angle;
	class Shot shot[10];
	int dim;
	int move;
	long time;

public:

	Ship2(const char *name);
	Ship2();
	virtual ~Ship2();
	void Move(float t);
	void Initialize();
	void SpecialKey(int key);
	void Draw();

	Vector2 GetPos();
	void SetPos(Vector2);
	void Key(unsigned char key);
	void SetVel(float x, float y);
	Shot* getShot(int i);
	friend class Interaction;
};

