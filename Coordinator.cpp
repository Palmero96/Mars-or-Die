#include "Coordinator.h"

Coordinator::Coordinator()
{
	phase = HOME;
	p = a = b = c = d = false;
	phase1 = 0;
	phase2 = 0;
	phase3 = 0;
	end = 0;
	gameOver = 0;
	t = 0;
}

Coordinator::~Coordinator() {}

void Coordinator::Draw()
{
	switch (phase)
	{
	case HOME:
		
		home.Draw();
		break;

	case PAUSE:

		pause.Draw();
		break;

	case FIRST_PHASE:

		if(phase1)
		phase1->Draw();
		break;

	case SECOND_PHASE:

		if(phase2)
		phase2->Draw();
		break;

	case THIRD_PHASE:

		if(phase3)
		phase3->Draw();
		break;

	case GAME_OVER:
		if(gameOver)
		gameOver->Draw();
		break;

	case END:
		if(end)
		end->Draw();
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
		if (!c)
		{
			ETSIDI::playMusica("music/home_song.mp3", true);
			c = true;
		}
		break;

	case SECOND_PHASE:
		if (!d) {
			ETSIDI::playMusica("music/phase2.wav", true);
			d = true;
		}
		break;

	case THIRD_PHASE:
		if (!a)
		{
			ETSIDI::playMusica("music/phase3_song.mp3", false);
			a = true;
		}

		if (phase3)
		{
			switch (phase3->GetStatus())
			{

			case 1:
				t += 0.025;
				if (!b)
				{
					ETSIDI::playMusica("music/final_song.mp3", false);
					b = true;
				}
				if (t >= 7.12)
				{
					end = new End;
					phase = END;
				}
				break;

			default:
				break;
			}
		}

		break;
	}
}

void Coordinator::Timer()
{
	switch (phase)
	{
	case HOME:
		if (home.GetText_Gone())
		{
			phase1 = new Phase1;
			phase1->Initialize();
			phase = FIRST_PHASE;
		}
		home.Timer();

	case FIRST_PHASE:
		if (phase1)
		{
			phase1->Timer();
			if (phase1->GetStatus())
			{
				phase2 = new Phase2;
				phase2->Initialize();
				phase = SECOND_PHASE;
			}
		}
		break;

	case SECOND_PHASE:
		
		if(phase2)
		phase2->Timer();
		break;

	case THIRD_PHASE:

		if (phase3)
		{
			phase3->Timer();

			switch (phase3->GameOver())
			{
			case 1:
				t += 0.025;
				if (t > 5)
				{
					gameOver = new GameOver();
					phase = GAME_OVER;
				}
				break;

			case 0:
				break;
			}
		}
		break;

	case END:

		if(end)
		end->SetPoints(phase2->GetPoints() + phase3->GetPoints());
		break;
	}
}


void Coordinator::Key(unsigned char key, int x_t, int y_t)
{
	switch (phase)
	{
	case HOME:
		home.Key(key, x_t, y_t);
		break;

	case FIRST_PHASE:
		phase1->Key(key, x_t, y_t);
		break;

	case SECOND_PHASE:
		phase2->Key(key, x_t, y_t);
		break;

	case THIRD_PHASE:
		phase3->Key(key, x_t, y_t);
		break;

	case GAME_OVER:
		gameOver->Key(key, x_t, y_t);
		break;

	case END:
		end->Key(key, x_t, y_t);
		break;
	}

	if (key == 'c')
	{
		switch (phase)
		{
		case FIRST_PHASE:

			phase2 = new Phase2;
			phase2->Initialize();
			phase = SECOND_PHASE;
			break;

		case SECOND_PHASE:

			phase3 = new Phase3;
			phase3->Initialize();
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
}


void Coordinator::ArrowKey(int key, int x, int y)
{
	if (phase == SECOND_PHASE)
		phase2->SpecialKey(key);
	if (phase == THIRD_PHASE)
		phase3->SpecialKey(key, x, y);
}