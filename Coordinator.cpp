#include "Coordinator.h"

Coordinator::Coordinator()
{
	phase = HOME;
	p = a = b = c = false;
	t = 0;
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
		if (!c)
		{
			ETSIDI::playMusica("music/home_song.mp3", true);
			c = true;
		}

		phase1.Draw();
		break;

	case SECOND_PHASE:

		phase2.Draw();
		break;

	case THIRD_PHASE:

		phase3.Draw();
		break;

	case GAME_OVER:

		break;
	case END:

		break;

	default: break;
	}
}

void Coordinator::Music()
{
	switch (phase)
	{
	case HOME:
		break;

	case FIRST_PHASE:
		break;

	case SECOND_PHASE:
		break;

	case THIRD_PHASE:
		if (!a)
		{
			ETSIDI::playMusica("music/phase3_song.mp3", false);
			a = true;
		}
		switch (phase3.GetStatus())
		{

		case 1:
			t += 0.025;
			if (!b)
			{
				ETSIDI::playMusica("music/final_song.mp3", false);
				b = true;
			}
			if (t >= 7.12) phase = END;
			break;

		case END:
			break;

		default:
			break;
		}

		break;
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
		if (phase1.GetStatus())	phase = SECOND_PHASE;
		break;

	case SECOND_PHASE:

		phase2.Timer();
		break;

	case THIRD_PHASE:

		phase3.Timer();

		switch (phase3.GameOver())
		{
			case 1:
				t += 0.025;
					if(t>5)
				phase = GAME_OVER;
				break;
			case 0:		
				break;
		}

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
	if (phase == SECOND_PHASE)
		phase2.SpecialKey(key);
	if (phase == THIRD_PHASE)
		phase3.SpecialKey(key, x, y);
}