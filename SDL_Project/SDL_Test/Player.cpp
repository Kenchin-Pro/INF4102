#include "Player.hh"
#include <iostream>

void Player::PlayerMove(std::string D) {
    if (D == "H" && this->posY>0) {        //Haut
        this->posY += -1 * this->speed;
    }
    else if (D == "D" && this-> posX < 620) {    //Droite
        this->posX += 1 * this->speed;
    }
    else if (D == "B" && this->posY < 620) {    //Bas
        this->posY += 1 * this->speed;
    }
    else if (D == "G" && this->posX >0) {    //Gauche
        this->posX += -1 * this->speed;
    }
}
/*
void Player::DisplayPlayer(const SDL_Surface & A) {
    auto surf = IMG_Load("sheep1.png");
    auto rect2 = SDL_Rect{ this->posX,this->posY,900,500 };
    SDL_BlitSurface(surf, NULL,  & A, &rect2);
}*/

int Player::getPos() {
    return this->posX, this->posY;
}

void Player::SetPos(int x, int y) {
    this->posX = x;
    this->posY = y;
}

int Player::getPosX() {
    return this->posX;
}
int Player::getPosY() {
    return this->posY;
}

int Player::Sprite(std::string D) {
    if (D == "D") {
        return 1;
    }
    else if (D == "G") {
        return 2;
    }
    else return 0;
}
