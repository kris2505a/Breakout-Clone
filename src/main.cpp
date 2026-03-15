#include "game/game.hpp"
#include <exception>
#include <iostream>

int main() {
	auto game = new Game();
	try {
		game->run();
	} 
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}
