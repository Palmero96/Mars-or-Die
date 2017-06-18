#pragma once
#include "Phase.h"

class Pause : public Phase
{
public:

	Pause();
	virtual ~Pause();

	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
};

