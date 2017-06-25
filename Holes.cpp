#include "Holes.h"
#define MAX_X 300
#define MAX_Y 400
#define MAX_R 20
#define MAX_A 1


Holes::Holes(const char *name)
{
	P = new ETSIDI::Sprite(name, rand() % MAX_X, rand() % MAX_Y, rand() % MAX_R);
	//SetRadius(rand() % MAX_R);//Valor random de tamaño entre 0 y 20
	//SetPos(rand() % MAX_X, rand() % MAX_Y);
	//SetAcc(rand() % MAX_A, rand() % MAX_A);
}


Holes::~Holes()
{
	delete P;
}

void Holes::Draw(Vector2 p){}
