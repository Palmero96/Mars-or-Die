#define EARTH 1.6
#define MARS 0.8
#define VENUS 3.9
#define MERCURY 4.8

#include "World.h"
using ETSIDI::getTexture;

World::World() 
{ 
	ship = 0; 
	success = false;
}

World::~World() {delete ship; }

void World::Initialize() {

	sloMo = false;
	srand(time(NULL));

	x_eye = 0;
	y_eye = 400;
	z_eye = 400;

	x_look = 0;
	y_look = -90;
	z_look = 30;

	sun.SetColor(1.0F, 1.0F, 0);
	sun.SetRadius(20);

	earth.SetColor(0.0F, 0.0F, 1.0F);
	earth.SetRadius(4.5);
	earth.SetOrbitRadius(210);
	earth.SetOmega(EARTH);
	earth.SetAngle(rand()%360); // sets a random value between 0 and 359 for the first angle

	mars.SetColor(1.0F, 0.5F, 0);
	mars.SetRadius(3);
	mars.SetOrbitRadius(350);
	mars.SetOmega(MARS);
	mars.SetAngle(rand() % 360);

	mercury.SetColor(0.5F, 0.0F, 0.5F);
	mercury.SetRadius(2);
	mercury.SetOrbitRadius(30);
	mercury.SetOmega(4.8);
	mercury.SetAngle(rand() % 360);

	venus.SetColor(0.8F, 0.5F, 1.0F);
	venus.SetRadius(2.8);
	venus.SetOrbitRadius(60);
	venus.SetOmega(3.9);
	venus.SetAngle(rand() % 360);

	ETSIDI::playMusica("music/home_song.mp3", true);

}

void World::Draw() 
{
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/space1.png").id);
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
	
	sun.Draw();
	mercury.Draw();
	earth.Draw();
	mars.Draw();
	venus.Draw();
	
	if (ship)
		ship->Draw();

}

void World::Timer() 
{		
	if (ship) {
		if (Interaction::ProximityOrbit(mars.GetPos(), ship->GetPos()))
			ship->SetOrbit(true);

		if (ship->GetOrbit())
		{
			ship->OrbitAround(mars.GetPos()); // with this condition on you are able to pass to the next phase
			success = true;
			x_look = mars.GetPos().x;
			z_look = mars.GetPos().y;
			y_look = 0;
		}
		else
			ship->Move();
	}
	earth.Move();
	mercury.Move();
	mars.Move();
	venus.Move();
	
}

void World::CloseUp()
{
	float t = 0.025;

	if(y_eye > 9)
		y_eye -= y_eye * t;
	if( z_eye > mars.GetOrbitRadius() + 10)
	{
		z_eye --;
	}
	if (x_eye > mars.GetOrbitRadius() + 10)
	{
		x_eye --;
	}

}

bool World::GetSuccess()
{
	return success;
}

void World::Key(unsigned char key, int x_t, int y_t)
{
	if (key == ' ')
	{
		if (!sloMo)
		{
			sloMo = true;
			ship = new Ship;
			ship->SetPos(earth.GetPos());
			ship->SetOmega(earth.GetOmega());
			ship->GetAV(mars.GetPos());
			earth.SetOmega(EARTH * 0.1);
			mars.SetOmega(MARS * 0.1);
			venus.SetOmega(VENUS * 0.1);
			mercury.SetOmega(MERCURY * 0.1);
		}
		else
		{
			sloMo = false;
			earth.SetOmega(EARTH);
			mars.SetOmega(MARS);
			mercury.SetOmega(MERCURY);
			venus.SetOmega(VENUS);
			ship->SetT(2.5);
		}
	}
}