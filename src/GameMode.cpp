#include "Headers/GameMode.h"
#include "Headers/Config.h"
#include <iostream>


GameMode::GameMode(sf::RenderWindow* window){
    this->targetWindow = window;
    this->player = new Paddle(this->targetWindow);
    this->ball = new Ball(this->targetWindow, this->player);
    this->health = 3;

    this->font.loadFromFile("resources/GyrochromeVF.ttf");
    
    this->scoreIndicator.setFont(this->font);
    this->scoreIndicator.setFillColor(sf::Color::Cyan);
    this->scoreIndicator.setPosition(sf::Vector2f(10, 10));

    this->healthIndicator.setFont(this->font);
    this->healthIndicator.setFillColor(sf::Color::Cyan);
    this->healthIndicator.setPosition(sf::Vector2f(WIN_WIDTH - 200, 10));

    this->gameOverIndicator.setFont(this->font);
    this->gameOverIndicator.setFillColor(sf::Color::Magenta);
    this->gameOverIndicator.setPosition(sf::Vector2f((WIN_WIDTH / 2) - 250, (WIN_HEIGHT / 2) - 50));
    this->gameOverIndicator.setString("GAME OVER");
    this->gameOverIndicator.setScale(sf::Vector2f(2.f, 2.f));
}

void GameMode::render(){
    if(this->health == 0){
        this->targetWindow->draw(this->gameOverIndicator);
        return;
    }
    this->targetWindow->draw(this->scoreIndicator);
    this->targetWindow->draw(this->healthIndicator);
}

void GameMode::update(float& deltaTime){
    if(this->health == 0){
        this->ball->setTick(false);
        this->player->setTick(false);
    }
    this->health = this->ball->getHealth();
    this->scoreIndicator.setString("Score: " + std::to_string(this->score));
    this->healthIndicator.setString("Health: " + std::to_string(this->health));
}

void GameMode::tick(float& deltaTime){
    if(this->player->tickStatus())
        this->player->tick(deltaTime);
    if(this->player->tickStatus())
        this->ball->tick(deltaTime);
    this->render();
    this->update(deltaTime);
}

