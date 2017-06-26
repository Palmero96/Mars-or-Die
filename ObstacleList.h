#pragma once
#include "Obstacle.h"
#include "Capsule.h"
#include "Interaction.h"

#define MAXIMUM 50

class ObstacleList
{
	Obstacle *list[MAXIMUM];
	int num;

public:
	ObstacleList();
	virtual ~ObstacleList();

	bool Add(Obstacle *c);
	void Remove();
	void Draw();
	void Move();
	void DestroyContent();

	int GetNum();
	void SetNum(int);

	void SetPos(float [], float[]);

	void ListCollision(Capsule);
};

