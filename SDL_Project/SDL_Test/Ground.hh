#pragma once

#include <string>

#ifdef WINDOWSOS
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL/SDL_ttf.h>
#endif
#include <vector>

#include "Animal.hh"
#include "Sheep.hh"
#include "Wolf.hh"
#include "Player.hh"




typedef std::vector<Animal> Ecosystem;
typedef std::vector<std::shared_ptr<Animal>> Eco;



class Ground{
public :

	void InputDetect();//ajouté une nouvelle entité au jeu
	int CheckInteraction();		// regarde si deux entités sont proche/donc en intéraction, retourne leur id
	void Logic(SDL_Surface * W, SDL_Window * Win);
	void ResetInputBuffer();
	std::string GetDir();
	int GetScore();
	void AddScore(int Sc);
	void InitGame();
	void EntityMoves(int x, int y);
	void AffEntity(SDL_Surface* W, int i, SDL_Window* Win);
	void EntityAff(SDL_Surface* W);
	void EntityMove(Animal * A);
	void EntityMoves2();
	int ChronoR(int milliseconde);
	void InitChrono(int NbSeconde);

private:

	int NbEntities, time;
	std::string input;
	bool Gaming;
	SDL_Event Game;
	Ecosystem Tab;
	Eco Tab2;
	int Chrono;
	int score = 0;
};