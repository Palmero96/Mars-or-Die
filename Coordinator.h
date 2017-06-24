#pragma once
#include "World.h"
#include "Phase2.h"
#include "Pause.h"
#include "Phase3.h"
#include "Home.h"

class Coordinator
{
	Window window;
	Home home;
	Pause pause;
	World world;
	Phase2 phase2;
	Phase3 phase3;
	enum State{HOME, PAUSE, FIRST_PHASE, SECOND_PHASE, THIRD_PHASE, GAME_OVER};
	State phase;
	State prevState;	// works as an auxiliar state for the pause implementation

	bool p;   // setting the pause state with only one key

public:

	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);
	void ArrowKey(int key, int x, int y);

	Coordinator();
	virtual ~Coordinator();
};

