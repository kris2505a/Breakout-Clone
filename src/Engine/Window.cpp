#include "Window.h"
#include <SDL2/SDL_syswm.h>

Window::Window (int width, int height, const std::string& title) {
	SDL_Init(SDL_INIT_VIDEO);
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
}

void Window::pollEvent() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			m_open = false;
		}
	}
}

bool Window::isOpen() const {
	return m_open;
}

Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

HWND Window::getWindowHandle() {
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(m_window, &wmInfo);
	return wmInfo.info.win.window;
}
