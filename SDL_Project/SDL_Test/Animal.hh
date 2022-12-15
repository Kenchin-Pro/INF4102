#pragma once

#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>



#ifndef ANIMAL_HH_
#define ANIMAL_HH_


class Animal {
public:
	Animal();
	Animal(int X, int Y, int S,int speed);
	int GetSpeedX();
	int GetSpeedY();
	int GetPosX();
	int GetPosY();
	int GetSpeedMax();
	int GetStamina();
	int GetSprite();
	int GetMF();
	int GetAge();
	bool GetFuite();
	bool GetProliferate();
	void SetPosX(int X);
	void SetPosY(int Y);
	void SetSprite(int sprite);
	void SetStamina(int S);
	void SetSpeedX(int S);
	void SetSpeedY(int Y);
	void SetSpeedMax(int Spd);
	void SetFuite(bool F);
	void SetMF(int S); //1 = mâle, 2 = femelle
	void SetProliferate(bool C);
	void UpdateAge();
	void ResetAge();
	void Move(int X, int Y);
	void automaticMoves();
	void automaticMovesWolf(int x, int y);
	void InitStamina(int Sta);
	void Death();


	//void Move(int X, int Y);

private:
	int posX;
	int posY;
	int Sprite;
	int MF = 0;
	int SpeedX;
	int SpeedY;
	int SpeedMax;
	int Stamina;
	int StaminaMax;
	bool fuite;
	bool cProlif = true;
	int age = 0; //l'age de l'entité en frame
};

#endif
