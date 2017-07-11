#define EARTH 1.6
#define MARS 0.8
#define VENUS 3.9
#define MERCURY 4.8

#include "Phase1.h"
using ETSIDI::getTexture;

Phase1::Phase1()
{
	ship = 0;
	ang = 0;
	game_status = 0;
	w = q = a = 0;
}

Phase1::~Phase1() { delete ship; }

void Phase1::Initialize() {

	sloMo = false;
	srand(time(NULL));

	x_eye = 0;
	y_eye = 400;
	z_eye = 400;

	x_look = 0;
	y_look = -90;
	z_look = 30;

	sun.SetColor(1.0F, 1.0F, 1.0F);
	sun.SetRadius(20);

	earth.SetIni(1.0F, 1.0F, 1.0F, 6, 200, EARTH);//4.5

	mars.SetIni(1.0F, 1.0F, 1.0F, 5.5, 320, MARS);//3

	mercury.SetIni(1.0F, 1.0F, 1.0F, 3.5, 30, MERCURY);//2
													   //Se inicializa venus
	venus.SetIni(1.0F, 1.0F, 1.0F, 2, 60, VENUS);//2.8



}

void Phase1::Draw()
{
	if (y_eye < 15)
	{
		switch (q)
		{
		case 0:
			window.Draw(0, 0, 3);
			break;
		case 1:
			window.Draw(0, 0, 4);
			break;
		case 2:
			window.Draw(0, 0, 5);
			break;
		}

	}

	if (y_eye > 15)
	{
		switch (w)
		{
		case 0:
			w1.Draw(0, 0, 0);
			break;

		case 1:
			w1.Draw(0, 0, 1);
			break;

		case 2:
			w1.Draw(0, 0, 2);
			break;

		default:
			break;
		}

	}

	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/space1.png").id);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);  glVertex3f(-800, -50, 500);
	glTexCoord2d(1, 1);  glVertex3f(-800, -50, -500);
	glTexCoord2d(1, 0);  glVertex3f(-200, -50, -500);
	glTexCoord2d(0, 0);  glVertex3f(-200, -50, 500);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/space1.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);  glVertex3f(-300, -50, 500);
	glTexCoord2d(1, 1);  glVertex3f(-300, -50, -500);
	glTexCoord2d(1, 0);  glVertex3f(300, -50, -500);
	glTexCoord2d(0, 0);  glVertex3f(300, -50, 500);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/space1.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);  glVertex3f(200, -50, 500);
	glTexCoord2d(1, 1);  glVertex3f(200, -50, -500);
	glTexCoord2d(1, 0);  glVertex3f(800, -50, -500);
	glTexCoord2d(0, 0);  glVertex3f(800, -50, 500);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHT0);

	sun.Draw("textures/phase1/Sun.png");
	mercury.Draw("textures/phase1/Mercury.png");
	earth.Draw("textures/phase1/Tierra.png");
	mars.Draw("textures/phase1/Mars.png");
	venus.Draw("textures/phase1/Venus.png");

	if (ship)
		ship->Draw();
}

void Phase1::Timer()
{
	if (ship) {
		if (Interaction::ProximityOrbit(mars.GetPos(), ship->GetPos()))
			ship->SetOrbit(true);

		if (ship->GetOrbit())
		{
			if (!a)
			{
				play("music/ship.wav");
				a = true;
			}
			ship->OrbitAround(mars.GetPos()); // with this condition on you are able to pass to the next phase
			CloseUp();
			x_look = mars.GetPos().x;
			z_look = mars.GetPos().y;
			y_look = 0;
			earth.SetOmega(EARTH);
			mars.SetOmega(MARS);
			mercury.SetOmega(MERCURY);
			venus.SetOmega(VENUS);
		}

		else
			ship->Move();
	}
	earth.Move();
	mercury.Move();
	mars.Move();
	venus.Move();

}

void Phase1::CloseUp()
{
	float t = 0.025;

	if (y_eye > 9)
		y_eye -= y_eye * t;
	if (z_eye > mars.GetOrbitRadius() + 10)
		z_eye--;
}

void Phase1::Key(unsigned char key, int x_t, int y_t)
{
	if (key == ' ')
	{
		w++;
		if (w <= 3) play("music/beep.wav");
		if (w > 3 && y_eye > 15)
		{
			if (!sloMo)
			{
				play("music/launch.wav");
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

		if (y_eye < 15)
		{
			q++;
			play("music/beep.wav");
			if (q > 3)
				game_status = true;
		}
	}
}

float Phase1::GetEye(char c)
{
	switch (c)
	{
	case 'x':
		return x_eye;
		break;
	case 'y':
		return y_eye;
		break;
	case 'z':
		return z_eye;
		break;
	default:
		break;
	}
}