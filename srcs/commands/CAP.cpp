#include "CAP.hpp"

CAP::CAP(Commands *c) {
	commands = c;
	command = "CAP";
}

CAP::~CAP(void) {
}

CAP &CAP::operator = (CAP const &copy) {
	(void)copy;
	return (*this);
}

void CAP::handleCommand(std::string message, Client *source) {
	(void)message;
	commands->sendCommand(arranger(), source);
}

std::string CAP::arranger() {
	return (this->command);
}
