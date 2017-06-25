#pragma once
#include "Ship2.h"
#include "Obstacle.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Fuel.h"
#include "Wormholes.h"
#include "Vector2.h"
#include "Phase.h"
#define MAX 500

class Phase2 :public Phase
{
	Obstacle* List[MAX];
	float x_eye, y_eye, z_eye;
	Ship2 *ship;
public:
	Phase2() {}
	virtual ~Phase2();
	void Initialize();
	void Draw();
	virtual void Timer();
	virtual void Key(unsigned char key, int x_t, int y_t);
};

