#include "NICK.hpp"

NICK::NICK(void) {
}

NICK::~NICK(void) {
}

void NICK::execute(std::string message, Client *client) {
	// std::cout << "NICK command: Message: " << message << std::endl;
	this->sendMsg(message, client);
}

std::string NICK::arranger(std::string message) {
	return ("NICK " + message);
}
