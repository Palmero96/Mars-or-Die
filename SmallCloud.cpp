#include "SmallCloud.h"
#define CLOUD_0 "textures/phase3/clouds/small_cloud0.png"
#define CLOUD_1 "textures/phase3/clouds/small_cloud1.png"
#define CLOUD_2 "textures/phase3/clouds/small_cloud2.png"
#define CLOUD_3 "textures/phase3/clouds/small_cloud3.png"
#define CLOUD_4 "textures/phase3/clouds/small_cloud4.png"

SmallCloud::SmallCloud(float x, float y, int index)
{
	acc.x = 0;
	acc.y = 5;

	position.x = x;
	position.y = y;

	vel.x = 0;
	vel.y = 60;

	rand_cloud = index;
}

SmallCloud::~SmallCloud()	{}

void SmallCloud::Draw()
{
	switch (rand_cloud)
	{
		case 0:
		{
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(CLOUD_0).id);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(1, 1);  glVertex3f(position.x + 10, position.y + 10, 0);
			glTexCoord2d(0, 1);  glVertex3f(position.x, position.y + 10, 0);
			glTexCoord2d(0, 0);  glVertex3f(position.x, position.y, 0);
			glTexCoord2d(1, 0);  glVertex3f(position.x + 10, position.y, 0);
			glEnd();
		}

		case 1:
		{

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(CLOUD_1).id);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(1, 1);  glVertex3f(position.x + 10, position.y + 10, 0);
			glTexCoord2d(0, 1);  glVertex3f(position.x, position.y + 10, 0);
			glTexCoord2d(0, 0);  glVertex3f(position.x, position.y, 0);
			glTexCoord2d(1, 0);  glVertex3f(position.x + 10, position.y, 0);
			glEnd();

		}

		case 2:
		{

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(CLOUD_2).id);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(1, 1);  glVertex3f(position.x + 10, position.y + 10, 0);
			glTexCoord2d(0, 1);  glVertex3f(position.x, position.y + 10, 0);
			glTexCoord2d(0, 0);  glVertex3f(position.x, position.y, 0);
			glTexCoord2d(1, 0);  glVertex3f(position.x + 10, position.y, 0);
			glEnd();

		}

		case 3:
		{
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(CLOUD_3).id);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(1, 1);  glVertex3f(position.x + 10, position.y + 10, 0);
			glTexCoord2d(0, 1);  glVertex3f(position.x, position.y + 10, 0);
			glTexCoord2d(0, 0);  glVertex3f(position.x, position.y, 0);
			glTexCoord2d(1, 0);  glVertex3f(position.x + 10, position.y, 0);
			glEnd();
		}

		case 4:
		{
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(CLOUD_4).id);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(1, 1);  glVertex3f(position.x + 10, position.y + 10, 0);
			glTexCoord2d(0, 1);  glVertex3f(position.x, position.y + 10, 0);
			glTexCoord2d(0, 0);  glVertex3f(position.x, position.y, 0);
			glTexCoord2d(1, 0);  glVertex3f(position.x + 10, position.y, 0);
			glEnd();

		}
	}

}

void SmallCloud::Move()
{
	float t = 0.025;
	if (vel.y > 60)
		vel.y = 60;
	position.y = position.y + vel.y * t + acc.y * t * t;
}

void SmallCloud::Decelerate()
{
	vel.x = 0;
	acc.y = 0;
	if(vel.y > 30)
		vel.y--;
}

void SmallCloud::Accelerate()
{
	if (vel.y < 60)
		vel.y++;	
}