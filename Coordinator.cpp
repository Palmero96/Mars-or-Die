#include "Coordinator.h"

Coordinator::Coordinator()
{
	state = HOME;
	p = false;
}

void Coordinator::Draw()
{
	switch (state)
	{
	case HOME:

		home.Draw();
		if (home.GetText_Gone()) world.Initialize();
		break;

	case PAUSE:

		pause.Draw();
		break;

	case FIRST_PHASE: 

		world.Draw();
		break;

	case SECOND_PHASE: 

		phase2.Draw();
		break;

	default: break;
	}
}

void Coordinator::Key(unsigned char key, int x_t, int y_t)
{
	if (state == HOME)
		home.Key(key, x_t, y_t);
	
	if (state == FIRST_PHASE)
		world.Key(key, x_t, y_t);

	if (key == 'p')
		state = PAUSE;
}

void Coordinator::Timer()
{
	if (state == FIRST_PHASE)
	{
		if (world.GetSuccess())
			world.CloseUp();
		world.Timer();
	}

	if (home.GetText_Gone())
		state = FIRST_PHASE;
}

Coordinator::~Coordinator()
{

}
