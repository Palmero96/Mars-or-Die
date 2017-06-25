#pragma once
#include "glut.h"
//D:\Elena2\Documents\ETSIDI\3º\2º Cuatrimestre\Informática Industrial\Fase2\Fase2\scr\

#include "Interaction.h"
#include "Obstacle.h"
class Asteroid :public Obstacle
{

public:
	Asteroid(const char *name);
	virtual ~Asteroid();
	void Draw(Vector2 pos);
	friend class Interaction;
};

