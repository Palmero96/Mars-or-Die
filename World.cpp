#include "World.h"

World::World() 
{ 
	ship = 0; 
}

World::~World() { delete ship; }

void World::Initialize() {

	srand(time(NULL));

	x_eye = -300;
	y_eye = 320;
	z_eye = 300;

	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetRadius(19);

	earth.SetColor(0.0F, 0.0F, 1.0F);
	earth.SetRadius(3.5);
	earth.SetOrbitRadius(190);
	earth.SetOmega(1.6);
	earth.SetAngle(rand()%360); // sets a random value between 0 and 359 for the first angle

	mars.SetColor(1.0F, 0.5F, 0);
	mars.SetRadius(2.3F);
	mars.SetOrbitRadius(310);
	mars.SetOmega(.8);
	mars.SetAngle(rand() % 360);

	venus.SetColor(0.8F, 0.5F, 1.0F);
	venus.SetRadius(2);
	venus.SetOrbitRadius(30);
	venus.SetOmega(4.8);
	venus.SetAngle(rand() % 360);

}

void World::Draw() 
{
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, -70, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	sun.Draw();
	earth.Draw();
	mars.Draw();
	venus.Draw();
	
	if (ship) 
		ship->Draw();
}

void World::Timer() 
{		
	if (ship) ship->Move();
	earth.Move();
	mars.Move();
	venus.Move();
}

void World::Key(unsigned char key, int x_t, int y_t)
{	
	if (key == 'l')
	{
		ship = new Ship;
		ship->SetPos(earth.GetPos());
	}
}