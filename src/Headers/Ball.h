#pragma once
#include "Entity.h"
#include "Paddle.h"

class Ball : public Entity{

private:
    sf::CircleShape ball;
    float radius;
    sf::Vector2f speed;
    Paddle* player;
    int health;

    virtual void update(float&) override;
    virtual void render() override;
    virtual void handleInput(float&) override;
    void resetBall();
    void bounceBall();
    

public:
    Ball(sf::RenderWindow*, Paddle*);
    virtual ~Ball() override;
    int getHealth();
    
};