#include "Headers/Brick.h"

Brick::Brick(sf::RenderWindow* window, Ball* ball, sf::Vector2f pos){
    this->targetWindow = window;
    this->ball = ball;
    this->position = pos;
    this->width = 100;
    this->height = 20;
    this->brick.setSize({this->width, this->height});
    this->brick.setPosition(this->position);
    this->brick.setFillColor(sf::Color::Blue);
}

