#include "Headers/Game.h"
#include "Headers/Log.h"

float Game::deltaTime = 0;


Game::Game() {
	this->initVariables();
	this->initWindow();
}


void Game::initVariables() {
	this->resolution = sf::VideoMode(1280, 720);
	Log::messageLog("Resolution set to 1280 x 720");
	this->title = "Breakout-Clone";
	this->fps = 120;
	Log::messageLog("Frames Per Second set to: 120");
}

void Game::initWindow() {
	this->window = new sf::RenderWindow(this->resolution, this->title, sf::Style::Close | sf::Style::Resize);
	if (!window) {
		Log::errorLog("Unable to create Window!");
		return;
	}
	Log::messageLog("Window Created.");
	window->setFramerateLimit(this->fps);
}


float Game::getDeltaTime() {
	return deltaTime;
}


Game::~Game() {
	if (window) {
		delete this->window;
		Log::messageLog("Window Destroyed.");
	}
}


void Game::gameLoop() {
	if (!window)
		return;
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}

		window->clear(sf::Color::Cyan);
		window->display();
	}
}