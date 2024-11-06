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
	static float deltaTime;

public:
	Game();
	~Game();
	void initWindow();
	void initVariables();
	static float getDeltaTime();

	void gameLoop();

};