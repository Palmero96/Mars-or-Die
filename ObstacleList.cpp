#include "ObstacleList.h"



ObstacleList::ObstacleList()	{}


ObstacleList::~ObstacleList()	{}

void ObstacleList::Check()
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
		{
			if (list[i]->alive == false)
				list[i] = NULL;
		}
	}
}

bool ObstacleList::Add(Obstacle *c)
{
	if (num < MAXIMUM)
		list[num++] = c;
	else return false;
	return true;
}

void ObstacleList::Remove()
{
	if (num <= 0)	return;
	if (list[num])
	{
		delete list[num - 1];
		num--;
	}
}

void ObstacleList::Draw()
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			list[i]->draw();
	}
}

void ObstacleList::Move()
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			list[i]->Move();
	}
}

void ObstacleList::DestroyContent()
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			delete list[i];
	}
}

int ObstacleList::GetNum()
{
	return num;
}

void ObstacleList::SetNum(int n)
{
	num = n;
}

void ObstacleList::SetPos(float vx[], float vy[])
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			list[i]->SetPos(vx[i], vy[i]);
	}
}

void ObstacleList::ListCollision(Capsule &c)
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
		{
			Interaction::Contact(c, *list[i]);
			glPopMatrix();
		}

	}
}

void ObstacleList::ListBurn(SpriteSequence f)
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			Interaction::AlienBurn(f, *list[i]);
	}
}

