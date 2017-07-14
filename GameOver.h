#pragma once
#include "Phase.h"
class GameOver :
	public Phase
{
public:
	GameOver();
	virtual ~GameOver();
	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
};

