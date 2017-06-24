#include "Phase3.h"

Phase3::Phase3()
{
	y = 0;					//camera parameter
	time = 0;
	burn = burning = false;
	for (int i = 0; i < 10; i++)
	{
		randomVectorX[i] = 0;
		randomVectorY[i] = 0;
		randomCloud[i] = 0;
	}
	dragon = new Capsule("textures/phase3/nave.png");
}

Phase3::~Phase3()
{
	small_cloud.DestroyContent();
	delete dragon;
}
void Phase3::Initialize()
{
	for (int i = 0; i < CLOUDS; i++)
		randomVectorX[i] = (rand() % 110) - 60;

	for (int i = 0; i < CLOUDS; i++)
		randomVectorY[i] = (rand() % 1600) - 1800;

	for (int i = 0; i < CLOUDS; i++)
		randomCloud[i] = rand() % 5;
	
	for (int i = 0; i < CLOUDS; i++)
	{
		SmallCloud *jonSnow = new SmallCloud(randomVectorX[i], randomVectorY[i], randomCloud[i]);
		small_cloud.Add(jonSnow);
		int n = small_cloud.GetNum();
		small_cloud.SetNum(n++);
	}

}

void Phase3::Draw()
{
	fuelBar.Draw();
	if (y < -132) y = -132;
	gluLookAt(0, y, 40,  // posicion del ojo
		0.0, y, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	dragon->Draw();

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
	glTexCoord2d(1, 1);  glVertex3f(60, -140, 0);
	glTexCoord2d(0, 1);  glVertex3f(-60, -140, 0);
	glTexCoord2d(0, 0);  glVertex3f(-60, -200, 0);
	glTexCoord2d(1, 0);  glVertex3f(60, -200, 0);

	glEnd();

	small_cloud.Draw();


	glDisable(GL_BLEND);				// VERY IMPORTANT! DON'T CHANGE THE ORTHER OF THESE FUNCTIONS BELOW (or the Vogons will come to read us their poetry...)
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
		burn = false;
		burning = true;
	}
	if (burning)
	{
		time++;
		if (time == 100)
		{
			small_cloud.Spec(&SmallCloud::Accelerate);
			time = 0;
			burning = false;
		}
	}
	
	dragon->Move();
	small_cloud.Move();

	y = dragon->GetPos().y; //camera movement


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

			small_cloud.Spec(&SmallCloud::Accelerate);
			burn = false;
			break;
			
		case GLUT_KEY_UP:
			if (fuelBar.GetNum() > 0)
			{
				small_cloud.Spec(&SmallCloud::Decelerate);
				burn = true;
			}
			break;
		case GLUT_KEY_LEFT:
			dragon->SetAcc(Vector2(-25, dragon->GetAcc().y));
			break;
		case GLUT_KEY_RIGHT:
			dragon->SetAcc(Vector2(25, dragon->GetAcc().y));
			break;
	}
	
}