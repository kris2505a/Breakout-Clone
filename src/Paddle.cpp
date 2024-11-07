#include "Headers/Paddle.h"
#include <fstream>
#include "Headers/Log.h"

Paddle::Paddle(sf::RenderWindow* wind) {
	this->window = wind;
	std::ifstream paddleConfig("config/paddle.ini");
	if (!paddleConfig.is_open()) {
		Log::errorLog("Unable to open config file");
		return;
	}
	float w, h;
	paddleConfig >> w >> h;
	paddleConfig >> this->speed;
	paddleConfig.close();
	rectangle.setSize(sf::Vector2f(w, h));
	rectangle.setFillColor(sf::Color::Green);
	this->position = sf::Vector2f((window->getSize().x - w) / 2, window->getSize().y - 25);
	this->rectangle.setPosition(this->position);
	this->rectangle.setOutlineThickness(10);
	this->rectangle.setOutlineColor(sf::Color::Blue);
}


void Paddle::render() {
	window->draw(rectangle);
}

void Paddle::handleInput(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->move(-1, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->move(1, deltaTime);
}

void Paddle::move(int direction, float deltaTime) {
	this->position.x += (this->speed * direction * deltaTime);
	this->position.y = window->getSize().y - 25;
	this->rectangle.setPosition(this->position);
}


void Paddle::tick(float deltaTime) {
	this->handleInput(deltaTime);
	this->render();
}