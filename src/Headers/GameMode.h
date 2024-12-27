#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"


class GameMode{
private:
    sf::RenderWindow* targetWindow {nullptr};
    Paddle* player {nullptr};
    Ball* ball {nullptr};
    int health {0};
    int score {0};
    void render();
    void update(float&);

public:
    GameMode(sf::RenderWindow*);
    void tick(float&);

};