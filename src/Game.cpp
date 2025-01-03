#include "Headers/Game.h"
#include "Headers/GameMode.h"



Game::Game(){
    this->resolution = sf::VideoMode(WIN_WIDTH, WIN_HEIGHT);
    window = new sf::RenderWindow(this->resolution, "Kriss", sf::Style::Close);
}

Game::~Game(){
    delete this->window;
}

void Game::gameLoop(){
    if(!window)
        return;
    
    sf::Clock dtClock;
    GameMode mode(this->window);

    while(window->isOpen()){
        sf::Event event;
        deltaTime = dtClock.restart().asSeconds();
        window->clear(sf::Color::Black);
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
        }

        mode.tick(this->deltaTime);
        window->display();
    }
}

