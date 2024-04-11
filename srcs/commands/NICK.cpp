#include "NICK.hpp"

NICK::NICK(void) {
}

NICK::~NICK(void) {
}

void NICK::execute(std::string message) const {
	std::cout << "NICK command: Message: " << message << std::endl;
}
