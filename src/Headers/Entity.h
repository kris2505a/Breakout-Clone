#pragma once
#include <SFML/Graphics.hpp>

class Entity{
protected:
    sf::RenderWindow* targetWindow;
    sf::Vector2f position;
    virtual void render() = 0;
    virtual void update(float&) = 0;
    virtual void handleInput(float&) = 0;
    bool canTick = false;

public:
    inline Entity(){ this->canTick = true; }
    virtual ~Entity() = default;
    inline virtual void tick(float& deltaTime) {
        this->update(deltaTime);
        this->render();
    }
    inline bool tickStatus() { return this->canTick; }
    inline void setTick(bool tick) { this->canTick = tick; }
    inline sf::Vector2f getPosition() { return this->position; }

};