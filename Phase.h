#pragma once
#include "glut.h"
#include "Puntuation.h"
#include "ETSIDI.h"

class Phase
{
protected:
	bool game_status;
	bool game_over;
	Puntuation punt;

public:

	Phase();
	virtual ~Phase();

	virtual void Draw();
	virtual Puntuation GetPoints();
	virtual void Initialize() = 0;
	virtual void Key(unsigned char key, int x_t, int y_t) = 0;
	virtual void Timer() = 0;
	inline bool GetStatus() { return game_status; }
	inline bool GameOver() { return game_over; }
};

