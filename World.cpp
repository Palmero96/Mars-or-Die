#include "World.h"


World::World()	{}

World::~World()	{}

void World::Initialize() {

	x_eye = 110;
	y_eye = 70;
	z_eye = 110;

	sun.SetColor(1.0, 1.0, 0);
	sun.SetRadius(5);

	earth.SetPos(-40.0, 10);
	earth.SetRadius(1);
	earth.SetColor(0.0, 0.0, 1.0);

	mars.SetPos(40.0, 20);
	mars.RiseRadius(0.7);
	mars.SetColor(1.0, 0.5, 0);

	d = sqrt(pow(x_eye, 2) + pow(y_eye, 2));
	theta = atan2(x_eye, y_eye);
}

void World::Draw() {
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	sun.Draw();
	earth.Draw();
	mars.Draw();
}

void World::Timer() {
		
	theta += 0.005;
	x_eye = d*cos(theta);
	z_eye = d*sin(theta);

}