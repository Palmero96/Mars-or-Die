#pragma once
#include "Ship2.h"
#include "Vector2.h"
#include "Phase.h"
#include "Elements.h"
#include "Puntuation.h"
#include "ETSIDI.h"
#include "Alien.h"
#define MAX 600

class Phase2 :public Phase
{
	Elements *List[MAX];
	float x_eye, y_eye, z_eye;
	Ship2 *spacecraft;
	Puntuation punt;
	int elim;
	ETSIDI::SpriteSequence *explosion;
	bool boom;
	int explosion_time, invincible_time;
	bool tutorial, game, succes,gameover;
	bool invincible;
public:
	Phase2();
	virtual ~Phase2();
	void Initialize();
	void Draw();
	virtual void Timer();
	virtual void Key(unsigned char key, int x_t, int y_t);
	void SpecialKey(int key);
};

