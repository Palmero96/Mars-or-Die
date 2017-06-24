#pragma once
#include "Interaction.h"
#include "FuelBar.h"
#include "Phase.h"
#include "SmallCloud.h"
#include "Capsule.h"
#include "List.h"

#define CLOUDS 70

class Phase3 : public Phase
{

	Capsule *dragon;
	List<class FuelBonus, 8> fuel_bonus;
	FuelBar fuelBar;
	List<class SmallCloud, 70> small_cloud;
	double y;

	int randomVectorX[CLOUDS];
	int randomVectorY[CLOUDS];
	int randomCloud[CLOUDS];

	bool burn, burning;

	int time;

public:

	Phase3();
	virtual ~Phase3();

	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
	void SpecialKey(int key, int x, int y);
};

