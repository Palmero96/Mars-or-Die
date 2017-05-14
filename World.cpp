
#include "World.h"


World::World()	{}

World::~World()	{}

void World::Initialize() {

	x_eye = 130;
	y_eye = 130;
	z_eye = 130;

	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetRadius(19);

	earth.SetPos(-55.0F, 10);
	earth.SetVel(2);
	earth.SetRadius(2);
	earth.SetColor(0.0F, 0.0F, 1.0F);
	earth.SetR_elip(earth.GetInitPos());


	mars.SetPos(69.0, 20);
	mars.SetVel(1);
	mars.SetRadius(1.7F);
	mars.SetR_elip(mars.GetInitPos());
	mars.SetColor(1.0F, 0.5F, 0);

}

void World::Draw() {
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLineWidth(3);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 100.0);
	glEnd();

	sun.Draw();
	earth.Draw();
	mars.Draw();
	shot.Draw();
}

void World::Timer() {
		
	earth.Move(earth.GetVel(), earth.GetD());
	mars.Move(mars.GetVel(), mars.GetD());
	shot.Move(earth.GetPos(), earth.GetAngle());
	
}