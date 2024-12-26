#include "Headers/Ball.h"
#include "Headers/Collision.h"
#include "Config.h"

Ball::Ball(sf::RenderWindow* window){
    this->targetWindow = window;
    this->radius = 10;
    this->ball.setRadius(this->radius);
    this->ball.setFillColor(sf::Color::Red);
    this->position = sf::Vector2f((WIN_WIDTH / 2), (WIN_HEIGHT - (20 + radius)));
    this->ball.setPosition(this->position);
    this->speed = sf::Vector2f(1000, 1000);
}

void Ball::render() {
    this->targetWindow->draw(this->ball);
}

void Ball::update(float& deltaTime){
    this->position -= this->speed * deltaTime;
    this->ball.setPosition(this->position);
    if(this->position.x <= 0 || this->position.x >= WIN_WIDTH)
        this->speed.x *= -1;
    if(this->position.y <= 0)
        this->speed.y *= -1;
}


Ball::~Ball(){

}