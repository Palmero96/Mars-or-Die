#include "Phase3.h"

Phase3::Phase3()
{
	eye_y = 0;					//camera parameter

	fuel.SetNum(0);
	aliens.SetNum(0);

	burning = gameOver = false;

	hermes = new Capsule("textures/phase3/nave.png");

	fuelBar.SetNum(hermes->GetFuel());
}

Phase3::~Phase3()
{
	clouds.DestroyContent();
	aliens.DestroyContent();
	fuel.DestroyContent();
	delete hermes;
}

void Phase3::Initialize()
{
	for (int i = 0; i < CLOUDS; i++)
		randomVectorX[i] = (rand() % 110) - 60;

	for (int i = 0; i < CLOUDS; i++)
		randomVectorY[i] = (rand() % 1700) - 2000;

	for (int i = 0; i < CLOUDS; i++)
		randomCloud[i] = rand() % 5;

	for (int i = 0; i < CLOUDS; i++)
	{
		Cloud *jonSnow = new Cloud(randomVectorX[i], randomVectorY[i], randomCloud[i]);
		clouds.Add(jonSnow);
		int n = clouds.GetNum();
		clouds.SetNum(n++);
	}


	for (int i = 0; i < ALIENS; i++)
		randomAlienVectorX[i] = (rand() % 110) - 60;

	for (int i = 0; i < ALIENS; i++)
		randomAlienVectorY[i] = (rand() % 1000) - 1500;

	for (int i = 0; i < FUEL; i++)
		randomFuelVectorX[i] = (rand() % 110) - 60;

	for (int i = 0; i < FUEL; i++)
		randomFuelVectorY[i] = (rand() % 1000) - 1500;

	for (int i = 0; i < ALIENS; i++)
	{
		Obstacle *a = new Obstacle("textures/phase3/ufo.png");
		a->SetSize(6, 2);
		aliens.Add(a);
		int n = aliens.GetNum();
		aliens.SetNum(n++);
	}

	for (int i = 0; i < FUEL; i++)
	{
		Obstacle *gas = new Obstacle("textures/phase3/gas.png");
		gas->SetSize(5, 5);
		fuel.Add(gas);
		int n = fuel.GetNum();
		fuel.SetNum(n++);
	}

	aliens.SetPos(randomAlienVectorX, randomAlienVectorY);
	fuel.SetPos(randomFuelVectorX, randomFuelVectorY);
}

void Phase3::Draw()
{
	fuelBar.Draw();

	if (eye_y < -132) eye_y = -132;

	gluLookAt(0, eye_y - 13, 40,  // posicion del ojo
		0.0, eye_y - 13, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	fuel.Draw();
	aliens.Draw();
	hermes->Draw();

	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/surface.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 1);  glVertex3f(60, -170, 0);
	glTexCoord2d(0, 1);  glVertex3f(-60, -170, 0);
	glTexCoord2d(0, 0);  glVertex3f(-60, -230, 0);
	glTexCoord2d(1, 0);  glVertex3f(60, -200, 0);

	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/transition.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 1);  glVertex3f(60, 20, 0);
	glTexCoord2d(0, 1);  glVertex3f(-60, 20, 0);
	glTexCoord2d(0, 0);  glVertex3f(-60, -160, 0);
	glTexCoord2d(1, 0);  glVertex3f(60, -160, 0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/stars.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 1);  glVertex3f(80, 20 + hermes->GetPos().y * 0.1, 0);
	glTexCoord2d(0, 1);  glVertex3f(-40, 20 + hermes->GetPos().y * 0.1, 0);
	glTexCoord2d(0, 0);  glVertex3f(-40, -40 + hermes->GetPos().y * 0.1, 0);
	glTexCoord2d(1, 0);  glVertex3f(80, -40 + hermes->GetPos().y * 0.1, 0);

	glEnd();

	//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/glow.png").id);
	//glBegin(GL_POLYGON);
	//glColor3f(1, 1, 1);
	//glTexCoord2d(1, 1);  glVertex3f(60, -140, 0);
	//glTexCoord2d(0, 1);  glVertex3f(-60, -140, 0);
	//glTexCoord2d(0, 0);  glVertex3f(-60, -200, 0);
	//glTexCoord2d(1, 0);  glVertex3f(60, -200, 0);

	//glEnd();	


	clouds.Draw();

	glDisable(GL_BLEND); // VERY IMPORTANT! DON'T CHANGE THE ORTHER OF THESE FUNCTIONS BELOW (or the Vogons will come to read us their poetry...)
	glDepthMask(GL_TRUE);

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Phase3::Timer()
{
	aliens.ListCollision(*hermes);
	fuel.ListCollision(*hermes);
	fuelBar.SetNum(hermes->GetFuel());

	if (fuelBar.GetNum() < 0) hermes->SetBurn(false); // if you ran out of fuel

	if(hermes->GetAcc().y == -5) clouds.Spec(&Cloud::Accelerate);

	eye_y = hermes->GetPos().y; //camera movement

	hermes->Move();
	clouds.Move();
	fuel.Move();
	aliens.Move();

	if (!hermes->Alive())
	{
		fuelBar.SetNum(0);
		gameOver = true;
	}
}

void Phase3::Key(unsigned char key, int x_t, int y_t)
{
	switch (key)
	{
	case ' ':

		hermes->SetAlive(false);
		break;
	}
}

void Phase3::SpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:

		clouds.Spec(&Cloud::Accelerate);
		break;

	case GLUT_KEY_UP:

		if (fuelBar.GetNum() > 0)
		{
			clouds.Spec(&Cloud::Decelerate);
			hermes->SetBurn(true);
		}

		break;

	case GLUT_KEY_LEFT:

		hermes->SetAcc(Vector2(-60, hermes->GetAcc().y));
		break;

	case GLUT_KEY_RIGHT:

		hermes->SetAcc(Vector2(60, hermes->GetAcc().y));
		break;

	}

}

bool Phase3::GameOver() { return gameOver; }