#include "NICK.hpp"

NICK::NICK(void) {
	command = "NICK";
}

NICK::~NICK(void) {
}

void NICK::execute(std::string message, Client *source) {
	(void)message;
	commands->sendCommand(arranger(), source);
}

std::string NICK::arranger() {
	return (this->command);
}
