#include "Headers/Ball.h"
#include <fstream>
#include "Headers/Log.h"


Ball::Ball(sf::RenderWindow* wind) {
	this->window = wind;
	std::ifstream ballConfig("config/ball.ini");
	if (!ballConfig.is_open()) {
		Log::errorLog("Unable to open config file");
		return;
	}
	float rad;
	ballConfig >> rad;
	int sp;
	ballConfig >> sp;
	ballConfig >> this->location.x >> this->location.y;
	this->circle.setRadius(rad);
	this->speed = sf::Vector2f(sp, sp);
	this->circle.setPosition(this->location);
	this->circle.setFillColor(sf::Color::Red);
	Log::messageLog("Ball Created");
	ballConfig.close();
}


void Ball::render() {

	window->draw(this->circle);
}


void Ball::update(float deltaTime) {
	this->location += this->speed * deltaTime;
	this->circle.setPosition(this->location);
	if (circle.getPosition().x <= 0 || circle.getPosition().x >= window->getSize().x)
		this->speed.x *= -1;
	if (circle.getPosition().y <= 0 || circle.getPosition().y >= window->getSize().y)
		this->speed.y *= -1;
}


void Ball::tick(float deltaTime) {
	this->update(deltaTime);
	this->render();
}