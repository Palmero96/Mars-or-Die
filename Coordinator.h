#pragma once
#include "Phase1.h"
#include "Phase2.h"
#include "Pause.h"
#include "Phase3.h"
#include "Home.h"

class Coordinator
{
	Window window;
	Home home;
	Pause pause;
	Phase1 phase1;
	Phase2 phase2;
	Phase3 phase3;
	enum State { HOME, PAUSE, FIRST_PHASE, SECOND_PHASE, THIRD_PHASE, GAME_OVER, END };
	State phase;
	State prevState;	// works as an auxiliar state for the pause implementation

	bool p, a,b,c;   // setting the pause state with only one key
	float t;

public:

	void Draw();
	void Timer();
	void Music();
	void Key(unsigned char key, int x_t, int y_t);
	void ArrowKey(int key, int x, int y);

	Coordinator();
	virtual ~Coordinator();
};

