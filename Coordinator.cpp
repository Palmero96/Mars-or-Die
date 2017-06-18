#include "Coordinator.h"

Coordinator::Coordinator()
{
	state = HOME;
	text_x = -10;
	text_gone = false;
	text_leave = false;
}

void Coordinator::Draw()
{
	switch (state)
	{
	case HOME:
	{
		gluLookAt(0, 8, 20,  // posicion del ojo
			0.0, 8, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/mars_home.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-25, 20, 0);
		glTexCoord2d(1, 1); glVertex3f(25, 20, 0);
		glTexCoord2d(1, 0); glVertex3f(25, -10, 0);
		glTexCoord2d(0, 0); glVertex3f(-25, -10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		if (text_leave)
				text_x++;
		if(text_x >= 25)
		{
			text_gone = true;
			text_leave = false;
			world.Initialize();
		}

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 50);
		ETSIDI::printxy("MARS or Die", text_x, 7);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
		ETSIDI::printxy("Ignacio Hermes Rodriguez & Elena Rodríguez", 0, 0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
		ETSIDI::printxy("Press a to start", -4, 5);

	}
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
	{
		if (key == 'a')
			text_leave = true;
	}
	if (state == FIRST_PHASE)
	world.Key(key, x_t, y_t);
}

void Coordinator::Timer()
{
	if (state == FIRST_PHASE)
	{
		if (world.GetSuccess())
			world.CloseUp();
		world.Timer();
	}
	if (text_gone)
		state = FIRST_PHASE;
}

Coordinator::~Coordinator()
{

}
