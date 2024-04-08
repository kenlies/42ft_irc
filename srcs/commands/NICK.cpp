#include "NICK.hpp"

NICK::NICK(void) {
}

NICK::~NICK(void) {
}

void NICK::execute(std::string message) {
	std::cout << "NICK command executed: " << message << std::endl;
}
