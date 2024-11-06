#pragma once
#include <SFML/Graphics.hpp>


class Ball {

private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::Vector2f location{ 0,0 };
	float speed{ 0 };

public:
	Ball(sf::RenderWindow, float);
	~Ball();
};