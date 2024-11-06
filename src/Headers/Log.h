#pragma once
#include <iostream>

#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define CYAN	"\033[36m"
#define RESET   "\033[0m"


static class Log {

public:
	static void messageLog(const std::string&&);
	static void errorLog(const std::string&&);
	static void debugLog(const std::string&&);

};



void Log::messageLog(const std::string&& msg) {
	std::cout << GREEN << "[Message]: " << msg << RESET << std::endl;
}

void Log::errorLog(const std::string&& msg) {
	std::cout << RED << "[Error]: " << msg << RESET << std::endl;
}

void Log::debugLog(const std::string&& msg) {
	std::cout << CYAN << "[DebugLog]: " << msg << RESET << std::endl;
}