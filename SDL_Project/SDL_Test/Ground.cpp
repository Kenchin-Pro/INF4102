#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include "Ground.hh"
#include "For_each.hh"
#include <filesystem>
namespace fs = std::filesystem;

//GESTION DU SCORE
int Ground::GetScore() {
    return this->score;
}

void Ground::AddScore(int Sc) {
    this->score += Sc;
}



void Ground::ResetInputBuffer() {
    this->input = " ";
}

std::string Ground::GetDir() {
    return this->input;
}

void Ground::InitChrono(int NbSeconde) {
    this->Chrono = NbSeconde;
}

int Ground::ChronoR(int milliseconde) {
    int T = this->Chrono - (int)(milliseconde / 1000);
    return T;
}

void Ground::InputDetect() {
	while (SDL_PollEvent(&this->Game)) {
        switch (this->Game.type) {
            /* Look for a keypress */
            case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
                switch (this->Game.key.keysym.sym) {
                    case SDLK_LEFT:
                        this->input = "G"; //Gauche
                        break;
                    case SDLK_RIGHT:
                        this->input = "D"; //Droite
                        break;
                    case SDLK_UP:
                        this->input = "H"; //Haut
                        break;
                    case SDLK_DOWN:
                        this->input = "B"; //Bas
                        break;
                    default:
                        break;
                }
            case SDL_QUIT:
                this->Gaming = false;
                break;
        }
		
			
	}
	
}

void Ground::InitGame() {

    InitChrono(60);

    Sheep S1(100, 600, 1, 2, 180,1);
    Sheep S2(150, 600, 1, 2, 120,1);
    Sheep S3(200, 600, 1, 2, 160,1);
    Sheep S4(250, 600, 1, 2, 130,2);
    Sheep S5(300, 600, 1, 2, 122,2);
    Sheep S6(350, 600, 1, 2, 190,2);

    Wolf W1(250, 100, 2, 3, 80);
    Wolf W2(350, 100, 2, 3, 80);

    this->Tab2.push_back(std::make_shared<Animal>(S1));
    this->Tab2.push_back(std::make_shared<Animal>(S2));
    this->Tab2.push_back(std::make_shared<Animal>(S3));
    this->Tab2.push_back(std::make_shared<Animal>(S4));
    this->Tab2.push_back(std::make_shared<Animal>(S5));
    this->Tab2.push_back(std::make_shared<Animal>(S6));
    this->Tab2.push_back(std::make_shared<Animal>(W1));
    this->Tab2.push_back(std::make_shared<Animal>(W2));
}

void  Ground::AffEntity(SDL_Surface* W, int i, SDL_Window* Win) {
    auto Sprite = IMG_Load("Sheep.png");
    if (Tab2[i]->GetSprite() == 2) {
        auto Sprite = IMG_Load("Wolf.png");
    }
    
    auto rect7 = SDL_Rect{ Tab2[i]->GetPosX(),Tab2[i]->GetPosY(), 900,500 };
    std::cout << "Debug line 113"<<std::endl;
    SDL_BlitSurface(Sprite, NULL, W, &rect7);

    SDL_UpdateWindowSurface(Win);
}

