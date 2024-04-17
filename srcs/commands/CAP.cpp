#include "CAP.hpp"

CAP::CAP(Server *s) {
	server = s;
	command = "CAP";
	server->addCommandToList(command, this);
}

CAP::~CAP(void) {
}

void CAP::execute(std::string message, Client *client) {
	this->sendMsg(arranger(message), client);
}

std::string CAP::arranger(std::string message) {
	return (this->command + " " + message);
}
