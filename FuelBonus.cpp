#include "FuelBonus.h"



FuelBonus::FuelBonus()
{

}
FuelBonus::~FuelBonus()
{


}

void FuelBonus::Draw()
{
	image->setPos(position.x, position.y);
	image->draw();
}