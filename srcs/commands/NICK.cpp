#include "NICK.hpp"

NICK::NICK(void) {
//	server = s;
	command = "NICK";
//	server->addCommandToList(command, this);
}

NICK::~NICK(void) {
}

void NICK::execute(std::string message, Client *client) {
	(void)message;
	this->sendMsg(arranger(), client);
}

std::string NICK::arranger() {
	return (this->command);
}
