#pragma once
#include "World.h"
#include "Phase2.h"

class Coordinator
{
	World world;
	Phase2 phase2;
	enum State{HOME, FIRST_PHASE, FIRST_PHASE_DONE, SECOND_PHASE,GAME_OVER};
	State state;

	int text_x;
	bool text_leave;
	bool text_gone;

public:

	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);

	Coordinator();
	virtual ~Coordinator();
};

