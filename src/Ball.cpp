#include "Headers/Ball.h"
#include "Headers/Collision.h"
#include "Config.h"

Ball::Ball(sf::RenderWindow* window, Paddle* pl){
    this->player = pl;
    this->targetWindow = window;
    this->radius = 10;
    this->ball.setRadius(this->radius);
    this->ball.setFillColor(sf::Color::Red);
    this->position = sf::Vector2f((WIN_WIDTH / 2), (WIN_HEIGHT - (30+ radius)));
    this->ball.setPosition(this->position);
    this->speed = sf::Vector2f(600, 600);
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
    this->bounceBall();
    this->resetBall();
}

void Ball::bounceBall(){
    if(Collision::isCollision(this->player->getShape(), this->ball)){
        this->speed.x *= -1;
        this->speed.y *= -1;
    }
}

void Ball::resetBall(){
    if(this->position.y > WIN_HEIGHT){
        this->setTick(false);
        this->position = sf::Vector2f((WIN_WIDTH / 2), (WIN_HEIGHT - (30+ radius)));  
          
    }
}

Ball::~Ball(){

}