#include "Headers/Game.h"
#include "Headers/Log.h"
#include <fstream>
#include "Headers/Ball.h"




Game::Game() {
	this->initVariables();
	this->initWindow();
	this->ball = new Ball(this->window);
}


void Game::initVariables() {
	std::ifstream winConfig("config/window.ini");
	if (!winConfig.is_open()) {
		Log::errorLog("Unable to open window config file.");
		return;
	}
	std::getline(winConfig, this->title);
	winConfig >> this->resolution.width >> this->resolution.height;
	winConfig >> this->fps;
	winConfig.close();
	
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
		deltaTime = clock.restart().asSeconds();
		window->clear(sf::Color::Cyan);
		this->tick();
		window->display();
	}
}


void Game::render() {
	
}

void Game::update() {

}

void Game::tick() {
	this->ball->tick(this->deltaTime);
}