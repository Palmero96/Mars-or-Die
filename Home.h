#pragma once
#include "Capsule.h"
#include "Phase.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

class Home : public Phase
{
	SpriteSequence *flame;
	int text_x;
	bool text_leave;
	bool text_gone;

public:
	Home();
	~Home();

	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);
	void Initialize();

	void SetText_x(int);
	int GetText_x();

	void SetText_Gone(bool);
	bool GetText_Gone();

	void SetText_Leave(bool);
	bool GetText_Leave();

};

