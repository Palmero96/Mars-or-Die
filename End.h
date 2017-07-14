#pragma once
#include "Phase.h"
#include <stdio.h>

class End :
	public Phase
{
public:
	End();
	~End();

	void SetPoints(Puntuation);
	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
};

