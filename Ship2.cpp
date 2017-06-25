#include "Ship2.h"

Ship2::Ship2(){}

Ship2::Ship2(const char *name)
{

	dim = 0;
	move = 0;

	up = new ETSIDI::SpriteSequence("textures/Flame.png", 5, 5, true, position.x, position.y + 2, 0.1, 20);
	up->setAngle(-90);

	down = new ETSIDI::SpriteSequence("textures/Flame.png", 5, 5, true, position.x, position.y - 2, 0.1, 20);
	down->setAngle(-90);

	position.x = -20;
	position.y = 0;

	ship = new ETSIDI::Sprite(name, position.x, position.y, 25, 10);
	angle = 0.0F;

}

void Ship2::Initialize() {
	velocity.x = 1.0F;
	velocity.y = 1.0F;
	acc.x = 0;
	acc.y = 0;

}
Ship2::~Ship2()
{
	delete ship;
}

void Ship2::Move(float t) {
	if (position.x<1000) position.x = position.x + velocity.x*cos(angle*3.141593 / 180)*t + acc.x*cos(angle*3.141593 / 180)*pow(t, 2);

	if (-300<position.y<300) position.y = position.y + velocity.y*sin(angle*3.141593 / 180)*t + acc.y*sin(angle*3.141593 / 180)*pow(t, 2);

	if (velocity.x>0)velocity.x = velocity.x + acc.x*t;

	if (velocity.y>0)velocity.y = velocity.y + acc.y*t;
}
void Ship2::SpecialKey(int key) {

	if (key == GLUT_KEY_UP) {
		if (angle < 90)
			angle += 1;
		down->loop();
	}
	else if (key == GLUT_KEY_DOWN) {
		if (angle > -90)
			angle -= 1;
		up->loop();
	}
	else if (key == GLUT_KEY_RIGHT) {
		acc = acc + 0.1;
	}
	else if (key == GLUT_KEY_LEFT) {
		acc.x = acc.x - 0.1;
		acc.y = acc.y - 0.1;
	}


}

void Ship2::Key(unsigned char key) {
	time = ETSIDI::getMillis();
	shot[dim++].Move(key, position, velocity);
	if (key == ' ')shot[move++].Move(key, position, velocity);
	if (time > 1000) {
		move--;
		time = 0;
	}

}
void Ship2::SetVel(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

Shot* Ship2::getShot(int i)
{
	return &shot[i];
}

void Ship2::Draw() 
{
	ship->setAngle(angle);
	ship->setPos(position.x, position.y);
	ship->draw();
	up->setAngle(angle + 90);
	up->setPos(position.x + 2 - 40 * cos(angle*3.141593 / 180), position.y + 2 - 40 * sin(angle*3.141593 / 180));
	down->setAngle(angle + 90);
	down->setPos(position.x - 2 - 40 * cos(angle*3.141593 / 180), position.y - 2 - 40 * sin(angle*3.141593 / 180));
	up->draw();
	down->draw();
	for (int i = 0; i < 10; i++) shot[i].Draw(position);
}

Vector2 Ship2::GetPos() { return position; }

void Ship2::SetPos(Vector2 p) { position = p; }