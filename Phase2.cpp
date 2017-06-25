#include "Phase2.h"


Phase2::~Phase2() {
	for (int i = 0; i < MAX; i++) delete List[i];
}
void Phase2::Initialize() {
	//	srand(time(NULL));
	ship = new Ship2;
	ship->SetPos(Vector2(0, 0));
	Vector2 aux = ship->GetPos();
	x_eye = aux.x;
	y_eye = 300;
	z_eye = 0;
	for (int i = 0; i<MAX; i++) {
		if (i<200)List[i] = new Asteroid("textures/phase2/Asteroid1.png");
		else if (200 <= i&&i<300)List[i] = new Fuel("textures/phase2/Fuel.png");
		else if (300 <= i&&i<400)List[i] = new Wormholes("Textures/phase2/Fuel.png");
		else if (400 <= i&&i<500)List[i] = new UFO("Textures/phase2/Alien.png");
	}

}
void Phase2::Draw() {
	Vector2 aux;
	aux = ship->GetPos();
	gluLookAt(aux.x, y_eye, z_eye,  // posicion del ojo
		aux.x, aux.y, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 0, 1.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/space1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);  glVertex3f(-300, -50, 500);
	glTexCoord2d(1, 1);  glVertex3f(-300, -50, -500);
	glTexCoord2d(1, 0);  glVertex3f(300, -50, -500);
	glTexCoord2d(0, 0);  glVertex3f(300, -50, 500);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	ship->Draw();
}

void Phase2::Timer() {}
void Phase2::Key(unsigned char key, int x_t, int y_t) {}