#pragma once
#include "ETSIDI.h"
#include "Vector2.h"
#include "Interaction.h"
#include "Shot.h"
#include "glut.h"

class Ship2
{
	ETSIDI::SpriteSequence *up, *down, *center;
	ETSIDI::Sprite *ship;
	Vector2 position, velocity, acc;
	float angle;
	bool undraw;
	bool die;
public:

	Ship2(const char *name);
	Ship2();
	virtual ~Ship2();
	void Move(float t);
	void Initialize();
	void SpecialKey(int key);
	void Draw();
	bool Win();
	void reset();
	ETSIDI::Vector2D getPos();
	ETSIDI::Vector2D getCenter();
	void stop();

	Vector2 GetPos();
	void Key(unsigned char key);
	friend class Interaction;
};

