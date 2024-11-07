#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Game {

private:
	sf::VideoMode resolution;
	std::string title{ "No Name" };
	int fps{ 120 };
	sf::RenderWindow* window{ nullptr };
	sf::Clock clock;
	float deltaTime;

private:
	class Ball* ball{ nullptr };
	class Paddle* paddle{ nullptr };

private:
	void render();
	void update();
	void tick();

public:
	Game();
	~Game();
	void initWindow();
	void initVariables();


	void gameLoop();

};