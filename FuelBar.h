#pragma once
#include "Window.h"
#include "FuelUnit.h"
#include "List.h"

class FuelBar
{
	List <class FuelUnit, 3> fuel;

public:
	FuelBar();
	~FuelBar();
	void Draw();
	void Burn();
	int GetNum();
};

