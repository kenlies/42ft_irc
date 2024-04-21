#include "NICK.hpp"

NICK::NICK(Commands *c) {
	commands = c;
	command = "NICK";
}

NICK::~NICK(void) {
}

NICK &NICK::operator = (NICK const &copy) {
	(void)copy;
	return (*this);
}

void NICK::handleCommand(std::string message, Client *source) {
	(void)message;
	commands->sendCommand(arranger(), source);
}

std::string NICK::arranger() {
	return (this->command);
}
