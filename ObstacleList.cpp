#include "ObstacleList.h"



ObstacleList::ObstacleList()
{
}


ObstacleList::~ObstacleList()
{
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
	delete list[num - 1];
	num--;
}

void ObstacleList::Draw()
{
	for (int i = 0; i < num; i++)
		list[i]->Draw();
}

void ObstacleList::Move()
{
	for (int i = 0; i < num; i++)
		list[i]->Move();
}

void ObstacleList::DestroyContent()
{
	for (int i = 0; i < num; i++)
		delete list[i];
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
		list[i]->SetPos(vx[i], vy[i]);
}

void ObstacleList::ListCollision(Capsule c)
{
	for (int i = 0; i < num; i++)
		Interaction::Contact(c, *list[i]);
}