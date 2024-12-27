#include "Headers/GameMode.h"
#include <iostream>


GameMode::GameMode(sf::RenderWindow* window){
    this->targetWindow = window;
    this->player = new Paddle(this->targetWindow);
    this->ball = new Ball(this->targetWindow, this->player);
    this->health = 3;
}

void GameMode::render(){

}

void GameMode::update(float& deltaTime){
    this->health = this->ball->getHealth();
    system("cls");
    std::cout << "Health: " << this->health << std::endl;
}

void GameMode::tick(float& deltaTime){
    this->player->tick(deltaTime);
    this->ball->tick(deltaTime);
    this->render();
    this->update(deltaTime);
}

