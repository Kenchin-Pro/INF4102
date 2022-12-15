#include "Sheep.hh"

Sheep::Sheep() {
	Animal::Animal();// 400, 100, 1, 4);
}

Sheep::Sheep(int x, int y) {
	Animal::SetPosX(x);
	Animal::SetPosY(y);
	Animal::SetSprite(1);
	Animal::SetSpeedX(3);
	Animal::SetSpeedY(3);
	Animal::InitStamina(120);
	Animal::SetSpeedMax(3);
	int Rs = (rand() % 2) + 1;
	//int Rs = 1;
	Animal::SetMF(Rs);
}
Sheep::Sheep(int X, int Y, int sprite, int speed, int Stamina, int S) {
	Animal::SetPosX(X);
	Animal::SetPosY(Y);
	Animal::SetSprite(sprite);
	Animal::SetSpeedX(speed);
	Animal::SetSpeedY(speed);
	Animal::InitStamina(Stamina);
	Animal::SetSpeedMax(speed);
	Animal::SetMF(S);
}

/*
int Sheep::GetSpeed() {
	return Animal::GetSpeedX();
}

void Sheep::Move(int X, int Y) {
	Animal::SetPosX(Animal::GetPosX() + X);
}*/
/*
void Sheep::automaticMoves() {
	if (GetPosX()+GetSpeed()+25 > 640 || GetPosX()+GetSpeed() < 0) {
		SetSpeed(GetSpeed() * -1);
	}
	else Move(Animal::GetSpeed(), 0);
}*/
