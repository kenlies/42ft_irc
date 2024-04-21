#include "CAP.hpp"

CAP::CAP(void) {
	command = "CAP";
}

CAP::~CAP(void) {
}

void CAP::execute(std::string message, Client *source) {
	(void)message;
	commands->sendCommand(arranger(), source);
}

std::string CAP::arranger() {
	return (this->command);
}
