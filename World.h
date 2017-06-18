#pragma	once
#include "Planet.h"
#include "Interaction.h"
#include "Sphere.h"
#include "Ship.h"
#include <time.h>
#include <math.h>
#include "Phase.h"
#include "ETSIDI.h"


class World: public Phase
{
	Sphere sun;
	Ship *ship;
	Planet earth, mars, venus, mercury;
	Planet moon;
	Vector2 z;
	float x_eye, y_eye, z_eye;
	float x_look, y_look, z_look;
	bool sloMo, success;

public:

	World();
	virtual ~World();

	void Initialize();
	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);
	void CloseUp();
	bool GetSuccess();
};

