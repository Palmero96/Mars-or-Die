#pragma	once
#include "Planet.h"
#include "Interaction.h"
#include "Sphere.h"
#include "Ship.h"
#include <time.h>
#include <math.h>
#include "Phase.h"
#include "Window.h"
#include "ETSIDI.h"


class Phase1 : public Phase
{
	Sphere sun;
	Ship *ship;
	Planet earth, mars, venus, mercury;
	Planet moon;
	Window window, w1, w2, w3;
	Vector2 z;
	float x_eye, y_eye, z_eye, ang;
	float x_look, y_look, z_look;
	bool sloMo, success, flag;
	int w; // window

public:

	Phase1();
	virtual ~Phase1();

	void Initialize();
	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);
	void CloseUp();
	bool GetSuccess();

	float GetEye(char c);
};