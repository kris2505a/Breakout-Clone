#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"

class Game{
private:
    
    sf::RenderWindow* window;
    sf::VideoMode resolution;
    float deltaTime;

public:
    Game();
    ~Game();
    void gameLoop();
};