#pragma once
#include "ETSIDI.h"
#include "MovingObject.h"
#include "Vector2.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Obstacle : public MovingObject
{
protected:

	Sprite *image;
	friend class Interaction;
public:

	Obstacle();
	Obstacle(const char*);
	~Obstacle();

	virtual void Draw(Vector2 pos);
	void Move();
	void Draw();
	void SetPos(float, float);
	void SetSize(float, float);
	bool Collision(Sprite);

	Sprite getImage() { return *image; }
};

