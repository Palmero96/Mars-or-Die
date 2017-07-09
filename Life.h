#pragma once
#include "ETSIDI.h"
#include "List.h"

using namespace ETSIDI;

class Life
{
	List <class Sprite, 3> life;

public:

	void Draw();

	int GetNum();
	void SetNum(int);

	Life();
	~Life();
};

