#pragma once
#include "Entity.h"
#include "Ball.h"

class Brick : public Entity{

private:
    float width, height;
    sf::RenderWindow* targetWindow;
    Ball* ball;
    sf::RectangleShape brick;
    bool activeStatus;

    virtual void render() override;
    virtual void update(float&) override;
    virtual void handleInput(float&) override;

public:
    Brick(sf::RenderWindow*, Ball*, sf::Vector2f);
    ~Brick() = default;
    bool isActive();

};