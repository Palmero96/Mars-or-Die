#include "World.h"

World::World()	{}

World::~World()	{}

void World::Initialize() {

	x_eye = 300;
	y_eye = 300;
	z_eye = 300;

	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetPos(15.0, 5.0);
	sun.SetRadius(19);

	earth.SetInitPos(-110.0F, 20);
	earth.SetVel(2*0.025);
	earth.SetRadius(3.5);
	earth.SetColor(0.0F, 0.0F, 1.0F);
	earth.SetR_elip(earth.GetInitPos());


	mars.SetInitPos(138.0, 40);
	mars.SetVel(1*0.025);
	mars.SetRadius(2.3F);
	mars.SetR_elip(mars.GetInitPos());
	mars.SetColor(1.0F, 0.5F, 0);

	venus.SetInitPos(-50.0F, 20);
	venus.SetVel(5 * 0.025);
	venus.SetRadius(2);
	venus.SetColor(0.8F, 0.5F, 1.0F);
	venus.SetR_elip(venus.GetInitPos());


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
	shot.Draw();
}

void World::Timer() {
		
	earth.Move(earth.GetVel(), earth.GetD());
	mars.Move(mars.GetVel(), mars.GetD());
	venus.Move(venus.GetVel(), venus.GetD());
	shot.Move(earth.GetPos(), mars.GetD(), earth.GetVel());
	
	
}

void World::Key(unsigned char key, int x_t, int y_t){

	if (key == 'd') {
		shot.Move(earth.GetPos(), mars.GetD(), earth.GetVel());
	
		
	}
}