#include "CAP.hpp"

CAP::CAP(void) {
//	server = s;
	command = "CAP";
//	server->addCommandToList(command, this);
}

CAP::~CAP(void) {
}

void CAP::execute(std::string message, Client *client) {
	(void)message;
	this->sendMsg(arranger(), client);
}

std::string CAP::arranger() {
	return (this->command);
}
