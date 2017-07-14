#include "Phase.h"



Phase::Phase()
{
	game_over = game_status = false;
}


Phase::~Phase()
{
}


void Phase::Draw()
{
	gluLookAt(0, 8, 20,  // posicion del ojo
		0.0, 8, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

Puntuation Phase::GetPoints()
{
	return punt;
}