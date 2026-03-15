#pragma once
#include <glad/glad.h>
#include <SDL2/SDL.h>

class Game {
public:
	Game();
	~Game();
	void run();

private:
	void pollEvents();
	void update();
	void render();
	void handleInput();
	static void APIENTRY glDebugOutput(
		GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char *message, const void *userParam);
private:
	SDL_Window* m_window;
};
