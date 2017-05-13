#pragma	once
#include "Planet.h"
#include "Sphere.h"
#include "Material.h"
#include <math.h>

class World
{
	Sphere sun;
	Planet earth, mars, moon;
	Material emitter;
	float x_eye, y_eye, z_eye;
	float theta, d;

public:

	World();
	~World();

	void Initialize();
	void Draw();
	void Timer();
};

