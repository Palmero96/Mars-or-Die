#pragma once
#include "ETSIDI.h"
#include "Vector2.h"
#include "Interaction.h"

enum TYPE {ASTEROID1,ASTEROID2,ASTEROID3,FUEL,BONUS,LIFE,ALIEN};

class Elements: public ETSIDI::Sprite
{
	TYPE type;
public:
	Elements(TYPE itype, const char *name);
	~Elements();
	virtual void draw();
	virtual void move();
	TYPE getType();
	friend class Interaction;
};

