#include "Animal.hh"

#ifndef SHEEP_HH_
#define SHEEP_HH_

class Sheep : public Animal
{
public:
	Sheep();
	Sheep(int x, int y);
	Sheep(int X, int Y, int sprite, int speed, int Stamina, int S);
private:
	
};

#endif