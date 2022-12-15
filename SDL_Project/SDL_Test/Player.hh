#pragma once

#include <string>
#ifdef WINDOWSOS
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

class Player {
public:

	void PlayerMove(std::string D); //D =  Direction de l'input
	int getPos();
	int getPosX();
	int getPosY();
	void SetPos(int x, int y);
	void DisplayPlayer(const SDL_Surface & A);
	int Sprite(std::string D);

private:

	int speed = 10;
	int posX = 0;
	int posY = 0;
	

};