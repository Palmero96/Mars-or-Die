#include "Phase3.h"

Phase3::Phase3()
{
	eye_y = 0;					//camera parameter
	explosion = NULL;
	fuel.SetNum(0);
	aliens.SetNum(0);
	surfacePos = -195;
	landPos = -215;
	burning = sound = radio_sound = false;
	game_over = game_status = false;

	hermes = new Capsule("textures/phase3/nave.png");

	landingPad = new SpriteSequence("textures/phase3/landingPad.png", 2, 1, 1000, true, 0, landPos, 20, 8);
	landingPad->flip(false, true);

	landingZone = new Sprite("textures/phase3/landZone.png", 0, landPos,0,0);
	landingZone->setSize(80, 39);
	fuelBar.SetNum(hermes->GetFuel());
	lifeBar.SetNum(hermes->GetLife());
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
		randomVectorY[i] = (rand() % 2000) - 2200;

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
		randomAlienVectorY[i] = (rand() % 1300) - 1500;

	for (int i = 0; i < FUEL; i++)
		randomFuelVectorX[i] = (rand() % 110) - 60;

	for (int i = 0; i < FUEL; i++)
		randomFuelVectorY[i] = (rand() % 1600) - 1800;

	for (int i = 0; i < ALIENS; i++)
	{
		Obstacle *a = new Obstacle("textures/phase3/ufo.png");
		a->setSize(6, 2);
		a->SetNature(true);
		aliens.Add(a);
		int n = aliens.GetNum();
		aliens.SetNum(n++);
	}

	for (int i = 0; i < FUEL; i++)
	{
		Obstacle *gas = new Obstacle("textures/phase3/gas.png");
		gas->setSize(5, 5);
		gas->SetNature(false);
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
	lifeBar.Draw();

	if (eye_y < -130) eye_y = -130;

	gluLookAt(0, eye_y - 13, 40,  // posicion del ojo
		0.0, eye_y - 13, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	
	fuel.Draw();
	aliens.Draw();
	hermes->Draw();

	landingPad->draw();
	landingPad->setAngle(180);
	landingZone->draw();

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
	glTexCoord2d(0, 0);  glVertex3f(-40, -40 + hermes->GetPos().y * 0.3, 0);
	glTexCoord2d(1, 0);  glVertex3f(80, -40 + hermes->GetPos().y * 0.3, 0);
	glTexCoord2d(1, 1);  glVertex3f(80, 20 + hermes->GetPos().y * 0.3, 0);
	glTexCoord2d(0, 1);  glVertex3f(-40, 20 + hermes->GetPos().y * 0.3, 0);

	glEnd();
	if (hermes->GetPos().y < -100)
	{
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase3/surface.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0);  glVertex3f(-48, surfacePos, 0);
		glTexCoord2d(1, 0);  glVertex3f(48, surfacePos, 0);
		glTexCoord2d(1, 1);  glVertex3f(48, surfacePos + 70, 0);
		glTexCoord2d(0, 1);  glVertex3f(-48, surfacePos + 70, 0);
		glEnd();
	}

	clouds.Draw();

	

	glDisable(GL_BLEND); // VERY IMPORTANT! DON'T CHANGE THE ORTHER OF THESE FUNCTIONS BELOW (or the Vogons will come to read us their poetry...)
	glDepthMask(GL_TRUE);

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	if (game_status)
	{
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 40);
		ETSIDI::printxy("mission completed!", -15 , hermes->GetPos().y + 15);
	}
	if (game_over)
	{
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 40);
		ETSIDI::printxy("mission failed!", -15, hermes->GetPos().y);
	}

}

void Phase3::Timer()
{
	if (Interaction::Contact(*hermes, *landingPad) && hermes->GetVel().y >-2)
	{
			hermes->Land();
			game_status = true;
			if (!radio_sound)
			{
				ETSIDI::play("music/radio.wav");
				radio_sound = true;
			}
	}

	else
	{
		if (Interaction::Contact(*hermes, *landingPad) && hermes->GetVel().y < -2)
			hermes->SetAlive(false);

		if(hermes->GetBurning()) aliens.ListBurn(hermes->GetFlame());

		if (hermes->Alive())
		{
			aliens.ListCollision(*hermes);
			fuel.ListCollision(*hermes);
		}

		if (Interaction::Contact(*hermes, *landingZone))	hermes->SetAlive(false);

		cout << hermes->GetPos().y << "		" << landingPad->getPos().y  << endl;

		aliens.Check(); 
		fuel.Check();
		fuelBar.SetNum(hermes->GetFuel());
		lifeBar.SetNum(hermes->GetLife());

		if (fuelBar.GetNum() < 0) hermes->SetBurn(false); // if you ran out of fuel

		if (hermes->GetAcc().y == -5) clouds.Spec(&Cloud::Accelerate);

		eye_y = hermes->GetPos().y; //camera movement

		hermes->Move();
		clouds.Move();
		fuel.Move();
		aliens.Move();
		

		if (hermes->GetPos().y < -110 && hermes->GetPos().y > -143 && !game_over)
			surfacePos -= hermes->GetVel().y * 0.02;

		if (hermes->GetPos().y < -143 && hermes->GetPos().y > -151 && !game_over)
		{
			landPos -= hermes->GetVel().y * 0.1;
			landingZone->setPos(-35, landPos);
			landingPad->setPos(6, landPos + 39);
		}
	}

	fuel.Check();
	fuelBar.SetNum(hermes->GetFuel());
	landingPad->loop();

	if (!hermes->Alive())
	{
		fuelBar.SetNum(0);
		lifeBar.SetNum(0);
		game_over = true;

		if (!sound)
		{
			ETSIDI::play("music/capsuleExplosion.wav");
			sound = true;
		}
	}
}

void Phase3::Key(unsigned char key, int x_t, int y_t)
{
	switch (key)
	{
	case ' ':
		if(!game_over)
		hermes->SetAlive(false);
		break;

	case 'f':
		if(hermes->GetFuel()<7)hermes->SetFuel(hermes->GetFuel() + 1);
		hermes->SetLife(3);
		ETSIDI::play("music/cheat.wav");
		break;

	case 'q':
		hermes->SetPos(Vector2(0, -130));
	}

}

void Phase3::SpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		break;

	case GLUT_KEY_UP:

		if (fuelBar.GetNum() > 0)	hermes->SetBurn(true);
		break;

	case GLUT_KEY_LEFT:

		hermes->SetAcc(Vector2(-100, hermes->GetAcc().y));
		break;

	case GLUT_KEY_RIGHT:

		hermes->SetAcc(Vector2(100, hermes->GetAcc().y));
		break;

	}

}
