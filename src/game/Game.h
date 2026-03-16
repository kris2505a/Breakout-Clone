#pragma once
#include "Engine/Window.h"
#include "Renderer/Renderer.h"

class Game {
public:
	void run();
	
private:
	void init();
	void cleanup();
	void mainLoop();

	void update();
	void render();
	void handleInput();

private:
	std::unique_ptr <Window> m_window;
};