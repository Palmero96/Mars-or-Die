#pragma once
#include "Ship.h"

#define MAX_SHIPS

class ShipList
{
	int num = 0;
	Ship *list[MAX_SHIPS];

public:

	ShipList();
	~ShipList();

	bool add(Ship *s);
	void Draw();
	void Move();

};

