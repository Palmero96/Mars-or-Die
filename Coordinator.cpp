#include "Coordinator.h"

Coordinator::Coordinator()
{
	phase = HOME;
	p = false;
}


Coordinator::~Coordinator() {}

void Coordinator::Draw()
{
	switch (phase)
	{
	case HOME:

		home.Draw();
		if (home.GetText_Gone())
		{
			phase1.Initialize();
			phase = FIRST_PHASE;
		}
		break;

	case PAUSE:

		pause.Draw();
		break;

	case FIRST_PHASE:

		phase1.Draw();
		break;

	case SECOND_PHASE:

		phase2.Draw();
		break;

	case THIRD_PHASE:

		phase3.Draw();
		break;

	default: break;
	}
}

void Coordinator::Timer()
{
	switch (phase)
	{
	case HOME:
		home.Timer();

	case FIRST_PHASE:

		phase1.Timer();
		if (phase1.GetSuccess())	phase1.CloseUp();
		break;

	case SECOND_PHASE:

		phase2.Timer();
		break;

	case THIRD_PHASE:

		phase3.Timer();
		break;
	}
}


void Coordinator::Key(unsigned char key, int x_t, int y_t)
{
	if (phase == HOME)
		home.Key(key, x_t, y_t);

	if (phase == FIRST_PHASE)
		phase1.Key(key, x_t, y_t);

	if (phase == SECOND_PHASE)
		phase2.Key(key, x_t, y_t);

	if (phase == THIRD_PHASE)
		phase3.Key(key, x_t, y_t);

	if (key == 'c')
	{
		switch (phase)
		{
		case FIRST_PHASE:
			phase2.Initialize();
			phase = SECOND_PHASE;
			break;
		case SECOND_PHASE:
			phase3.Initialize();
			phase = THIRD_PHASE;
			break;
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

	if (key == '3')
	{
		phase3.Initialize();
		phase = THIRD_PHASE;
	}
}


void Coordinator::ArrowKey(int key, int x, int y)
{
	if (phase == THIRD_PHASE)
		phase3.SpecialKey(key, x, y);
}