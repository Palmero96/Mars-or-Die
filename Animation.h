#pragma once
#include "ETSIDI.h"
#include "Vector2.h"
class Animation
{
	ETSIDI::SpriteSequence *explosion;
	ETSIDI::SpriteSequence *flame;
public:
	Animation();
	~Animation();
	void Draw();
	void Move();
	void SetPos(Vector2 pos);


};

