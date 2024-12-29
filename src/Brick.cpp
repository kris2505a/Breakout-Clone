#include "Headers/Brick.h"
#include "Headers/Collision.h"

Brick::Brick(sf::RenderWindow* window, Ball* ball, sf::Vector2f pos){
    this->targetWindow = window;
    this->ball = ball;
    this->position = pos;
    this->width = 100;
    this->height = 20;
    this->brick.setSize({this->width, this->height});
    this->brick.setPosition(this->position);
    this->brick.setFillColor(sf::Color::Blue);
    this->activeStatus = true;
}


bool Brick::isActive(){
    return this->activeStatus;
}

void Brick::render(){
    this->targetWindow->draw(this->brick);
}

void Brick::update(float& deltaTime){
    if(Collision::isCollision(this->brick, this->ball->getBall())){
        this->activeStatus = false;
        this->ball->reverseBall();
    }
}

void Brick::handleInput(float& deltaTime){

}