#include "Animation.h"



Animation::Animation()
{
	explosion = new ETSIDI::SpriteSequence("textures/phase2/Explosion.png", 5, 3, 25, true, -50, -50, 20, 20);
}


Animation::~Animation()
{
	delete explosion;
}

void Animation::Draw() { explosion->draw(); }

void Animation::Move() {
	explosion->draw();
	explosion->loop();

}
void Animation::SetPos(Vector2 pos) {
	explosion->setPos(pos.x, pos.y);
}