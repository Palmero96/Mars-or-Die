#include "Shot.h"
#define MAX_X 1000
#define MAX_Y -300
//#define MAX_H 10
//#define MAX_W 10


Shot::Shot()
{
	radio = 1.0F;
	vel = Vector2(0, 0);
	//image = new ETSIDI::Sprite(name,0,0,1,1);
	pos = Vector2(-20, 0);
}


Shot::~Shot()
{
}

void Shot::Draw(Vector2 posi) {
	//image->draw();
	pos.x += vel.x*0.5;
	pos.y += vel.y*0.5;
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(radio, 50, 50);
	glPopMatrix();
}

void Shot::Move(unsigned char key, Vector2 posi, Vector2 veli) {
	if (key == ' ') {
		vel.x = veli.x + 12;
		vel.y = veli.y + 12;
	}
	else
		vel.x = veli.x;
	vel.y = veli.y;


	//image->setPos(posi.x, posi.y);
	//image->setVel(vel.x+2, vel.y+2);
}

Vector2 Shot::getPos() { return pos; }