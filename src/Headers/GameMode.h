#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <vector>


class GameMode{
private:
    sf::RenderWindow* targetWindow {nullptr};
    Paddle* player {nullptr};
    Ball* ball {nullptr};
    std::vector <Brick*> bricks;
    int health {0};
    void render();
    void update(float&);
    sf::Font font;
    sf::Text healthIndicator;
    sf::Text gameOverIndicator;
    void createBricks();

public:
    GameMode(sf::RenderWindow*);
    void tick(float&);
    ~GameMode();

};