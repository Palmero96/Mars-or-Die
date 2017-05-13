#include "World.h"


World::World()	{}

World::~World()	{}

void World::Initialize() {

	x_eye = 130;
	y_eye = 150;
	z_eye = -130;

	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetRadius(19);

	earth.SetPos(-55.0F, 10);
	earth.SetVel(2);
	earth.SetRadius(2);
	earth.SetColor(0.0F, 0.0F, 1.0F);
	earth.SetR_elip(earth.GetPos());

	mars.SetPos(69.0, 20);
	mars.SetVel(1);
	mars.SetRadius(1.7F);
	mars.SetR_elip(mars.GetPos());
	mars.SetColor(1.0F, 0.5F, 0);

	emitter.SetAmbient(1.0, 1.0, 1.0, 1.0);
	emitter.SetDiffuse(1.0, 1.0, 1.0, 1.0);




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
	
}

void World::Timer() {
		
	earth.Move(earth.GetVel());
	mars.Move(mars.GetVel());
}