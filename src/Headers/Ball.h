#pragma once
#include <SFML/Graphics.hpp>


class Ball {

private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::Vector2f location{ 0, 0 };
	sf::Vector2f speed{ 0, 0 };
	bool active{ false };


private:
	void render();
	void update(float);
	void resetBall();

public:
	Ball(sf::RenderWindow*);
	~Ball();
	void tick(float);
};