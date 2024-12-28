#pragma once
#include "Entity.h"
#include "Ball.h"

class Brick : public Entity{

private:
    float width, height;
    sf::RenderWindow* targetWindow;
    Ball* ball;
    sf::RectangleShape brick;

    virtual void render() override;
    virtual void update(float&) override;

public:
    Brick(sf::RenderWindow*, Ball*, sf::Vector2f);
    ~Brick() = default;

};