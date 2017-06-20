#include "Coordinator.h"

Coordinator::Coordinator()
{
	phase = HOME;
	p = false;
}

void Coordinator::Draw()
{
	switch (phase)
	{
	case HOME:

		home.Draw();
		if (home.GetText_Gone())
		{
			world.Initialize();
			phase = FIRST_PHASE;
		}
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
	if (phase == HOME)
		home.Key(key, x_t, y_t);

	if (phase == FIRST_PHASE)
	{
		world.Key(key, x_t, y_t);
	}

	if (key == 'c')
	{
		if (phase == FIRST_PHASE)
		{
			phase2.Initialize();
			phase = SECOND_PHASE;
		}

	}

	if (key == 'p')		//	PAUSE
	{
		if (!p)
		{
			prevState = phase;
			phase = PAUSE;
			p = true;
		}
		else
		{
			phase = prevState;
			p = false;
		}

	}
	
}

void Coordinator::Timer()
{
	switch(phase)
	{
	case FIRST_PHASE:
	
		if (world.GetSuccess())
			world.CloseUp();
		world.Timer();
		break;

	case SECOND_PHASE:

		phase2.Timer();
		break;
	}

}

Coordinator::~Coordinator()
{

}
