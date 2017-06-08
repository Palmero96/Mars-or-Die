#pragma	once
#include "Planet.h"
#include "Sphere.h"
#include "Ship.h"
#include <time.h>
#include <math.h>
#include "glm\glm.hpp"


class World
{
	Sphere sun;
	Ship *ship;
	Planet earth, mars, venus;
	Vector2D z;
	float x_eye, y_eye, z_eye;
	float theta, d;

public:

	World();
	~World();

	void Initialize();
	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);
};

