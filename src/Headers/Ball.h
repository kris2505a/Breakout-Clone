#pragma once
#include "Entity.h"

class Ball : public Entity{

private:
    sf::CircleShape ball;
    float radius;
    float speed;

    virtual void update(float&) override;
    virtual void render() override;
    void resetBall();

public:
    Ball(sf::RenderWindow*);
    virtual ~Ball() override;
};