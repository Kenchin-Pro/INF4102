#include <stdio.h>
#include <stdexcept>
#include <iostream>

#include "Player.hh"
#include "Ground.hh"



// ATTENTION
// This file is only to check if
// SDL is correctly installed and linked against
// If everything works, an application is launched showing
// an image.
// However the application is "buggy" as it leaks memory
// and violates some other rules

#ifdef WINDOWSOS
  #include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_ttf.h>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
  #include <SDL2/SDL_ttf.h>
#endif








int main(int argc, char* argv[])
{
  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw std::runtime_error(std::string(SDL_GetError()));

  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("SDL_image could not initialize! "
                             "SDL_image Error: " + std::string(IMG_GetError()));

  //Initialise SDL_ttf
  


  auto window_ptr = SDL_CreateWindow("C++ Project",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     640, 640,
                                     0);

 

  if (!window_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  auto window_surface_ptr = SDL_GetWindowSurface(window_ptr);

  SDL_FillRect(window_surface_ptr, NULL, SDL_MapRGB(window_surface_ptr->format, 0, 200, 0));

  auto Grass = IMG_Load("Grass1.png");
  if (!Grass)
      throw std::runtime_error("Could not load image");
  auto rect1 = SDL_Rect{ 0,0,640,640 };
  if (SDL_BlitSurface(Grass, NULL, window_surface_ptr, &rect1))
      throw std::runtime_error("Could not apply texture.");
  

  if (!window_surface_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  auto surf = IMG_Load("HumainDv1.png");
  if (!surf)
    throw std::runtime_error("Could not load image");
  auto rect2 = SDL_Rect{0,0,900,500}; //x,y,
  if (SDL_BlitSurface(surf, NULL, window_surface_ptr, &rect2))
      throw std::runtime_error("Could not apply texture.");


  SDL_UpdateWindowSurface(window_ptr);

  

  

  int x = 0;
  
  Ground game;

  bool gaming = false;
  Sheep S1;
  auto SpriteS = IMG_Load("Sheep1.png");

     
        //Loop du jeu
  game.Logic(window_surface_ptr, window_ptr);



  return 0;
}