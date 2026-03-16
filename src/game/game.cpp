#include "Game.h"

void Game::run() 
{
	init();
	mainLoop();
	cleanup();
}

void Game::init() 
{
	m_window = std::make_unique <Window>(1600, 900, "Breakout");
	Renderer::init(1600, 900, m_window->getWindowHandle());
}

void Game::cleanup() 
{
	Renderer::cleanup();
}

void Game::mainLoop() 
{
	while (m_window->isOpen()) 
	{
		handleInput();
		update();
		
		Renderer::preRender();
		render();
		Renderer::postRender();

		m_window->pollEvent();
	}
}

void Game::update()
{

}

void Game::render()
{
	
}

void Game::handleInput()
{

}
