#include "ObstacleList.h"



ObstacleList::ObstacleList() { explosion = 0; }


ObstacleList::~ObstacleList() {}

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
	if (explosion)
		explosion->draw();
	
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			list[i]->draw();
	}
}

void ObstacleList::Move()
{
	if (explosion)
		explosion->loop();
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
			if (Interaction::Contact(c, *list[i]))
			{
				if (list[i]->GetNature())	// the boolean damage is true so it's an alien
				{
					explosion = new SpriteSequence("textures/phase3/alienExplosion2.png", 4, 4, 50,
						false, list[i]->GetPos().x + 1, list[i]->GetPos().y + 1, 7, 5);

					list[i]->SetAlive(false);
					ETSIDI::play("music/alienExplosion.wav");

					if (c.GetLife() > 1)	c.SetLife(c.GetLife() - 1);

					else c.SetAlive(false);
				}

				else	// the boolean damage is false so its fuel
				{
					list[i]->SetAlive(false);
					ETSIDI::play("music/fuel.wav");
					if (c.GetFuel() < 7)
						c.SetFuel(c.GetFuel() + 1);
				}
			}
		}

	}
}

void ObstacleList::ListBurn(SpriteSequence f)
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
		{
			if (Interaction::AlienBurn(f, *list[i]))
			{
				if (f.getState() < 19)
				{
					explosion = new SpriteSequence("textures/phase3/alienExplosion.png", 4, 4, 50,
						false, list[i]->GetPos().x + 1, list[i]->GetPos().y + 1, 7, 5);

					ETSIDI::play("music/alienKilled.wav");
					list[i]->SetAlive(false);
				}
			}

		}
	}
}

