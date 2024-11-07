#pragma once
#include <SFML/Graphics.hpp>



class Paddle {

private:
	sf::RenderWindow* window{ nullptr };
	sf::RectangleShape rectangle;
	float speed{ 0.f };
	sf::Vector2f position{ 0, 0 };

private:
	void render();
	void handleInput(float);
	void move(int, float);

public:
	Paddle(sf::RenderWindow*);
	~Paddle();
	void tick(float);
	



};