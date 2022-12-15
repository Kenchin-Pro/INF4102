/*
AUTEUR : Quentin Guyot

V0.01

26.10.2022
*/

#pragma once

#include "Animal.hh"
    
Animal::Animal () {
	this->posX = 400;
	this->posY = 600;
	this->Sprite = 1;
	this->SpeedX = 42;
	this->SpeedY = 2;
}

Animal::Animal(int X, int Y, int S, int speed) {
	this->posX = X;
	this->posY = Y;
	this->Sprite = S;
	this->SpeedX = speed;
}

void Animal::SetSprite(int sprite) {
	this->Sprite = sprite;
}

int Animal::GetPosX() {
	return this->posX;
}

void Animal::SetFuite(bool F) {
	this->fuite = F;
}

int Animal::GetPosY() {
	return this->posY;
}

int Animal::GetSprite() {
	return this->Sprite;
}

int Animal::GetSpeedX() {
	return this->SpeedX;
}
int Animal::GetSpeedY() {
	return this->SpeedY;
}

int Animal::GetSpeedMax() {
	return this->SpeedMax;
}

bool Animal::GetFuite() {
	return this->fuite;
}

bool Animal::GetProliferate() {
	return this->cProlif;
}

int Animal::GetAge() {
	return this->age;
}

void Animal::SetSpeedX(int S) {
	this->SpeedX = S;
} 

void Animal::SetSpeedY(int Y) {
	this->SpeedY = Y;
}

void Animal::SetSpeedMax(int spd) {
	this->SpeedMax = spd;
}

int Animal::GetMF() {
	return this->MF;
}

int Animal::GetStamina() {
	return this->Stamina;
}

void Animal::SetMF(int S) {
	this->MF = S;
}

void Animal::InitStamina(int Sta) {
	this->StaminaMax = Sta;
	this->Stamina = Sta;
}

void Animal::SetStamina(int S) {
	this->Stamina = S;
}

void Animal::SetPosX(int X) {
	this->posX = X; 
}
void Animal::SetPosY(int Y) {
	this->posY = Y;
}

void Animal::SetProliferate(bool c)
{
	this->cProlif = c;
}

//Age
void Animal::ResetAge() {
	this->age = 0;
}

void Animal::UpdateAge() {
	this->age++;
}

void Animal::Move(int X, int Y) {
	SetPosX(GetPosX() + X);
	SetPosY(GetPosY() + Y);
}

void Animal::automaticMoves() {
	
	if (Stamina-- <= 0) {
		int Rx = (rand() % 3) - 1;
		int Ry = (rand() % 3) - 1;

		SetSpeedX(GetSpeedMax() * Rx);
		SetSpeedY(GetSpeedMax() * Ry);

		this->Stamina = this->StaminaMax;
	}
	else if ((GetPosX() + GetSpeedX() + 25 > 640 || GetPosX() + GetSpeedX() < 0)) {
		SetSpeedX(this->SpeedX * (-1));
	}
	else if (GetPosY() + GetSpeedY() < 0 || GetPosY() + GetSpeedY() + 10>640) {
		SetSpeedY(this->SpeedY * (-1));
	}
	else Move(GetSpeedX(), GetSpeedY());
}
void Animal::automaticMovesWolf(int x, int y) {//Déplacement du loup, en parametre la position du joueur
	if (Stamina-- <= 0) {
		int Rx = (rand() % 3) - 1;
		int Ry = (rand() % 3) - 1;

		SetSpeedX(GetSpeedMax() * Rx);
		SetSpeedY(GetSpeedMax() * Ry);

		this->Stamina = this->StaminaMax;
	}
	else if (GetPosX() + GetSpeedX() + 25 > 640 || GetPosX() + GetSpeedX() < 0 ) {
		SetSpeedX(this->SpeedX * (-1));
	}
	else if (GetPosY() + GetSpeedY() < 0 || GetPosY() + GetSpeedY() + 10 > 640) {
		SetSpeedY(this->SpeedY * (-1));
	}
	else if (GetPosX()<x+80 && GetPosX()>x-60 && GetPosY()<y+80 && GetPosY()>y-60) {
		if ( abs((GetPosX() + GetSpeedX())-x) < abs(GetPosX()-x)) {
			SetSpeedX(GetSpeedX() * -1);
		}
		if (abs((GetPosY() + GetSpeedY()) - y) < abs(GetPosY() - y)) {
			SetSpeedY(GetSpeedY() * -1);
		}
		/*
		SetSpeedX(this->SpeedX * (-1));
		SetSpeedY(this->SpeedY * (-1));
		*/
		Move(GetSpeedX(), GetSpeedY());
	}
	else Move(GetSpeedX(), GetSpeedY());
}

void Animal::Death() {
	this->~Animal();
}

/*Animal::Animal(int Type) {
		if (Type == 1) {
			this->Type = 1;
			Sheep S;
			Wolf W;
			this->A = S;
			this->B = W;
		}
		else{
			this->Type = 2;
			Sheep S;
			Wolf W;
			this->A = S;
			this->B = W;
		}
	}*/




	/*

	void Animal::Move(int X, int Y) {
		this->posX = this->posX + this->SpeedX;
		this->posY = this->posY + this->SpeedY;
	}
	*/
