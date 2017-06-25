#pragma once
#include "Interaction.h"
#include "FuelBar.h"
#include "Phase.h"
#include "SmallCloud.h"
#include "Capsule.h"
#include "List.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

#define CLOUDS 80
#define ALIENS 20
#define FUEL 15

class Phase3 : public Phase
{
	//SpriteList aliens, fuelBonus;
	List<class Cloud, 70> small_cloud;

	Capsule *dragon;
	FuelBar fuelBar;
	SpriteSequence *flame;

	int randomVectorX[CLOUDS];	//vectors for storing random numbers
	int randomVectorY[CLOUDS];
	int randomAlienVectorX[ALIENS];	//vectors for storing random numbers
	int randomAlienVectorY[ALIENS];
	int randomFuelVectorX[FUEL];	//vectors for storing random numbers
	int randomFuelVectorY[FUEL];
	int randomCloud[CLOUDS];

	bool burn, burning;

	int time;
	float y;


public:

	Phase3();
	virtual ~Phase3();

	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
	void SpecialKey(int key, int x, int y);
};

