#pragma	once
#include "Planet.h"
#include "Sphere.h"
#include "Material.h"
#include "Shot.h"
#include <math.h>
#include "glm\glm.hpp"


class World
{
	Sphere sun;
	Planet earth, mars, moon;
	Shot shot;
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

