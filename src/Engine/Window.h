#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <Windows.h>

class Window 
{
public:
	Window(int width, int height, const std::string& title);
	~Window();
	void pollEvent();
	bool isOpen() const;
	HWND getWindowHandle();

private:
	SDL_Window* m_window;
	bool m_open;
};
