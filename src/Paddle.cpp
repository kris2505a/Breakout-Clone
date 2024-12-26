#include "Headers/Paddle.h"
#include "Headers/Config.h"


Paddle::Paddle(sf::RenderWindow* window) {
    this->targetWindow = window;
    this->width = 80.0f;
    this->height = 20.0f;
    this->position = sf::Vector2f((WIN_WIDTH - this->width) / 2, (WIN_HEIGHT - this->height));
    this->pad.setFillColor(sf::Color::White);
    this->pad.setPosition(this->position);
    this->pad.setSize(sf::Vector2f(this->width, this->height)); 
    this->speed = 1100.0f;
}

void Paddle::render(){
    this->targetWindow->draw(this->pad);
}

void Paddle::update(float& deltaTime){
    this->handleInput(deltaTime);
    this->pad.setPosition(this->position);
    this->limitPaddle();
}

void Paddle::limitPaddle(){
    if(this->position.x < 0)
        this->position.x = 0;
    if(this->position.x > WIN_WIDTH - this->width)
        this->position.x = WIN_WIDTH - this->width;
}

void Paddle::handleInput(float& deltaTime){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->position.x -= this->speed * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->position.x += this->speed * deltaTime;        
}

Paddle::~Paddle(){

}

sf::RectangleShape Paddle::getShape(){
    return this->pad;
}