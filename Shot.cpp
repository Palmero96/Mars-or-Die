#include "Shot.h"


Shot::Shot()	{
	position.x = 0;
	position.y = 0;
	base = 12;
	height = 50;
	angle = 0;
}

Shot::~Shot()	{}


void Shot::Draw() {

	glPushMatrix();
	glTranslatef(position.x, 0.0, position.y);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glLineWidth(1);
	glColor4f(1.0, 1.0, 1.0, 0.2);
	glutWireCone(base, height, 30, 1);
	glPopMatrix();
}

void Shot::Move(Vector2D pos, float omega) {

	float r_vertex = pos.mod();
	float r_orb = sqrtf(pow(r_vertex, 2) + pow(height, 2));
	position.x = r_orb* sin(-omega);
	position.y = r_orb * cos(-omega);
	pos = pos - position;
	
	Vector2D q = position - pos;
	Vector2D z; z.x = 0; z.y = 1;
	float w = z.x * q.x + z.y * q.y;
	float m1 = 1.0;
	float m2 = sqrtf(pow(q.x, 2) + pow(q.y, 2));
	float c = cos(w / (q.x*z.x+q.y*z.y));

	cout << c << endl;
	angle -= acosf(c);
}

float Shot::GetOrRad(float f) {

	Vector2D a;
	a.x = height;
	a.y = f;

	return a.mod();
}

float Shot::GetAngle(float a, float b) {

	float w = a * position.x + b*position.y;
	float m1 = sqrtf(pow(a, 2) + pow(b, 2));
	float m2 = sqrtf(pow(position.x, 2) + pow(position.y, 2));
	float c = cosf(w / (a*b));

	return acosf(c);
}