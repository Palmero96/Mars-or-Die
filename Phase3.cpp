#include "Phase3.h"

Phase3::Phase3()
{
	y = 0;

	for (int i = 0; i < 10; i++)
	{
		randomVectorX[i] = 0;
		randomVectorY[i] = 0;
		randomCloud[i] = 0;
	}
}

Phase3::~Phase3()
{
	small_cloud.DestroyContent();
}
void Phase3::Initialize()
{
	for (int i = 0; i < CLOUDS; i++)
		randomVectorX[i] = (rand() % 110) - 60;

	for (int i = 0; i < CLOUDS; i++)
		randomVectorY[i] = (rand() % 1200) - 2000;

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
	fuel.Draw();

	gluLookAt(0, y, 40,  // posicion del ojo
		0.0, y, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	
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
	glTexCoord2d(1, 1);  glVertex3f(80, 20 + dragon.GetPos().y * 0.1, 0);
	glTexCoord2d(0, 1);  glVertex3f(-40, 20 + dragon.GetPos().y * 0.1, 0);
	glTexCoord2d(0, 0);  glVertex3f(-40, -40 + dragon.GetPos().y * 0.1, 0);
	glTexCoord2d(1, 0);  glVertex3f(80, -40 + dragon.GetPos().y * 0.1, 0);

	glEnd();

	small_cloud.Draw();


	glDisable(GL_BLEND);				// VERY IMPORTANT! DON'T CHANGE THE ORTHER OF THESE FUNCTIONS BELOW (or the Vogons will come to read us their poetry...)
	glDepthMask(GL_TRUE);

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	dragon.Draw();
}

void Phase3::Timer()
{
	dragon.Move();
	small_cloud.Move();
	y = dragon.GetPos().y;
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
			break;
		case GLUT_KEY_UP:
			small_cloud.Spec(&SmallCloud::Decelerate);
			break;
		case GLUT_KEY_LEFT:
			dragon.SetAcc(Vector2(-15, 0));
			break;
		case GLUT_KEY_RIGHT:
			dragon.SetAcc(Vector2(15, 0));
			break;
		default:
			break;
	}
	
}