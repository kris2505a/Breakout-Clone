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
	if (active) {
		this->location += this->speed * deltaTime;
		this->circle.setPosition(this->location);
		if (circle.getPosition().x <= 0 || circle.getPosition().x >= window->getSize().x - circle.getRadius())
			this->speed.x *= -1;
		if (circle.getPosition().y <= 0)
			this->speed.y *= -1;
		if (circle.getPosition().y >= window->getSize().y - circle.getRadius()) {
			this->resetBall();
			this->active = false;
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			this->active = true;
	}
}


void Ball::tick(float deltaTime) {
	this->update(deltaTime);
	this->render();
}


void Ball::resetBall() {
	this->location = sf::Vector2f(640, 480);
	this->circle.setPosition(this->location);
}

Ball::~Ball() {
	delete this;
	Log::messageLog("Ball Destroyed");
}