void Ground::EntityMoves(int x, int y) {
    int mult;
    for (int i = 0; i < this->Tab2.size(); i++) {

        Tab2[i]->UpdateAge();

        //INTERACTION
        if (i < this->Tab2.size() - 1) {
            for (int j = i + 1; j < this->Tab2.size(); j++)
            {
                if (abs(Tab2[i]->GetPosX() - Tab2[j]->GetPosX()) < 60 && abs(Tab2[i]->GetPosY() - Tab2[j]->GetPosY()) < 60) {

                    if ((Tab2[i]->GetSprite() == 1 && Tab2[j]->GetSprite() == 2) || (Tab2[i]->GetSprite() == 2 && Tab2[j]->GetSprite() == 1)) {

                        if (Tab2[i]->GetSprite() == 1 && Tab2[i]->GetAge()>300) {
                            if (Tab2[i]->GetSpeedX() < 4) mult = 2;
                            else mult = 1;
                            if (abs((Tab2[i]->GetPosX() + Tab2[i]->GetSpeedX()) - Tab2[j]->GetPosX()) < abs(Tab2[i]->GetPosX() - Tab2[j]->GetPosX())) {

                                Tab2[i]->SetSpeedX(Tab2[i]->GetSpeedX() * -mult);
                            }
                            else Tab2[i]->SetSpeedX(Tab2[i]->GetSpeedX() * mult);
                            if (abs((Tab2[i]->GetPosY() + Tab2[i]->GetSpeedY()) - Tab2[j]->GetPosY()) < abs(Tab2[i]->GetPosY() - Tab2[j]->GetPosY())) {

                                Tab2[i]->SetSpeedY(Tab2[i]->GetSpeedY() * -mult);
                            }
                            else Tab2[i]->SetSpeedY(Tab2[i]->GetSpeedY() * mult);
                            Tab2[i]->SetStamina(120);
                        }
                        else if(Tab2[j]->GetSprite() == 1 && Tab2[j]->GetAge() > 300) {
                            if (Tab2[j]->GetSpeedX() < 5 && Tab2[j]->GetSpeedY() < 5 ) mult = 2;
                            else mult = 1;
                            if (abs((Tab2[j]->GetPosX() + Tab2[j]->GetSpeedX()) - Tab2[i]->GetPosX()) < abs(Tab2[i]->GetPosX() - Tab2[j]->GetPosX())) {

                                Tab2[j]->SetSpeedX(Tab2[j]->GetSpeedX() * -mult);
                            }
                            else Tab2[j]->SetSpeedX(Tab2[j]->GetSpeedX() * mult);
                            if (abs((Tab2[j]->GetPosY() + Tab2[j]->GetSpeedY()) - Tab2[i]->GetPosY()) < abs(Tab2[i]->GetPosY() - Tab2[j]->GetPosY())) {
                                Tab2[j]->SetSpeedY(Tab2[j]->GetSpeedY() * -mult);
                            }
                            else Tab2[j]->SetSpeedY(Tab2[j]->GetSpeedY() * mult);
                            Tab2[j]->SetStamina(120);
                        }
                        
                    }
                }
                if (abs(Tab2[i]->GetPosX() - Tab2[j]->GetPosX()) < 20 && abs(Tab2[i]->GetPosY() - Tab2[j]->GetPosY()) < 20) {
                    if ((Tab2[i]->GetSprite() == 1 && Tab2[j]->GetSprite() == 2) || (Tab2[i]->GetSprite() == 2 && Tab2[j]->GetSprite() == 1)) //intéraction mouton loup
                    {
                        //LE MOUTON MEURT
                        if (Tab2[i]->GetSprite() == 1) {
                            Tab2[i]->Death();//LE MOUTON MEURT
                            Tab2.erase(Tab2.begin() + i);
                            Tab2[j]->ResetAge();//lorsqu'un loup mange sa faim est rassasié, il ne va donc pas mourir
                            AddScore(-50);
                        }
                        else {

                            Tab2[j]->Death();//LE MOUTON MEURT
                            Tab2.erase(Tab2.begin() + j);
                            Tab2[i]->ResetAge();//lorsqu'un loup mange sa faim est rassasié, il ne va donc pas mourir
                            AddScore(-50);
                        }
                        
                    }
                    else if (Tab2[i]->GetSprite() == 1 && Tab2[j]->GetSprite() == 1) { //Mouton Mouton
                        if (Tab2[i]->GetMF() != Tab2[j]->GetMF()) {
                            if (Tab2[i]->GetMF() == 2 && Tab2[i]->GetAge() > 300) {
                                Sheep S(Tab2[i]->GetPosX(), Tab2[i]->GetPosY()); //intéraction Mouton Mouton -> naissance d'un mouton
                                this->Tab2.push_back(std::make_shared<Animal>(S));
                                Tab2[i]->ResetAge();//le mouton femelle qui vient d'enfanter ne peut plus pendant 5 secondes
                                AddScore(100);
                            }
                            else if (Tab2[j]->GetMF()==2 && Tab2[j]->GetAge() > 300) {
                                Sheep S(Tab2[j]->GetPosX(), Tab2[j]->GetPosY()); //intéraction Mouton Mouton -> naissance d'un mouton
                                this->Tab2.push_back(std::make_shared<Animal>(S));
                                Tab2[j]->ResetAge();//le mouton femelle qui vient d'enfanter ne peut plus pendant 5 secondes
                                AddScore(100);
                            }


                        }
                    }
                }
            }
        }

        //déplacement

        if (Tab2[i]->GetSprite() == 1) {//c'est un mouton
            this->Tab2.at(i)->automaticMoves();
        }
        else {
            if (Tab2[i]->GetAge() > 960) {//Si le loup n'a pas mangé depuis 16 secondes il meurt
                Tab2[i]->Death();
                Tab2.erase(Tab2.begin() + i);
                AddScore(250);
            }
            else this->Tab2.at(i)->automaticMovesWolf(x,y);
        }
        
    }
}
void Ground::EntityAff(SDL_Surface * W) {
    for (int i = 0; i < this->Tab2.size(); i++) {
        this->Tab2.at(i);
    }
}


