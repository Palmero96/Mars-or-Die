#include "Phase2.h"

Phase2::Phase2()	
{
	x_eye = 0;
	y_eye = 20;
	z_eye = 60;
}

Phase2::~Phase2()	{}

void Phase2::Initialize()
{

}

void Phase2::Draw()
{
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 60, 00,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void Phase2::Timer()
{

}

void Phase2::Key(unsigned char key, int x_t, int y_t)
{

}
