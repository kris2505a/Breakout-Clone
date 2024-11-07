#pragma once
#include <iostream>

#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define CYAN	"\033[36m"
#define RESET   "\033[0m"


namespace Log {
	static void messageLog(std::string&&);
	static void errorLog(std::string&&);
	static void debugLog(std::string&&);
}


namespace Log {
	void Log::messageLog(std::string&& msg) {
		std::cout << GREEN << "[Message]: " << msg << RESET << std::endl;
	}

	void Log::errorLog(std::string&& msg) {
		std::cout << RED << "[Error]: " << msg << RESET << std::endl;
	}

	void Log::debugLog(std::string&& msg) {
		std::cout << CYAN << "[DebugLog]: " << msg << RESET << std::endl;
	}
}