#include "Ship2.h"
#define MAX_X 2000
#define MAX_Y 300
#define MIN_Y -300
Ship2::Ship2(){}

Ship2::Ship2(const char *name)
{
	up = new ETSIDI::SpriteSequence("textures/phase2/blueflame.png", 5, 4, 50, true, position.x, position.y + 2,3,6);
	up->setAngle(-90);

	down = new ETSIDI::SpriteSequence("textures/phase2/blueflame.png", 5, 4, 50, true, position.x, position.y - 2, 3, 6);
	down->setAngle(-90);

	center = new ETSIDI::SpriteSequence("textures/phase2/Flame.png", 5, 4, 50, true, position.x, position.y, 7, 9);
	center->setAngle(-90);

	position.x = -80;
	position.y = 0;

	ship = new ETSIDI::Sprite(name, position.x, position.y,15, 9);

	undraw = false;
}

void Ship2::Initialize() {
	velocity.x = 1.0F;
	velocity.y = 1.0F;
	acc.x = 0;
	acc.y = 0;
	angle = 0.0F;
}
Ship2::~Ship2()
{
	//delete ship;
}

void Ship2::Move(float t) {
	if (position.x<=MAX_X) 
		position.x = position.x + velocity.x*cos(angle*3.141593 / 180)*t + acc.x*cos(angle*3.141593 / 180)*pow(t, 2);
	position.y = position.y + velocity.y*sin(angle*3.141593 / 180)*t + acc.y*sin(angle*3.141593 / 180)*pow(t, 2);
	if (MIN_Y > position.y) position.y = MAX_Y;
	if (position.y > MAX_Y) position.y = MIN_Y;
	velocity = velocity + acc*t;
	if (acc.x < 0)
		if (velocity.x < 0) {
			velocity.x = 0;
			velocity.y = 0;
		}
}
void Ship2::SpecialKey(int key) {

	if (key == GLUT_KEY_UP) {
		if (angle < 90)
			angle += 1;
		if (angle > 45)up->loop();
		else down->loop();
		undraw = false;
	}
	else if (key == GLUT_KEY_DOWN) {
		if (angle > -90)
			angle -= 1;
		if (angle > 45) down->loop();
		else up->loop();
		undraw = false;
	}
	else if (key == GLUT_KEY_RIGHT) {
		acc = acc + 0.1;
		up->loop();
		down->loop();
		center->loop();
		undraw = false;
	}
	else if (key == GLUT_KEY_LEFT) {
		acc.x = acc.x - 0.1;
		acc.y = acc.y - 0.1;
		undraw = true;
	}
}

void Ship2::Key(unsigned char key)
{
}


void Ship2::Draw() 
{
	ship->setAngle(angle);
	ship->setPos(position.x, position.y);
	ship->draw();
	center->setAngle(angle + 90);
	center->setPos(position.x - 9 * cos(angle*3.141593 / 180), position.y - 9 * sin(angle*3.141593 / 180));
	up->setAngle(angle + 90);
	up->setPos(position.x + 2*(float)(2*abs(angle)/180)  - 7 * cos(angle*3.141593 / 180), position.y + 2*(float)((180-2 * abs(angle)) / 180) - 7 * sin(angle*3.141593 / 180));
	down->setAngle(angle + 90);
	down->setPos(position.x - 2*(float)(2 * abs(angle) / 180) - 7 * cos(angle*3.141593 / 180), position.y - 2*(float)((180 - 2 * abs(angle)) / 180) -7 * sin(angle*3.141593 / 180));
	if (!undraw) {
		up->draw();
		down->draw();
		center->draw();
	}
}

Vector2 Ship2::GetPos() { return position; }

bool Ship2::Win() {
	if (position.x == MAX_X) return true;
	return false;
}

void Ship2::reset()
{
	undraw = false;
	velocity.x = 1.0F;
	velocity.y = 1.0F;
	acc.x = 0;
	acc.y = 0;
	angle = 0.0F;
}
