#pragma once
#include "Entity.h"

class Ball : public Entity{

private:
    sf::CircleShape ball;
    float radius;
    sf::Vector2f speed;

    virtual void update(float&) override;
    virtual void render() override;
    void resetBall();
    void bounceBall();

public:
    Ball(sf::RenderWindow*);
    virtual ~Ball() override;
};