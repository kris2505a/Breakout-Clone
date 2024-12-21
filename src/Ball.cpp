#include "Headers/Ball.h"

Ball::Ball(sf::RenderWindow* window){
    this->targetWindow = window;
    this->radius = 10;
    this->ball.setRadius(this->radius);
    this->ball.setFillColor(sf::Color::Red);
}
