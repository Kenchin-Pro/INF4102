#include "Animal.hh"

#ifndef WOLF_HH_
#define WOLF_HH_

class Wolf : public Animal
{
public:
	Wolf();
	Wolf(int X, int Y, int sprite, int speed, int Stamina);
	int GetSpeed();
	void Move(int X, int Y);
	void automaticMoves();

private:

};

#endif