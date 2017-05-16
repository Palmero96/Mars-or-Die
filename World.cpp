#include "World.h"

World::World()	{ship=0;}

World::~World()	{}

void World::Initialize() {

	srand(time(NULL));

	x_eye = -250;
	y_eye = 300;
	z_eye = 250;

	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetRadius(19);

	earth.SetColor(0.0F, 0.0F, 1.0F);
	earth.SetRadius(3.5);
	earth.SetOrbitRadius(110);
	earth.SetVel(1.8);
	earth.SetAngle(rand()%360);

	mars.SetColor(1.0F, 0.5F, 0);
	mars.SetRadius(2.3F);
	mars.SetOrbitRadius(160);
	mars.SetVel(1);
	mars.SetAngle(rand() % 360);

	venus.SetColor(0.8F, 0.5F, 1.0F);
	venus.SetRadius(2);
	venus.SetOrbitRadius(30);
	venus.SetVel(5);
	venus.SetAngle(rand() % 360);

}

void World::Draw() {
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	sun.Draw();
	earth.Draw();
	mars.Draw();
	venus.Draw();
	if(ship)ship->Draw();
}

void World::Timer() 
{		
	if (ship)ship->Move();
	earth.Move();
	mars.Move();
	venus.Move();
	
}

void World::Key(unsigned char key, int x_t, int y_t)
{

}