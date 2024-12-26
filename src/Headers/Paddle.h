#pragma once
#include "Entity.h"

class Paddle : public Entity{

private:

    float width, height;
    sf::RectangleShape pad;
    float speed;

    virtual void update(float&) override;
    virtual void render() override;
    void limitPaddle();
    virtual void handleInput(float&);

public:
    Paddle(sf::RenderWindow*);
    virtual ~Paddle() override;
    sf::RectangleShape getShape();
    float getWidth();
};