#include "Wolf.hh"

Wolf::Wolf() {
	Animal::Animal(400, 100, 2, 4);
}

Wolf::Wolf(int X, int Y, int sprite, int speed, int Stamina) {
	Animal::SetPosX(X);
	Animal::SetPosY(Y);
	Animal::SetSprite(sprite);
	Animal::SetSpeedX(speed);
	Animal::SetSpeedY(speed); 
	Animal::InitStamina(Stamina);
	Animal::SetSpeedMax(speed);
}



int Wolf::GetSpeed() {
	return Animal::GetSpeedX();
}

void Wolf::Move(int X, int Y) {
	Animal::SetPosX(Animal::GetPosX() + X);
}
/*
void Wolf::automaticMoves() {
	if (GetPosX() + GetSpeed() + 25 > 640 || GetPosX() + GetSpeed() < 0) {
		SetSpeed(GetSpeed() * -1);
	}
	else Move(Animal::GetSpeed(), 0);
}*/