//Dimension de l'écran 640x640
void Ground::Logic(SDL_Surface * W, SDL_Window * Win) {
    if (TTF_Init() < 0)
        throw std::runtime_error("SDL_TTF could not initializa"
            "SLD _TTF Error " + std::string(TTF_GetError()));
    
    TTF_Font* police = NULL;
    police = TTF_OpenFont("police.ttf", 30);

    Player moi;
    moi.SetPos(320, 320);
    
    auto start = SDL_GetTicks();
    bool gaming = false;
    auto SpriteS = IMG_Load("../Media/Sheep1.png");
    std::cout << SDL_GetError() << std::endl;
    auto SpriteW = IMG_Load("Wolf.png");


    auto Grass = IMG_Load("Grass1.png");
    auto rect1 = SDL_Rect{ 0,0,640,640 };
    int NbImage = 1;

    auto Chien = IMG_Load("absol.png");
    auto surf = IMG_Load("HumainDv1.png");
    InitGame();
    
    int Timer = 99;
    int T1 = 0;
    int Debug = 0;
    SDL_Color noir = { 0, 0, 0 };
    SDL_Surface* Time = NULL;
    SDL_Surface* ScoreTitre = NULL;
    SDL_Surface* TimerScreen = NULL;//initialisation des affichages
    SDL_Surface* ScoreScreen = NULL;

    if ((Time = TTF_RenderText_Blended(police, "Time", noir)) == 0) {
        Debug = 1;
    }
    if ((ScoreTitre = TTF_RenderText_Blended(police, "Score", noir)) == 0) {
        Debug = 1;
    }

    //initialisation de la position des textes
    auto rectHaut1 = SDL_Rect{ 300, 0,900,500 };
    auto rectHaut2 = SDL_Rect{ 310, 50,900,500 };
    auto rectHautGauche1 = SDL_Rect{ 500,0,900,500 };
    auto rectHautGauche2 = SDL_Rect{ 460,50,900,500 };


    while (Timer !=0 && !gaming)
    {
        //texture herbe
        SDL_BlitSurface(Grass, NULL,W, &rect1);
         //attention ce n'est pas un Uint32
        //détection imput clavier
        this->InputDetect();

        //Affichage du JOUEUR
        int PlayerSprite = moi.Sprite(GetDir());


        moi.PlayerMove(GetDir());
        auto rect3 = SDL_Rect{ moi.getPosX(), moi.getPosY(),45,60 };
        auto rectC = SDL_Rect{ moi.getPosX()+10, moi.getPosY()+5 , 100,100 };
        

        if (PlayerSprite == 1) {
            surf = IMG_Load("HumainDv1.png");
        }
        else if (PlayerSprite == 2) {
            surf = IMG_Load("HumainGv1.png");
        }

        SDL_BlitSurface(surf, NULL, W, &rect3);
        SDL_GetError();
        SDL_BlitSurface(Chien, NULL, W, &rectC);
        SDL_GetError();

        SDL_BlitSurface(Time, NULL, W, &rectHaut1);
        SDL_BlitSurface(ScoreTitre, NULL, W, &rectHautGauche1);
        EntityMoves(moi.getPosX(), moi.getPosY());


        //Affichage des animaux--------------------------------------------
        //std::string * SpriteS = "../../Media/Sheep1.png";
        char* SpriteW = "Wolf.png";
        for (int i = 0; i < this->Tab2.size(); i++) {
            auto rect7 = SDL_Rect{ Tab2[i]->GetPosX(),Tab2[i]->GetPosY(), 50,35 };

            if (Tab2[i]->GetSprite() == 1) {
                auto SpriteA = IMG_Load("Sheep1.png");
                SDL_BlitScaled(SpriteA, NULL, W, &rect7);
                SDL_GetError();
            }
            else if (Tab2[i]->GetSprite()==2){
                auto SpriteB = IMG_Load("Wolf.png");
                SDL_BlitScaled(SpriteB, NULL, W, &rect7);
                SDL_GetError();
            }
        }//fin affichage Animaux--------------------------------------------

        int Time = SDL_GetTicks() - start;
        SDL_Delay((17 * NbImage++) - Time);
        Timer = ChronoR((int)SDL_GetTicks());
        //char Timer2 = char(Timer);
        std::string t = std::to_string(Timer);
        char Timer2[3];
        strcpy(Timer2, t.c_str());
        //std::cout << Timer2 << std::endl;
        if ((TimerScreen = TTF_RenderText_Blended(police, Timer2, noir)) == 0) {
            Debug = 1;
        }
        SDL_BlitSurface(TimerScreen, NULL, W, &rectHaut2);

        std::string s = std::to_string(GetScore());
        char Score[4];
        strcpy(Score, s.c_str());
        ScoreScreen = TTF_RenderText_Blended(police, Score, noir);
        SDL_BlitSurface(ScoreScreen, NULL, W, &rectHautGauche2);



        ResetInputBuffer();
        SDL_UpdateWindowSurface(Win);

        

    }
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();
    Tab2.clear();   

}

/*int Ground::CheckInteraction() {
	for (int i = 0; i < NbEntities - 1; ++i) {
		for (int j = i + 1; j < NbEntities; ++j) {
			if (abs(Entities[i]->getPosX() - Entities[j]->getPosX()) < 20 && abs(Entities[i]->getPosY() - Entities[j]->getPosY()) < 20) {


				

			}
		}
	}	
	return 0;	// regarde si deux entités sont proche/donc en intéraction, retourne leur id
}*/


