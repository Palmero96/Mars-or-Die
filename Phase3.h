#pragma once
#include "Interaction.h"
#include "ObstacleList.h"
#include "FuelBar.h"
#include "Phase.h"
#include "Cloud.h"
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
	List<class Cloud, 70> clouds;
	ObstacleList fuel, aliens;
	Capsule *hermes;
	SpriteSequence *explosion;
	FuelBar fuelBar;

	float randomVectorX[CLOUDS];	//vectors for storing random numbers
	float randomVectorY[CLOUDS];
	float randomAlienVectorX[ALIENS];	//vectors for storing random numbers
	float randomAlienVectorY[ALIENS];
	float randomFuelVectorX[FUEL];	//vectors for storing random numbers
	float randomFuelVectorY[FUEL];
	float randomCloud[CLOUDS];

	bool burning, gameOver;

	int time;
	float eye_y;


public:

	Phase3();
	virtual ~Phase3();

	void Draw();
	void Timer();
	void Initialize();
	void Key(unsigned char key, int x_t, int y_t);
	void SpecialKey(int key, int x, int y);

	bool GameOver();
};

