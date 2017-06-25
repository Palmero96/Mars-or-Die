#include "Phase3.h"

Phase3::Phase3()
{/*
 aliens.SetNum(0);
 fuelBonus.SetNum(0);*/
	y = 0;					//camera parameter
	flame = 0;
	time = 0;
	burn = burning = false;

	dragon = new Capsule("textures/phase3/nave.png");
}

Phase3::~Phase3()
{
	small_cloud.DestroyContent();
	/*aliens.DestroyContent();
	fuelBonus.DestroyContent();*/
	delete dragon;
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
		small_cloud.Add(jonSnow);
		int n = small_cloud.GetNum();
		small_cloud.SetNum(n++);
	}


	//for (int i = 0; i < ALIENS; i++)
	//	randomAlienVectorX[i] = (rand() % 110) - 60;

	//for (int i = 0; i < ALIENS; i++)
	//	randomAlienVectorY[i] = (rand() % 1700) - 2000;

	//for (int i = 0; i < FUEL; i++)
	//	randomFuelVectorX[i] = (rand() % 110) - 60;

	//for (int i = 0; i < FUEL; i++)
	//	randomFuelVectorY[i] = (rand() % 1700) - 2000;

	//for (int i = 0; i < ALIENS; i++)
	//{
	//	Sprite *a = new Sprite("textures/phase3/ufo.png", 0, 0, 2, 2);
	//	aliens.Add(a);
	//	int n = aliens.GetNum();
	//	aliens.SetNum(n++);
	//}

	//for (int i = 0; i < FUEL; i++)
	//{
	//	Sprite *gas = new Sprite("textures/phase3/gas.png", 0, 0, 2, 2);
	//	fuelBonus.Add(gas);
	//	int n = fuelBonus.GetNum();
	//	fuelBonus.SetNum(n++);
	//}

	//aliens.SetPos(randomAlienVectorX, randomAlienVectorY, ALIENS);
	//fuelBonus.SetPos(randomFuelVectorX, randomFuelVectorY, FUEL);
}

void Phase3::Draw()
{

	fuelBar.Draw();

	if (y < -132) y = -132;

	gluLookAt(0, y - 13, 40,  // posicion del ojo
		0.0, y - 13, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	dragon->Draw();

	if (flame)
	{
		flame->setAngle(180);
		flame->draw();
	}

	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


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
	glTexCoord2d(1, 1);  glVertex3f(80, 20 + dragon->GetPos().y * 0.1, 0);
	glTexCoord2d(0, 1);  glVertex3f(-40, 20 + dragon->GetPos().y * 0.1, 0);
	glTexCoord2d(0, 0);  glVertex3f(-40, -40 + dragon->GetPos().y * 0.1, 0);
	glTexCoord2d(1, 0);  glVertex3f(80, -40 + dragon->GetPos().y * 0.1, 0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/glow.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 1);  glVertex3f(60, -140, 0);
	glTexCoord2d(0, 1);  glVertex3f(-60, -140, 0);
	glTexCoord2d(0, 0);  glVertex3f(-60, -200, 0);
	glTexCoord2d(1, 0);  glVertex3f(60, -200, 0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/surface.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 1);  glVertex3f(60, -170, 0);
	glTexCoord2d(0, 1);  glVertex3f(-60, -170, 0);
	glTexCoord2d(0, 0);  glVertex3f(-60, -230, 0);
	glTexCoord2d(1, 0);  glVertex3f(60, -200, 0);

	glEnd();

	small_cloud.Draw();


	glDisable(GL_BLEND);			// VERY IMPORTANT! DON'T CHANGE THE ORTHER OF THESE FUNCTIONS BELOW (or the Vogons will come to read us their poetry...)
	glDepthMask(GL_TRUE);

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Phase3::Timer()
{
	if (fuelBar.GetNum() < 0) burn = false; // if you ran out of fuel

	if (burn) // condition of decelerating the clouds and a filter for executing the rest
	{
		fuelBar.Burn();
		flame = new ETSIDI::SpriteSequence("textures/phase3/flame.png", 5, 4, 50, false, dragon->GetPos().x, dragon->GetPos().y, 12, 15);
		burning = true;
		burn = false;
		dragon->SetAcc(Vector2(0, 5));
	}

	if (burning)
	{
		time++;

		if (time == 100)
		{
			dragon->SetAcc(Vector2(0, -5));
			small_cloud.Spec(&Cloud::Accelerate);
			time = 0;
			burning = false;
		}
	}

	y = dragon->GetPos().y; //camera movement


	dragon->Move();
	small_cloud.Move();

	if (flame)
	{
		flame->setPos(dragon->GetPos().x - 5.2, dragon->GetPos().y - 14);
		flame->loop();
	}
}

void Phase3::Key(unsigned char key, int x_t, int y_t)
{
	switch (key)
	{
	case ' ':

		break;
	}
}

void Phase3::SpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:

		small_cloud.Spec(&Cloud::Accelerate);
		burn = false;
		break;

	case GLUT_KEY_UP:

		if (fuelBar.GetNum() > 0)
		{
			flame = new ETSIDI::SpriteSequence("textures/phase3/flame.png", 5, 4, 50, false, -10, 7, 10, 10);
			small_cloud.Spec(&Cloud::Decelerate);
			burn = true;
		}

		break;

	case GLUT_KEY_LEFT:

		dragon->SetAcc(Vector2(-60, dragon->GetAcc().y));
		break;

	case GLUT_KEY_RIGHT:

		dragon->SetAcc(Vector2(60, dragon->GetAcc().y));
		break;

	}

}